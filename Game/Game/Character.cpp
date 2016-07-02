#include <iostream>

#include "Character.hpp"

#include "GL/glut.h"

using namespace std;

Character::Character()
	: speed(1.0), isMoving(false), position(0.0, 0.0), direction(WEST), texture_id(nullptr)
{

}

Character::Character(const Vector<double>& position, const Size<double>& size)
	: speed(1.0), isMoving(false), position(position), size(size), direction(WEST), texture_id(nullptr)
{

}

Character::Character(const Vector<double>& position)
	: speed(1.0), isMoving(false), position(position), direction(WEST), texture_id(nullptr)
{

}

Character::~Character() {
	if (texture_id != nullptr)
		delete texture_id;
}

void Character::init(void) {

}

void Character::startMoving(void)
{
	static Vector<double> directionVectorTable[] = {
		Vector<double>(0.0, 0.0),
		Vector<double>(0.0, 1.0),
		Vector<double>(0.0, -1.0),
		Vector<double>(1.0, 0.0),
		Vector<double>(-1.0, 0.0),
	};
	if (isMoving)
		return;
	if (direction == INVALID)
		return;
	isMoving = true;
	Vector<double> directionVector = directionVectorTable[direction];
	destination = position;
	destination += directionVector;
	source = position;
	moveCount = 0;
}

void Character::move(void)
{
	if (!isMoving)
		return;
	static Vector<double> directionVectorTable[] = {
		Vector<double>(0.0, 0.0),
		Vector<double>(0.0, 1.0),
		Vector<double>(0.0, -1.0),
		Vector<double>(1.0, 0.0),
		Vector<double>(-1.0, 0.0),
	};
	Vector<double> directionVector = directionVectorTable[direction];
	directionVector *= 1.0 / 20;
	position += directionVector;
	moveCount++;
	if (moveCount == 20) {
		isMoving = false;
		position = destination;
	}
}

void Character::breakWall(void) {
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
	double width = size.getWidth();
	double height = size.getHeight();
	glBegin(GL_QUADS);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
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

