enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3 };
class Character {
protected:
	int x;				//x座標
	int y;				//y座標
	int width;
	int height;
	Direction direction;//キャラクターの向き
	int *texture_id;	//テクスチャIDの配列
	
	/**
	 * キャラクターの向きを指定する関数
	 * @param d 向く方向
	 */
	void face(Direction d);

	/**
	 * 向いている方へ1歩移動する関数
	 */
	virtual void move(void);

	/**
	 * 壁を壊す関数
	 */
	virtual void breakWall(void);

public:
	Character() {}
	Character(int x, int y, int width, int height, int size);
	/**
	 * コンストラクタ
	 * @param x		Characterのx座標
	 * @param y		Characterのy座標
	 * @param size	テクスチャIDの配列のサイズ
	 */
	Character(int x, int y, int size);
	Character(int x, int y);
	~Character();
	
	/**
	 * 初期化関数
	 */
	virtual void init();

	/**
	 * displayに対応する関数
	 */
	virtual void draw(void) = 0;
	
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
};
