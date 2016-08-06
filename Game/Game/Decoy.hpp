#ifndef ___Class_Decoy
#define ___Class_Decoy

#include "Character.hpp"
#include "Vector.hpp"
#include "Size.hpp"

class Decoy : public Character {
protected:
	void init(void);
	void loadAnimations(void);

public:
	Decoy(const Vector<double>& position = Vector<double>(0.0, 0.0), const Size<double>& size = Size<double>(0.0, 0.0));
	~Decoy();

	void changeColor(void) const;
};

#endif

