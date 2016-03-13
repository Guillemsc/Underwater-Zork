#include "Head.h"
#include <stdio.h>
#include <stdlib.h>
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

bool DoThings(char input[20], int &printNum, int &position, bool &wantToSetPos, bool &textNorth, bool &textSouth, bool &textEast, bool &textWest, bool &printRoom, bool &pass, bool &lantern, bool &key, bool &seaSuit, bool &metalBar, bool &oxigenTank, bool &masterPass, bool &reenforcedSeasuit, bool &electricity, bool &robot, bool &elevator, bool &enemy)
{
	bool end = false;

//Print-------------
	if (printRoom)
	{
		PrintPlaces(position, printRoom, wantToSetPos, textNorth, textSouth, textEast, textWest, pass, lantern, key, seaSuit, metalBar, oxigenTank, masterPass, reenforcedSeasuit, electricity, end, robot, elevator, enemy);
	}
	
//DeadEnd-----------
	if (end)
	{
		delete[] Rooms; //free Rooms class
		return true;

	}

//Input-------------
//Move--------------
	if (wantToSetPos){
		switch (InputWords(input)) //Unify Input
		{
		case 'n':
			if (!(strcmp(Rooms[position].north, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].north, "T"))){ textNorth = true; printRoom = true; }
			for (int n = 0; n < 21; n++){ if (!(strcmp(Rooms[position].north, Rooms[n].name))){ position = n; printRoom = true; break; } }
			break;
		case 's':
			if (!(strcmp(Rooms[position].south, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].south, "T"))){ textSouth = true;  printRoom = true; }
			for (int s = 0; s < 21; s++){ if (!(strcmp(Rooms[position].south, Rooms[s].name))){ position = s; printRoom = true; break; } }
			break;
		case 'e':
			if (!(strcmp(Rooms[position].east, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].east, "T"))){ textEast = true; printRoom = true; }
			for (int e = 0; e < 21; e++){ if (!(strcmp(Rooms[position].east, Rooms[e].name))){ position = e; printRoom = true; break; } }
			break;
		case 'w':
			if (!(strcmp(Rooms[position].west, "E"))){ printf("You can't go there\n"); printRoom = false; }
			if (!(strcmp(Rooms[position].west, "T"))){ textWest = true; printRoom = true; }
			for (int w = 0; w < 21; w++){ if (!(strcmp(Rooms[position].west, Rooms[w].name))){ position = w; printRoom = true; break; } }
			break;
		case 'u':
			if (!(strcmp(Rooms[position].up, "E"))){ printf("You can't go there\n"); printRoom = false; }
			for (int u = 0; u < 21; u++){ if (!(strcmp(Rooms[position].up, Rooms[u].name))){ position = u; printRoom = true; break; } }
			break;
		case 'd':
			if (!(strcmp(Rooms[position].down, "E"))){ printf("You can't go there\n"); printRoom = false; }
			for (int d = 0; d < 21; d++){ if (!(strcmp(Rooms[position].down, Rooms[d].name))){ position = d; printRoom = true; break; } }
			break;
		case 'i':
			PrintObjects(position, pass);
			break;
		case 'h':
			PrintHelp();
			break;
		case 'l':
			PrintPlaces(position, printRoom, wantToSetPos, textNorth, textSouth, textEast, textWest, pass, lantern, key, seaSuit, metalBar, oxigenTank, masterPass, reenforcedSeasuit, electricity, end, robot, elevator, enemy);
			break;
		case 'q':
			delete[] Rooms; //free Rooms class
			return true;
		}
	}
	//returns to continue playing
	return false;
}

char InputWords(char input[20])
{
	printf("> "); scanf_s("%s", input, 20);
	
	if (!strcmp(input, "north") || !strcmp(input, "n") || !strcmp(input, "go north") || !strcmp(input, "go n")) //north
		return 'n';
	if (!strcmp(input, "south") || !strcmp(input, "s") || !strcmp(input, "go south") || !strcmp(input, "go s")) //south
		return 's';
	if (!strcmp(input, "east") || !strcmp(input, "e") || !strcmp(input, "go east") || !strcmp(input, "go e")) //east
		return 'e';
	if (!strcmp(input, "west") || !strcmp(input, "w") || !strcmp(input, "go west") || !strcmp(input, "go w")) //west
		return 'w';
	if (!strcmp(input, "up") || !strcmp(input, "u") || !strcmp(input, "go up") || !strcmp(input, "go u")) //up
		return 'u';
	if (!strcmp(input, "down") || !strcmp(input, "d") || !strcmp(input, "go down") || !strcmp(input, "go d")) //down
		return 'd';
	if (!strcmp(input, "inventary") || !strcmp(input, "i") || !strcmp(input, "open inventary")) //inventory
		return 'i';
	if (!strcmp(input, "look") || !strcmp(input, "l")) //look
		return 'l';
	if (!strcmp(input, "help") || !strcmp(input, "h")) //help
		return 'h';
	if (!strcmp(input, "quit") || !strcmp(input, "q") || !strcmp(input, "end")) //quit
		return 'q';
}




