#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "Scene.h"

class Unit;

class CircleObject :
	public Entity
{
public:
	CircleObject(Scene* scene, path path);
	~CircleObject();

	void update(float dt);
	void collision(Unit* u);

	Scene* scene;
	Sprite* Spr;
	float BDistance;
};

