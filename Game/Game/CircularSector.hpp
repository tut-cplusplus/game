#ifndef ___Class_CircularSector
#define ___Class_CircularSector

#include "Vector.hpp"

/**
 * 円弧クラス
 * あたり判定に用いる
 */
class CircularSector {
private:
	Vector<double> position;	//円弧の中心位置
	double angle;				//角度
	double viewAngle;			//視野角
	double radius;				//半径

public:
	CircularSector();
	CircularSector(const Vector<double>& position, double angle, double viewAngle, double radius);
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
	bool isHit(const Vector<double>& position) const;
};

#endif

