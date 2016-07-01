#pragma once

#include "Character.hpp"
#include "Size.hpp"

class Player : public Character {
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
	Player(double x, double y, const Size<double>& size);
	/**
	* コンストラクタ
	* @param x		Characterのx座標
	* @param y		Characterのy座標
	*/
	Player(double x, double y);
	~Player();

	void changeColor(void) const;
};

