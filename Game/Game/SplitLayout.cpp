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

