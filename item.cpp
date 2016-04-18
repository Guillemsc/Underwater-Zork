#include <iostream>
#include "item.h"
#include "player.h"
#include "world.h"
#include "exit.h"

Item::Item(p2String name, p2String description, int _position, Item* _other, bool _can_be_used, bool _can_interact, bool _can_be_equiped) :
Entity(name, description, NULL), position(_position), can_be_used(_can_be_used), can_interact(_can_interact), can_be_equiped(_can_be_equiped)
{
	type = ITEM;
}

Item::~Item()
{
}

int Item::get_position()
{
	return position;
}

void Item::set_position(int _position)
{
	position = _position;
}

