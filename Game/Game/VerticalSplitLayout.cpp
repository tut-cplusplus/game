#include "VerticalSplitLayout.hpp"

#include "GL/glut.h"

VerticalSplitLayout::VerticalSplitLayout(const Size<double>& size, double pow)
	: SplitLayout(size, pow)
{

}

void VerticalSplitLayout::draw(void)
{
	double height = size.getHeight();
	glPushMatrix();
	for (auto itr = components.begin(); itr != components.end(); ++itr) {
		if (*itr != nullptr)
			(*itr)->draw();
		glTranslated(0.0, height * pow, 0.0);
	}
	glPopMatrix();
}

void VerticalSplitLayout::setComponent1(Component* component)
{
	double width = size.getWidth();
	double height = size.getHeight();
	SplitLayout::setComponent1(component);
	component->setSize(Size<double>(width, height * pow));
}

void VerticalSplitLayout::setComponent2(Component* component)
{
	double width = size.getWidth();
	double height = size.getHeight();
	SplitLayout::setComponent2(component);
	component->setSize(Size<double>(width, height * (1.0 - pow)));
}

