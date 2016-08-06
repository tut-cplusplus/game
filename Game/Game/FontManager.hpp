#ifndef ___Class_FontManager
#define ___Class_FontManager

#include <string>

#include "Size.hpp"

#include "GL/glut.h"

class FontManager {
private:
	static GLuint ID;

public:
	static void init(void);
	static void draw(char c, const Size<double>& size);
	static void draw(const std::string& str, const Size<double>& size);
};

#endif

