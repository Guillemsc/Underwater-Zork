#ifndef __Entity__
#define __Entity__

#include "p2string.h"
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	ENEMY,
	PLAYER,
	CONTAINER
};

class Entity
{
private:
	p2String name;
	p2String description;

public:
	Entity(p2String _name, p2String _description, Entity* _other);
	virtual ~Entity();

	p2String get_name();
	p2String get_description();
	void set_name(p2String _name);
	void set_description(p2String _description);

	bool check_type(EntityType _type);

	Entity* parent;

	EntityType type;
};
#endif