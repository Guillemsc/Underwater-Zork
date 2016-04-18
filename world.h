#ifndef __World__
#define __World__ 

#include "p2vector.h"
#include "p2string.h"
#include "entity.h"
#include "exit.h"
#include "player.h"
#include "exit.h"
#include "room.h"
#include "item.h"
#include "input.h"
#include "box.h"
#include "enemy.h"

class World
{
public:
	World();
	~World();

	p2vector<Entity*> entities;
	p2vector<Player*> players;
	p2vector<Exit*> exits;
	p2vector<Room*> rooms;
	p2vector<Item*> items;
	p2vector<Box*> boxes;
	p2vector<Enemy*> enemies;
};

#endif