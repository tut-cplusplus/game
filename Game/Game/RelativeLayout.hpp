#ifndef ___Class_RelativeLayout
#define ___Class_RelativeLayout

#include <GL/glut.h>

#include "Layout.hpp"
#include "Position.hpp"

class RelativeLayout : public Layout {
protected:
	std::vector<Position<double>> positions;

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
	 * @param position 位置
	 */
	void add(Component* component, const Position<double>& position);
};

inline void RelativeLayout::add(Component* component, const Position<double>& position)
{
	components.push_back(component);
	positions.push_back(position);
}

#endif

