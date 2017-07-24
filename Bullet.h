#pragma once
#include "Entity.h"
#include "Animation.h"
#include "Scene.h"

enum BULLET_CODE{
	STURN_BULLET,
	POISON_BULLET
};

class Unit;

class Bullet :
	public Entity
{
public:
	Bullet(Scene* scene, Unit* target, int code);
	~Bullet();

	void update(float dt);

	Scene* scene;
	int code;
	Animation* ani;
	float moveSpeed;
	float timer;
	Vec2 v;

	Unit* target;
};

