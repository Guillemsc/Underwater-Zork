#include "enemy.h"

Enemy::Enemy(p2String name, p2String description, Entity* other, int _position) :
Entity(name, description, other), position(_position)
{
}

Enemy::~Enemy()
{
}

int Enemy::get_position()
{
	return position;
}

void Enemy::set_position(int _position)
{
	position = _position;
}

int Enemy::get_healt()
{
	return health;
}
void Enemy::substract_healt(int _h)
{
	health -= _h;
}