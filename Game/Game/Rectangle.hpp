#ifndef ___Class_Rectangle
#define ___Class_Rectangle

#include "Size.hpp"

/**
 * 長方形クラス
 */
class Rectangle {
protected:
	Size<double> size;

public:
	Rectangle();
	Rectangle(const Size<double>& size);

	/**
	 * アクセッサ
	 */
	Size<double> getSize(void) const;
	void setSize(const Size<double>& size);
};

inline Size<double> Rectangle::getSize(void) const
{
	return size;
}

inline void Rectangle::setSize(const Size<double>& size)
{
	this->size = size;
}

#endif

