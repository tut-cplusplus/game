#ifndef ___Class_VerticalSplitLayout
#define ___Class_VerticalSplitLayout

#include "SplitLayout.hpp"

/**
 * 縦方向の分割レイアウトクラス
 */
class VerticalSplitLayout : public SplitLayout {
public:
	VerticalSplitLayout(const Size<double>& size = Size<double>(0.0, 0.0), double pow = 0.5);
	virtual void draw(void);
	virtual void setComponent1(Component* component);
	virtual void setComponent2(Component* component);
};

#endif

