#include <stdio.h>
#include "world.h"

#define NUMBER_OF_ROOMS 22
#define NUMBER_OF_EXITS 45
#define NUMBER_OF_ITEMS 7
#define NUMBER_OF_BOXES 1
#define NUMBER_OF_ENEMIES 1

World::World()
{
	// Create World-----------------------------

	//Player
	Player* player = new Player("Hero", "You don't know who you are", NULL, 0); players.push_back(player);

	//Enemies
	Enemy* crazy = new Enemy("CrazyMan", "Crazy man that also woke up as you.\n", NULL, 17); enemies.push_back(crazy);

	// Items
	Item* key = new Item("key", "There is a KEY hanging on the wall", 2, NULL, false, true, false); items.push_back(key); //0
	Item* pass = new Item("pass", "There is something on the BOX", 1, NULL, false, false, false); items.push_back(pass); //1
	Item* lantern = new Item("lantern", "There is a LANTERN on the ground near the stairs", 0, NULL, true, true, false); items.push_back(lantern); //2
	Item* seasuit = new Item("seasuit", "There is a SEASUIT placed on a cylinder", 2, NULL, false, true, true);	items.push_back(seasuit); //3
	Item* metalbar = new Item("bar", "There is a BAR made of metall on the floor", 11, NULL, false, true, true); items.push_back(metalbar); //4
	Item* masterpass = new Item("masterpass", "There is a tiny MASTERPASS on the ground", 12, NULL, false, true, false); items.push_back(masterpass); //5
	Item* superseasuit = new Item("superseasuit", "There is a SUPERSEASUIT", 16, NULL, false, true, true); items.push_back(superseasuit); //6
	Item* tank = new Item("tank", "There is a oxigent on the ground TANK", 11, NULL, false, false, false); items.push_back(tank); //6


	//Containers
	Box* box = new Box("box", "There is a BOX on a table. In the top its written: 'Emergency pass'", 1, pass, false, key); boxes.push_back(box);
	
	// Rooms
	Room* bodies = new Room("BODIES", "You are sorrounded by beds full of people's bodies connected into \na wierd machines", 0); rooms.push_back(bodies);//0
	Room* bodiesup = new Room("BODIES<UP>", "You are on the top floor", 1);	rooms.push_back(bodiesup);//1
	Room* bodiesdown = new Room("BODIES<DOWN>", "You are on the bottom floor.", 2);	 rooms.push_back(bodiesdown);//2
	Room* elevator = new Room("ELEVATOR", "It's a big metal elevator that goes to the deepness", 3); rooms.push_back(elevator);//3
	Room* entrancesouth = new Room("BUILDING<SOUTH>", "It's a big building.\nThere is a door to enter but the pass lector seems broken", 4); rooms.push_back(entrancesouth);//4
	Room* entranceeast = new Room("BUILDING<EAST>", "It's a big building.\nThere are stairs to the top floor", 5); rooms.push_back(entranceeast);//5
	Room* entranceup = new Room("BUILDING<UP>", "It's a big building.\nYou are on the top floor of the building", 6); rooms.push_back(entranceup);//6
	Room* entrancenorth = new Room("BUILDING<NORTH>", "It's a big building", 7); rooms.push_back(entrancenorth);//7
	Room* entrancewest = new Room("BUILDING<WEST>", "It's a big building", 8); rooms.push_back(entrancewest);//8
	Room* room1 = new Room("ROOM 1", "This furniture of this room is completly destroyed", 9); rooms.push_back(room1);//9
	Room* room2 = new Room("ROOM 2", "It's a very dark room, you can't see anithing", 10);	rooms.push_back(room2); //10
	Room* lightsroom = new Room("LIGHTS ROOM", "It's a big room with some switches and electircity warnings on the screens.\n In this place is controlled all the electricity of.\n the base", 11);				 rooms.push_back(lightsroom);	  //11
	Room* holeroom = new Room("HOLE ROOM", "It's very dark down here", 12); rooms.push_back(holeroom);//12
	Room* passage1 = new Room("PASSAGE1", "It's a long passage", 13); rooms.push_back(passage1);//13
	Room* passage2 = new Room("PASSAGE2", "It's a long passage", 14); rooms.push_back(passage2);//14
	Room* controlroom = new Room("CONTROL ROOM", "It's full of shining lights and wierd buttons.\n Mabye you can activate something usefull here", 15);											 rooms.push_back(passage1);		  //15
	Room* deeppreparation = new Room("DEEP PREPARATION", "It's a small room with recipents full of seasuits", 16); rooms.push_back(deeppreparation);//16
	Room* deepstation = new Room("DEEP STATION", "It's super dark down here", 17); rooms.push_back(deepstation);//17
	Room* path1 = new Room("PATH<1>", "It's a long path illuminated by lampposts", 18); rooms.push_back(path1);//18
	Room* path2 = new Room("PATH<2>", "It's a long path illuminated by lampposts", 19); rooms.push_back(path2);//19
	Room* lookout = new Room("LOOKOUT", "Small elevation in front of a precipice.\n You have really cool views right here", 20); rooms.push_back(lookout);//20
	Room* escaperoom = new Room("EMERGENCY ESCAPE ROOM", "It's a very big building with a train waiting", 21); rooms.push_back(escaperoom);//21


	// Exits
	// Bodies----
	Exit* bodies_south = new Exit(bodies, elevator, "south", pass, false); exits.push_back(bodies_south); //1
	Exit* bodies_up = new Exit(bodies, bodiesup, "up", NULL, true); exits.push_back(bodies_up);  //2
	Exit* bodies_up_down = new Exit(bodiesup, bodies, "down", NULL, true); exits.push_back(bodies_up_down);  //3
	Exit* bodies_down = new Exit(bodies, bodiesdown, "down", NULL, true); exits.push_back(bodies_down);  //4
	Exit* bodies_down_up = new Exit(bodiesdown, bodies, "up", NULL, true); exits.push_back(bodies_down_up);  //5

	// Elevator---
	Exit* elevator_west = new Exit(elevator, bodies, "west", key, true); exits.push_back(elevator_west);  //6
	Exit* elevator_north = new Exit(elevator, entrancesouth, "north", NULL, true);  exits.push_back(elevator_north);  //7
	Exit* elevator_east = new Exit(elevator, passage2, "east", masterpass, false);  exits.push_back(elevator_east);  //8
	Exit* elevator_south = new Exit(elevator, deeppreparation, "south", masterpass, false);  exits.push_back(elevator_south);  //9

	// Building--
	Exit* building_south_north = new Exit(entrancesouth, holeroom, "north", metalbar, false); exits.push_back(building_south_north);  //10
	Exit* building_south_south = new Exit(entrancesouth, elevator, "south", NULL, true); exits.push_back(building_south_south);  //11
	Exit* building_south_east = new Exit(entrancesouth, entranceeast, "east", NULL, true); exits.push_back(building_south_east);  //12
	Exit* building_south_west = new Exit(entrancesouth, entrancewest, "west", NULL, true); exits.push_back(building_south_west);  //13
	Exit* building_west_south = new Exit(entrancewest, entrancesouth, "south", NULL, true); exits.push_back(building_west_south);  //14
	Exit* building_west_north = new Exit(entrancewest, entrancenorth, "north", NULL, true); exits.push_back(building_west_north);  //15
	Exit* building_north_west = new Exit(entrancenorth, entrancewest, "west", NULL, true); exits.push_back(building_north_west);  //16
	Exit* building_north_east = new Exit(entrancenorth, entranceeast, "east", NULL, true); exits.push_back(building_north_east);  //17
	Exit* building_east_north = new Exit(entranceeast, entrancenorth, "north", NULL, true); exits.push_back(building_east_north);  //18
	Exit* building_east_south = new Exit(entranceeast, entrancesouth, "south", NULL, true); exits.push_back(building_east_south);  //19
	Exit* building_east_up = new Exit(entranceeast, entranceup, "up", NULL, true); exits.push_back(building_east_up);  //20

	Exit* building_up_north = new Exit(entranceup, room1, "north", masterpass, false); exits.push_back(building_up_north); //21
	Exit* building_up_down = new Exit(entranceup, entranceeast, "down", NULL, true); exits.push_back(building_up_down); //22
	Exit* building_up_west = new Exit(entranceup, room2, "west", NULL, true); exits.push_back(building_up_west); //23
	Exit* building_room2_east = new Exit(room2, entranceup, "east", NULL, true); exits.push_back(building_room2_east); //24
	Exit* building_room1_south = new Exit(room1, entranceup, "south", NULL, true); exits.push_back(building_room1_south); //25
	Exit* building_room1_west = new Exit(room1, lightsroom, "west", NULL, true); exits.push_back(building_room1_west); //26
	Exit* building_lightsroom = new Exit(lightsroom, room1, "east", NULL, true); exits.push_back(building_lightsroom); //27

	// Tunels--
	Exit* hole_room = new Exit(holeroom, passage1, "south", NULL, false); exits.push_back(hole_room); //28
	Exit* passage2_west = new Exit(passage2, elevator, "west", masterpass, false); exits.push_back(passage2_west); //29
	Exit* passage1_north = new Exit(passage1, holeroom, "north", NULL, true); exits.push_back(passage1_north); //30
	Exit* passage1_west = new Exit(passage1, passage2, "west", NULL, true); exits.push_back(passage1_west); //31
	Exit* passage1_south = new Exit(passage1, controlroom, "south", NULL, true); exits.push_back(passage1_south); //32
	Exit* passage2_east = new Exit(passage2, passage1, "east", NULL, true); exits.push_back(passage2_east); //33


	// Deep preparation--
	Exit* deeppreparation_west = new Exit(deeppreparation, elevator, "west", masterpass, false); exits.push_back(deeppreparation_west); //34
	Exit* controlroom_north = new Exit(controlroom, passage1, "north", NULL, true); exits.push_back(controlroom_north); //35
	Exit* controlroom_south = new Exit(controlroom, deeppreparation, "south", NULL, true); exits.push_back(controlroom_south); //36
	Exit* deeppreparation_north = new Exit(deeppreparation, controlroom, "north", NULL, true); exits.push_back(deeppreparation_north); //37

	//Deep--
	Exit* deeppstation_south = new Exit(deepstation, path1, "south", NULL, true); exits.push_back(deeppstation_south); //38
	Exit* path1_north = new Exit(path1, deepstation, "north", NULL, true); exits.push_back(path1_north); //39
	Exit* path1_south = new Exit(path1, path2, "south", NULL, true); exits.push_back(path1_south); //40
	Exit* path1_west = new Exit(path1, lookout, "west", NULL, true); exits.push_back(path1_west); //41
	Exit* look_out = new Exit(lookout, path1, "east", NULL, true); exits.push_back(look_out); //42
	Exit* path2_north = new Exit(path2, path1, "north", NULL, true); exits.push_back(path2_north); //43
	Exit* path2_south = new Exit(path2, escaperoom, "south", NULL, true); exits.push_back(path2_south); //44
	Exit* escape_room = new Exit(escaperoom, path2, "north", NULL, true); exits.push_back(escape_room); //45

	// First text
	/*printf("Welcome to the UNDERWATER ZORK, you are going to start a new adventure.\nIf you need help with the commands just type help on the commands input.\n");
	printf("------------------------------------------------------------------------\n\n");
	printf("Suddenly you wake up.\n"); getchar(); 
	printf("You look arround\n"); getchar();
	printf("You don't know where you are.\n"); getchar();
	printf("There is a screen at your bed that prints: energy failure.\n"); getchar();
	printf("You need to know what's happening.\n"); getchar();*/
}  

World::~World()
{
	delete players[0];
	for (int i = 0; i < NUMBER_OF_ROOMS; i++)
	{
		rooms[i] = nullptr;
		delete rooms[i];
	}
	for (int x = 0; x < NUMBER_OF_EXITS; x++)
	{
		exits[x] = nullptr;
		delete exits[x];
	}
	for (int y = 0; y < NUMBER_OF_ITEMS; y++)
	{
		items[y] = nullptr;
		delete items[y];
	}
	for (int z = 0; z < NUMBER_OF_BOXES; z++)
	{
		boxes[z] = nullptr;
		delete boxes[z];
	}

	for (int e = 0; e < NUMBER_OF_ENEMIES; e++)
	{
		enemies[e] = nullptr;
		delete enemies[e];
	}
}

