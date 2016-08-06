#define _USE_MATH_DEFINES
#include <random>
#include <cmath>

#include "Global.hpp"
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

Enemy::Enemy(const Vector<double>& position, const Size<double>& size, double speed, double viewAngle, double radius, int life)
	: Character(position, size, speed), viewAngle(viewAngle), radius(radius), first(true), onEyes(false), count(0), life(life)
{
	init();
}

Enemy::~Enemy()
{

}

void Enemy::onMoveAI(void)
{
	isFindPlayer = false;
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

	if (!onEyes) {
		if (count != 0) {
			count --;
			std::cout << "find out : " << count << std::endl;
		}
	}
	else {
		count = 10;
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

void Enemy::onFindDirect(const Character& character)
{
	isFindPlayer = true;
	if (!isLookingPlayer)
		onFindFirst(character);
	isLookingPlayer = true;
	onFind(character);
}

void Enemy::onFind(const Character& character)
{
	oldTarget = newTarget;
	newTarget = character.getPosition();
	onEyes = true;
}

void Enemy::onFindFirst(const Character& character)
{
	Vector<double> position = this->position;
	const Size<double>& size = character.getSize();
	position.setX(position.getX() * size.getWidth());
	position.setY(position.getY() * size.getHeight());
	Information information(position, 50, character);
	information.registerID(ID);
	informations.push_back(information);
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
	if (!isFindPlayer)
		isLookingPlayer = false;
	//本体の表示
	Character::draw();
}

void Enemy::drawVisibility() const
{
	double width = size.getWidth();
	double height = size.getHeight();
	double angle = getAngle();
	//視界の表示
	CircularSector circularSector(Vector<double>(width / 2, height / 2), angle, viewAngle, radius);
	circularSector.draw();
}

void Enemy::drawInformations(void)
{
	//伝達情報の表示
	for (auto itr = informations.begin(); itr != informations.end(); ++itr) {
		Information& information = *itr;
		information.draw();
		double radius = information.getRadius();
		if (radius > 2 * Global::WORLD_WIDTH) {
			itr = informations.erase(itr);
			break;
		}
	}
}

