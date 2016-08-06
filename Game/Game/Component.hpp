#ifndef _COMPONENT
#define _COMPONENT

#include "Rectangle.hpp"

class Component : public Utility::Rectangle {
public:
	Component(const Size<double>& size = Size<double>(0.0, 0.0));
	virtual ~Component();

	/**
	 * アクセッサ
	 */
	const Size<double>& getSize(void) const;

	/**
	 * コンストラクタに共通する処理を書く
	 */
	virtual void init(void);
	/**
	 * 描画関数
	 */
	virtual void draw(void);
	/**
	 * GLUTのイベントプロシージャ
	 */
	virtual void mouse(int button, int state, int x, int y);
	virtual void keyboard(unsigned char key, int x, int y);
	virtual void keyboardOnce(unsigned char key, int x, int y);
	virtual void keyboardup(unsigned char key, int x, int y);
	virtual void keyboardupOnce(unsigned char key, int x, int y);
	virtual void special(int key, int x, int y);
	virtual void specialOnce(int key, int x, int y);
	virtual void specialup(int key, int x, int y);
	virtual void specialupOnce(int key, int x, int y);
};

inline const Size<double>& Component::getSize(void) const
{
	return size;
}

#endif
