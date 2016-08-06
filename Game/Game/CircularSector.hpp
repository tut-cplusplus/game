#ifndef ___Class_CircularSector
#define ___Class_CircularSector

#include "Vector.hpp"

/**
 * 円弧クラス
 * あたり判定に用いる
 */
class CircularSector {
protected:
	Vector<double> position;	//円弧の中心位置
	double angle;				//角度
	double viewAngle;			//視野角
	double radius;				//半径
	bool isDrawRadius;

public:
	CircularSector();
	CircularSector(const Vector<double>& position, double angle, double viewAngle, double radius, bool isDrawRadius = true);
	/**
	 * angleを0~360に調整する
	 */
	void adjustAngle(void);
	/**
	 * あたり判定
	 *
	 * @param position 対象の位置
	 * @return 当たっていればtrue，そうでなければfalse
	 */
	virtual bool isHit(const Vector<double>& position) const;
	/**
	 * 描画関数
	 */
	virtual void draw(void);
	/**
	 * アクセッサ
	 */
	double getRadius(void) const;
	void setRadius(double radius);
};

inline void CircularSector::adjustAngle(void)
{
	angle += 360.0;
	while (angle >= 360.0)
		angle -= 360.0;
}

inline double CircularSector::getRadius(void) const
{
	return radius;
}

inline void CircularSector::setRadius(double radius)
{
	this->radius = radius;
}

#endif

