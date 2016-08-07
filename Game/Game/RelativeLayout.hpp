#ifndef ___Class_RelativeLayout
#define ___Class_RelativeLayout

#include "Layout.hpp"
#include "Vector.hpp"

#include "GL/glut.h"

class RelativeLayout : public Layout {
protected:
	std::vector<Vector<double>> vs;

public:
	RelativeLayout(const Size<double>& size = Size<double>(0.0, 0.0));
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
	 * @param isFill コンポーネントを最大化するか
	 */
	void add(Component* component, const Vector<double>& v = Vector<double>(0.0, 0.0), bool isFill = false);
};

inline void RelativeLayout::add(Component* component, const Vector<double>& v, bool isFill)
{
	components.push_back(component);
	vs.push_back(v);
	if (!isFill)
		return;
	double width = size.getWidth() - v.getX();
	double height = size.getHeight() - v.getY();
	component->setSize(Size<double>(width, height));
}

#endif

