#include <iostream>

#include "FontManager.hpp"
#include "TextureManager.hpp"

using namespace std;

GLuint FontManager::ID;

void FontManager::init(void)
{
	ID = TextureManager::registerTexture("data/fonts/opensans.ppm");
}

void FontManager::draw(char c, double width, double height)
{
	double colsDouble = 16.3;	//フォントテクスチャの右側にある余白への対処
	int cols = colsDouble;
	int rows = 8;
	int row = c / cols;
	int col = c % cols;

	double left = (double)col / colsDouble;
	double right = (double)(col + 1) / colsDouble;
	double bottom = (double)(rows - row) / rows;
	double top = (double)(rows - (row + 1)) / rows;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, ID);
	glBegin(GL_QUADS);
	glTexCoord2d(left, bottom);
	glVertex2d(0.0, 0.0);
	glTexCoord2d(right, bottom);
	glVertex2d(width, 0.0);
	glTexCoord2d(right, top);
	glVertex2d(width, height);
	glTexCoord2d(left, top);
	glVertex2d(0.0, height);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void FontManager::draw(const string& str, double width, double height)
{
	double step = width / str.length();
	glPushMatrix();
	for (unsigned i = 0; i < str.length(); i++) {
		draw(str[i], step, height);
		glTranslated(step, 0.0, 0.0);
	}
	glPopMatrix();
}


