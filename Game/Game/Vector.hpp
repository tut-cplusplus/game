#ifndef ___Class_Vector
#define ___Class_Vector

/**
 * ベクトルクラス．
 */
template <typename T, typename T2 = double>
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
	Vector(const Vector<T2,T2>& v);
	double norm2(void) const;
	/**
	 * アクセッサ
	 */
	T getX(void) const;
	T getY(void) const;
	void setX(const T& x);
	void setY(const T& y);

	Vector<T,T2> operator-(void) const;
	void operator+=(const Vector<T,T2>& v);
	void operator-=(const Vector<T,T2>& v);
	void operator*=(const T& value);
	void operator/=(const T& value);
	Vector<T,T2> operator+(const Vector<T,T2>& v) const;
	Vector<T,T2> operator-(const Vector<T,T2>& v) const;
	bool operator==(const Vector<T,T2>& v) const;
};

template <typename T, typename T2>
Vector<T,T2>::Vector()
	: x((T)0.0), y((T)0.0)
{

}

template <typename T, typename T2>
Vector<T,T2>::Vector(const Vector<T2,T2>& v)
	: x((T)v.getX()), y((T)v.getY())
{

}

template <typename T, typename T2>
Vector<T,T2>::Vector(const T& x, const T& y)
	: x(x), y(y)
{

}

template <typename T, typename T2>
inline double Vector<T,T2>::norm2(void) const
{
	return x * x + y * y;
}

template <typename T, typename T2>
inline T Vector<T,T2>::getX(void) const
{
	return x;
}

template <typename T, typename T2>
inline T Vector<T,T2>::getY(void) const
{
	return y;
}

template <typename T, typename T2>
inline void Vector<T,T2>::setX(const T& x)
{
	this->x = x;
}

template <typename T, typename T2>
inline void Vector<T,T2>::setY(const T& y)
{
	this->y = y;
}

template <typename T, typename T2>
inline Vector<T,T2> Vector<T,T2>::operator-(void) const
{
	return Vector<T,T2>(-x, -y);
}

template <typename T, typename T2>
inline void Vector<T,T2>::operator+=(const Vector<T,T2>& v)
{
	x += v.x;
	y += v.y;
}

template <typename T, typename T2>
inline void Vector<T,T2>::operator-=(const Vector<T,T2>& v)
{
	(*this)+=(-v);
}

template <typename T, typename T2>
inline void Vector<T,T2>::operator*=(const T& value)
{
	x *= value;
	y *= value;
}

template <typename T, typename T2>
inline void Vector<T,T2>::operator/=(const T& value)
{
	this->operator*=(1 / value);
}

template <typename T, typename T2>
inline Vector<T,T2> Vector<T,T2>::operator+(const Vector<T,T2>& v) const
{
	Vector tmp(*this);
	tmp += v;
	return tmp;
}

template <typename T, typename T2>
inline Vector<T,T2> Vector<T,T2>::operator-(const Vector<T,T2>& v) const
{
	return (*this)+(-v);
}

template <typename T, typename T2>
inline bool Vector<T,T2>::operator==(const Vector<T,T2>& v) const
{
	return x == v.x && y == v.y;
}

#endif

