#include "SplitLayout.hpp"

void SplitLayout::deleteComponent(Component** component)
{
	if (*component == nullptr)
		return;
	delete *component;
	*component = nullptr;
}

SplitLayout::SplitLayout(int width, int height, double pow)
	: Layout(width, height), pow(pow), component1(nullptr), component2(nullptr)
{

}

SplitLayout::~SplitLayout()
{
	deleteComponent(&component1);
	deleteComponent(&component2);
}

void SplitLayout::init(void)
{

}

void SplitLayout::setComponent1(Component* component)
{
	deleteComponent(&component1);
	component1 = component;
}

void SplitLayout::setComponent2(Component* component)
{
	deleteComponent(&component2);
	component2 = component;
}

void SplitLayout::mouse(int button, int state, int x, int y)
{
	if (component1 != nullptr)
		component1->mouse(button, state, x, y);
	if (component2 != nullptr)
		component2->mouse(button, state, x, y);
}

void SplitLayout::keyboard(unsigned char key, int x, int y)
{
	if (component1 != nullptr)
		component1->keyboard(key, x, y);
	if (component2 != nullptr)
		component2->keyboard(key, x, y);
}

void SplitLayout::keyboardup(unsigned char key, int x, int y)
{
	if (component1 != nullptr)
		component1->keyboardup(key, x, y);
	if (component2 != nullptr)
		component2->keyboardup(key, x, y);
}

void SplitLayout::special(int key, int x, int y)
{
	if (component1 != nullptr)
		component1->special(key, x, y);
	if (component2 != nullptr)
		component2->special(key, x, y);
}

void SplitLayout::specialup(int key, int x, int y)
{
	if (component1 != nullptr)
		component1->specialup(key, x, y);
	if (component2 != nullptr)
		component2->specialup(key, x, y);
}

