#ifndef ___Class_Layout
#define ___Class_Layout

#include <vector>

#include "Component.hpp"

/**
 * Layoutクラス．
 * コンポーネントを保持するだけで，レイアウト管理する機能の無い抽象クラス．
 */
class Layout : public Component {
private:
	std::vector<Component> components;	/* コンポーネント */

protected:
	/**
	 * コンポーネントを登録する．
	 *
	 * @param component コンポーネント
	 */
	void add(const Component& component);

public:
	Layout();
	virtual void init(void);
	/**
	 * 描画する．
	 */
	virtual void draw(void) = 0;
	/**
	 * GLUTのイベント
	 */
	void mouse(int button, int state, int x, int y);
	void keyboard(unsigned char key, int x, int y);
	void keyboardup(unsigned char key, int x, int y);
	void special(int key, int x, int y);
	void specialup(int key, int x, int y);
	/**
	 * コンポーネントの数を取得する．
	 *
	 * @return 登録されているコンポーネントの数
	 */
	int getComponentNum(void) const;
};

inline void Layout::add(const Component& component)
{
	components.push_back(component);
}

Layout::Layout()
{

}

void Layout::init(void)
{

}

inline void Layout::mouse(int button, int state, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(*itr).mouse(button, state, x, y);
}

inline void Layout::keyboard(unsigned char key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(*itr).keyboard(key, x, y);
}

inline void Layout::keyboardup(unsigned char key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(*itr).keyboardup(key, x, y);
}

inline void Layout::special(int key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(*itr).special(key, x, y);
}

inline void Layout::specialup(int key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(*itr).specialup(key, x, y);
}

inline int Layout::getComponentNum(void) const
{
	return components.size();
}

#endif
