#include <iostream>
#include <queue>
#include <random>

#include "ComponentGame.hpp"
#include "BlockAir.hpp"
#include "BlockNormalWall.hpp"
#include "BlockUnbreakableWall.hpp"
#include "Position.hpp"

#include "GL/glut.h"

using namespace std;

const int ComponentGame::MAP_WIDTH = 33;
const int ComponentGame::MAP_HEIGHT = 33;

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
		map[i][j] = nullptr;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		map[i][0] = new BlockUnbreakableWall(blockWidth, blockHeight);
		map[i][MAP_WIDTH - 1] = new BlockUnbreakableWall(blockWidth, blockHeight);
	}
	for (int i = 0; i < MAP_WIDTH; i++) {
		map[0][i] = new BlockUnbreakableWall(blockWidth, blockHeight);
		map[MAP_HEIGHT - 1][i] = new BlockUnbreakableWall(blockWidth, blockHeight);
	}

	vector<Position<int>> v;
	for (int i = 4; i < MAP_HEIGHT - 1; i += 4) {
		v.push_back(Position<int>(0, i));
		v.push_back(Position<int>(MAP_WIDTH - 1, i));
	}
	for (int i = 4; i < MAP_WIDTH - 1; i += 4) {
		v.push_back(Position<int>(i, 0));
		v.push_back(Position<int>(i, MAP_HEIGHT - 1));
	}

	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> rnd(0.0, 1.0);
	static Position<int> directions[] = {
		Position<int>(1, 0),
		Position<int>(-1, 0),
		Position<int>(0, 1),
		Position<int>(0, -1),
	};
	while (v.size()) {
		int idx = rnd(mt) * v.size();
		Position<int> position = v[idx];
		v.erase(v.begin() + idx);
		vector<int> directionIDs = getValidDirections(position);
		int size = directionIDs.size();
		if (!size)
			continue;
		idx = rnd(mt) * size;
		const Position<int>& direction = directions[directionIDs[idx]];
		for (int i = 0; i < 4; i++) {
			position += direction;
			int x = position.getX();
			int y = position.getY();
			map[y][x] = new BlockNormalWall(blockWidth, blockHeight);
			if (i == 3)
				v.push_back(position);
		}
	}
	for (int i = 1; i < MAP_HEIGHT - 1; i++)
	for (int j = 1; j < MAP_WIDTH - 1; j++)
		if (map[i][j] == nullptr)
			map[i][j] = new BlockAir(blockWidth, blockHeight);
}

vector<int> ComponentGame::getValidDirections(const Position<int>& _position)
{
	static Position<int> directions[] = {
		Position<int>(1, 0),
		Position<int>(-1, 0),
		Position<int>(0, 1),
		Position<int>(0, -1),
	};
	int n = sizeof(directions) / sizeof(directions[0]);

	vector<int> ret;
	for (int i = 0; i < n; i++) {
		Position<int> position(_position);
		const Position<int>& direction = directions[i];
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			position += direction;
			int x = position.getX();
			int y = position.getY();
			if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
				flag = true;
				break;
			}
			if (map[y][x] != nullptr) {
				flag = true;
				break;
			}
		}
		if (!flag)
			ret.push_back(i);
	}
	return ret;
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

void ComponentGame::setBlockSize(void)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			map[i][j]->setWidth(blockWidth);
			map[i][j]->setHeight(blockHeight);
		}
	}
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
	setBlockSize();
}

void ComponentGame::setHeight(int height)
{
	this->height = height;
	blockHeight = (double)height / MAP_HEIGHT;
	setBlockSize();
}

void ComponentGame::init(void)
{
	allocMap();
	generateMap();
}

void ComponentGame::draw(void)
{
	glColor3d(1.0, 1.0, 1.0);
	glPushMatrix();
	for (int i = 0; i < MAP_HEIGHT; i++) {
		glPushMatrix();
		for (int j = 0; j < MAP_WIDTH; j++) {
			map[i][j]->draw();
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

