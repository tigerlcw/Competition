#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "SkillState.h"

enum ITEM_CODE{
	RED,
	BLUE,
	YELLOW,
	GREEN,
	BLACK,
	ORANGE,
	INDIGO,
	PURPLE,
	RAINBOW
};

class Item :
	public Entity
{
public:
	Item(int code);
	~Item();

	void getItem(Unit* target);

	Sprite* spr;
	int code;
	float BDistance;
};

