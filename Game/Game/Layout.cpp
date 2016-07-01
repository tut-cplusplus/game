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

void Layout::mouse(int button, int state, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(**itr).mouse(button, state, x, y);

}

void Layout::keyboard(unsigned char key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(**itr).keyboard(key, x, y);
}

void Layout::keyboardup(unsigned char key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(**itr).keyboardup(key, x, y);
}

void Layout::special(int key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(**itr).special(key, x, y);
}

void Layout::specialup(int key, int x, int y)
{
	for (auto itr = components.begin(); itr != components.end(); ++itr)
		(**itr).specialup(key, x, y);

}

