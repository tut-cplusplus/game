#ifndef ___Class_HorizontalSplitLayout
#define ___Class_HorizontalSplitLayout

#include "SplitLayout.hpp"

/**
 * 横方向の分割レイアウトクラス
 */
class HorizontalSplitLayout : public SplitLayout {
public:
	HorizontalSplitLayout(int width, int height, double pow);
	virtual void draw(void);
	virtual void setComponent1(Component* component);
	virtual void setComponent2(Component* component);
};

#endif

