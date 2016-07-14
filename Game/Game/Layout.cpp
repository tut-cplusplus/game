#include <iostream>

#include "Layout.hpp"

using namespace std;

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
	keyEvent(key, x, y, &Component::keyboard);
}

void Layout::keyboardOnce(unsigned char key, int x, int y)
{
	keyEvent(key, x, y, &Component::keyboardOnce);
}

void Layout::keyboardup(unsigned char key, int x, int y)
{
	keyEvent(key, x, y, &Component::keyboardup);
}

void Layout::keyboardupOnce(unsigned char key, int x, int y)
{
	keyEvent(key, x, y, &Component::keyboardupOnce);
}

void Layout::special(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::special);
}

void Layout::specialOnce(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::specialOnce);
}

void Layout::specialup(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::specialup);
}

void Layout::specialupOnce(int key, int x, int y)
{
	keyEvent(key, x, y, &Component::specialupOnce);
}

