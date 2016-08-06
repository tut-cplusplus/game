#ifndef ___Class_HorizontalSplitLayout
#define ___Class_HorizontalSplitLayout

#include "SplitLayout.hpp"

/**
 * 横方向の分割レイアウトクラス
 */
class HorizontalSplitLayout : public SplitLayout {
public:
	HorizontalSplitLayout(const Size<double>& size = Size<double>(0.0, 0.0), double pow = 0.5);
	virtual void draw(void);
	virtual void setComponent1(Component* component);
	virtual void setComponent2(Component* component);
};

#endif

