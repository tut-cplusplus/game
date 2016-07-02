#ifndef __Class_Enemy
#define __Class_Enemy

#include "Character.hpp"
#include "Size.hpp"

class Enemy : public Character {
protected:
	double player_x;	//プレイヤーの座標
	double player_y;	//プレイヤーの座標

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

	Enemy(const Vector<double>& position, const Size<double>& size);
	Enemy(const Vector<double>& position);
	virtual ~Enemy();

	void changeColor(void) const;
};

#endif
