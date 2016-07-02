#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"

class Player : public Character {
private:
	Keypad keypad;

protected:
	/**
	 * 向いている方へ移動する関数
	 */
	void move(void);

	/**
	 * 壁を壊す関数
	 */
	void breakWall(void);
public:
	Player();
	Player(double x, double y, const Size<double>& size, const Keypad& keypad);
	/**
	* コンストラクタ
	* @param x		Characterのx座標
	* @param y		Characterのy座標
	*/
	Player(double x, double y, const Keypad& keypad);
	~Player();

	void onUp(void);
	void onDown(void);
	void onLeft(void);
	void onRight(void);
	void onBreakBlock(void);

	void changeColor(void) const;
	Keypad getKeypad(void) const;
};

