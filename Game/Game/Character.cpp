#include "Character.h"

Character::Character(int x, int y) : x(x),y(y),direction(WEST) {
}


Character::~Character() {
}


void Character::face(Direction d) {
	this->direction = d;
}

void Character::breakWall(void) {
}