#include "Head.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void PrintPlaces(int &position, bool &printRoom, bool &wantToSetPos, bool &textNorth, bool &textSouth, bool &textEast, bool &textWest, bool &pass, bool &lantern, bool &key, bool &seaSuit, bool &metalBar, bool &oxigenTank, bool &masterPass, bool &reenforcedSeasuit, bool &electricity, bool &end, bool &robot, bool &elevator, bool &enemy)
{

		switch (position)
		{
		case 0: //BODIES
			wantToSetPos = true;
			if (textNorth) //bodies North
			{
				printf("Why are those people bodies right there...\nThey look like they are sleeping.\nMy bed's computer is printing an error: 'Narcotics Fail'.\nProbably that's why you wake up.\n");
				textNorth = false; 
			}
			else if (textSouth) //bodies South
			{
				if (pass)
				{
					 printf("You opened the door and went outisde\n"); 
					 if (seaSuit){ position = 3; wantToSetPos = false; }
					 else{ printf("You died drowned\nDead End\n"); end = true; }
				}
				else{ printf("You need a pass to open this door\n"); }
				textSouth = false; 
			}
			else if (textEast) //bodies East
			{
				printf("There is an up and down stair right there.\n");
				textEast = false;
			}
			else{
				printf("\nBODIES ROOM\n\nYou are sorrounded by beds full of people bodies connected\nto a wierd machines.\nYou have a door at your south.\nAn up and donw stairs at the right.\nBodies at your north.\n");
				printRoom = true; wantToSetPos = true;
			}

			break;
		case 1: //BODIES(UP)
			if (textNorth) //bodies(up) North
			{
				printf("Ther's a text on the briefcase: 'normal passes'.Open it?(y/n): "); char r1[2];
				scanf_s("%s", r1 , 2);
				if (!(strcmp(r1, "y")))
				{
					if (!pass)
					{
						if (key){ pass = true; printf("You took the pass that is inside.\n"); }
						else{ printf("You need a key to open it.\n"); }
					}
					else{ printf("You already took the pass\n."); }
				}
				textNorth = false; 
			}
			else if (textEast) //bodies(up) East
			{
				printf("There is a down stair right there.\n");
				textWest = false;
			}
			else if (textWest) //bodies(up) West
			{
				if (electricity){ printf("The computer is opened"); }
				else{ printf("There's a computer right there.\nYou try to switch on it, but ther's no electicity.\n"); }
				textEast = false;
			}
			else{
				printf("\nBODIES ROOM(UP)\nYou are on the top floor.\nYou see a briefcase on a table at the north.\nA computre at the west.\nStairs at the east.\n");
				 wantToSetPos = true;
			}
			break;
		case 2: //BODIES(DOWN)
			if (textNorth) //bodies(down) North
			{
				if (!key){
					printf("Thats a key, do you want to take it?(y/n): "); char r2a[2];
					scanf_s("%s", r2a, 2);
					if (!(strcmp(r2a, "y"))){ key = true; printf("Tou take it.\n"); }
				}
				else{ "You already took the key"; }
				textNorth = false; 

			}
			else if (textSouth) //bodies(down) South
			{
				printf("This look like a suit to go under the water.\n It has an oxigen tank.\n It's in good conditions.\nDo you want to wear it?(y/n): "); char r2b[2];
				scanf_s("%s", r2b, 2);
				if (!(strcmp(r2b, "y"))){ seaSuit = true; printf("Now you wear a seasuit and you can walk under the water.\n"); }
				textSouth = false; 
			}
			else if (textEast) //bodies(down) East
			{
				printf("There is a up stair right there.\nThere's also a lantern down there, do you want to take it?(y/n)"); char r2c[2];
				scanf_s("%s", r2c, 2);
				if (!(strcmp(r2c, "y")))
				{
					lantern = true; printf("You took it.\n");
				}
				textEast = false; 
			}
			else{
				printf("\nBODIES ROOM(DOWN)\nThere is a key hanging on a nail at the north.\nSome wierd seasuit at your south.\nUp stairs at he right with something below.\n");
			}
			break;
		case 3: //ELEVATOR
				wantToSetPos = true;
				printf("\nELEVATOR\nThere's a big building at the east.\nThere's a tunnel at the south.\n");
				printf("Do you want to use the elvator to go to the deepStation?:(y/n)"); char r3[2];
				scanf_s("%s", r3, 2);
				if (!(strcmp(r3, "y")))
				{
					if (reenforcedSeasuit && electricity && elevator)
					{
						printf("The elvator is working.\nYou started moving.\nYou are scared.\nYou are going to the deepness.\n...\nAfter some minutes the elevator stops.\n");
						position = 16;
						wantToSetPos = false;
					}
					else if(!electricity){ printf("It's not working, you need electricity.\n"); }
					else if (!reenforcedSeasuit){ printf("You need a reenforced seasuit to go tho the deepness.\n"); }
					else if (!elevator){ printf("You need to activate the elevator.\n"); }
				}
			break;
		case 4: //ENTRANCE S
			if (textNorth) //entrance s North
			{
				printf("Ther's a door that's not working.\n");
				textNorth = false; 
			}
			else{
				printf("\nENTRANCE(SOUTH)\n");
				if (robot)
				{
					printf("There is a door to enter into the building.\nYou try to open it.\nIt's broken.\n");
					printf("Suddenly you hear a sound.\nYou look behind and it's a small robot that swims in circles.\nThe robot repeats always the same prhase:\nI love swiming throuht the hair\nYou think its wierd.\nWhat you want to do?: \n(h -> ask for help. p ->punch him i -> ingore )"); 
					char r4[2];
					scanf_s("%s", r4, 2);
					if (!(strcmp(r4, "h")))
					{
						printf(">Can you help me enter the building?\n-I love to swim through the hair.\n>...\n>You can touch my hair if you want.\nHe touch you hair.\nHe took you to a stairs at the east.\nHe open a hole on the building with his laser.\nThe robot leaves swiming.\n");
						position = 5;
						wantToSetPos = false;
						robot = false;
					}
					else if (!(strcmp(r4, "h")))
					{
						printf("You hit him on the face.\nThe robot is made of metal.\n Your seasuit brokes on the hand and the water enters.\n You die drowned\nDEAD END");
						end = true;
					}
					else if (!(strcmp(r4, "i"))){ printf("You ignore him.\nHe feels that that's rude.\nHe destroy you.\nDEAD END"); end = true; }
				}
				else{printf("Ther are stairs at the south.\nA door at the north\nA stairs at the west.\nThe elevator at the west");}
			}
			break;
		case 5: //STAIRS
			if (textWest)
			{
				if (masterPass)
				{
					printf("Now you can open this room.\n");
					position = 10;
					wantToSetPos = false;
				}
				else
				{
					printf("You are into the building.\nThere are two rooms.\nYou try top open the first one but the pass needs to be different.\nYou open the second one.\n Do you want to enter?(y/n): "); char r5[2];
					scanf_s("%s", r5, 2);
					if (!(strcmp(r5, "y")))
					{
						printf("You enter the room 2\n");
						position = 8;
						wantToSetPos = false;
					}
				}
				textWest = false;
			}
			else{
				wantToSetPos = true;
				printf("\nSTAIRS\n You enter the building.\nThe north of the building is at your front.\nYou can enter the building at your west.\n");
			}
			break;
		case 6: //ENTRANCE N
			printf("Building(North)\nThe stairs are at the east.\n The building(west) is at the west");
			break;
		case 7: //ENTRANCE W
			printf("Building(West)\nThe building(north) at the north.\nThe entrance at the south.\n");
			break;
		case 8: //ROOM 2
			wantToSetPos = true;
				printf("\nBUILDING(ROOM 2)\nYou fall into a hole\n");
				position = 11;
			wantToSetPos = false;
			
			break;
		case 9: //ROOM 1
				printf("\nBUILDING(ROOM 1)\nYou have the stairs at the east.\n You have a room at the west.\n");
			
			break;
		case 10: //LIGHT ROOM
			wantToSetPos = true;
			if (textNorth)
			{
				if (!metalBar){
					printf("Ther's a metal bar right threre, do you want to take it?(y/n): "); char r10[2];
					if (oxigenTank = false)
					{
						printf("You replaced you oxigen tank.\n"); oxigenTank = true;
					}
					scanf_s("%s", r10, 2);
					if (!(strcmp(r10, "a")))
					{
						printf("Now you are equiped with a metal bar.\n"); metalBar = true;
					}
				}
				textNorth = false;
			}
			if (textWest)
			{
				printf("It's a control panel with a lot of buttons.\nYou press some of them randomly.\nAll the lights suddenly tun on.\nThe electricity is on.\n");
				electricity = true;
				textWest = false; 
			}
			else{
				printf("\nLIGHT ROOM\nThere's the room 1 at the east.\nAt your left you have a control panel.\nThere's a metal bar and some oxigent tanks an your front.\n");
			}
			break;
		case 11: //HOLE ROOM
			wantToSetPos = true;
				printf("\nHOLE ROOM\nThere's a passage to the south.\n");
				if (lantern){
					printf("It's very dark\n you turn on the lantern.\nYou see a card\nDo you want to take it?(y/n): "); char r11[2];
					scanf_s("%s", r11, 2);
					if (!(strcmp(r11, "y")))
					{
						masterPass = true;
					}
				}
			
			break;
		case 12: //PASSAGE 1
			wantToSetPos = true;
			if (textSouth)
			{
				printf("You feel like something is watching you.\n");
				if (lantern){
					printf("Wich path do you want to take( a -> passage 2  b -> control room)"); char r12[2];
					scanf_s("%s", r12, 2);
					if (!(strcmp(r12, "a")))
					{
						printf("You go to the passage 2.\n");
						position = 13;
						wantToSetPos = false;
					}
					else if (!(strcmp(r12, "b")))
					{
						printf("You go to the Control Room.\n");
						position = 14;
						wantToSetPos = false;
					}
				}
				else{ printf("You walk throught the dark passage.\n You can't see anything.\nYou feel someone at your back and suddenly you are hit\non the head by something.\nDEAD END"); end = true; }
				textSouth = false;
			}
			else{
				printf("\nPASSAGE 1\nThe hole room is at the north\nThere are two paths at the south.\n");
			}
			break;
		case 13: //PASSAGE 2
			wantToSetPos = true;
			if (textEast)
			{
				printf("Wich path do you want to take( a -> passage 1  b -> control room)"); char r13[2];
				scanf_s("%s", r13, 2);
				if (!(strcmp(r13, "a")))
				{
					printf("You go to the passage 1.\n");
					position = 12;
					wantToSetPos = false;
				}
				if (!(strcmp(r13, "b")))
				{
					printf("You go to the Control Room.\n");
					position = 14;
					wantToSetPos = false;
				}
				textEast = false;
			}
			else if (textWest)
			{
				if (masterPass){
					printf("You go outside.\n");
					position = 3;
					wantToSetPos = false;
				}
				else{ printf("You need a diferent pass to open this door.\n"); }
				textWest = false; 
			}
			else{
				printf("\nPASSAGE 2\nYou can go outside to the elevator at the west.\n There are two paths at the east.\n");
			}
			break;
		case 14: //CONTROL ROOM
			wantToSetPos = true;
			if (textNorth)
			{
				printf("Wich path do you want to take( a -> passage 1  b -> passage 2)"); char r14a[2];
				scanf_s("%s", r14a, 2);
				if (!(strcmp(r14a, "a")))
				{
					printf("You go to the passage 1.\n");
					position = 12;
					wantToSetPos = false;
				}
				else if (!(strcmp(r14a, "b")))
				{
					printf("You go to the passage 2.\n");
					position = 13;
					wantToSetPos = false;
				}
				textNorth = false; 
			}
			
			else if (textWest)
			{
				printf("There is a big red button with a text: 'Activate Elevator'.\nDo you want to press it(y/n)?: "); char r14b[2];
				scanf_s("%s", r14b, 2);
				if (!(strcmp(r14b, "y")))
				{
					printf("You pressed the button.\n"); elevator = true;
				}

				textWest = false; 
			}
			else{
				printf("\nCONTROL ROOM\nThere's another room at the south.There are two paths at the north.\n");
			}
			break;
		case 15: //DEEP PREPARATION
		
			if (textSouth)
			{
				printf("Those are a different seasuits that mine.\nThere's a text on the top: 'Reenforced Seasuits, for going deeper'.\nDo you want to change it by the current?(y/n): \n"); char r15[2];
				scanf_s("%s", r15, 2);
				if (!(strcmp(r15, "y")))
				{
					printf("Now you are wearing a reenforced seasuit.\n"); reenforcedSeasuit = true;
				}
				textSouth = false; 
			}
			
			else{
				printf("\nDEEP PREPARATION\nYou have the control room at the north.\nYou have a path to the Elevator to the west.\nThere's a lot of cases with seasuits ath the south.\n");
			}
			break;
		case 16: //DEEP STATION
			wantToSetPos = true;
			if (textNorth)
			{
				printf("Do you want to use the elvator to go up?(y/n): \n"); char r16[2];
				scanf_s("%s", r16, 2);
				if (!(strcmp(r16, "y")))
				{
					position = 3;
					wantToSetPos = false;
				}
				textNorth = false;
			}
			else
			{
				printf("\nDEEP STATION\n\It's even more dark down here.\nYou have a path to the south.\nYou can go up with the elvator at the north.\n");
			}
			
			break;
		case 17: //PATH 1
			wantToSetPos = true;
			if (textSouth)
			{
				printf("Wich path do you want to take( a -> look out  b -> path 2)"); char r17[2];
				scanf_s("%s", r17, 2);
				if (!(strcmp(r17, "a")))
				{
					printf("You go to the look out.\n");
					position = 18;
					wantToSetPos = false;
				}
				else if (!(strcmp(r17, "b")))
				{
					printf("You go to the path 2.\n");
					position = 19;
					wantToSetPos = false;
				}
				textSouth = false; 
			}
			else{
				printf("\nPATH 1\nYou have the deep station at the north.\n At the south you have two paths.\n");
			}
			break;
		case 18: //LOOK OUT
			wantToSetPos = true;
			if (textEast)
			{
				printf("Wich path do you want to take( a -> path 1  b -> path 2)"); char r18[2];
				scanf_s("%s", r18, 2);
				if (!(strcmp(r18, "a")))
				{
					printf("You go to the path 1.\n");
					position = 17;
					wantToSetPos = false;
				}
				else if (!(strcmp(r18, "b")))
				{
					printf("You go to the path 2.\n");
					position = 19;
					wantToSetPos = false;
				}
				textEast = false; 
			}
			else if (textWest)
			{
				printf("It's a small look out to admire a big planure on the see.\nYou think its beautufull.\nSomething it's moving behind you.\n");
				textWest = false; 
			}
			else{
				printf("\nLOOK OUT.\nYou can look at the sea at the left.\nAt the east you have two paths.\n");
			}
			break;
		case 19: //PATH 2
			wantToSetPos = true;
			if (textNorth)
			{
				printf("Wich path do you want to take( a -> look out  b -> path 1)"); char r18[2];
				scanf_s("%s", r18, 2);
				if (!(strcmp(r18, "a")))
				{
					printf("You go to the look out.\n");
					position = 18;
					wantToSetPos = false;
				}
				else if (!(strcmp(r18, "b")))
				{
					printf("You go to the path 1.\n");
					position = 17;
					wantToSetPos = false;
				}
				textNorth = false; 

			}
			else if (textSouth)
			{
				srand(time(NULL));
				int i = 5;
				int y = rand() % 7;
				int x = rand() % 2;
				if (enemy)
				{
					int x = rand() % 2;
					while (i > 0)
					{
						if (y != i)
						{
							printf("You keep walking through the path.\n");
							i++;
						}
						else
						{ 
							printf("Someone hit you in the head.\n You fall on the ground.\n");
							if (metalBar)
							{
								printf("You wake up and with your metal bar you stop his next hit.\nThen with all your force you hit him on the oxigen tank.\nHe dies.\n");
								enemy = false;
								if (x == 1)
								{
									printf("You noticed that your oxigent tank it's also broken and the air is scaping.\nYou need another oxigent tank very fast.\n");
									oxigenTank = false;
								}

							}
							else{ printf("He hit you again in the helmet.\nThe blood starts to appear.\nDEAD END.\n"); end = true; }
						}i = 0;
						i--;
					}
				}
				else{
					if (oxigenTank = true)
					{
						position = 20; printf("You arrived to the emergency room scape.\n"); wantToSetPos = false;
					}
					else{ printf("You need to get another oxigen tank.\n"); }
				}
				textSouth = false; 
			}
			
			else{
				printf("\nPATH 2.\nYou feel you are close to your destiny.\nYou can return to the path 1 or at the look out at the north.\n You can continue walking at the south.\n");
			}
			break;
		case 20: //EMERGENCY SCAPE
			wantToSetPos = true;
			
				printf("\nEMERGENCY SCAPE\nAfter all the adventure, you finally made it.\nYou are filled with determination.\nYou go up the train.\nYou press the emergency button.\nThe train starts moving.\nYou are very happy.\nA warning it's shown at the computer.\nThe train explodes.\nYOU WIN CONGRATULATIONS\n\nBy Guillem Sunyer.\n");
				getchar();
				printf("Do you want to play again?(y/n)"); char r20[2];
				scanf_s("%s", r20, 2);
				if (!(strcmp(r20, "y")))
				{
					position = 0;
					wantToSetPos = false;
					pass = lantern = key = seaSuit = metalBar = masterPass = reenforcedSeasuit = electricity = elevator = false;
					enemy = robot = oxigenTank = true;
				}
				else{ end = true; }
			
			break;
		
		}
}

void PrintObjects(int &position, bool pass)
{
	if (pass)
		printf("Pass");
}

void PrintHelp()
{
	printf("help");
}