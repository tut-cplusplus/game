#ifndef ___Class_ComponentTeapot
#define ___Class_ComponentTeapot

#include "Component.hpp"

/**
 * Teapotコンポーネント．
 * レイアウトのテストに用いる．
 */
class ComponentTeapot : public Component {
private:
	int angle;

public:
	ComponentTeapot();
	ComponentTeapot(int width, int height);

	virtual void draw(void);
};

#endif

