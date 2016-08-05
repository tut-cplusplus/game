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
	Decoy();
	Decoy(const Vector<double>& position, const Size<double>& size);
	~Decoy();

	void changeColor(void) const;
};

#endif

