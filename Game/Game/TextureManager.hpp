#ifndef ___Class_TextureManager
#define ___Class_TextureManager

#include <vector>
#include <string>

#include "GL/glut.h"

#include "Image.hpp"

class TextureManager {
public:
	class CannotRegisterException{};

private:
	static const int MAX_TEXTURE;
	static GLuint IDs[];
	static unsigned num;
	static std::vector<std::string> paths;
	static std::vector<Image> images;

public:
	static void init(void);
	static GLuint registerTexture(const std::string& path);
};

#endif

