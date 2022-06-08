#include "DXUT.h"
#include "BoxObject.h"
#include "GameScene.h"


BoxObject::BoxObject(Scene* scene, path path) : scene(scene)
{
	Spr = new Sprite(path);
	addChild(Spr);

	rect = Spr->rect;
}


BoxObject::~BoxObject()
{
}

void BoxObject::update(float dt)
{
	Entity::update(dt);

	GameScene* GS = (GameScene*)scene;
	collision(GS->player1->target, dt);
	collision(GS->player2->target, dt);
}

void BoxObject::collision(Unit* u, float dt)
{
	if (rectWithPos().intersects_Rect(u->rect, u->pos)){
		u->pos -= u->moveVector * u->moveSpeed * dt;

		u->pos.x += u->moveVector.x * u->moveSpeed * dt;
		if (rectWithPos().intersects_Rect(u->rect, u->pos)){
			if (u->moveVector.x > 0){
				u->pos.x = pos.x - u->rect.right;
			}
			else{
				u->pos.x = pos.x + rect.right;
			}
			//u->pos.x -= u->moveVector.x * u->moveSpeed * dt;
		}

		u->pos.y += u->moveVector.y * u->moveSpeed * dt;
		if (rectWithPos().intersects_Rect(u->rect, u->pos)){
			if (u->moveVector.y > 0){
				u->pos.y = pos.y - u->rect.bottom;
			}
			else{
				u->pos.y = pos.y + rect.bottom;
			}
			//u->pos.y -= u->moveVector.y * u->moveSpeed * dt;
		}
	}
}