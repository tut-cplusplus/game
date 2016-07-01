#include "Size.hpp"

template <typename T>
Size<T>::Size()
	: width(0), height(0)
{

}

template <typename T>
Size<T>::Size(const T& width, const T& height)
	: width(width), height(height)
{

}

