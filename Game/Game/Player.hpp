#pragma once
#include "Character.hpp"
class Player : public Character {
protected:
	/**
	 * 向いている方へ移動する関数
	 */
	void move(void);

	/**
	 * 壁を壊す関数
	 */
	void breakWall(void);
public:
	Player();
	/**
	* コンストラクタ
	* @param x		Characterのx座標
	* @param y		Characterのy座標
	* @param width x軸方向の幅
	* @param height y軸方向の幅
	* @param size	テクスチャIDの配列のサイズ
	*/
	Player(int x, int y, int width, int height, int size);
	Player(int x, int y, int size);
	Player(int x, int y);
	~Player();

	/**
	* displayに対応する関数
	*/
	void drawDisplay(void);

	/**
	* visibilityに対応する関数
	*
	* @param state [よくわからない]
	*/
	void visibility(int state);

	/**
	* resizeに対応する関数
	*
	* @param w リサイズ後のウィンドウの幅
	* @param h リサイズ後のウィンドウの高さ
	*/
	void resize(int w, int h);

	/**
	* mouseに対応する関数,マウスからの入力を与える
	*
	* @param button 押されたボタンの種類
	* @param state  ボタンの押下状態
	* @param x      ボタンの押下したx座標
	* @param x      ボタンの押下したy座標
	*/
	void inputMouse(int button, int state, int x, int y);

	/**
	* activeMotionに対応する関数,マウスのボタンを押下中の座標を与える
	*
	* @param x ボタン押下中のマウスx座標
	* @param x ボタン押下中のマウスy座標
	*/
	void inputActiveMotion(int x, int y);

	/**
	* passiveMotionに対応する関数
	* マウスのボタンが押下されていない時の座標を与える
	*
	* @param x 呼び出し時のマウスx座標
	* @param x 呼び出し時のマウスy座標
	*/
	void inputPassiveMotion(int x, int y);

	/**
	* keyboardに対応する関数，キーボード押下時の入力を与える
	*
	* @param key 押下されたキーの種類
	* @param x   キーボード押下時のマウスx座標
	* @param x   キーボード押下時のマウスy座標
	*/
	void inputKeyboard(unsigned char key, int x, int y);

	/**
	* keyboardupに対応する関数，キーが離された時の入力を与える
	*
	* @param key 離されたキーの種類
	* @param x   キーが離された時のマウスx座標
	* @param x   キーが離された時のマウスy座標
	*/
	void inputKeyboardUp(unsigned char key, int x, int y);

	/**
	* specialに対応する関数，特殊キー押下時の入力を与える
	*
	* @param key 押下された特殊キーの種類
	* @param x   特殊キー押下時のマウスx座標
	* @param x   特殊キー押下時のマウスy座標
	*/
	void inputSpecialKey(unsigned char key, int x, int y);

	/**
	* specialupに対応する関数，特殊キーが離された時の入力を与える
	*
	* @param key 離された特殊キーの種類
	* @param x   特殊キーが離された時のマウスx座標
	* @param x   特殊キーが離された時のマウスy座標
	*/
	void inputSpecialKeyUp(unsigned char key, int x, int y);

	/**
	* idleに対応する関数
	*/
	void idle(void);
};

