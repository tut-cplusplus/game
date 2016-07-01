#pragma once
#include "Character.hpp"
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
	/**
	* コンストラクタ
	* @param x		Characterのx座標
	* @param y		Characterのy座標
	* @param width x軸方向の幅
	* @param height y軸方向の幅
	* @param size	テクスチャIDの配列のサイズ
	*/
	Player(double x, double y, double width, double height, int size);
	Player(double x, double y, int size);
	Player(double x, double y);
	~Player();

	void changeColor(void) const;
};

