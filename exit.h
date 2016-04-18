#ifndef __Exit__
#define __Exit__ 

#include "p2string.h"
#include "entity.h"

class Room;
class Item;
class Player;


class Exit : public Entity
{
public:
	Room* enter;
	Room* out;
	Item* obj;
	p2String orientation;
	bool opened;
	
	Exit(Room* _enter, Room* _out, p2String _orientation, Item* _object, bool _opened);
	~Exit();

};

#endif
