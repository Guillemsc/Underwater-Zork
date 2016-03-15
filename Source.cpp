#include "Head.h"
#include <iostream>

using namespace std;

int main()
{
//START----------------------------

	//internal
	bool end = false; //end state
	char input[20]; //player input

	bool printRoom = true;
	int printNum = 1; //do i have to print the room?

	bool wantToSetPos = true; //do you want to go to change the position?

	bool textNorth = false; //priting text north
	bool textSouth = false; //priting text south
	bool textEast = false; //priting text east
	bool textWest = false; //priting text west

	//player
	int position = 0; //current position

	//inventory
	bool pass = false;
	bool lantern = false;
	bool key = false;
	bool seaSuit = false;
	bool metalBar = false;
	bool oxigenTank = true; //true
	bool masterPass = false;
	bool reenforcedSeasuit = false;

	//no inventory
	bool electricity = false;
	bool robot = true; //true
	bool elevator = false;
	bool enemy = true;
	bool gate = false;

	StartRooms();

//LOOP-----------------------------

	while (!end)
	{
		end = DoThings(input, printNum, position, wantToSetPos, textNorth, textSouth, textEast, textWest, printRoom, pass, lantern, key, seaSuit, metalBar, oxigenTank, masterPass, reenforcedSeasuit, electricity, robot, elevator, enemy, gate);
	}

//FREE-----------------------------

	getchar();
	return 0;
}



