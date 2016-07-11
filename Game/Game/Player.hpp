#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"

class Player : public Character {
private:
	Keypad keypad;	//キーパッド
	bool isPlacing;	//ブロックを設置中かどうか
	bool lastUp;	//前フレームでキーが押されていたか
	bool lastDown;
	bool lastLeft;
	bool lastRight;
	bool lastBreakBlock;
	bool lastPlaceBlock;

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
	 * placeBlockキーが押されたときに呼び出される
	 */
	void onPlaceBlock(void);
	/**
	 * キーが押されたときに呼び出される．ただし，1度キーを離すまでは再度呼び出されない
	 */
	void onUpDown(void);
	void onDownDown(void);
	void onLeftDown(void);
	void onRightDown(void);
	void onBreakBlockDown(void);
	void onPlaceBlockDown(void);
	/**
	 * キーが離されたときに呼び出される．ただし，1度キーを押すまでは再度呼び出されない
	 */
	void onUpUp(void);
	void onDownUp(void);
	void onLeftUp(void);
	void onRightUp(void);
	void onBreakBlockUp(void);
	void onPlaceBlockUp(void);

	void changeColor(void) const;
	void draw(void);
	/**
	 * キーパッドを取得する
	 *
	 * @return キーパッド
	 */
	Keypad getKeypad(void) const;
	bool getIsPlacing(void) const;
	bool getLastUp(void) const;
	bool getLastDown(void) const;
	bool getLastLeft(void) const;
	bool getLastRight(void) const;
	bool getLastBreakBlock(void) const;
	bool getLastPlaceBlock(void) const;
	void setLastUp(bool lastUp);
	void setLastDown(bool lastDown);
	void setLastLeft(bool lastLeft);
	void setLastRight(bool lastRight);
	void setLastBreakBlock(bool lastBreakBlock);
	void setLastPlaceBlock(bool lastPlaceBlock);
	void setIsPlacing(bool isPlacing);

};

inline bool Player::getIsPlacing(void) const
{
	return isPlacing;
}

inline bool Player::getLastUp(void) const
{
	return lastUp;
}

inline bool Player::getLastDown(void) const
{
	return lastDown;
}

inline bool Player::getLastLeft(void) const
{
	return lastLeft;
}

inline bool Player::getLastRight(void) const
{
	return lastRight;
}

inline bool Player::getLastBreakBlock(void) const
{
	return lastBreakBlock;
}

inline bool Player::getLastPlaceBlock(void) const
{
	return lastPlaceBlock;
}

inline void Player::setIsPlacing(bool isPlacing)
{
	this->isPlacing = isPlacing;
}

inline void Player::setLastUp(bool lastUp)
{
	this->lastUp = lastUp;
}

inline void Player::setLastDown(bool lastDown)
{
	this->lastDown = lastDown;
}

inline void Player::setLastLeft(bool lastLeft)
{
	this->lastLeft = lastLeft;
}

inline void Player::setLastRight(bool lastRight)
{
	this->lastRight = lastRight;
}

inline void Player::setLastBreakBlock(bool lastBreakBlock)
{
	this->lastBreakBlock = lastBreakBlock;
}

inline void Player::setLastPlaceBlock(bool lastPlaceBlock)
{
	this->lastPlaceBlock = lastPlaceBlock;
}

