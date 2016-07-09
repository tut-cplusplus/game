#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"

class Player : public Character {
private:
	Keypad keypad;	//キーパッド

protected:
	void loadAnimations(void);

	/**
	 * 壁を壊す関数
	 */
	void breakWall(void);
public:
	Player();
	Player(const Vector<double>& position, const Size<double>& size, const Keypad& keypad);
	Player(const Vector<double>& position, const Keypad& keypad);
	~Player();

	/**
	 * upキーが押されたときに呼び出される
	 */
	void onUp(void);
	/**
	 * downキーが押されたときに呼び出される
	 */
	void onDown(void);
	/**
	 * leftキーが押されたときに呼び出される
	 */
	void onLeft(void);
	/**
	 * rightキーが押されたときに呼び出される
	 */
	void onRight(void);
	/**
	 * breakBlockキーが押されたときに呼び出される
	 */
	void onBreakBlock(void);

	void changeColor(void) const;
	void draw(void);
	/**
	 * キーパッドを取得する
	 *
	 * @return キーパッド
	 */
	Keypad getKeypad(void) const;
};

