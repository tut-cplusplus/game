#ifndef __Class_Enemy
#define __Class_Enemy
#include "Character.hpp"
class Enemy : public Character {
protected:
	double player_x;	//プレイヤーの座標
	double player_y;	//プレイヤーの座標

	/**
	 * 向いている方へ移動する関数
	 */
	void move(void);

	/**
	 * 壁を壊す関数
	 */
	void breakWall(void);

	/**
	 * 情報伝達を行う関数
	 */
	virtual void message(void);

public:
	
	Enemy();

	/**
	 * コンストラクタ
	 * @param x		Characterのx座標
	 * @param y		Characterのy座標
	 * @param width x軸方向の幅
	 * @param height y軸方向の幅
	 * @param size	テクスチャIDの配列のサイズ
	 */
	Enemy(double x, double y, double width, double height, int size);
	Enemy(double x, double y, int size);
	Enemy(double x, double y);
	~Enemy();

	/**
	 * displayに対応する関数
	 */
	virtual void draw(void) = 0;
};

#endif
