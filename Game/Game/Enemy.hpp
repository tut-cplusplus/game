#ifndef __Class_Enemy
#define __Class_Enemy

#include "Character.hpp"
#include "Size.hpp"

class Enemy : public Character {
public:
	
	Enemy();

	Enemy(const Vector<double>& position, const Size<double>& size);
	Enemy(const Vector<double>& position);
	virtual ~Enemy();

	void onMoveAI(void);
	void changeColor(void) const;
};

#endif
