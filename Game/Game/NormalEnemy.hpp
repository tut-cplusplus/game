#ifndef ___Class_NormalEnemy
#define ___Class_NormalEnemy

#include "Enemy.hpp"
#include "Size.hpp"

/**
 * 普通の敵クラス
 */
class NormalEnemy : public Enemy {
public:
	NormalEnemy(const Vector<double>& position = Vector<double>(0.0, 0.0), const Size<double>& size = Size<double>(0.0, 0.0));
};

#endif

