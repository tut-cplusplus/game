#ifndef ___Class_SplitLayout
#define ___Class_SplitLayout

#include "Component.hpp"
#include "Layout.hpp"

/**
 * 分割レイアウトクラス
 * 抽象クラス
 */
class SplitLayout : public Layout {
protected:
	double pow;	/* 分割率 */

private:
	void deleteComponent(Component** component);
	void setComponent(Component*& dst, Component* component);

public:
	SplitLayout(const Size<double>& size = Size<double>(0.0, 0.0), double pow = 0.5);
	~SplitLayout();
	virtual void init(void);
	virtual void draw(void) = 0;
	/**
	 * セッタ
	 */
	virtual void setComponent1(Component* component);
	virtual void setComponent2(Component* component);
};

#endif

