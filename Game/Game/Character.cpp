#include <iostream>

#include "Character.hpp"

#include "GL/glut.h"

using namespace std;

int Character::IDCounter = 0;

void Character::init(void) {
	loadAnimations();
}

void Character::loadAnimations(void)
{
	setSize(size);
}

Character::Character(const Vector<double>& position, const Size<double>& size)
	: Rectangle(size), speed(1.0), isMoving(false), isBreaking(false), position(position), direction(WEST), ID(IDCounter++)
{
	init();
}

Character::~Character() {

}

void Character::startMoving(void)
{
	if (isMoving)
		return;
	if (direction == INVALID)
		return;
	isMoving = true;
	//進行方向のベクトル
	const Vector<double>& directionVector = getDirectionVector();
	//出発地点と目的地を設定する
	destination = position;
	destination += directionVector;
	source = position;
	moveCount = 0;
	animation.start();
}

void Character::move(void)
{
	if (!isMoving)
		return;
	//進行方向のベクトル
	Vector<double> directionVector = getDirectionVector();
	//20フレームで1マス進む
	directionVector *= 1.0 / 20;
	position += directionVector;
	moveCount++;
	if (moveCount == 20) {
		isMoving = false;
		position = destination;
		onStop();
	}
}

void Character::startBreaking(void) {
	isBreaking = true;
}

void Character::onStop(void)
{
	animation.stop();
}

void Character::onHit(void)
{
	isMoving = false;
	position = source;
}

void Character::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

void Character::draw(void)
{
	changeColor();
	animation.draw();
}

void Character::keyboard(const Key& key)
{

}

void Character::mouse(int button, int state, int x, int y)
{

}

void Character::keyboard(unsigned char key, int x, int y)
{

}

void Character::keyboardup(unsigned char key, int x, int y)
{

}

void Character::special(int key, int x, int y)
{

}

void Character::specialup(int key, int x, int y)
{

}

const Vector<double>& Character::getDirectionVector(void) const
{
	static Vector<double> directionVectorTable[] = {
		Vector<double>(0.0, 0.0),
		Vector<double>(0.0, 1.0),
		Vector<double>(0.0, -1.0),
		Vector<double>(1.0, 0.0),
		Vector<double>(-1.0, 0.0),
	};
	return directionVectorTable[direction];
}

void Character::setSize(const Size<double>& size)
{
	Rectangle::setSize(size);
	for (auto itr = animations.begin(); itr != animations.end(); ++itr)
		(*itr).setSize(size);
	animation.setSize(size);
}

