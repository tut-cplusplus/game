#ifndef ___Class_Vector
#define ___Class_Vector

#include <iostream>

template <typename T>
class Vector;
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v);

/**
 * ベクトルクラス．
 */
template <typename T>
class Vector {
private:
	T x;	/* x座標 */
	T y;	/* y座標 */

public:
	Vector();
	/**
	 * コンストラクタ
	 *
	 * @param x x座標
	 * @param y y座標
	 */
	Vector(const T& x, const T& y);
	/**
	 * コピーコンストラクタ
	 */
	template <typename T2>
	Vector(const Vector<T2>& v);
	double norm2(void) const;
	/**
	 * アクセッサ
	 */
	T getX(void) const;
	T getY(void) const;
	void setX(const T& x);
	void setY(const T& y);

	Vector<T> operator-(void) const;
	void operator+=(const Vector<T>& v);
	void operator-=(const Vector<T>& v);
	void operator*=(const T& value);
	void operator/=(const T& value);
	Vector<T> operator+(const Vector<T>& v) const;
	Vector<T> operator-(const Vector<T>& v) const;
	bool operator==(const Vector<T>& v) const;
	bool operator!=(const Vector<T>& v) const;
	friend std::ostream& operator<<<T>(std::ostream& os, const Vector<T>& v);
};

template <typename T>
Vector<T>::Vector()
	: x((T)0.0), y((T)0.0)
{

}

template <typename T>
template <typename T2>
Vector<T>::Vector(const Vector<T2>& v)
	: x((T)v.getX()), y((T)v.getY())
{

}

template <typename T>
Vector<T>::Vector(const T& x, const T& y)
	: x(x), y(y)
{

}

template <typename T>
inline double Vector<T>::norm2(void) const
{
	return x * x + y * y;
}

template <typename T>
inline T Vector<T>::getX(void) const
{
	return x;
}

template <typename T>
inline T Vector<T>::getY(void) const
{
	return y;
}

template <typename T>
inline void Vector<T>::setX(const T& x)
{
	this->x = x;
}

template <typename T>
inline void Vector<T>::setY(const T& y)
{
	this->y = y;
}

template <typename T>
inline Vector<T> Vector<T>::operator-(void) const
{
	return Vector<T>(-x, -y);
}

template <typename T>
inline void Vector<T>::operator+=(const Vector<T>& v)
{
	x += v.x;
	y += v.y;
}

template <typename T>
inline void Vector<T>::operator-=(const Vector<T>& v)
{
	(*this)+=(-v);
}

template <typename T>
inline void Vector<T>::operator*=(const T& value)
{
	x *= value;
	y *= value;
}

template <typename T>
inline void Vector<T>::operator/=(const T& value)
{
	this->operator*=(1 / value);
}

template <typename T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& v) const
{
	Vector tmp(*this);
	tmp += v;
	return tmp;
}

template <typename T>
inline Vector<T> Vector<T>::operator-(const Vector<T>& v) const
{
	return (*this)+(-v);
}

template <typename T>
inline bool Vector<T>::operator==(const Vector<T>& v) const
{
	return x == v.x && y == v.y;
}

template <typename T>
inline bool Vector<T>::operator!=(const Vector<T>& v) const
{
	return !operator==(v);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

#endif

