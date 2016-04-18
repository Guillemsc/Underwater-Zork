#include "entity.h"

Entity::Entity(p2String _name, p2String _description, Entity* other = NULL) : 
name(_name), description(_description), parent(other)
{
	type = ENTITY;
}

Entity::~Entity()
{
}

p2String Entity::get_name()
{
	return name;
}

p2String Entity::get_description()
{
	return description;
}

void Entity::set_name(p2String _name)
{
	name = _name;
}

void Entity::set_description(p2String _description)
{
	description = _description;
}

bool Entity::check_type(EntityType _type)
{
	if (type == _type)
		return true;
	else return false;
}