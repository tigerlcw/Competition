#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "Scene.h"

class Map :
	public Entity
{
public:
	Map(Scene* scene, int stage);
	~Map();

	void update(float dt);

	Scene* scene;
	Sprite* ground;
};

