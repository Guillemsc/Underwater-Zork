#ifndef __Box__
#define __Box__ 

#include "entity.h"
#include "p2string.h"
#include "p2vector.h"

class Item;

class Box : public Entity
{
private:
	int position;
	
public:
	Box(p2String name, p2String description, int _position, Item* _other, bool _can_be_opened, Item* _opener);
	~Box();
	
	int get_position();
	void set_position(int _position);
	bool on_player = false;
	bool can_be_opened;  bool is_opened = false;
	bool can_interact = true;
	
	Item* object_inside;
	Item* opener;
	
	
};

#endif