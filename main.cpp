#include <iostream>
#include "world.h"
#include "memleaks.h"

int main()
{
	printf("\n");
	World my_world;

	while (my_world.players[0]->end == false)
	{
		// Look Around
		if (my_world.players[0]->want_to_look == true)
		{
			my_world.players[0]->look(my_world.rooms, my_world.players, my_world.exits, my_world.items, my_world.boxes);
		}

		// Check dead end
		Check(my_world.players, my_world.rooms, my_world.exits, my_world.items, my_world.boxes, my_world.enemies);

		// Get Input
		if (my_world.players[0]->want_to_input == true)
		{
			Tokenize(my_world.players, my_world.rooms, my_world.exits, my_world.items, my_world.boxes);
		}
		else
			my_world.players[0]->want_to_input = true;

	}

	printf("\nBye :)\n");
	
	getchar(); getchar();
	return 0;
}