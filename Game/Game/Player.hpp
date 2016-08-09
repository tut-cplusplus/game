#pragma once

#include "Character.hpp"
#include "Size.hpp"
#include "Keypad.hpp"
#include "Audio.hpp"
#include "ItemStack.hpp"

class Player : public Character {
private:
	int stamina;
	int maxStamina;
	int staminaCount;
	Keypad keypad;	//キーパッド
	bool isChangingDirection;	//向きを変更中かどうか
	int changeDirectionCount;	//向きを変更中のフレーム数
	bool isPlacing;	//ブロックを設置中かどうか
	ItemStack itemStacks[ItemStack::MAX_BLOCK_TYPE];
	ItemStack::Type placingBlockType;	//設置中のブロックの種類

protected:
	void init(void);
	void loadAnimations(void);

	void startPlacing(ItemStack::Type blockType);

public:
	Player(const Vector<double>& position = Vector<double>(0.0, 0.0), const Size<double>& size = Size<double>(0.0, 0.0), double speed = 1.0, int maxStamina = 1, const Keypad& keypad = Keypad());
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

	void move(void);
	void onHit(void);
	void onBlockBroken(void);
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
	const Keypad& getKeypad(void) const;
	bool getIsPlacing(void) const;
	void setIsPlacing(bool isPlacing);
	ItemStack& getItemStack(ItemStack::Type type);
	ItemStack::Type getPlacingBlockType(void) const;
	void useStamina(void);
};

inline bool Player::getIsPlacing(void) const
{
	return isPlacing;
}

inline void Player::setIsPlacing(bool isPlacing)
{
	this->isPlacing = isPlacing;
}

inline ItemStack& Player::getItemStack(ItemStack::Type type)
{
	return itemStacks[type];
}

inline ItemStack::Type Player::getPlacingBlockType(void) const
{
	return placingBlockType;
}

inline void Player::useStamina(void)
{
	stamina--;
}

