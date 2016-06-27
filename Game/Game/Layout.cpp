#include "Layout.hpp"

Layout::Layout(int width, int height)
	: Component(width, height)
{

}

Layout::~Layout()
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		delete *itr;
}

void Layout::init(void)
{

}

