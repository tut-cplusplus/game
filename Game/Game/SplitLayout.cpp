#include "SplitLayout.hpp"

void SplitLayout::deleteComponent(Component** component)
{
	if (*component == nullptr)
		return;
	delete *component;
	*component = nullptr;
}

SplitLayout::SplitLayout(const Size<double>& size, double pow)
	: Layout(size), pow(pow), component1(nullptr), component2(nullptr)
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
	keyEvent(key, x, y, &Component::keyboard);
}

void SplitLayout::keyboardOnce(unsigned char key, int x, int y)
{
	keyEvent(key, x, y, &Component::keyboardOnce);
}

void SplitLayout::keyboardup(unsigned char key, int x, int y)
{
	keyEvent(key, x, y, &Component::keyboardup);
}

void SplitLayout::keyboardupOnce(unsigned char key, int x, int y)
{
	keyEvent(key, x, y, &Component::keyboardupOnce);
}

void SplitLayout::special(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::special);
}

void SplitLayout::specialOnce(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::specialOnce);
}

void SplitLayout::specialup(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::specialup);
}

void SplitLayout::specialupOnce(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::specialupOnce);
}

