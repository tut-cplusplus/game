#ifndef ___Class_RelativeLayout
#define ___Class_RelativeLayout

#include "Layout.hpp"
#include "Vector.hpp"

#include "GL/glut.h"

class RelativeLayout : public Layout {
protected:
	std::vector<Vector<double>> vs;

public:
	RelativeLayout(int width, int height);
	virtual void init(void);
	/**
	 * 描画する．
	 */
	virtual void draw(void);
	/**
	 * コンポーネントを登録する．
	 *
	 * @param component コンポーネント
	 * @param v 位置
	 */
	void add(Component* component, const Vector<double>& v);
};

inline void RelativeLayout::add(Component* component, const Vector<double>& v)
{
	components.push_back(component);
	vs.push_back(v);
}

#endif

