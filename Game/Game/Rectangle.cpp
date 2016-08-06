#include "Rectangle.hpp"

Utility::Rectangle::Rectangle(const Size<double>& size)
	: size(size)
{

}

void Utility::Rectangle::setSize(const Size<double>& size)
{
	this->size = size;
}

