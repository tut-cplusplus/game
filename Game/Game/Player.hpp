#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"

class Player : public Character {
public:
	enum BlockType {WALL, TRAP, DECOY};	//ブロックの種類

private:
	Keypad keypad;	//キーパッド
	bool isChangingDirection;	//向きを変更中かどうか
	int changeDirectionCount;	//向きを変更中のフレーム数
	bool isPlacing;	//ブロックを設置中かどうか
	BlockType placingBlockType;	//設置中のブロックの種類

protected:
	void init(void);
	void loadAnimations(void);

	void startPlacing(BlockType blockType);

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
	 * placeTrapキーが押されたときに呼び出される
	 */
	void onPlaceTrap(void);
	/**
	 * placeDecoyキーが押されたときに呼び出される
	 */
	void onPlaceDecoy(void);
	/**
	 * キーが押されたときに呼び出される．ただし，1度キーを離すまでは再度呼び出されない
	 */
	void onUpDown(void);
	void onDownDown(void);
	void onLeftDown(void);
	void onRightDown(void);
	void onBreakBlockDown(void);
	void onPlaceWallDown(void);
	void onPlaceTrapDown(void);
	void onPlaceDecoyDown(void);
	/**
	 * キーが離されたときに呼び出される．ただし，1度キーを押すまでは再度呼び出されない
	 */
	void onUpUp(void);
	void onDownUp(void);
	void onLeftUp(void);
	void onRightUp(void);
	void onBreakBlockUp(void);
	void onPlaceWallUp(void);
	void onPlaceTrapUp(void);
	void onPlaceDecoyUp(void);

	void changeColor(void) const;
	/**
	 * 向きの変更を試みる
	 * 移動中であれば何もしない
	 *
	 * @param direction 方向
	 */
	void try2changeDirection(Direction direction);
	/**
	 * 移動を試みる
	 * 移動中や向きの変更直後は何もしない
	 *
	 * @param direction 方向
	 */
	void try2startMoving(Direction direction);
	/**
	 * キーパッドを取得する
	 *
	 * @return キーパッド
	 */
	Keypad getKeypad(void) const;
	bool getIsPlacing(void) const;
	void setIsPlacing(bool isPlacing);
	BlockType getPlacingBlockType(void) const;

};

inline bool Player::getIsPlacing(void) const
{
	return isPlacing;
}

inline void Player::setIsPlacing(bool isPlacing)
{
	this->isPlacing = isPlacing;
}

inline Player::BlockType Player::getPlacingBlockType(void) const
{
	return placingBlockType;
}

