#ifndef ___Class_Character
#define ___Class_Character

#include <vector>

#include "Vector.hpp"
#include "Size.hpp"
#include "Key.hpp"
#include "Rectangle.hpp"
#include "Animation.hpp"

class Character : public Rectangle {
public:
	enum Direction { INVALID, NORTH, SOUTH, EAST, WEST };	//向き

private:
	Vector<double> destination;	//移動後の座標
	Vector<double> source;		//移動前の座標
	int moveCount;				//移動における何フレーム目か
	double speed;				//移動速度

protected:
	bool isMoving;				//移動中かどうか
	bool isBreaking;			//ブロックを破壊中かどうか
	Vector<double> position;	//現在位置
	Direction direction;		//キャラクターの向き
	std::vector<Animation> animations;	//アニメーションのベクタ
	Animation animation;		//現在再生中のアニメーション

	/**
	 * 初期化関数
	 */
	virtual void init();
	/**
	 * アニメーションのロード
	 */
	virtual void loadAnimations(void);
	/**
	 * 壁を壊す関数
	 * この関数は壁を壊す要求をするだけであり，実際の破壊処理はComponentGameで行う
	 */
	virtual void startBreaking(void);

public:
	Character();
	Character(const Vector<double>& position, const Size<double>& size);
	Character(const Vector<double>& position);
	virtual ~Character();
	
	/**
	 * 移動を開始する
	 */
	void startMoving(void);
	/**
	 * 移動する
	 * 毎フレーム呼び出される
	 */
	void move(void);
	/**
	 * 一マス分の移動が終了したときに呼び出される
	 */
	virtual void onStop(void);
	/**
	 * 壁に当たったときに呼び出される
	 */
	virtual void onHit(void);
	/**
	 * 色を変更する
	 * テクスチャの実装後に削除する
	 */
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

	/**
	 * ゲッタ及びセッタ
	 */
	Vector<double> getPosition(void) const;
	Vector<double> getSource(void) const;
	Direction getDirection(void) const;
	Vector<double> getDirectionVector(void) const;
	/**
	 * directionを角度として返す
	 *
	 * @return x軸の正の向きを0度とした反時計回りの角度(-90~180)
	 */
	double getAngle(void) const;
	void setPosition(const Vector<double>& position);
	void setSize(const Size<double>& size);
	bool getIsMoving(void) const;
	bool getIsBreaking(void) const;
	void setIsBreaking(bool isBreaking);
};

inline Vector<double> Character::getPosition(void) const
{
	return position;
}

inline Vector<double> Character::getSource(void) const
{
	return source;
}

inline Character::Direction Character::getDirection(void) const
{
	return direction;
}

inline double Character::getAngle(void) const
{
	static double angles[] = {
		0.0,
		90.0,
		-90.0,
		0.0,
		180.0,
	};
	return angles[direction];
}

inline void Character::setPosition(const Vector<double>& position)
{
	this->position = position;
}

inline bool Character::getIsMoving(void) const
{
	return isMoving;
}

inline bool Character::getIsBreaking(void) const
{
	return isBreaking;
}

inline void Character::setIsBreaking(bool isBreaking)
{
	this->isBreaking = isBreaking;
}

#endif

