#ifndef ___Class_VerticalSplitLayout
#define ___Class_VerticalSplitLayout

#include "SplitLayout.hpp"

/**
 * 縦方向の分割レイアウトクラス
 */
class VerticalSplitLayout : public SplitLayout {
public:
	VerticalSplitLayout(int width, int height, double pow);
	virtual void draw(void);
	virtual void setComponent1(Component* component);
	virtual void setComponent2(Component* component);
};

#endif

