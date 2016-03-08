#include "Head.h"


bool compareNames(char a[10], char b[10])
{
	int sizeA = 0;
	int sizeB = 0;
	int correct = 0;

	for (int i = 0; a[i] != '\0'; i++)
	{
		sizeA++;
	}
	for (int i = 0; b[i] != '\0'; i++)
	{
		sizeB++;
	}

	if (sizeA == sizeB)
	{
		for (int y = 0; y < sizeA; y++)
		{
			if (a[y] == b[y]){ correct++; }
		}
		if (correct == sizeA){ return true; }
		else{ return false; }
	}
	else{ return false; }
	
}

