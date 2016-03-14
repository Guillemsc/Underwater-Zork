#include "Head.h"
#include <iostream>
#include <string.h>

using namespace std;

//RoomsCreation
Room *Rooms = new Room[21];

void StartRooms(void)
{
	//RoomsDirections
	//N-S-E-W-U-D
	//E = empty; T = some text or special thing
	
	Rooms[0].GetRooms("Bodies", "T", "T", "T", "E", "BodiesUp", "BodiesDown"); //Bodies
	Rooms[1].GetRooms("BodiesUp","T","E","T","T","E","Bodies" ); //BodiesUp
	Rooms[2].GetRooms("BodiesDown", "T", "T", "T", "E", "Bodies", "E"); //BodiesDown
	Rooms[3].GetRooms("Elevator", "Bodies", "Passage1", "EntranceS", "E", "E", "DeepStation"); //Elevator
	Rooms[4].GetRooms("EntranceS", "T", "E", "Stairs", "Elevator", "E", "E"); //EntranceS
	Rooms[5].GetRooms("Stairs", "EntranceN", "EntranceS", "E", "T", "E", "E"); //Stairs
	Rooms[6].GetRooms("EntranceN", "E", "E", "Stairs", "EntranceW", "E", "E"); //EntranceN
	Rooms[7].GetRooms("EntranceW", "EntranceN", "EntranceS", "E", "E", "E", "E"); //EntranceW
	Rooms[8].GetRooms("Room2", "E", "E", "E", "E", "E", "HoleRoom"); //Room2
	Rooms[9].GetRooms("Room1", "E", "E", "Stairs", "LightRoom", "E", "E"); //Room1
	Rooms[10].GetRooms("LightRoom", "T", "E", "Room1", "T", "E", "E"); //LightRoom
	Rooms[11].GetRooms("HoleRoom", "E", "Passage1", "E", "E", "E", "E"); //HoleRoom
	Rooms[12].GetRooms("Passage1", "HoleRoom", "T", "E", "E", "E", "E"); //Passage1
	Rooms[13].GetRooms("Passage2", "E", "E", "T", "Elevator", "E", "E"); //Passage2
	Rooms[14].GetRooms("ControlRoom", "T", "DeepPreparation", "E", "T", "E", "E"); //ControlRoom
	Rooms[15].GetRooms("DeepPreparation", "ControlRoom", "T", "E", "Elevator", "E", "E"); //DeepPreparation
	Rooms[16].GetRooms("DeepStation", "T", "Path1", "E", "E", "T", "E"); //DeepStation
	Rooms[17].GetRooms("Path1", "DeepStation", "Path2", "E", "LookOut", "E", "E"); //Path1
	Rooms[18].GetRooms("LookOut", "Path1", "Path2", "E", "E", "E", "E"); //LookOut
	Rooms[19].GetRooms("Path2", "T", "T", "E", "E", "E", "E"); //Path2
	Rooms[20].GetRooms("EmergencyEscapeRoom", "E", "E", "E", "E", "E", "E"); //EmergencyScapeRoom
	
	//InitialPrinting
	printf("WELCOME TO THE UNDERWATER ZORK\n\nYou are goin to start a new adventure.\nIf in any case you need help about the comands, just type 'help'.\n");
	printf("-----------------------------\n\n");
	printf("You wake up from a bed.\nYou don't know where you are...\nYou look through a window and you only see water. Is this a dream?\nI need to find answers.\n");

}

bool DoThings(char input[20], int &printNum, int &position, bool &wantToSetPos, bool &textNorth, bool &textSouth, bool &textEast, bool &textWest, bool &printRoom, bool &pass, bool &lantern, bool &key, bool &seaSuit, bool &metalBar, bool &oxigenTank, bool &masterPass, bool &reenforcedSeasuit, bool &electricity, bool &robot, bool &elevator, bool &enemy, bool &gate)
{
	bool end = false;

//Print-------------
	if (printRoom)
	{
		PrintPlaces(position, printRoom, wantToSetPos, textNorth, textSouth, textEast, textWest, pass, lantern, key, seaSuit, metalBar, oxigenTank, masterPass, reenforcedSeasuit, electricity, end, robot, elevator, enemy, gate);
	}
	
//DeadEnd-----------
	if (end)
	{
		delete[] Rooms; //free Rooms class
		return true;
	}

//Move--------------
	if (wantToSetPos){
		switch (InputWords(input)) //Unify Input
		{
		case 'n': //north
			if (!(strcmp(Rooms[position].north, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].north, "T"))){ textNorth = true; printRoom = true; }
			for (int n = 0; n < 21; n++){ if (!(strcmp(Rooms[position].north, Rooms[n].name))){ position = n; printRoom = true; break; } }
			break;
		case 's': //south
			if (!(strcmp(Rooms[position].south, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].south, "T"))){ textSouth = true;  printRoom = true; }
			for (int s = 0; s < 21; s++){ if (!(strcmp(Rooms[position].south, Rooms[s].name))){ position = s; printRoom = true; break; } }
			break;
		case 'e': //east
			if (!(strcmp(Rooms[position].east, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].east, "T"))){ textEast = true; printRoom = true; }
			for (int e = 0; e < 21; e++){ if (!(strcmp(Rooms[position].east, Rooms[e].name))){ position = e; printRoom = true; break; } }
			break;
		case 'w': //west
			if (!(strcmp(Rooms[position].west, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].west, "T"))){ textWest = true; printRoom = true; }
			for (int w = 0; w < 21; w++){ if (!(strcmp(Rooms[position].west, Rooms[w].name))){ position = w; printRoom = true; break; } }
			break;
		case 'u': //up
			if (!(strcmp(Rooms[position].up, "E"))){ printf("You can't go there\n"); printRoom = false; }
			for (int u = 0; u < 21; u++){ if (!(strcmp(Rooms[position].up, Rooms[u].name))){ position = u; printRoom = true; break; } }
			break;
		case 'd': //down
			if (!(strcmp(Rooms[position].down, "E"))){ printf("You can't go there\n"); printRoom = false; }
			for (int d = 0; d < 21; d++){ if (!(strcmp(Rooms[position].down, Rooms[d].name))){ position = d; printRoom = true; break; } }
			break;
		case 'i': //inventory
			PrintObjects(position, pass, lantern, key, seaSuit, metalBar, oxigenTank, masterPass, reenforcedSeasuit);
			break;
		case 'h': //help
			PrintHelp();
			break;
		case 'l': //look
			PrintPlaces(position, printRoom, wantToSetPos, textNorth, textSouth, textEast, textWest, pass, lantern, key, seaSuit, metalBar, oxigenTank, masterPass, reenforcedSeasuit, electricity, end, robot, elevator, enemy, gate);
			break;
		case 'q': //quit
			delete[] Rooms; //free Rooms class
			return true;
		case'o': //open door
			if ((position == 0 || position == 3) && pass)
			{gate = true; printf("Door opened.\n");}
			else{ printf("You can't do this now.\n"); } 
			printRoom = false;
			break;
		case 'c': //close door
			if (position == 0 || position == 3 && pass)
			{gate = false; printf("Door closed.\n");}
			else{ printf("You can't do this now"); }
			printRoom = false;
			break;
		default: //wrong command
			printf("\nI cant recognize this command.\n"); printRoom = false;
			break;
		}
	}
	//returns to continue playing
	return false;
}

//Input-------------
char InputWords(char input[20])
{
	printf("> "); scanf_s(" %s", input, 20);	printf("\n");
	
	if (!strcmp(input, "north") || !strcmp(input, "n") || !strcmp(input, "gonorth") || !strcmp(input, "gon")) //north
		return 'n';
	if (!strcmp(input, "south") || !strcmp(input, "s") || !strcmp(input, "gosouth") || !strcmp(input, "gos")) //south
		return 's';
	if (!strcmp(input, "east") || !strcmp(input, "e") || !strcmp(input, "goeast") || !strcmp(input, "goe")) //east
		return 'e';
	if (!strcmp(input, "west") || !strcmp(input, "w") || !strcmp(input, "gowest") || !strcmp(input, "gow")) //west
		return 'w';
	if (!strcmp(input, "up") || !strcmp(input, "u") || !strcmp(input, "goup") || !strcmp(input, "gou")) //up
		return 'u';
	if (!strcmp(input, "down") || !strcmp(input, "d") || !strcmp(input, "godown") || !strcmp(input, "god")) //down
		return 'd';
	if (!strcmp(input, "inventory") || !strcmp(input, "i") || !strcmp(input, "openinventory")) //inventory
		return 'i';
	if (!strcmp(input, "look") || !strcmp(input, "l")) //look
		return 'l';
	if (!strcmp(input, "help") || !strcmp(input, "h")) //help
		return 'h';
	if (!strcmp(input, "quit") || !strcmp(input, "q") || !strcmp(input, "end")) //quit
		return 'q';
	if (!strcmp(input, "opendoor") || !strcmp(input, "od")) //open door
		return 'o';
	if (!strcmp(input, "closedoor") || !strcmp(input, "cd")) //open door
		return 'c';
}




