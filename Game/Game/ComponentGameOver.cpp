#include "ComponentGameOver.hpp"
#include "TextureManager.hpp"
#include "RelativeLayout.hpp"
#include "ComponentTitle.hpp"
#include "Global.hpp"
#include "FontManager.hpp"

#include "GL/glut.h"

ComponentGameOver::ComponentGameOver(const Size<double>& size)
	: Component(size), game_restart(false), id(TextureManager::registerTexture("data/images/GameOver.ppm"))
{
}

void ComponentGameOver::draw(void)
{
	double width = Global::WORLD_WIDTH;
	double height = Global::WORLD_HEIGHT;
	glColor3d(1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, id);
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

	if (game_restart) {
		RelativeLayout* layout = new RelativeLayout(Size<double>(Global::WORLD_WIDTH, Global::WORLD_HEIGHT));
		layout->add(new ComponentTitle(Size<double>(0.0, 0.0)), Vector<double>(0.0, 0.0), true);
		throw layout;
	}
}

void ComponentGameOver::keyboard(unsigned char key, int x, int y)
{
	game_restart = key == 't';
}
