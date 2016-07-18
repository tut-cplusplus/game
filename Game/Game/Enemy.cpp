#define _USE_MATH_DEFINES
#include <random>
#include <cmath>

#include "Enemy.hpp"
#include "CircularSector.hpp"

#include <GL/glut.h>

using namespace std;

void Enemy::loadAnimations(void)
{
	animation = Animation("data/animations/Enemy/Enemy.ani");
	animations.push_back(animation);
	Character::loadAnimations();
}

Enemy::Enemy()
	: Character(), viewAngle(45.0), radius(100.0), first(true), onEyes(false)
{
	init();
}

Enemy::Enemy(const Vector<double>& position, const Size<double>& size)
	: Character(position, size), viewAngle(45.0), radius(100.0), first(true), onEyes(false)
{
	init();
}

Enemy::Enemy(const Vector<double>& position)
	: Character(position), viewAngle(45.0), radius(100.0), first(true), onEyes(false)
{
	init();
}


Enemy::~Enemy()
{

}

double Enemy::getViewAngle(void) const
{
	return viewAngle;
}

double Enemy::getRadius(void) const
{
	return radius;
}

void Enemy::onMoveAI(void)
{
	//移動中であれば何もしない
	if (isMoving)
		return;
	static random_device rd;
	static mt19937 mt(rd());
	static uniform_int_distribution<int> randomDirection(NORTH, WEST);
	if (first) {
		//最初だけ方向を決める
		direction = (Direction)randomDirection(mt);
		first = false;
	}


	static int count = 0;
	if (!onEyes) {
		if (count != 0) {
			count --;
			std::cout << "find out : " << count << std::endl;
		}
	}
	else {
		count = 100;
	}

	if (count) {
		double dx = newTarget.getX() - this->position.getX();
		double dy = newTarget.getY() - this->position.getY();

		if (pow(dx, 2.0) > pow(dy, 2.0)) {
			if (dx < 0) {
				direction = WEST;
			}
			else {
				direction = EAST;
			}
		}
		else {
			if (dy < 0) {
				direction = SOUTH;
			}
			else {
				direction = NORTH;
			}
		}

		onEyes = false;
	}

	//移動の開始
	startMoving();
}

void Enemy::onHit(void)
{
	Character::onHit();
	static random_device rd;
	static mt19937 mt(rd());
	static uniform_int_distribution<int> randomDirection(NORTH, WEST);
	//方向を決める（変更する）
	direction = (Direction)randomDirection(mt);
	//移動の開始
	startMoving();
}

void Enemy::onFind(const Player& player)
{
	oldTarget = newTarget;
	newTarget = player.getPosition();
	onEyes = true;
}

void Enemy::onFind(const Vector<int>& position, const Block& block)
{

}

void Enemy::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

void Enemy::draw(void)
{
	double width = size.getWidth();
	double height = size.getHeight();
	double angle = getAngle();
	//本体の表示
	Character::draw();
	//視界の表示
	CircularSector circularSector(Vector<double>(width / 2, height / 2), angle, viewAngle, radius);
	circularSector.draw();
}
