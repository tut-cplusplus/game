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
	void add(const Component& component, const Position<double>& position);
};

RelativeLayout::RelativeLayout(int width, int height)
	: Layout(width, height)
{

}

void RelativeLayout::init(void)
{

}

void RelativeLayout::draw(void)
{
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
	unsigned n = components.size();
	for (unsigned i = 0; i < n; i++) {
		Component& component = components[i];
		const Position<double>& position = positions[i];
		glPushMatrix();
		glTranslated(position.getX(), position.getY(), 0.0);
		component.draw();
		glPopMatrix();
	}
}

#endif

