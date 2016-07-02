#ifndef ___Class_ComponentGame
#define ___Class_ComponentGame

#include <vector>
#include <random>
#include <list>

#include "Component.hpp"
#include "Block.hpp"
#include "Vector.hpp"
#include "Player.hpp"
#include "NormalEnemy.hpp"
#include "Size.hpp"

#include "GL/glut.h"

class ComponentGame : public Component {
public:
	class CannotAllocateException{};

private:
	static const int MAP_WIDTH;
	static const int MAP_HEIGHT;

private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_real_distribution<double> rnd;

	Block*** map;
	std::vector<Player*> players;
	std::vector<Enemy*> enemies;
	Size<double> blockSize;
	std::list<Key> keys;

private:
	void allocMap(void);
	void clearMap(void);
	void generateMap(void);
	std::vector<int> getValidDirections(const Vector<int>& v);
	void deleteMap(void);
	void addPlayer(void);
	void deletePlayers(void);
	void addEnemy(void);
	void deleteEnemies(void);
	template <typename T>
	void drawCharacters(const std::vector<T*> characters) const;
	std::vector<Vector<int>> getTransparentBlockVectors(void) const;
	void setBlockSize(void);
	std::list<Key>::iterator searchKey(const Key& key);
	void addKey(const Key& key);
	void deleteKey(const Key& key);
	void keyEvent(void);

public:
	ComponentGame();
	ComponentGame(int width, int height);
	~ComponentGame();

	void setWidth(int width);
	void setHeight(int height);

	virtual void init(void);
	virtual void draw(void);
	virtual void mouse(int button, int state, int x, int y);
	virtual void keyboard(unsigned char key, int x, int y);
	virtual void keyboardup(unsigned char key, int x, int y);
	virtual void special(int key, int x, int y);
	virtual void specialup(int key, int x, int y);
};

template <typename T>
inline void ComponentGame::drawCharacters(const std::vector<T*> characters) const
{
	double blockWidth = blockSize.getWidth();
	double blockHeight = blockSize.getHeight();
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		glPushMatrix();
		T& character = **itr;
		double x = character.getX();
		double y = character.getY();
		glTranslated(x * blockWidth, y * blockHeight, 0.0);
		character.draw();
		glPopMatrix();
	}
}

#endif

