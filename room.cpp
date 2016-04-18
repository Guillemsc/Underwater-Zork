#include <iostream>
#include "room.h"

Room::Room(p2String name, p2String description, int _position) :
Entity(name, description, NULL)
{
	type = ROOM;
	position = _position;
}

Room::~Room(){}

int Room::get_position()
{
	return position;
}
