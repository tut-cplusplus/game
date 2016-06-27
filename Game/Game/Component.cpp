#include "Component.hpp"

Component::Component()
{
  return ;
}

Component::Component(int width, int height)
{
  this->width = width;
  this->height = height;
  return ;
}

Component::~Component()
{
  
}

void Component::init(void)
{

}

void Component::draw(void)
{

}

void Component::mouse(int button, int state, int x, int y)
{

}

void Component::keyboard(unsigned char key, int x, int y)
{

}

void Component::keyboardup(unsigned char key, int x, int y)
{

}

void Component::special(int key, int x, int y)
{

}

void Component::specialup(int key, int x, int y)
{

}

