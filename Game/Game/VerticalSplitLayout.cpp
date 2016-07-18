#include "VerticalSplitLayout.hpp"

#include "GL/glut.h"

VerticalSplitLayout::VerticalSplitLayout(int width, int height, double pow)
	: SplitLayout(width, height, pow)
{

}

void VerticalSplitLayout::draw(void)
{
	glPushMatrix();
	if (component1 != nullptr)
		component1->draw();
	glTranslated(0.0, height * pow, 0.0);
	if (component2 != nullptr)
		component2->draw();
	glPopMatrix();
}

void VerticalSplitLayout::setComponent1(Component* component)
{
	SplitLayout::setComponent1(component);
	component->setWidth(width);
	component->setHeight((int)(height * pow));
}

void VerticalSplitLayout::setComponent2(Component* component)
{
	SplitLayout::setComponent2(component);
	component->setWidth(width);
	component->setHeight((int)(height * (1.0 - pow)));
}

