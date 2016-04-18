#ifndef __Input__
#define __Input__ 

#include "world.h"
#include "p2string.h"


class Player;
class Room;
class Exit;
class Item;
class Box;
class Enemy;

void Tokenize(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits, p2vector<Item*> &items, p2vector<Box*> &boxes);
void Check(p2vector<Player*> &player, p2vector<Room*> &rooms, p2vector<Exit*> &exits, p2vector<Item*> &items, p2vector<Box*> &boxes, p2vector<Enemy*> enemies);
void Inputs(p2vector<Player*> &player, p2String a1, p2String a2, p2String a3, p2String a4, p2vector<Room*> &rooms, p2vector<Exit*> &exits, int args, p2vector<Item*> &items, p2vector<Box*> &boxes);

bool Compare(const p2String a, const p2String b);




#endif