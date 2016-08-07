#include "SplitLayout.hpp"

void SplitLayout::deleteComponent(Component** component)
{
	if (*component == nullptr)
		return;
	delete *component;
	*component = nullptr;
}

void SplitLayout::setComponent(Component*& dst, Component* component)
{
	deleteComponent(&dst);
	dst = component;
}

SplitLayout::SplitLayout(const Size<double>& size, double pow)
	: Layout(size, 2), pow(pow)
{

}

SplitLayout::~SplitLayout()
{

}

void SplitLayout::init(void)
{

}

void SplitLayout::setComponent1(Component* component)
{
	setComponent(components[0], component);
}

void SplitLayout::setComponent2(Component* component)
{
	setComponent(components[1], component);
}

