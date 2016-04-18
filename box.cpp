#include "box.h"
#include "item.h"

Box::Box(p2String name, p2String description, int _position, Item* _other, bool _can_be_opened, Item* _opener) :
Entity(name, description, NULL), can_be_opened(_can_be_opened), object_inside(_other), opener(_opener)
{
	type = CONTAINER;
	position = _position;
}

Box::~Box()
{
}

int Box::get_position()
{
	return position;
}

void Box::set_position(int _position)
{
	position = _position;
}