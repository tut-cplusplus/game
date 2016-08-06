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
	if (component1 != nullptr)
		component1->draw();
	glTranslated(width * pow, 0.0, 0.0);
	if (component2 != nullptr)
		component2->draw();
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

