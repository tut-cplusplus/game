#ifndef ___Class_SplitLayout
#define ___Class_SplitLayout

#include "Component.hpp"
#include "Layout.hpp"

/**
 * 分割レイアウトクラス
 * 抽象クラス
 */
class SplitLayout : public Layout {
protected:
	double pow;	/* 分割率 */
	Component* component1;
	Component* component2;

private:
	void deleteComponent(Component** component);

public:
	SplitLayout(int width, int height, double pow);
	~SplitLayout();
	virtual void init(void);
	virtual void draw(void) = 0;
	/**
	 * セッタ
	 */
	virtual void setComponent1(Component* component);
	virtual void setComponent2(Component* component);
	/**
	 * GLUTのイベント
	 */
	void mouse(int button, int state, int x, int y);
	void keyboard(unsigned char key, int x, int y);
	void keyboardOnce(unsigned char key, int x, int y);
	void keyboardup(unsigned char key, int x, int y);
	void keyboardupOnce(unsigned char key, int x, int y);
	void special(int key, int x, int y);
	void specialOnce(int key, int x, int y);
	void specialup(int key, int x, int y);
	void specialupOnce(int key, int x, int y);
	/**
	 * キーイベントをすべてのコンポーネントに送る
	 */
	template <typename T>
	void keyEvent(T key, int x, int y, void (Component::*func)(T, int, int));
};

template <typename T>
void SplitLayout::keyEvent(T key, int x, int y, void (Component::*func)(T, int, int))
{
	if (component1 != nullptr)
		(component1->*func)(key, x, y);
	if (component2 != nullptr)
		(component2->*func)(key, x, y);
}

#endif

