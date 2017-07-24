#include "DXUT.h"
#include "CircleObject.h"
#include "GameScene.h"


CircleObject::CircleObject(Scene* scene) : scene(scene)
{
	Spr = new Sprite("image/circle.png");
	addChild(Spr);

	rect = Spr->rect;
	BDistance = rect.right / 2;
}


CircleObject::~CircleObject()
{
}


void CircleObject::update(float dt)
{
	Entity::update(dt);

	GameScene* GS = (GameScene*)scene;
	collision(GS->player1->target);
	collision(GS->player2->target);
}

void CircleObject::collision(Unit* u)
{
	float distance = pita(u->center(), center());
	if (distance < u->BDistance + BDistance){
		float dir = angle(u->center(), center());
		u->pos -= Vec2(cos(dir), sin(dir)) * (u->BDistance + BDistance - distance);
	}
}