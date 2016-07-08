#ifndef ___Class_NormalEnemy
#define ___Class_NormalEnemy

#include "Enemy.hpp"
#include "Size.hpp"

/**
 * 普通の敵クラス
 */
class NormalEnemy : public Enemy {
public:
	NormalEnemy();
	NormalEnemy(const Vector<double>& position, const Size<double>& size);
	NormalEnemy(const Vector<double>& position);
};

#endif

