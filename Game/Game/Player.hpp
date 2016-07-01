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
	Player(int x, int y, int width, int height, int size);
	Player(int x, int y, int size);
	Player(int x, int y);
	~Player();

	/**
	 * displayに対応する関数
	 */
	void draw(void);
};

