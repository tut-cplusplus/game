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
	double angle;
	int step;

public:
	ComponentTeapot();
	ComponentTeapot(int width, int height);

	virtual void draw(void);
};

#endif

