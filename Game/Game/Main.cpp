#include <GL/glut.h>
#include <iostream>

using namespace std;

/**
 * glutDisplayFuncに登録する関数
 */
void display(void);

/**
 * glutVisibilityFuncに登録する関数
 * @param state [よくわかんない]
 */
void visibility(int state);

/**
 * glutReshapeFuncに登録する関数
 * @param w リサイズ後のウィンドウの幅
 * @param h リサイズ後のウィンドウの高さ
 */
void resize(int w, int h);

/**
 * glutMouseFuncに登録する関数
 * @param button 押されたボタンの種類
 * @param state  ボタンの押下状態
 * @param x      ボタンの押下したx座標
 * @param y      ボタンの押下したy座標
 */
void mouse(int button, int state, int x, int y);

/**
 * glutMotionFuncに登録する関数
 *
 * マウスのボタンが押下されている時に呼び出される
 *
 * @param x マウスの現在位置のx座標
 * @param y マウスの現在位置のy座標
 */
void activeMotion(int x, int y);

/**
 * glutPassiveMotion
 *
 * マウスのボタンが押下されてない時に呼び出される
 *
 * @param x マウスの現在位置のx座標
 * @param y マウスの現在位置のy座標
 */
void passiveMotion(int x, int y);

/**
 * glutKeyboradFuncに登録する関数
 * @param key 押下されたキーの種類
 * @param x   キーが押下された時のマウスのx座標
 * @param y   キーが押下された時のマウスのy座標
 */
void keyboard(unsigned char key, int x, int y);

/**
 * glutKeyboardupFuncに登録する関数
 * @param key 離されたキーの種類
 * @param x   キーが離された時のマウスのx座標
 * @param y   キーが離された時のマウスのy座標
 */
void keyboardup(unsigned char key, int x, int y);

/**
 * glutSpecialFuncに登録する関数
 * @param key 押下された特殊キーの種類
 * @param x   特殊キーが押下された時のマウスのx座標
 * @param y   特殊キーが押下された時のマウスのy座標
 */
void special(int key, int x, int y);

/**
 * glutSpecialupFuncに登録する関数
 * @param key 押下された特殊キーの種類
 * @param x   特殊キーが離された時のマウスのx座標
 * @param y   特殊キーが離された時のマウスのy座標
 */
void specialup(int key, int x, int y);

/**
 * glutIdleFuncに登録する関数
 *
 * 処理に余裕があるときに呼び出される
 */
void idle(void);


/**
 * main関数
 * @param  argc プログラム実行時に受け取った引数の個数
 * @param  argv プログラム実行に受け取った引数の一覧
 * @return      終了状態
 */
int main(int argc, char** argv)
{
	//glutの初期化
	glutInit(&argc, argv);

	//ウィンドウの作成
	glutCreateWindow(argv[0]);

	//CALLBACK登録
	glutDisplayFunc(display);
	glutVisibilityFunc(visibility);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutMotionFunc(activeMotion);
	glutPassiveMotionFunc(passiveMotion);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutSpecialFunc(special);
	glutSpecialUpFunc(specialup);
	glutIdleFunc(idle);

	//glutメインループ開始
	glutMainLoop();

	return 0;
}


void display(void)
{
	cout << "display" << endl;
	return ;
}


void visibility(int state)
{
	cout << "visibility" << endl;
	return ;
}


void resize(int w, int h)
{
	cout << "resize" << endl;
	return ;
}


void mouse(int button, int state, int x, int y)
{
	cout << "mouse" << endl;
	return ;
}


void activeMotion(int x, int y)
{
	cout << "activeMotion" << endl;
	return ;
}


void passiveMotion(int x, int y)
{
	cout << "passiveMotion" << endl;
	return ;
}


void keyboard(unsigned char key, int x, int y)
{
	cout << "keyboard" << endl;
	return ;
}


void keyboardup(unsigned char key, int x, int y)
{
	cout << "keyboard-up" << endl;
	return ;
}


void special(int key, int x, int y)
{
	cout << "special" << endl;
	return ;
}


void specialup(int key, int x, int y)
{
	cout << "special-up" << endl;
	return ;
}


void idle(void)
{
	//cout << "idle" << endl;
	return ;
}
