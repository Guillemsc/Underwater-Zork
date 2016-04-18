#ifndef __Player__
#define __Player__

#include "entity.h"
#include "p2string.h"
#include "world.h"

class Entity;
class Room;
class Player;
class Exit;
class Item;
class Box;

//----------------------------
class Player : public Entity
{
private:
	int position = 0;
	int health = 100;
	int oxigent = 100;

public:
	Player(p2String name, p2String description, Entity* other, int _position);
	~Player();

	int get_position();
	void set_position(int _pos);
	int get_healt();
	void substract_health(int _h);
	int get_oxigent();
	void substract_oxigent(int _h);

	void move(p2vector<Room*> &rooms, p2vector<Player*> &player, p2vector<Exit*> &exits, p2String orientation, p2vector<Item*> &items, p2vector<Box*> &boxes);
	void look(p2vector<Room*> &rooms, p2vector<Player*> &player, p2vector<Exit*> &exits, p2vector<Item*> &items, p2vector<Box*> &boxes);

	void inventory(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Box*> &boxes);
	void stats(p2vector<Player*> player);
	void help(p2vector<Player*> player);

	void take_object(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2vector<Box*> &boxes);
	void drop_object(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2vector<Box*> &boxes);
	void use_object(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2vector<Box*> &boxes);

	void equip(p2vector<Player*> &player, p2vector<Item*> &items, p2String item);
	void unequip(p2vector<Player*> &player, p2vector<Item*> &items, p2String item);

	void open_door(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits);
	void close_door(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits);

	void put_inside(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2String box_name, p2vector<Box*> &boxes);
	void open_box(p2vector<Player*> &player, p2String box_name, p2vector<Box*> &boxes);
	void close_box(p2vector<Player*> &player, p2String box_name, p2vector<Box*> &boxes);
	void take_outside(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2String box_name, p2vector<Box*> &boxes);

	bool want_to_look = true;
	bool want_to_input = true;
	bool tank = true;
	bool end = false;
	bool light = false;
	bool elevator = false;
	bool broken_tank = false;
};

#endif