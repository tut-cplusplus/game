#include "Decoy.hpp"
#include "Animation.hpp"

#include <GL/glut.h>

using namespace std;

void Decoy::init(void)
{
	loadAnimations();
}

void Decoy::loadAnimations(void)
{
	animation = Animation("data/animations/Player/down.ani");
	Character::loadAnimations();
}

Decoy::Decoy()
	: Character()
{
	init();
}

Decoy::Decoy(const Vector<double>& position, const Size<double>& size)
	: Character(position, size)
{
	init();
}

Decoy::~Decoy()
{
}

void Decoy::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

