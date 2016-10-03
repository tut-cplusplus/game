#include "ComponentTitle.hpp"
#include "RelativeLayout.hpp"
#include "VerticalSplitLayout.hpp"
#include "Global.hpp"
#include "ComponentGame.hpp"
#include "ComponentFPS.hpp"
#include "TextureManager.hpp"
#include "GL/glut.h"


ComponentTitle::ComponentTitle(const Size<double>& size)
	: Component(size), game_start(false), id(TextureManager::registerTexture("data/images/Title.ppm"))
{
}

void ComponentTitle::draw(void)
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

	if (game_start) {
		RelativeLayout* layout = new RelativeLayout(Size<double>(Global::WORLD_WIDTH, Global::WORLD_HEIGHT));
		VerticalSplitLayout* verticalSplitLayout = new VerticalSplitLayout(Size<double>(0, 0), 0.05);
		layout->add(verticalSplitLayout, Vector<double>(0.0, 0.0), true);
		verticalSplitLayout->setComponent2(new ComponentGame(Size<double>(0.0, 0.0), "data/stages/stage01.txt"));
		layout->add(new ComponentFPS(Size<double>(450.0, 16.0)));
		throw layout;
	}
}

void ComponentTitle::keyboard(unsigned char key, int x, int y)
{
	game_start = key == ' ';
}
