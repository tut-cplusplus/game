#include "Rectangle.hpp"

Utility::Rectangle::Rectangle()
	: size(Size<double>(0.0, 0.0))
{

}

Utility::Rectangle::Rectangle(const Size<double>& size)
	: size(size)
{

}

void Utility::Rectangle::setSize(const Size<double>& size)
{
	this->size = size;
}

