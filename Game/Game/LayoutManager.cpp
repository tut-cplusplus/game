#include "LayoutManager.hpp"

using namespace std;

Layout* LayoutManager::layout = nullptr;

Layout* LayoutManager::getLayout(void)
{
	return layout;
}

void LayoutManager::registerLayout(Layout* _layout)
{
	if (layout != nullptr)
		delete layout;
	layout = _layout;
}

void LayoutManager::draw(void)
{
	layout->draw();
}

void LayoutManager::mouse(int button, int state, int x, int y)
{
	layout->mouse(button, state, x, y);
}

void LayoutManager::keyboard(unsigned char key, int x, int y)
{
	layout->keyboard(key, x, y);
}

void LayoutManager::keyboardup(unsigned char key, int x, int y)
{
	layout->keyboardup(key, x, y);
}

void LayoutManager::special(int key, int x, int y)
{
	layout->special(key, x, y);
}

void LayoutManager::specialup(int key, int x, int y)
{
	layout->special(key, x, y);
}

