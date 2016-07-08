#include "Rectangle.hpp"

Rectangle::Rectangle()
	: size(Size<double>(0.0, 0.0))
{

}

Rectangle::Rectangle(const Size<double>& size)
	: size(size)
{

}

void Rectangle::setSize(const Size<double>& size)
{
	this->size = size;
}

