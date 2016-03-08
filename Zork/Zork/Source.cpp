#include <stdio.h>
#include <stdlib.h>
#include "Head.h"

struct Rooms
{
	char name[10];
	char north[10];
	char south[10];
	char east[10];
	char west[10];
	char top[10];
	char bot[10];
	char text[50];
	char northText[10];
	char southText[10];
	char eastText[10];
	char westText[10];
};

int main()
{
	//Rooms Allocation
	// T = text   E = empty
	Rooms* Room[20];	 //name		n		s		e	   w     top        bot        t
	Room[0] = new Rooms{"BodiesR", "T", "Elevator", "T", "T", "TopFloor", "BotFloor", "text", "northText", "southText", "eastText", "westText"}; //BodiesR
	Room[1] = new Rooms{ "TopFloor", "T", "E", "E", "T", "E", "BodiesR", "text", "northText", "southText", "eastText", "westText" }; //BodiesR - TopFloor
	Room[2] = new Rooms{ "DownFloor", "T", "E", "E", "T", "BodiesR", "E", "text", "northText", "southText", "eastText", "westText" }; //BodiesR - BotFloor
	Room[3] = new Rooms{ "Elevator", "Kitchen", "Passage2", "Entrance", "T", "E", "DeepStat","text" ,"northText", "southText", "eastText", "westText" }; //Elevator
	Room[4] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" }; //Entrance
	Room[5] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[6] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[7] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[8] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[9] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[10] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[11] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[12] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[13] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[14] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[15] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[16] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[17] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[18] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[19] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };
	Room[10] = new Rooms{ "TopFloor", "T", "E", "E", "T", "Kitchen", "E", "E", "northText", "southText", "eastText", "westText" };


	//variables

		//player
		int position = 0;

		//gameStats
		bool end = false;
		bool endLoop = false;

		//input
		char input;

		//inventario
		bool key = false;
	
		
	printf("Welcome to the Underwater Zork\n\n");
		
	//----------loop----------
	while (end == false)
	{
		//printing
		printf("You are in %s\n%s\n", Room[position]->name, Room[position]->text);

		//movePosition
		while (endLoop == false)
		{
			scanf_s(" %c", &input, 1);
			switch (input)
			{
			case 'n':
				if (*Room[position]->north == 'E'){ printf("You can't go this direction"); break; } //Empty
				else if (*Room[position]->north == 'T'){ printf("%s", Room[position]->northText); }
				for (int i = 0; i < 10; i++)
				{
					if (compareNames(Room[position]->north, Room[i]->name))
					{
						position = i;
						endLoop = true;
					}
				}
				break;
			case 's':
				if (*Room[position]->south == 'E'){ printf("You can't go this direction"); break; } //Empty
				else if (*Room[position]->south == 'T'){ printf("%s", Room[position]->southText); }
				for (int i = 0; i < 10; i++)
				{
					if (compareNames(Room[position]->south, Room[i]->name))
					{
						position = i;
						endLoop = true;
					}
				}
				break;
			case 'e':
				if (*Room[position]->east == 'E'){ printf("You can't go this direction"); break; } //Empty
				else if (*Room[position]->east == 'T'){ printf("%s", Room[position]->eastText); }
				for (int i = 0; i < 10; i++)
				{
					if (compareNames(Room[position]->east, Room[i]->name))
					{
						position = i;
						endLoop = true;
					}
				}
				break;
			case 'w':
				if (*Room[position]->west == 'E'){ printf("You can't go this direction"); break; } //Empty
				else if (*Room[position]->west == 'T'){printf("%s", Room[position]->westText); }
				for (int i = 0; i < 10; i++)
				{
					if (compareNames(Room[position]->west, Room[i]->name))
					{
						position = i;
						endLoop = true;
					}
				}
				break;
			case 'u':
				if (*Room[position]->top == 'E'){ printf("You can't go this direction"); break; } //Empty
				for (int i = 0; i < 10; i++)
				{
					if (compareNames(Room[position]->top, Room[i]->name))
					{
						position = i;
						endLoop = true;
					}
				}
				break;
			case 'd':
				if (*Room[position]->bot == 'E'){ printf("There is a wall right here"); break; }
				for (int i = 0; i < 10; i++)
				{
					if (compareNames(Room[position]->bot, Room[i]->name))
					{
						position = i;
						endLoop = true;
					}
				}
				break;
			}
		}
		endLoop = false;
	}
	//----------loop----------

	//deleting
	delete Room;

	getchar();
	return 0;
}

