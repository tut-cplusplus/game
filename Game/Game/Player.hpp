#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"

class Player : public Character {
private:
	Keypad keypad;

protected:
	/**
	 * 壁を壊す関数
	 */
	void breakWall(void);
public:
	Player();
	Player(const Vector<double>& position, const Size<double>& size, const Keypad& keypad);
	Player(const Vector<double>& position, const Keypad& keypad);
	~Player();

	void onUp(void);
	void onDown(void);
	void onLeft(void);
	void onRight(void);
	void onBreakBlock(void);

	void changeColor(void) const;
	Keypad getKeypad(void) const;
};

