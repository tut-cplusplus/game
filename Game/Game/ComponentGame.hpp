#ifndef ___Class_ComponentGame
#define ___Class_ComponentGame

#include "Component.hpp"
#include "Block.hpp"

class ComponentGame : public Component {
public:
	class CannotAllocateException{};

private:
	static const int MAP_WIDTH;
	static const int MAP_HEIGHT;

private:
	Block*** map;
	double blockWidth;
	double blockHeight;

private:
	void allocMap(void);
	void clearMap(void);
	void generateMap(void);
	void deleteMap(void);
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

