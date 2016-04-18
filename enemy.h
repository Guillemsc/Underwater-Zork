#ifndef __Enemy__
#define __Enemy__ 


#include "entity.h"
#include "p2string.h"

class Enemy : public Entity
{
private:
	int position;
	int health = 100;
public:
	Enemy(p2String name, p2String description, Entity* other, int _position);
	~Enemy();

	int get_position();
	void set_position(int _position);

	int get_healt();
	void substract_healt(int _h);
	
	bool is_dead = false;
};

#endif