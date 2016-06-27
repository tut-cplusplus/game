#ifndef ___Class_Layout
#define ___Class_Layout

#include <vector>

class Layout : public Component {
private:
	std::vector<Component> components;

public:
	Layout();
	~Layout();
};

#endif

