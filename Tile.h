#pragma once
#include "Entity.h"
#include "Sprite.h"
class Tile :
	public Entity
{
public:
	Tile(int code);
	~Tile();

	void update(float dt);
	void render();

	int tileCode;
	int effectCode;

	Sprite* spr;
};

