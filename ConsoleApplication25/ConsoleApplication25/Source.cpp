#include <stdio.h>

int main()
{

	/*
	MAP

	02 12
	01 11
	00 

	*/
	int x = 0;
	int y = 1;

	int rooms[2][3];
	char* roomsName[2][3];
												  //9NSEW
	roomsName[0][0] = "Bedroom";      rooms[0][0] = 91000; //bedroom      
	roomsName[0][1] = "Dinning Room"; rooms[0][1] = 91110; //dinningRoom
	roomsName[0][2] = "Kitchen";      rooms[0][2] = 90110; //kitchen
	roomsName[1][1] = "Bathroom";     rooms[1][1] = 90001; //bedroom
	roomsName[1][2] = "Pantry";       rooms[1][2] = 90001; //pantry
	
	char coordinate = 0;
	char place = 0;

	printf("You are on the %s.\n", roomsName[x][y]);

	while (coordinate != 'q')
	{
		printf("\n\nWhere do you want to go?(n/s/e/w): >");
		scanf_s(" %c", &coordinate, 1);

		//testing
		switch (coordinate)
		{
		case 'n': //north
			if (((rooms[x][y] / 1000) % 10) == 1)
			{y++;}
			else{ printf("\nThere's a wall to the North.\n"); }
			break;
		case 's': //south
			if (((rooms[x][y] / 100) % 10) == 1)
			{y--;}
			else{ printf("\nThere's a wall to the South.\n"); }
			break;
		case 'e': //east
			if (((rooms[x][y] / 10) % 10) == 1)
			{x++;}
			else{ printf("\nThere's a wall to the East.\n"); }
			break;
		case 'w': //west
			if (((rooms[x][y]) % 10) == 1)
			{x--;}
			else{ printf("\nThere's a wall to the West.\n"); }
			break;
		default: printf("wrong");
			break;
		}

		//printing
		printf("\nYou are on the %s\n", roomsName[x][y]); //room
		
		if (((rooms[x][y] / 1000) % 10) == 1)
				{printf("\nYou have the %s at the north.", roomsName[x][y+1]);} //north
		if (((rooms[x][y] / 100) % 10) == 1)
			{printf("\nYou have the %s at the south.", roomsName[x][y-1]);} //south
		if (((rooms[x][y] / 10) % 10) == 1)
			{printf("\nYou have the %s at your right.", roomsName[x + 1][y]);} //east
		if (((rooms[x][y]) % 10) == 1)
			{printf("\nYou have the %s at your left.", roomsName[x-1][y]);} //west
	
	}
	getchar();
	return 0;
}