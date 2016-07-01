#ifndef ___Class_ComponentGame
#define ___Class_ComponentGame

#include <vector>
#include <random>

#include "Component.hpp"
#include "Block.hpp"
#include "Position.hpp"
#include "Player.hpp"

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
	double blockWidth;
	double blockHeight;

private:
	void allocMap(void);
	void clearMap(void);
	void generateMap(void);
	std::vector<int> getValidDirections(const Position<int>& position);
	void deleteMap(void);
	void addPlayer(void);
	void deletePlayers(void);
	std::vector<Position<int>> getTransparentBlockPositions(void) const;
	void setBlockSize(void);

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

#endif

