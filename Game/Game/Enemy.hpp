#ifndef __Class_Enemy
#define __Class_Enemy

#include "Character.hpp"
#include "Size.hpp"

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

	Enemy(double x, double y, const Size<double>& size);
	/**
	 * コンストラクタ
	 * @param x		Characterのx座標
	 * @param y		Characterのy座標
	 */
	Enemy(double x, double y);
	virtual ~Enemy();

	void changeColor(void) const;
};

#endif
