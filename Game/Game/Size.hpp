#ifndef ___Class_Size
#define ___Class_Size

/**
 * サイズクラス
 * 幅と高さを管理する
 */
template <typename T>
class Size {
private:
	T width;
	T height;

public:
	Size();
	Size(const T& width, const T& height);

	T getWidth(void) const;
	T getHeight(void) const;
	void setWidth(const T& width);
	void setHeight(const T& height);
};

template <typename T>
inline Size<T>::Size()
	: width(0), height(0)
{

}

template <typename T>
inline Size<T>::Size(const T& width, const T& height)
	: width(width), height(height)
{

}

template <typename T>
inline T Size<T>::getWidth(void) const
{
	return width;
}

template <typename T>
inline T Size<T>::getHeight(void) const
{
	return height;
}

template <typename T>
inline void Size<T>::setWidth(const T& width)
{
	this->width = width;
}

template <typename T>
inline void Size<T>::setHeight(const T& height)
{
	this->height = height;
}

#endif

