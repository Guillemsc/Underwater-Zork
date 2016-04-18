#include <iostream>
#include "exit.h"
#include "room.h"
#include "item.h"

Exit::Exit(Room* _enter, Room* _out, p2String _orientation, Item* _object, bool _opened) :
Entity("Exit", "This is an exit", NULL), obj(_object)
{
	type = EXIT;

	enter = _enter;
	out = _out;
	orientation = _orientation;
	opened = _opened;
}

Exit::~Exit(){}

