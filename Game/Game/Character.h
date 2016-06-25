enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3 };
class Character {
private:
	int texture_id[20];
	int x;					//x座標
	int y;					//y座標
	Direction direction;	//キャラクターの向き
	
	void face(Direction d);
	void breakWall(void);
public:
	Character(int x, int y);
	~Character();

	/**
	 * displayに対応する関数
	 */
	virtual void drawDisplay(void) = 0;
	
	/**
	 * visibilityに対応する関数
	 *
	 * @param state [よくわからない]
	 */
	virtual void visibility(int state) = 0;
	
	/**
	 * resizeに対応する関数
	 * 
	 * @param w リサイズ後のウィンドウの幅
	 * @param h リサイズ後のウィンドウの高さ
	 */
	virtual void resize(int w, int h) = 0;
	
	/**
	* mouseに対応する関数,マウスからの入力を与える
	* 
	* @param button 押されたボタンの種類
	* @param state  ボタンの押下状態
	* @param x      ボタンの押下したx座標
	* @param x      ボタンの押下したy座標
	*/
	virtual void inputMouse(int button, int state, int x, int y) = 0;

	/**
	 * activeMotionに対応する関数,マウスのボタンを押下中の座標を与える
	 * 
	 * @param x ボタン押下中のマウスx座標
	 * @param x ボタン押下中のマウスy座標
	 */
	virtual void inputActiveMotion(int x, int y) = 0;
	
	/**
	 * passiveMotionに対応する関数
	 * マウスのボタンが押下されていない時の座標を与える
	 * 
	 * @param x 呼び出し時のマウスx座標
	 * @param x 呼び出し時のマウスy座標
	 */
	virtual void inputPassiveMotion(int x, int y) = 0;
	
	/**
	 * keyboardに対応する関数，キーボード押下時の入力を与える
	 * 
	 * @param key 押下されたキーの種類
	 * @param x   キーボード押下時のマウスx座標
	 * @param x   キーボード押下時のマウスy座標
	 */
	virtual void inputKeyboard(unsigned char key, int x, int y) = 0;

	/**
	 * keyboardupに対応する関数，キーが離された時の入力を与える
	 *
	 * @param key 離されたキーの種類
	 * @param x   キーが離された時のマウスx座標
	 * @param x   キーが離された時のマウスy座標
	 */
	virtual void inputKeyboardUp(unsigned char key, int x, int y) = 0;
	
	/**
	 * specialに対応する関数，特殊キー押下時の入力を与える
	 *
	 * @param key 押下された特殊キーの種類
	 * @param x   特殊キー押下時のマウスx座標
	 * @param x   特殊キー押下時のマウスy座標
	 */
	virtual void inputSpecialKey(unsigned char key, int x, int y) = 0;
	
	/**
 	 * specialupに対応する関数，特殊キーが離された時の入力を与える
	 *
	 * @param key 離された特殊キーの種類
	 * @param x   特殊キーが離された時のマウスx座標
	 * @param x   特殊キーが離された時のマウスy座標
	 */
	virtual void inputSpecialKeyUp(unsigned char key, int x, int y) = 0;
	
	/**
	 * idleに対応する関数
	 */
	virtual void idle(void) = 0;
};
