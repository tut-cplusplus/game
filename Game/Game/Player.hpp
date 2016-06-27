#pragma once
#include "Character.hpp"
class Player : public Character {
private:
	void move(void);
	void breakWall(void);
public:
	Player();
	~Player();

	void init(int x, int y, int size);
	void drawDisplay(void);
	void visibility(int state);
	void resize(int w, int h);
	void inputMouse(int button, int state, int x, int y);
	void inputActiveMotion(int x, int y);
	void inputPassiveMotion(int x, int y);
	void inputKeyboard(unsigned char key, int x, int y);
	void inputKeyboardUp(unsigned char key, int x, int y);
	void inputSpecialKey(unsigned char key, int x, int y);
	void inputSpecialKeyUp(unsigned char key, int x, int y);
	void idle(void);
};

