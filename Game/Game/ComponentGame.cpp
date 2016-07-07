#include <iostream>
#include <queue>
#include <random>

#include "ComponentGame.hpp"
#include "BlockAir.hpp"
#include "BlockNormalWall.hpp"
#include "BlockUnbreakableWall.hpp"
#include "Vector.hpp"
#include "CircularSector.hpp"
#include "Size.hpp"

#include "GL/glut.h"

using namespace std;

const int ComponentGame::MAP_WIDTH = 45;
const int ComponentGame::MAP_HEIGHT = 45;
const int ComponentGame::DIVISION_NUMBER = 100;

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
		map[i][0] = new BlockUnbreakableWall(blockSize);
		map[i][MAP_WIDTH - 1] = new BlockUnbreakableWall(blockSize);
	}
	for (int i = 0; i < MAP_WIDTH; i++) {
		map[0][i] = new BlockUnbreakableWall(blockSize);
		map[MAP_HEIGHT - 1][i] = new BlockUnbreakableWall(blockSize);
	}

	vector<Vector<int>> v;
	for (int i = 4; i < MAP_HEIGHT - 1; i += 4) {
		v.push_back(Vector<int>(0, i));
		v.push_back(Vector<int>(MAP_WIDTH - 1, i));
	}
	for (int i = 4; i < MAP_WIDTH - 1; i += 4) {
		v.push_back(Vector<int>(i, 0));
		v.push_back(Vector<int>(i, MAP_HEIGHT - 1));
	}

	static Vector<int> directions[] = {
		Vector<int>(1, 0),
		Vector<int>(-1, 0),
		Vector<int>(0, 1),
		Vector<int>(0, -1),
	};
	while (v.size()) {
		int idx = rnd(mt) * v.size();
		Vector<int> position = v[idx];
		vector<int> directionIDs = getValidDirections(position);
		int size = directionIDs.size();
		if (!size) {
			v.erase(v.begin() + idx);
			continue;
		}
		idx = rnd(mt) * size;
		const Vector<int>& direction = directions[directionIDs[idx]];
		for (int i = 0; i < 4; i++) {
			position += direction;
			int x = position.getX();
			int y = position.getY();
			map[y][x] = new BlockNormalWall(blockSize);
			if (i == 3)
				v.push_back(position);
		}
	}
	for (int i = 1; i < MAP_HEIGHT - 1; i++)
	for (int j = 1; j < MAP_WIDTH - 1; j++)
		if (map[i][j] == nullptr)
			map[i][j] = new BlockAir(blockSize);
}

vector<int> ComponentGame::getValidDirections(const Vector<int>& _position)
{
	static Vector<int> directions[] = {
		Vector<int>(1, 0),
		Vector<int>(-1, 0),
		Vector<int>(0, 1),
		Vector<int>(0, -1),
	};
	int n = sizeof(directions) / sizeof(directions[0]);

	vector<int> ret;
	for (int i = 0; i < n; i++) {
		Vector<int> position(_position);
		const Vector<int>& direction = directions[i];
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

void ComponentGame::addPlayer(void)
{
	vector<Vector<int>> positions = getTransparentBlockVectors();
	int n = positions.size();
	int idx = rnd(mt) * n;
	const Vector<int>& position = positions[idx];
	Keypad keypad(Key('w'), Key('s'), Key('a'), Key('d'), Key(' '));
	players.push_back(new Player(Vector<double>(position.getX(), position.getY()), keypad));
}

void ComponentGame::deletePlayers(void)
{
	for (auto itr = players.begin(); itr != players.end(); ++itr)
		delete *itr;
}

void ComponentGame::addEnemy(void)
{
	vector<Vector<int>> positions = getTransparentBlockVectors();
	int n = positions.size();
	int idx = rnd(mt) * n;
	const Vector<int>& position = positions[idx];
	enemies.push_back(new NormalEnemy(Vector<double>(position.getX(), position.getY())));
}

void ComponentGame::deleteEnemies(void)
{
	for (auto itr = enemies.begin(); itr != enemies.end(); ++itr)
		delete *itr;
}

void ComponentGame::moveEnemiesAI(void)
{
	for (auto itr = enemies.begin(); itr != enemies.end(); ++itr)
		(**itr).onMoveAI();
}

bool ComponentGame::isFound(const Player& player, const Enemy& enemy) const
{
	static Vector<double> dtable[] = {
		Vector<double>(0.0, 0.0),
		Vector<double>(1.0, 0.0),
		Vector<double>(0.0, 1.0),
		Vector<double>(1.0, 1.0),
	};
	int n = sizeof(dtable) / sizeof(dtable[0]);
	Vector<double> enemyPosition = enemy.getPosition();
	enemyPosition += Vector<double>(0.5, 0.5);
	Vector<double> enemyWorldPosition(enemyPosition);
	Size<double> enemySize = enemy.getSize();
	enemyWorldPosition.setX(enemyWorldPosition.getX() * enemySize.getWidth());
	enemyWorldPosition.setY(enemyWorldPosition.getY() * enemySize.getHeight());
	CircularSector circularSector(enemyWorldPosition, enemy.getAngle(), enemy.getViewAngle(), enemy.getRadius());
	Vector<double> playerPosition(player.getPosition());
	Size<double> playerSize = player.getSize();
	for (int i = 0; i < n; i++) {
		const Vector<double>& v = dtable[i];
		Vector<double> position = playerPosition + v;
		Vector<double> worldPosition(position);
		worldPosition.setX(worldPosition.getX() * playerSize.getWidth());
		worldPosition.setY(worldPosition.getY() * playerSize.getHeight());
		if (!circularSector.isHit(worldPosition))
			continue;
		if (isBlocked(position, enemyPosition))
			continue;
		return true;
	}
	return false;
}

bool ComponentGame::isBlocked(const Vector<double>& position1, const Vector<double>& position2) const
{
	Vector<double> v = position2 - position1;
	v /= DIVISION_NUMBER;
	Vector<double> position(position1);
	for (int i = 0; i < DIVISION_NUMBER; i++) {
		position += v;
		if (isHit(position))
			return true;
	}
	return false;
}

bool ComponentGame::isHit(const Vector<double>& position1, const Vector<double>& position2) const
{
	double bottom = position1.getY();
	double left = position1.getX();
	double top = bottom + 1.0;
	double right = left + 1.0;
	double x = position2.getX();
	double y = position2.getY();

	return (x > left && x < right) && (y > bottom && y < top);
}

bool ComponentGame::isHit(const Vector<double>& position) const
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			const Block& block = *map[i][j];
			if (block.isTransparent())
				continue;
			if (isHit(Vector<double>(j, i), position))
				return true;
		}
	}
	return false;
}

bool ComponentGame::isHit(const Character& character) const
{
	static Vector<double> dv[] = {
		Vector<double>(0.5, 0.0),
		Vector<double>(0.5, 1.0),
		Vector<double>(0.0, 0.5),
		Vector<double>(1.0, 0.5),
	};
	int n = sizeof(dv) / sizeof(dv[0]);
	Vector<double> position = character.getPosition();
	for (int i = 0; i < n; i++)
		if (isHit(position + dv[i]))
			return true;
	return false;
}

vector<Vector<int>> ComponentGame::getTransparentBlockVectors(void) const
{
	vector<Vector<int>> positions;
	//Characterを配置可能な場所を取得する
	for (int i = 1; i < MAP_HEIGHT - 1; i++) {
		for (int j = 1; j < MAP_WIDTH - 1; j++) {
			if (map[i][j]->isTransparent())
				positions.push_back(Vector<int>(j, i));
		}
	}
	return positions;
}

void ComponentGame::setBlockSize(void)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++)
			map[i][j]->setSize(blockSize);
	}
	for (auto itr = players.begin(); itr != players.end(); ++itr) {
		Player& player = **itr;
		player.setSize(blockSize);
	}
	for (auto itr = enemies.begin(); itr != enemies.end(); ++itr) {
		Enemy& enemy = **itr;
		enemy.setSize(blockSize);
	}
}

std::list<Key>::iterator ComponentGame::searchKey(const Key& key)
{
	for (auto itr = keys.begin(); itr != keys.end(); ++itr) {
		const Key& key1 = *itr;
		if (key1 == key)
			return itr;
	}
	return keys.end();
}

void ComponentGame::addKey(const Key& key)
{
	if (searchKey(key) == keys.end())
		keys.push_back(key);
}

void ComponentGame::deleteKey(const Key& key)
{
	auto itr = searchKey(key);
	if (itr != keys.end())
		keys.erase(itr);
}

void ComponentGame::keyEvent(void)
{
	for (auto itr = keys.begin(); itr != keys.end(); ++itr) {
		const Key& key = *itr;
		for (auto itr = players.begin(); itr != players.end(); ++itr) {
			Player& player = **itr;
			player.keyboard(key);
			Keypad keypad = player.getKeypad();
			if (keypad.getUp() == key)
				player.onUp();
			if (keypad.getDown() == key)
				player.onDown();
			if (keypad.getLeft() == key)
				player.onLeft();
			if (keypad.getRight() == key)
				player.onRight();
			if (keypad.getBreakBlock() == key)
				player.onBreakBlock();
		}
	}
}

void ComponentGame::moveEvent(void)
{
	moveCharacters(players);
	moveEnemiesAI();
	moveCharacters(enemies);
}

void ComponentGame::hitEvent(void)
{
	hitDetectCharacters(players);
	hitDetectCharacters(enemies);
}

void ComponentGame::findPlayerEvent(void)
{
	for (auto itr1 = players.begin(); itr1 != players.end(); ++itr1) {
		Player& player = **itr1;
		for (auto itr2 = enemies.begin(); itr2 != enemies.end(); ++itr2) {
			Enemy& enemy = **itr2;
			if (isFound(player, enemy))
				enemy.onFind(player);
		}
	}
}

ComponentGame::ComponentGame()
{

}

ComponentGame::ComponentGame(int width, int height)
	: Component(width, height), mt(rd()), rnd(0.0, 1.0), map(nullptr), blockSize((double)width / MAP_WIDTH, (double)height / MAP_HEIGHT)
{
	init();
}

ComponentGame::~ComponentGame()
{
	deleteMap();
	deletePlayers();
}

void ComponentGame::setWidth(int width)
{
	this->width = width;
	blockSize.setWidth((double)width / MAP_WIDTH);
	setBlockSize();
}

void ComponentGame::setHeight(int height)
{
	this->height = height;
	blockSize.setHeight((double)height / MAP_HEIGHT);
	setBlockSize();
}

void ComponentGame::init(void)
{
	allocMap();
	generateMap();
	addPlayer();
	for (int i = 0; i < 5; i++)
		addEnemy();
}

void ComponentGame::draw(void)
{
	keyEvent();
	moveEvent();
	hitEvent();
	findPlayerEvent();
	double blockWidth = blockSize.getWidth();
	double blockHeight = blockSize.getHeight();
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
	drawCharacters(players);
	drawCharacters(enemies);
}

void ComponentGame::mouse(int button, int state, int x, int y)
{
	for (auto itr = players.begin(); itr != players.end(); ++itr)
		(*itr)->mouse(button, state, x, y);
}

void ComponentGame::keyboard(unsigned char key, int x, int y)
{
	for (auto itr = players.begin(); itr != players.end(); ++itr)
		(*itr)->keyboard(key, x, y);
	addKey(Key(key));
}

void ComponentGame::keyboardup(unsigned char key, int x, int y)
{
	for (auto itr = players.begin(); itr != players.end(); ++itr)
		(*itr)->keyboardup(key, x, y);
	deleteKey(Key(key));
}

void ComponentGame::special(int key, int x, int y)
{
	for (auto itr = players.begin(); itr != players.end(); ++itr)
		(*itr)->special(key, x, y);
	addKey(Key(key));
}

void ComponentGame::specialup(int key, int x, int y)
{
	for (auto itr = players.begin(); itr != players.end(); ++itr)
		(*itr)->specialup(key, x, y);
	deleteKey(Key(key));
}

