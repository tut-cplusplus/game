#include "HorizontalSplitLayout.hpp"

#include "GL/glut.h"

HorizontalSplitLayout::HorizontalSplitLayout(int width, int height, double pow)
	: SplitLayout(width, height, pow)
{

}

void HorizontalSplitLayout::draw(void)
{
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
	SplitLayout::setComponent1(component);
	component->setHeight(height);
	component->setWidth((int)(width * pow));
}

void HorizontalSplitLayout::setComponent2(Component* component)
{
	SplitLayout::setComponent2(component);
	component->setHeight(height);
	component->setWidth((int)(width * (1.0 - pow)));
}

