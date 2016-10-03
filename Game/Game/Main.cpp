#include <iostream>

#include "Global.hpp"
#include "LayoutManager.hpp"
#include "RelativeLayout.hpp"
#include "VerticalSplitLayout.hpp"
#include "HorizontalSplitLayout.hpp"
#include "TextureManager.hpp"
#include "ComponentFPS.hpp"
#include "ComponentGame.hpp"
#include "FPSManager.hpp"
#include "FontManager.hpp"
#include "AudioManager.hpp"
#include "ComponentTitle.hpp"

#include <AL/alut.h>
#include <GL/glut.h>

using namespace std;

/**
 * ゲーム独自の初期化処理を行う関数
 */
void init(void);

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
	//alutの初期化
	alutInit(&argc, argv);

	glutInitWindowSize(Global::WINDOW_WIDTH, Global::WINDOW_HEIGHT);
	//glutの初期化
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	//ウィンドウの作成
	glutCreateWindow(argv[0]);
	glutSetWindowTitle("Block Hacking");

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
	//独自の初期化処理
	init();

	//glutメインループ開始
	glutMainLoop();

	return 0;
}


void init(void)
{
	TextureManager::init();
	AudioManager::init();
	FontManager::init();
	RelativeLayout* layout = new RelativeLayout(Size<double>(Global::WORLD_WIDTH, Global::WORLD_HEIGHT));
	layout->add(new ComponentTitle(Size<double>(0, 0)), Vector<double>(0.0, 0.0), true);
	LayoutManager::registerLayout(layout);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//キーを押したときと離されたときにのみイベントが呼ばれるようにする
	glutIgnoreKeyRepeat(GL_TRUE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	cout << "D key : toggle debug mode" << endl;
}


void display(void)
{
	FPSManager::startMeasure();
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	LayoutManager::draw();
	glutSwapBuffers();
	FPSManager::stopMeasure();
	FPSManager::update();
	FPSManager::sleep();
}


void visibility(int state)
{
	return ;
}


void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, Global::WORLD_WIDTH, 0.0, Global::WORLD_HEIGHT, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}


void mouse(int button, int state, int x, int y)
{
	LayoutManager::mouse(button, state, x, y);
	return ;
}


void activeMotion(int x, int y)
{
	return ;
}


void passiveMotion(int x, int y)
{
	return ;
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
	case '\033':
		alutExit();
		exit(0);
	case 'D':
		Global::DEBUG_MODE = !Global::DEBUG_MODE;
		break;
	}
	LayoutManager::keyboard(key, x, y);
}


void keyboardup(unsigned char key, int x, int y)
{
	LayoutManager::keyboardup(key, x, y);
	return ;
}


void special(int key, int x, int y)
{
	LayoutManager::special(key, x, y);
	return ;
}


void specialup(int key, int x, int y)
{
	LayoutManager::specialup(key, x, y);
	return ;
}


void idle(void)
{
	glutPostRedisplay();
}
