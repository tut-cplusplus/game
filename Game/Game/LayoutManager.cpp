#include <iostream>

#include "LayoutManager.hpp"
#include "SpecialKey.hpp"

using namespace std;

Layout* LayoutManager::layout = nullptr;
vector<unsigned char> LayoutManager::keys;
vector<int> LayoutManager::specialKeys;
vector<Vector<int>> LayoutManager::keyPositions;
vector<Vector<int>> LayoutManager::specialKeyPositions;

void LayoutManager::keyEvent(void)
{
	keyEvent(keys, keyPositions, &Layout::keyboard, &Layout::keyboardup);
	keyEvent(specialKeys, specialKeyPositions, &Layout::special, &Layout::specialup);
}

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
	keyEvent();
	try {
		layout->draw();
	}
	catch (Layout* layout) {
		registerLayout(layout);
	}
}

void LayoutManager::mouse(int button, int state, int x, int y)
{
	layout->mouse(button, state, x, y);
}

void LayoutManager::keyboard(unsigned char key, int x, int y)
{
	layout->keyboardOnce(key, x, y);
	if (!searchKey(keys, key)) {
		keys.push_back(key);
		keyPositions.push_back(Vector<int>(x, y));
	}
}

void LayoutManager::keyboardup(unsigned char key, int x, int y)
{
	layout->keyboardupOnce(key, x, y);
	deleteKey(keys, keyPositions, key);
}

void LayoutManager::special(int key, int x, int y)
{
	layout->specialOnce(key, x, y);
	if (!searchKey(specialKeys, key)) {
		specialKeys.push_back(key);
		specialKeyPositions.push_back(Vector<int>(x, y));
	}
}

void LayoutManager::specialup(int key, int x, int y)
{
	layout->specialupOnce(key, x, y);
	deleteKey(specialKeys, specialKeyPositions, key);
}

