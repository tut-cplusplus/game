#include "ComponentTexture.hpp"

using namespace std;

ComponentTexture::ComponentTexture(const Size<double>& size, const string& path)
	: Component(size)
{
	ID = TextureManager::registerTexture(path);
}

void ComponentTexture::draw(void)
{
	double width = size.getWidth();
	double height = size.getHeight();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(0.0, 0.0);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(width, 0.0);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(width, height);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(0.0, height);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

