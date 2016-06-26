#include "Character.hpp"

Character::Character(int x, int y,int size) : x(x),y(y),direction(WEST) {
	this->texture_id = new int[size];
}


Character::~Character() {
	delete texture_id;
}

void Character::init(int x, int y, int size) {
	this->x = x;
	this->y = y;
	if (this->texture_id != nullptr) {
		delete this->texture_id;
	}
	this->texture_id = new int[size];
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
