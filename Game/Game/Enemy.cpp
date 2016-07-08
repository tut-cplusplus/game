#include <random>
#include <cmath>

#include "Enemy.hpp"

#include <GL/glut.h>

using namespace std;

Enemy::Enemy()
	: Character(), viewAngle(45.0), radius(100.0), first(true)
{

}

Enemy::Enemy(const Vector<double>& position, const Size<double>& size)
	: Character(position, size), viewAngle(45.0), radius(100.0), first(true)
{

}

Enemy::Enemy(const Vector<double>& position)
	: Character(position), viewAngle(45.0), radius(100.0), first(true)
{

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
	//テストコード
	static int cnt = 0;
	cout << "find : "  << cnt++ << endl;
}

void Enemy::onFind(const Vector<int>& position, const Block& block)
{

}

void Enemy::changeColor(void) const
{
	glColor3d(0.0, 1.0, 0.0);
}

void Enemy::draw(void)
{
	static double angles[] = {
		0.0,
		90.0,
		-90.0,
		0.0,
		180.0,
	};
	double width = size.getWidth();
	double height = size.getHeight();
	double angle = angles[direction];
	//本体の表示
	Character::draw();
	//視界の表示
	glPushMatrix();
	glTranslated(width / 2, height / 2, 0.0);
	glRotated(angle, 0.0, 0.0, 1.0);
	glRotated(-viewAngle / 2, 0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(radius, 1.0);
	int n = 100;
	for (int i = 1; i <= n; i++) {
		double angle2 = (double)i / n * viewAngle / 180 * M_PI;
		double x = cos(angle2) * radius;
		double y = sin(angle2) * radius;
		glVertex2d(x, y);
	}
	glVertex2d(0.0, 0.0);
	glEnd();
	glPopMatrix();
}

