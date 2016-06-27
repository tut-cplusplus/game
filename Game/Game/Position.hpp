#ifndef ___Class_Position
#define ___Class_Position

/**
 * 位置クラス．
 * Layoutクラスのために作成
 */
template <typename T>
class Position {
private:
	T x;	/* x座標 */
	T y;	/* y座標 */

public:
	/**
	 * コンストラクタ
	 *
	 * @param x x座標
	 * @param y y座標
	 */
	Position(const T& x, const T& y);
	/**
	 * アクセッサ
	 */
	T getX(void) const;
	T getY(void) const;
	void setX(const T& x);
	void setY(const T& y);
};

template <typename T>
Position<T>::Position(const T& x, const T& y)
	: x(x), y(y)
{

}

template <typename T>
inline T Position<T>::getX(void) const
{
	return x;
}

template <typename T>
inline T Position<T>::getY(void) const
{
	return y;
}

template <typename T>
inline void Position<T>::setX(const T& x)
{
	this->x = x;
}

template <typename T>
inline void Position<T>::setY(const T& y)
{
	this->y = y;
}

#endif

