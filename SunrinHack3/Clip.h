#pragma once
#include "Entity.h"
#include "Animation.h"

class Unit;

class Clip :
	public Entity
{
public:
	Clip(Unit* target, Animation* left, Animation* right);
	~Clip();

	void update(float dt);

	Unit* target;
	Animation* left;
	Animation* right;
};

