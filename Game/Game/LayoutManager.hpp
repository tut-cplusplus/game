#ifndef ___Class_LayoutManager
#define ___Class_LayoutManager

#include "Layout.hpp"

/**
 * レイアウトマネージャ
 * ゲーム画面の管理に使用する．
 */
class LayoutManager {
private:
	static Layout* layout;	/* メインレイアウト */

public:
	/**
	 * メインレイアウトを取得する
	 *
	 * @return メインレイアウト
	 */
	static Layout* getLayout(void);
	/**
	 * メインレイアウトを登録する
	 *
	 * @param _layout レイアウト
	 */
	static void registerLayout(Layout* _layout);
	/**
	 * GLUTのイベントに対応する関数
	 */
	static void draw(void);
	static void mouse(int button, int state, int x, int y);
	static void keyboard(unsigned char key, int x, int y);
	static void keyboardup(unsigned char key, int x, int y);
	static void special(int key, int x, int y);
	static void specialup(int key, int x, int y);
};

#endif

