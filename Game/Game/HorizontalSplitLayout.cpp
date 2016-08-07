#include "HorizontalSplitLayout.hpp"

#include "GL/glut.h"

HorizontalSplitLayout::HorizontalSplitLayout(const Size<double>& size, double pow)
	: SplitLayout(size, pow)
{

}

void HorizontalSplitLayout::draw(void)
{
	double width = size.getWidth();
	glPushMatrix();
	for (auto itr = components.begin(); itr != components.end(); ++itr) {
		if (*itr != nullptr)
			(*itr)->draw();
		glTranslated(width * pow, 0.0, 0.0);
	}
	glPopMatrix();
}

void HorizontalSplitLayout::setComponent1(Component* component)
{
	double width = size.getWidth();
	double height = size.getHeight();
	SplitLayout::setComponent1(component);
	component->setSize(Size<double>(width * pow, height));
}

void HorizontalSplitLayout::setComponent2(Component* component)
{
	double width = size.getWidth();
	double height = size.getHeight();
	SplitLayout::setComponent2(component);
	component->setSize(Size<double>(width * (1.0 - pow), height));
}

