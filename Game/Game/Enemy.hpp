#ifndef __Class_Enemy
#define __Class_Enemy
#include "Character.hpp"
class Enemy : public Character {
protected:
	int player_x;	//プレイヤーの座標
	int player_y;	//プレイヤーの座標

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
	Enemy(int x, int y, int width, int height, int size);
	Enemy(int x, int y, int size);
	Enemy(int x, int y);
	~Enemy();

	/**
	* displayに対応する関数
	*/
	virtual void drawDisplay(void);

	/**
	* visibilityに対応する関数
	*
	* @param state [よくわからない]
	*/
	virtual void visibility(int state);

	/**
	* resizeに対応する関数
	*
	* @param w リサイズ後のウィンドウの幅
	* @param h リサイズ後のウィンドウの高さ
	*/
	virtual void resize(int w, int h);

	/**
	* mouseに対応する関数,マウスからの入力を与える
	*
	* @param button 押されたボタンの種類
	* @param state  ボタンの押下状態
	* @param x      ボタンの押下したx座標
	* @param x      ボタンの押下したy座標
	*/
	virtual void inputMouse(int button, int state, int x, int y);

	/**
	* activeMotionに対応する関数,マウスのボタンを押下中の座標を与える
	*
	* @param x ボタン押下中のマウスx座標
	* @param x ボタン押下中のマウスy座標
	*/
	virtual void inputActiveMotion(int x, int y);

	/**
	* passiveMotionに対応する関数
	* マウスのボタンが押下されていない時の座標を与える
	*
	* @param x 呼び出し時のマウスx座標
	* @param x 呼び出し時のマウスy座標
	*/
	virtual void inputPassiveMotion(int x, int y);

	/**
	* keyboardに対応する関数，キーボード押下時の入力を与える
	*
	* @param key 押下されたキーの種類
	* @param x   キーボード押下時のマウスx座標
	* @param x   キーボード押下時のマウスy座標
	*/
	virtual void inputKeyboard(unsigned char key, int x, int y);

	/**
	* keyboardupに対応する関数，キーが離された時の入力を与える
	*
	* @param key 離されたキーの種類
	* @param x   キーが離された時のマウスx座標
	* @param x   キーが離された時のマウスy座標
	*/
	virtual void inputKeyboardUp(unsigned char key, int x, int y);

	/**
	* specialに対応する関数，特殊キー押下時の入力を与える
	*
	* @param key 押下された特殊キーの種類
	* @param x   特殊キー押下時のマウスx座標
	* @param x   特殊キー押下時のマウスy座標
	*/
	virtual void inputSpecialKey(unsigned char key, int x, int y);

	/**
	* specialupに対応する関数，特殊キーが離された時の入力を与える
	*
	* @param key 離された特殊キーの種類
	* @param x   特殊キーが離された時のマウスx座標
	* @param x   特殊キーが離された時のマウスy座標
	*/
	virtual void inputSpecialKeyUp(unsigned char key, int x, int y);

	/**
	* idleに対応する関数
	*/
	virtual void idle(void);
};

#endif
