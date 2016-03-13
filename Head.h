#ifndef HEAD_H
#define HEAD_H

#include <iostream>

bool DoThings(char input[20], int &printNum, int &position, bool &wantToSetPos, bool &textNorth, bool &textSouth, bool &textEast, bool &textWest, bool &printRoom, bool &pass, bool &lantern, bool &key, bool &seaSuit, bool &metalBar, bool &oxigenTank, bool &masterPass, bool &reenforcedSeasuit, bool &electricity, bool &robot, bool &elevator, bool &enemy, bool &gate);
char InputWords(char input[15]);
void PrintPlaces(int &position, bool &wantToSetPos, bool &printRoom, bool &textNorth, bool &textSouth, bool &textEast, bool &textWest, bool &pass, bool &lantern, bool &key, bool &seaSuit, bool &metalBar, bool &oxigenTank, bool &masterPass, bool &reenforcedSeasuit, bool &electricity, bool &end, bool &robot, bool &elevator, bool &enemy, bool &gate);
void PrintObjects(int &position, bool pass, bool lantern, bool key, bool seaSuit, bool metalBar, bool oxigenTank, bool masterPass, bool reenforcedSeasuit);
void PrintHelp(void);
void StartRooms();

class Room
{
public:
	char name[20];
	char north[20];
	char south[20];
	char east[20];
	char west[20];
	char up[20];
	char down[20];

	void GetRooms(char _name[20], char _north[20], char _south[20], char _east[20], char _west[20], char _up[20], char _down[20])
	{
		strcpy_s(name, 20, _name); strcpy_s(north, 20, _north); strcpy_s(south, 20, _south); strcpy_s(east, 20, _east); strcpy_s(west, 20, _west); strcpy_s(up, 20, _up); strcpy_s(down, 20, _down);
	}
};

#endif