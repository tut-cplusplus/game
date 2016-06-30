#include <iostream>

#include "ComponentGame.hpp"
#include "BlockAir.hpp"
#include "BlockNormalWall.hpp"

#include "GL/glut.h"

using namespace std;

const int ComponentGame::MAP_WIDTH = 15;
const int ComponentGame::MAP_HEIGHT = 15;

void ComponentGame::allocMap(void)
{
	try {
		map = new Block**[MAP_HEIGHT];
		for (int i = 0; i < MAP_HEIGHT; i++)
			map[i] = new Block*[MAP_WIDTH];
	}
	catch (const bad_alloc& e) {
		throw CannotAllocateException();
	}
}

void ComponentGame::clearMap(void)
{
	deleteMap();
	allocMap();
}

void ComponentGame::generateMap(void)
{
	for (int i = 1; i < MAP_HEIGHT - 1; i++)
	for (int j = 1; j < MAP_WIDTH - 1; j++)
		map[i][j] = new BlockAir(blockWidth, blockHeight);
	for (int i = 0; i < MAP_HEIGHT; i++) {
		map[i][0] = new BlockNormalWall(blockWidth, blockHeight);
		map[i][MAP_WIDTH - 1] = new BlockNormalWall(blockWidth, blockHeight);
	}
	for (int i = 0; i < MAP_WIDTH; i++) {
		map[0][i] = new BlockNormalWall(blockWidth, blockHeight);
		map[MAP_HEIGHT - 1][i] = new BlockNormalWall(blockWidth, blockHeight);
	}
}

void ComponentGame::deleteMap(void)
{
	if (map == nullptr)
		return;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		if (map[i] == nullptr)
			continue;
		for (int j = 0; j < MAP_WIDTH; j++)
			if (map[i][j] != nullptr)
				delete map[i][j];
		delete[] map[i];
	}
	delete[] map;
}

ComponentGame::ComponentGame()
{

}

ComponentGame::ComponentGame(int width, int height)
	: Component(width, height), map(nullptr), blockWidth((double)width / MAP_WIDTH), blockHeight((double)height / MAP_HEIGHT)
{
	init();
}

ComponentGame::~ComponentGame()
{
	deleteMap();
}

void ComponentGame::setWidth(int width)
{
	this->width = width;
	blockWidth = (double)width / MAP_WIDTH;
}

void ComponentGame::setHeight(int height)
{
	this->height = height;
	blockHeight = (double)height / MAP_HEIGHT;
}

void ComponentGame::init(void)
{
	allocMap();
	generateMap();
}

void ComponentGame::draw(void)
{
	//cout << blockWidth << ", " << blockHeight << endl;
	glColor3d(1.0, 1.0, 1.0);
	glPushMatrix();
	for (int i = 0; i < MAP_HEIGHT; i++) {
		glPushMatrix();
		for (int j = 0; j < MAP_WIDTH; j++) {
			glBegin(GL_LINE_LOOP);
			glVertex2d(0.0, 0.0);
			glVertex2d(blockWidth, 0.0);
			glVertex2d(blockWidth, blockHeight);
			glVertex2d(0.0, blockHeight);
			glEnd();
			glTranslated(blockWidth, 0.0, 0.0);
		}
		glPopMatrix();
		glTranslated(0.0, blockHeight, 0.0);
	}
	glPopMatrix();
}

void ComponentGame::mouse(int button, int state, int x, int y)
{

}

void ComponentGame::keyboard(unsigned char key, int x, int y)
{

}

void ComponentGame::keyboardup(unsigned char key, int x, int y)
{

}

void ComponentGame::special(int key, int x, int y)
{

}

void ComponentGame::specialup(int key, int x, int y)
{

}

