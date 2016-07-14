#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"

class Player : public Character {
private:
	Keypad keypad;	//キーパッド
	bool isChangingDirection;	//向きを変更中かどうか
	bool isPlacing;	//ブロックを設置中かどうか

protected:
	void init(void);
	void loadAnimations(void);

	void startPlacing(void);
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
	/**
	 * placeWallキーが押されたときに呼び出される
	 */
	void onPlaceWall(void);
	/**
	 * キーが押されたときに呼び出される．ただし，1度キーを離すまでは再度呼び出されない
	 */
	void onUpDown(void);
	void onDownDown(void);
	void onLeftDown(void);
	void onRightDown(void);
	void onBreakBlockDown(void);
	void onPlaceWallDown(void);
	/**
	 * キーが離されたときに呼び出される．ただし，1度キーを押すまでは再度呼び出されない
	 */
	void onUpUp(void);
	void onDownUp(void);
	void onLeftUp(void);
	void onRightUp(void);
	void onBreakBlockUp(void);
	void onPlaceWallUp(void);

	void changeColor(void) const;
	void draw(void);
	/**
	 * キーパッドを取得する
	 *
	 * @return キーパッド
	 */
	Keypad getKeypad(void) const;
	bool getIsPlacing(void) const;
	void setIsPlacing(bool isPlacing);

};

inline bool Player::getIsPlacing(void) const
{
	return isPlacing;
}

inline void Player::setIsPlacing(bool isPlacing)
{
	this->isPlacing = isPlacing;
}

