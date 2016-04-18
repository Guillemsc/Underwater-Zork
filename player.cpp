#include "player.h"
#include "room.h"
#include "exit.h"
#include "input.h"
#include "box.h"
 
Player::Player(p2String name, p2String description, Entity* other, int _position) :
Entity(name, description, other), position(_position)
{
	type = PLAYER;
}

Player::~Player()
{
}

int Player::get_position()
{
	return position;
}

void Player::set_position(int pos)
{
	position = pos;
}

int Player::get_healt()
{
	return health;
}
void Player::substract_health(int _h)
{
	health -= _h;
}
int Player::get_oxigent()
{
	return oxigent;
}
void Player::substract_oxigent(int _o)
{
	oxigent -= _o;
}


void Player::move(p2vector<Room*> &rooms, p2vector<Player*> &player, p2vector<Exit*> &exits, p2String orientation, p2vector<Item*> &items, p2vector<Box*> &boxes)
{
	int p;
	for (p = 0; p < exits.get_things(); p++)
	{  
		if (rooms[position] == exits[p]->enter)
		{
			if (orientation == exits[p]->orientation)
			{
				if (exits[p]->opened == true)
				{
					player[0]->set_position(exits[p]->out->get_position());
					
					if (player[0]->broken_tank == true)
					{
						player[0]->substract_oxigent(6);
						printf("You are losing oxigent.\n");
					}
					player[0]->want_to_look = true;
					
					for (int y = 0; y < boxes.get_things(); y++)
					{
						if (boxes[y]->on_player == true)
						{
							boxes[y]->set_position(player[0]->get_position());
							if (boxes[y]->object_inside != NULL)
							boxes[y]->object_inside->set_position(player[0]->get_position());
						}
					}

					for (int x = 0; x < items.get_things(); x++)
					{
						if (items[x]->on_player == true)
						{
							items[x]->set_position(player[0]->get_position());
						}
					}
					break;
				}
				else{ printf("This door is closed.\n"); break; }
				player[0]->want_to_look = false;
			}
		}
	}
	if (p == exits.get_things()){ printf("You cant go there.\n"); player[0]->want_to_look = false; }
}

void Player::look(p2vector<Room*> &rooms, p2vector<Player*> &player, p2vector<Exit*> &exits, p2vector<Item*> &items, p2vector<Box*> &boxes)
{
	printf("-- %s --\n", rooms[player[0]->get_position()]->get_name());
	printf("%s.\n\n", rooms[player[0]->get_position()]->get_description());

	// look for exits
	for (int i = 0; i < exits.get_things(); i++)
	{
		if (rooms[player[0]->get_position()] == exits[i]->enter)
		{
			printf("-At the <%s> you have the ", exits[i]->orientation);
			printf("%s.\n", exits[i]->out->get_name());
		}
	}

	// look for boxes
	for (int y = 0; y < boxes.get_things(); y++)
	{
		if (boxes[y]->get_position() == player[0]->get_position() && boxes[y]->on_player == false)
		{
			printf("-%s.\n", boxes[y]->get_description());
		}
	}

	// look for items
	for (int x = 0; x < items.get_things(); x++)
	{
		if (items[x]->get_position() == player[0]->get_position() && items[x]->on_player == false)
		{
			printf("-%s.\n", items[x]->get_description());
		}
	}
	player[0]->want_to_look = false;
}

void Player::take_object(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2vector<Box*> &boxes)
{
	int i = 0;
	bool box = true;

	for (i = 0; i < items.get_things(); i++)
	{
		// take items------------------
		if (Compare(item_name, items[i]->get_name()))
		{
			if (player[0]->get_position() == items[i]->get_position())
			{
				if (items[i]->on_player == false)
				{
					if (items[i]->can_interact == true)
					{
						items[i]->on_player = true;
						printf("You have taken: %s.\n", item_name);
						player[0]->want_to_look = false;
						box = false;
						break;
					}
					else
					{printf("You can't do this.\n"); break;}
				}
				else{printf("You already have this item.\n"); player[0]->want_to_look = false; break;}
			}
			else{ printf("There is not a %s in this room.\n", item_name); }
		}
	}
	int b = 0;
	if (box == true)
	{
		for (b = 0; b < boxes.get_things(); b++)
		{
			// take boxes------------------
			if (Compare(item_name, boxes[b]->get_name()))
			{
				if (player[0]->get_position() == boxes[b]->get_position())
				{
					if (boxes[b]->on_player == false)
					{
						if (boxes[b]->can_interact == true)
						{
							boxes[b]->on_player = true;
							if (boxes[b]->object_inside != NULL)
								boxes[b]->object_inside->on_player = true;
							printf("You have taken: %s.\n", item_name);
							player[0]->want_to_look = false;
							break;
						}
						else{printf("You can't do this.\n"); break;}
					}
					else{printf("You already have this item.\n");player[0]->want_to_look = false;break;}
				}
				else{ printf("There is not a %s in this room.\n", item_name); }
			}
		}
	}

	if (box == false)
	{
		if (i == items.get_things()){ printf("I don't know what '%s' is.\n", item_name); }
	}
		
	else
	{
		if (b == boxes.get_things()){printf("I don't know what '%s' is.\n", item_name);}
	}

			player[0]->want_to_look = false;
}

void Player::drop_object(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2vector<Box*> &boxes)
{
	int i;
	bool box = true;

	for (i = 0; i < items.get_things(); i++)
	{
		// take items------------------
		if (Compare(item_name, items[i]->get_name()))
		{
			if (player[0]->get_position() == items[i]->get_position())
			{
				if (items[i]->on_player == true)
				{
					if (items[i]->can_interact == true)
					{
						items[i]->on_player = false;
						printf("You have doped: %s.\n", item_name);
						items[i]->set_position(player[0]->get_position());
						box = false;
						break;
					}
					else{printf("You can't do this.\n"); break;}
				}
				else{printf("You don't have this item.\n"); break;}
			}
			else{ printf("There is not a %s in this room.\n", item_name); }
		}
	}
	int b = 0;
	if (box == true)
	{
		for (b = 0; b < boxes.get_things(); b++)
		{
			// take boxes------------------
			if (Compare(item_name, boxes[b]->get_name()))
			{
				if (player[0]->get_position() == boxes[b]->get_position())
				{
					if (boxes[b]->on_player == true)
					{
						if (boxes[b]->can_interact == true)
						{
							if (boxes[b]->object_inside != NULL)
								boxes[b]->object_inside->on_player = false;

							boxes[b]->on_player = false;
							printf("You have droped: %s.\n", item_name);
							boxes[b]->set_position(player[0]->get_position());
							break;
						}
						else{printf("You can't do this.\n"); break;}
					}
					else{printf("You already have this item.\n");break;}
				}
				else{ printf("There is not a %s in this room.\n", item_name); }
			}
		}
	}
	if (box == false)
	{
		if (i == items.get_things()){ printf("I don't know what '%s' is.\n", item_name); }
	}

	else
	{
		if (b == boxes.get_things()){ printf("I don't know what '%s' is.\n", item_name); }
	}

		player[0]->want_to_look = false;
}

void Player::use_object(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2vector<Box*> &boxes)
{
	int i;
	for (i = 0; i < items.get_things(); i++)
	{
		// take items------------------
		if (Compare(item_name, items[i]->get_name()))
		{
			if (player[0]->get_position() == items[i]->get_position())
			{
				if (items[i]->on_player == true)
				{
					if (items[i]->can_be_used == true)
					{
						items[i]->is_used = true;
						printf("You used: %s.\n", item_name);
						break;
					}
					else{ printf("You can't use this item.\n"); break; }
				}
				else{printf("You can't do that.\n");break;}
			}
			else{ printf("You can't do that.\n"); break; }
		}
	}
	if (i == items.get_things()){ printf("I don't know what '%s' is.\n", item_name); }
	player[0]->want_to_look = false;
}

void Player::open_door(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits)
{
	//get room
	int i;
	for (i = 0; i < exits.get_things(); i++)
	{
		if (rooms[player[0]->get_position()] == exits[i]->enter)
		{
			if (exits[i]->obj != NULL) //there is a door?
			{
				if (exits[i]->obj->on_player == true) //can you open the door?
				{
					if (exits[i]->opened == false) //open door
					{
						exits[i]->opened = true;
						printf("You opened the door.\n");
						break;
					}
					else{ printf("This door is already opened.\n"); break; }
				}
				else{printf("You can't open this door.\n"); break;}
			}
			else{ continue; }
		}
	}
	if (i == exits.get_things()){ printf("There's no door here.\n"); }
	player[0]->want_to_look = false;
}

void Player::close_door(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits)
{
	//get room
	int i;
	for (i = 0; i < exits.get_things(); i++)
	{
		if (rooms[player[0]->get_position()] == exits[i]->enter)
		{
			if (exits[i]->obj != NULL) //there is a door?
			{
				if (exits[i]->obj->on_player == true) //can you open the door?
				{
					if (exits[i]->opened == true) //close door
					{
						exits[i]->opened = false;
						printf("You closed the door.\n");
						break;
					}
					else{ printf("This door is already closed.\n"); break; }
				}
				else{ printf("You can't close this door.\n"); break; }
			}
			else{ continue; }
		}
	}
	if (i == exits.get_things()){ printf("There's no door here.\n"); }
	player[0]->want_to_look = false;
}

void Player::put_inside(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2String box_name, p2vector<Box*> &boxes)
{
	int i;
	int b = 0;
	bool end = false;
	// taking item
	for (i = 0; i < items.get_things(); i++)
	{
		if (Compare(items[i]->get_name(), item_name))
		{
			if (items[i]->get_position() == player[0]->get_position() && items[i]->can_interact == true)
			{
				//taking box
				for (b = 0; b < boxes.get_things(); b++)
				{
					if (Compare(boxes[b]->get_name(), box_name))
					{
						if (boxes[b]->get_position() == player[0]->get_position())
						{
							// puting object into box
							if (boxes[b]->object_inside == NULL) // is box empty?
							{
								if (boxes[b]->is_opened == true) // is box opened?
								{
									if (items[i]->on_player == true) // the player has the object?
									{
										printf("You put the %s inside the ", item_name); //put inside
										printf("%s.\n", box_name);
										boxes[b]->object_inside = items[i];
										items[i]->can_interact = false;

										if (boxes[b]->on_player == true)
										{
											items[i]->on_player = false;
										}
										end = true; break;
									}
									else{ printf("You dont have the %s.\n", item_name); end = true; break; }
								}
								else{ printf("The %s is closed.\n", box_name); end = true; break; }
							}
							else{ printf("This %s already has an object inside.\n", box_name); end = true; break; }
						}
						else{ printf("You can't do this.\n"); end = true; break; }
					}
				}
				if (end = true){ break; }
			}
			else{ printf("You can't do that.\n"); break; }
		}
	}
	if (i == items.get_things()){ printf("I don't know what '%s' is.\n", item_name); }
	if (b == boxes.get_things()){ printf("You can't do this.\n"); }

	player[0]->want_to_look = false;
}

void Player::open_box(p2vector<Player*> &player, p2String box_name, p2vector<Box*> &boxes)
{
	// taking box
	int b;
	for (b = 0; b < boxes.get_things(); b++)
	{
		if (Compare(boxes[b]->get_name(), box_name))
		{
			if (boxes[b]->get_position() == player[0]->get_position())
			{
				if (boxes[b]->is_opened == false) // is box closed?
				{
					if (boxes[b]->opener->on_player == true) // is the opener on the player?
					{
						printf("You opened the %s.\n", box_name); // open box
						boxes[b]->is_opened = true;
						break;
					}
					else{ printf("It's locked.\n"); break; }
				}
				else{ printf("It's already opened.\n"); break; }
			}
			else{ printf("I can't do that.\n"); break; }
		}
	}
	if (b == boxes.get_things()){ printf("I don't know what '%s' is.\n", box_name); }

	player[0]->want_to_look = false;
}

void Player::close_box(p2vector<Player*> &player, p2String box_name, p2vector<Box*> &boxes)
{
	//taking box
	int b;
	for (b = 0; b < boxes.get_things(); b++)
	{
		if (Compare(boxes[b]->get_name(), box_name))
		{
			if (boxes[b]->get_position() == player[0]->get_position())
			{
				if (boxes[b]->is_opened == true) // is box opened?
				{
					printf("You closed the %s.\n", box_name); // close box
					boxes[b]->is_opened = false;
					break;
				}
				else{ printf("It's already closed.\n"); break; }
			}
			else{ printf("I can't do that.\n"); break; }
		}
	}
	if (b == boxes.get_things()){ printf("I don't know what '%s' is.\n", box_name); }

	player[0]->want_to_look = false;
}

void Player::take_outside(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Exit*> &exits, p2String item_name, p2String box_name, p2vector<Box*> &boxes)
{
	int i;
	int b = 0;
	bool end = false;
	// taking item
	for (i = 0; i < items.get_things(); i++)
	{
		if (Compare(items[i]->get_name(), item_name))
		{
			if (items[i]->get_position() == player[0]->get_position())
			{
				//taking box
				for (b = 0; b < boxes.get_things(); b++)
				{
					if (Compare(boxes[b]->get_name(), box_name))
					{
						if (boxes[b]->get_position() == player[0]->get_position())
						{
							// taking out object from the box
							if (boxes[b]->object_inside != NULL) // is box empty?
							{
								if (boxes[b]->is_opened == true) // is box opened?
								{
									if (Compare(boxes[b]->object_inside->get_name(), items[i]->get_name()))
									{
										printf("You take the %s from the ", item_name);
										printf("%s.\n", box_name); //take ouside
										boxes[b]->object_inside = NULL;
										items[i]->on_player = true;
										items[i]->can_interact = true;
										end = true; break;
									}
									else{ printf("You can't do that.\n"); end = true; break; }
								}
								else{ printf("The %s is closed.\n", box_name); end = true; break; }
							}
							else{ printf("This %s already has an object inside.\n", box_name); end = true; break; }
						}
						else{ printf("You can't do that.\n"); end = true; break; }
					}
				}
				if (end = true){ break; }
			}
			else{ printf("You can't do that.\n"); break; }
		}
	}
	if (i == items.get_things()){ printf("I don't know what '%s' is.\n", item_name); }
	if (b == boxes.get_things()){ printf("I can't do this.\n"); }
}

void Player::inventory(p2vector<Player*> &player, p2vector<Item*> &items, p2vector<Box*> &boxes)
{
	printf("<<<<INVENTORY>>>>\n\n");
	int i;
	int counter = 0;
	for (i = 0; i < items.get_things(); i++)
	{
		if (items[i]->on_player == true)
		{
			printf("-%s.\n", items[i]->get_name());
		}
		else{ counter++; }

	}
	int x;
	for (x = 0; x < boxes.get_things(); x++)
	{
		if (boxes[x]->on_player == true)
		{
			printf("-%s.\n", boxes[x]->get_name());
		}
		else{ counter++; }
	}
	if (items.get_things() + boxes.get_things() == counter){ printf("     empty\n"); }
	player[0]->want_to_look = false;
}

void Player::stats(p2vector<Player*> player)
{
	printf("<<<<STATS>>>>\n\n");
	printf("-Life: %d\n", player[0]->get_healt());
	printf("-Oxigent: %d\n", player[0]->get_oxigent());
}

void Player::equip(p2vector<Player*> &player, p2vector<Item*> &items, p2String item)
{
	int i;
	for (i = 0; i < items.get_things(); i++)
	{
		if (Compare(items[i]->get_name(), item))
		{
			if (items[i]->on_player == true)
			{
				if (items[i]->is_equiped == false)
				{
					if (items[i]->can_be_equiped == true)
					{
						items[i]->is_equiped = true;
						items[i]->can_interact = false;
						printf("You equiped the %s.\n", item);
						break;
					}
					else{ printf("You can't equip this item.\n"); break; }
				}
				else{ printf("You aleady equiped this item.\n"); break; }
			}
			else{ printf("You can't do that.\n"); break; }
		}
	}
	player[0]->want_to_look = false;
}

void Player::unequip(p2vector<Player*> &player, p2vector<Item*> &items, p2String item)
{
	int i;
	for (i = 0; i < items.get_things(); i++)
	{
		if (Compare(items[i]->get_name(), item))
		{
			if (items[i]->on_player == true)
			{
				if (items[i]->is_equiped == true)
				{
					if (items[i]->can_be_equiped == true)
					{
						items[i]->is_equiped = false;
						items[i]->can_interact = true;
						printf("You unequiped the %s.\n", item);
						break;
					}
					else{ printf("You can't unequip this item.\n"); break; }
				}
				else{ printf("You aleady unequiped this item.\n"); break; }
			}
			else{ printf("You can't do that.\n"); break; }
		}
	}
	player[0]->want_to_look = false;
}

void Player::help(p2vector<Player*> player)
{
	printf("<<<<HELP>>>>\n\n");
	printf("Basic commands:\n\n-(north/south/east/west) or (go north/go south...) or (n/s..)\n-look\n-take 'object'\n-drop 'object'\n-use 'object'\n-equip 'object'\n-open 'object'\n-put 'object' inside 'object'\n-take 'object' from 'object\n-open door\n-close door\n-inventory\n-stats\n-quit");
	printf("\n");
	player[0]->want_to_look = false;
}