#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "Scene.h"
#include "Unit.h"

class BoxObject :
	public Entity
{
public:
	BoxObject(Scene* scene);
	~BoxObject();

	void update(float dt);
	void collision(Unit* u, float dt);

	Scene* scene;
	Sprite* Spr;
};

