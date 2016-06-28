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
	Component* component1;
	Component* component2;

private:
	void deleteComponent(Component** component);

public:
	SplitLayout(int width, int height, double pow);
	~SplitLayout();
	virtual void init(void);
	virtual void draw(void) = 0;
	/**
	 * セッタ
	 */
	void setComponent1(Component* component);
	void setComponent2(Component* component);
};

#endif

