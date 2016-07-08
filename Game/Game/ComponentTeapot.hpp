#ifndef ___Class_ComponentTeapot
#define ___Class_ComponentTeapot

#include <random>

#include "Component.hpp"

/**
 * Teapotコンポーネント．
 * レイアウトのテストに用いる．
 */
class ComponentTeapot : public Component {
private:
	static std::random_device rd;
	static std::mt19937 mt;
	static std::uniform_int_distribution<int> rnd;
private:
	double angle;	//Y軸まわりの回転角
	int step;		//ステップ角

public:
	ComponentTeapot();
	ComponentTeapot(int width, int height);

	virtual void draw(void);
};

#endif

