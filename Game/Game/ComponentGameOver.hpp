#include "Component.hpp"
#include "GL/glut.h"
class ComponentGameOver : public Component
{
public:
	ComponentGameOver(const Size<double>& size = Size<double>(0.0, 0.0));
	
	virtual void draw(void);
	virtual void keyboard(unsigned char key, int x, int y);
public:
	bool game_restart;
	GLuint id;
};

