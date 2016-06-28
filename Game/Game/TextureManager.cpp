#include <iostream>

#include "TextureManager.hpp"

using namespace std;

const int TextureManager::MAX_TEXTURE = 256;
GLuint TextureManager::IDs[MAX_TEXTURE];
unsigned TextureManager::num = 0;
vector<string> TextureManager::paths;
vector<Image> TextureManager::images;

void TextureManager::init(void)
{
	glGenTextures(MAX_TEXTURE, IDs);
}

GLuint TextureManager::registerTexture(const std::string& path)
{
	try {
		images.push_back(Image(path));
	}
	catch (...) {
		throw CannotRegisterException();
	}
	paths.push_back(path);
	Image& image = images[num];
	GLuint ID = IDs[num];
	glBindTexture(GL_TEXTURE_2D, ID);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getWidth(), image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getData());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	num++;

	return ID;
}

