#include "input.h"
#include <stdio.h>
#include "world.h"

void Tokenize(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits, p2vector<Item*> &items, p2vector<Box*> &boxes)
{
	char tmp[30];
	unsigned int counter = 0;
	unsigned int args = 1;

	char argument1[30];
	char argument2[30];
	char argument3[30];
	char argument4[30];

	printf("\n> ");
	scanf_s(" %[^\n]s", tmp, 30);
	printf("\n");
	
	// Taking argument 1
	for (int i = 0; tmp[counter] != '\0'; i++)
	{
		argument1[i] = tmp[counter];
		counter++;

		if (tmp[counter] == ' ')
		{
			i++;
			argument1[i] = '\0';
			counter++;
			args++;
			break;
		}
		if (tmp[counter] == '\0')
		{
			i++;
			argument1[i] = '\0';
		}
	}

	// Taking argument 2
	if (args == 2)
	{
		for (int i = 0; tmp[counter] != '\0'; i++)
		{
			argument2[i] = tmp[counter];
			counter++;
			
			if (tmp[counter] == ' ')
			{
				i++;
				argument2[i] = '\0';
				counter++;
				args++;
				break;
			}
			if (tmp[counter] == '\0')
			{
				i++;
				argument2[i] = '\0';
			}
		}
	}
	else{ argument2[0] = 'E'; argument2[1] = '\0'; }

	// Taking argument 3
	if (args == 3)
	{
		for (int i = 0; tmp[counter] != '\0'; i++)
		{
			argument3[i] = tmp[counter];
			counter++;

			if (tmp[counter] == ' ')
			{
				i++;
				argument3[i] = '\0';
				counter++;
				args++;
				break;
			}
			if (tmp[counter] == '\0')
			{
				i++;
				argument3[i] = '\0';
			}
		}
	}
	else{ argument3[0] = 'E'; argument3[1] = '\0'; }

	// Taking argument 4
	if (args == 4)
	{
		for (int i = 0; tmp[counter] != '\0'; i++)
		{
			argument4[i] = tmp[counter];
			counter++;

			if (tmp[counter] == ' ')
			{
				i++;
				argument4[i] = '\0';
				counter++;
				args++;
				break;
			}
			if (tmp[counter] == '\0')
			{
				i++;
				argument4[i] = '\0';
			}
		}
	}
	else{ argument4[0] = 'E'; argument4[1] = '\0'; }

	p2String a1 = argument1; p2String a2 = argument2; p2String a3 = argument3; p2String a4 = argument4;

	Inputs(player, a1, a2, a3, a4, rooms, exits, args, items, boxes);
}

void Inputs(p2vector<Player*> &player, p2String a1, p2String a2, p2String a3, p2String a4, p2vector<Room*> &rooms, p2vector<Exit*> &exits, int args, p2vector<Item*> &items, p2vector<Box*> &boxes)
{
	switch (args)
	{
	case 1:
		if (Compare(a1, "north") || Compare(a1, "n"))
		{
			player[0]->move(rooms, player, exits, "north", items, boxes);
		}
		else if (Compare(a1, "south") || Compare(a1, "s"))
		{
			player[0]->move(rooms, player, exits, "south", items, boxes);
		}
		else if (Compare(a1, "east") || Compare(a1, "e"))
		{
			player[0]->move(rooms, player, exits, "east", items, boxes);
		}
		else if (Compare(a1, "west") || Compare(a1, "w"))
		{
			player[0]->move(rooms, player, exits, "west", items, boxes);
		}
		else if (Compare(a1, "up") || Compare(a1, "u"))
		{
			player[0]->move(rooms, player, exits, "up", items, boxes);
		}
		else if (Compare(a1, "down") || Compare(a1, "d"))
		{
			player[0]->move(rooms, player, exits, "down", items, boxes);
		}
		else if (Compare(a1, "look") || Compare(a1, "l"))
		{
			player[0]->look(rooms, player, exits, items, boxes);
		}
		else if (Compare(a1, "quit") || Compare(a1, "q"))
		{
			player[0]->end = true;
		}
		else if (Compare(a1, "inventory") || Compare(a1, "i"))
		{
			player[0]->inventory(player, items, boxes);
		}
		else if (Compare(a1, "stats") || Compare(a1, "s"))
		{
			player[0]->stats(player);
		}
		else if (Compare(a1, "help") || Compare(a1, "h"))
		{
			player[0]->help(player);
		}
		else{ printf("I can't understand this command.\n"); }
		break;
	case 2:
		if (Compare(a1, "open"))
		{
			if (Compare(a2, "door"))
			{
				player[0]->open_door(player, rooms, exits);
			}
			else
			{
				player[0]->open_box(player, a2, boxes);
			}
		}
		else if (Compare(a1, "close"))
		{
			if (Compare(a2, "door"))
			{
				player[0]->close_door(player, rooms, exits);
			}
			else
			{
				player[0]->close_box(player, a2, boxes);
			}
		}
		else if (Compare(a1, "go"))
		{
			if (Compare(a2, "north") || Compare(a2, "n"))
			{
				player[0]->move(rooms, player, exits, "north", items, boxes);
			}
			if (Compare(a2, "south") || Compare(a2, "s"))
			{
				player[0]->move(rooms, player, exits, "south", items, boxes);
			}
			if (Compare(a2, "east") || Compare(a2, "e"))
			{
				player[0]->move(rooms, player, exits, "east", items, boxes);
			}
			if (Compare(a2, "west") || Compare(a2, "w"))
			{
				player[0]->move(rooms, player, exits, "west", items, boxes);
			}
			if (Compare(a2, "up") || Compare(a2, "u"))
			{
				player[0]->move(rooms, player, exits, "up", items, boxes);
			}
			if (Compare(a2, "down") || Compare(a2, "d"))
			{
				player[0]->move(rooms, player, exits, "down", items, boxes);
			}
		}
		else if (Compare(a1, "equip"))
		{
			player[0]->equip(player, items, a2);
		}
		else if (Compare(a1, "take"))
		{
			if (Compare(a2, "tank"))
			{
				if (player[0]->get_position() == 11)
				{
					int i;
					for (i = 0; i < items.get_things(); i++)
					{
						if (Compare(items[i]->get_name(), "tank"))
						{
							if (items[i]->can_interact == true)
							{
								printf("Good!, you found an oxigent tank.\nNow you can return to finally escape from this place.\n");
								items[i]->on_player = true;
								items[i]->can_interact = false;
								player[0]->broken_tank = false;
								break;
							}
						}
					}
				}
				else{ printf("You can't do that.\n"); }
			}
			else
			{
				player[0]->take_object(player, items, exits, a2, boxes);
			}
		}
		else if (Compare(a1, "drop"))
		{
			player[0]->drop_object(player, items, exits, a2, boxes);
		}
		else if (Compare(a1, "unequip"))
		{
			player[0]->unequip(player, items, a2);
		}
		else if (Compare(a1, "use"))
		{
			if (Compare(a2, "elevator"))
			{
				if (player[0]->get_position() == 3)
				{
					if (player[0]->elevator == true)
					{
						player[0]->set_position(17); player[0]->want_to_look = true; player[0]->want_to_input = false;
					}
					else{ printf("The elevator is turned off"); }
				}
				else if (player[0]->get_position() == 17)
				{
					player[0]->set_position(3); player[0]->want_to_look = true; player[0]->want_to_input = false;
				}
				else{ printf("You can't do that.\n"); }

			}
			else if(Compare(a2, "train"))
			{
				if (player[0]->get_position() == 21)
				{
					if (player[0]->broken_tank == false)
					{
						printf("You finally made it.\n"); getchar();
						printf("You go inside the train.\n"); getchar();
						printf("The train starts moving.\n"); getchar();
						printf("You escaped! Congratulations.\n\n"); getchar();
						printf("Made by Guillem Sunyer"); getchar();
						player[0]->end = true;
					}
					else{ printf("You need another oxigent tank to use the train.\n"); }
				}
				else{ printf("You can't do that.\n"); }
			}
			else
			{
				player[0]->use_object(player, items, exits, a2, boxes);
			}
		}
		else{ printf("I can't understand this command.\n");; }
		break;
	case 3:
		if (Compare(a1, "turn"))
		{
			if (Compare(a2, "on"))
			{
				if (Compare(a3, "electricity"))
				{
					if (player[0]->get_position() == 11)
						player[0]->light = true;
					else
						printf("You can't do that.\n");
				}
				else if (Compare(a3, "elevator"))
				{
					if (player[0]->light == true)
					{
						if (player[0]->get_position() == 15)
							player[0]->elevator = true;
						else
							printf("You can't do that.\n");
					}
					else
						printf("You need to turn on the elecricity.\n");
				}
				else
					printf("I can't understand this command.\n");
			}
			else
				printf("I can't understand this command.\n");
		}
		else{ printf("I can't understand this command.\n"); }
		break;
	case 4:
		if (Compare(a1, "put"))
		{
			if (Compare(a3, "inside"))
			{
				player[0]->put_inside(player, items, exits, a2, a4, boxes);
			}
		}
		else if (Compare(a1, "take"))
		{
			if (Compare(a3, "from"))
			{
				player[0]->take_outside(player, items, exits, a2, a4, boxes);
			}
		}
		else{ printf("I can't understand this command.\n"); }
		break;
	default:
		printf("I can't understand this command.\n");
		player[0]->want_to_look = false;
		break;
	}
}

bool Compare(p2String a, p2String b)
{
	if (a == b)
		return true;
	else 
		return false;
}

void Check(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits, p2vector<Item*> &items, p2vector<Box*> &boxes, p2vector<Enemy*> enemies)
{
	//doors
	if (exits[28]->opened == true)
	{
		exits[7]->opened = true;
	}
	if (exits[33]->opened == true)
	{
		exits[8]->opened = true;
	}

	//fast movement
	if (player[0]->get_position() == 10)
	{
		player[0]->set_position(12);
		printf("You can't see anithing, you walk and you fall into a hole on the room.\n\n");
		player[0]->want_to_look = true;
		player[0]->want_to_input = false;
	}

	//dead end 1
	else if (player[0]->get_position() == 3)
	{
		for (int i = 0; i < items.get_things(); i++)
		{
			if (Compare(items[i]->get_name(), "seasuit"))
			{
				if (items[i]->is_equiped == false)
				{
					printf("\n!!!!!!!You die drowned by water.!!!!!!!\nDead end.\n");
					player[0]->end = true;
				}
			}
		}
	}

	//dead end 2
	else if (player[0]->get_position() == 13)
	{
		for (int i = 0; i < items.get_things(); i++)
		{
			if (Compare(items[i]->get_name(), "lantern"))
			{
				if (items[i]->is_used == false)
				{
					printf("\n!!!!!!!You can't see anithing.!!!!!!!\nSomebody kills you from the back.\nDead end.\n");
					player[0]->end = true;
				}
			}
		}
	}

	//dead end 3
	else if (player[0]->get_position() == 17)
	{
		for (int i = 0; i < items.get_things(); i++)
		{
			if (Compare(items[i]->get_name(), "superseasuit"))
			{
				if (items[i]->is_equiped == false)
				{
					printf("\n!!!!!!!The preasure of the water kills you.!!!!!!!\nDead end.\n");
					player[0]->end = true;
				}
			}
		}
	}
	//dead end 4
	else if (player[0]->get_oxigent() <= 0)
	{
		printf("\n!!!!!!!You don't have oxigent!!!!!!!\nDead end.\n");
		player[0]->end = true;
	}

	//fight
	else if (player[0]->get_position() == 17 && enemies[0]->is_dead == false)
	{
		printf("You feel like someone is following you.\n"); getchar();
		printf("You turn arround.\n"); getchar();
		printf("And then you see it, its a man that's looking at you.\n"); getchar();
		printf("He has a wierd eyes. He start running at you.\n"); getchar();
		printf("You are prepared to atack.\n"); getchar();

		int i;
		while (enemies[0]->get_healt() > 0 || player[0]->get_healt() > 0)
		{
			for (i = 0; i < items.get_things(); i++)
			{
				if (Compare(items[i]->get_name(), "bar"))
				{
					break;
				}
			}
			printf("The man hits you and deals you 20 of damage.\n"); player[0]->substract_health(20); getchar();
			if (items[i]->is_equiped == true)
			{
				printf("You hit the man with the bar and deal 40 of damage"); enemies[0]->substract_healt(40); getchar();
			}
			else{ printf("You hit the man with the bar and deal 25 of damage"); enemies[0]->substract_healt(25); getchar(); }
		}
		printf("You finally killed him.\n"); getchar();
		enemies[0]->is_dead = true;
		if (player[0]->get_healt() == 80)
		{
			printf("Oh no!, in the fight your oxigent TANK was damaged, you are losing oxigent.\nYou need to find another TANK very fast.\n");
			player[0]->broken_tank = true;
			for (i = 0; i < items.get_things(); i++)
			{
				if (Compare(items[i]->get_name(), "tank"))
				{
					items[i]->can_interact = true;
					break;
				}
			}
		}
	}
}