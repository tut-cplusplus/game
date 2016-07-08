#include <iostream>
#include <fstream>

#include "Animation.hpp"
#include "TextureManager.hpp"

using namespace std;

Animation::Animation(const string& fpath, const Size<double>& size)
	: Rectangle(size), isPlaying(false), isLoop(false), cnt(0)
{
	ifstream ifs(fpath);
	if (!ifs)
		throw FileCannotOpenException();

	string animationPath;
	ifs >> animationPath;
	ifs >> rows >> cols;
	ifs >> fps;
	ID = TextureManager::registerTexture(animationPath);
}

void Animation::draw(void)
{
	int idx = cnt / fps;
	int row = idx / cols;
	int col = idx % cols;

	double left = (double)col / cols;
	double right = (double)(col + 1) / cols;
	double bottom = (double)(rows - row) / rows;
	double top = (double)(rows - (row + 1)) / rows;

	const Size<double>& size = getSize();
	double width = size.getWidth();
	double height = size.getHeight();

	glEnable(GL_TEXTURE_2D);
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

	update();
}

void Animation::update(void)
{
	if (!isPlaying)
		return;
	int max = rows * cols * fps;
	if (++cnt >= max) {
		cnt = 0;
		if (!isLoop)
			isPlaying = false;
	}
}

