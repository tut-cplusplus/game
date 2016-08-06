#ifndef ___Class_NormalEnemy
#define ___Class_NormalEnemy

#include "Enemy.hpp"
#include "Size.hpp"

/**
 * 普通の敵クラス
 */
class NormalEnemy : public Enemy {
public:
	NormalEnemy(const Vector<double>& position = Vector<double>(0.0, 0.0), const Size<double>& size = Size<double>(0.0, 0.0), double speed = 1.0, double viewAngle = 45.0, double radius = 100.0, int life = 0);
};

#endif

