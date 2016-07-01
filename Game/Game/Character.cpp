#include "Character.hpp"

#include "GL/glut.h"

Character::Character(double x, double y, double width, double height, int size)
	: x(x), y(y), width(width), height(height), direction(WEST), texture_id(nullptr)
{

}

Character::Character(double x, double y,int size)
	: x(x) ,y(y), width(0), height(0), direction(WEST), texture_id(nullptr)
{

}

Character::Character(double x, double y)
	: x(x), y(y), width(0), height(0), direction(WEST), texture_id(nullptr)
{

}


Character::~Character() {
	if (texture_id != nullptr)
		delete texture_id;
}

void Character::init(void) {

}


void Character::face(Direction d) {
	this->direction = d;
}

void Character::move(void) {
	switch (direction)
	{
	case NORTH:
		y++;
		break;
	case SOUTH:
		y--;
		break;
	case EAST:
		x++;
		break;
	case WEST:
		x--;
		break;
	default:
		break;
	}
}

void Character::breakWall(void) {
}

void Character::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

void Character::draw(void)
{
	changeColor();
	glBegin(GL_QUADS);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
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

