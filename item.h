#ifndef __Item__
#define __Item__ 

#include "entity.h"
#include "p2string.h"
#include "p2vector.h"


class Player;
class Item;
class Exit;


class Item : public Entity
{
private:
	int position;

public:
	Item(p2String name, p2String description, int _position, Item* _other, bool can_be_used, bool _can_interact, bool can_be_equiped);
	~Item();

	int get_position();
	void set_position(int _position);
	bool on_player = false; //false
	bool can_be_used; bool is_used = false; //false
	bool can_be_equiped; bool is_equiped = false; //false
	bool can_interact;
};

#endif