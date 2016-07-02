#ifndef ___Class_Character
#define ___Class_Character

#include "Vector.hpp"
#include "Size.hpp"
#include "Key.hpp"

class Character {
public:
	enum Direction { INVALID, NORTH, SOUTH, EAST, WEST };

private:
	Vector<double> destination;
	Vector<double> source;
	int moveCount;
	double speed;

protected:
	bool isMoving;
	Vector<double> position;
	Size<double> size;
	Direction direction;//キャラクターの向き
	int *texture_id;	//テクスチャIDの配列
	
	/**
	 * 壁を壊す関数
	 */
	virtual void breakWall(void);

public:
	Character();
	Character(const Vector<double>& position, const Size<double>& size);
	Character(const Vector<double>& position);
	virtual ~Character();
	
	/**
	 * 初期化関数
	 */
	virtual void init();
	void startMoving(void);
	void move(void);

	virtual void onHit(void);

	virtual void changeColor(void) const;
	/**
	 * displayに対応する関数
	 */
	virtual void draw(void);
	
	void keyboard(const Key& key);
	/**
	* mouseに対応する関数,マウスからの入力を与える
	* 
	* @param button 押されたボタンの種類
	* @param state  ボタンの押下状態
	* @param x      ボタンの押下したx座標
	* @param x      ボタンの押下したy座標
	*/
	virtual void mouse(int button, int state, int x, int y);

	/**
	 * keyboardに対応する関数，キーボード押下時の入力を与える
	 * 
	 * @param key 押下されたキーの種類
	 * @param x   キーボード押下時のマウスx座標
	 * @param x   キーボード押下時のマウスy座標
	 */
	virtual void keyboard(unsigned char key, int x, int y);

	/**
	 * keyboardupに対応する関数，キーが離された時の入力を与える
	 *
	 * @param key 離されたキーの種類
	 * @param x   キーが離された時のマウスx座標
	 * @param x   キーが離された時のマウスy座標
	 */
	virtual void keyboardup(unsigned char key, int x, int y);
	
	/**
	 * specialに対応する関数，特殊キー押下時の入力を与える
	 *
	 * @param key 押下された特殊キーの種類
	 * @param x   特殊キー押下時のマウスx座標
	 * @param x   特殊キー押下時のマウスy座標
	 */
	virtual void special(int key, int x, int y);
	
	/**
 	 * specialupに対応する関数，特殊キーが離された時の入力を与える
	 *
	 * @param key 離された特殊キーの種類
	 * @param x   特殊キーが離された時のマウスx座標
	 * @param x   特殊キーが離された時のマウスy座標
	 */
	virtual void specialup(int key, int x, int y);

	Vector<double> getPosition(void) const;
	Size<double> getSize(void) const;
	Direction getDirection(void) const;
	void setPosition(const Vector<double>& position);
	void setSize(const Size<double>& size);
};

inline Vector<double> Character::getPosition(void) const
{
	return position;
}

inline Size<double> Character::getSize(void) const
{
	return size;
}

inline Character::Direction Character::getDirection(void) const
{
	return direction;
}

inline void Character::setPosition(const Vector<double>& position)
{
	this->position = position;
}

inline void Character::setSize(const Size<double>& size)
{
	this->size = size;
}

#endif

