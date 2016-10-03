#include "Component.hpp"
#include "GL/glut.h"

class ComponentTitle : public Component
{
public:
	ComponentTitle(const Size<double>& size = Size<double>(0.0,0.0));

	virtual void draw(void);
	virtual void keyboard(unsigned char key, int x, int y);
private:
	bool game_start;
	GLuint id;
};

