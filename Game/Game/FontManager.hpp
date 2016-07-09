#ifndef ___Class_FontManager
#define ___Class_FontManager

#include <string>

#include "GL/glut.h"

class FontManager {
private:
	static GLuint ID;

public:
	static void init(void);
	static void draw(char c, double width, double height);
	static void draw(const std::string& str, double width, double height);
};

#endif

