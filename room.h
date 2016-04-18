#ifndef __Room__
#define __Room__ 

#include "entity.h"
#include "p2string.h"

//----------------------------
class Room : public Entity
{
private:
	int position;

public:
	Room(p2String name, p2String description, int _position);
	~Room();

	int get_position();
};

#endif