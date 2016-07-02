#include <iostream>

#include "Character.hpp"

#include "GL/glut.h"

using namespace std;

Character::Character()
	: position(0.0, 0.0), direction(WEST), texture_id(nullptr)
{

}

Character::Character(const Vector<double>& position, const Size<double>& size)
	: position(position), size(size), direction(WEST), texture_id(nullptr)
{

}

Character::Character(const Vector<double>& position)
	: position(position), direction(WEST), texture_id(nullptr)
{

}

Character::~Character() {
	if (texture_id != nullptr)
		delete texture_id;
}

void Character::init(void) {

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

