#include "DXUT.h"
#include "Bullet.h"
#include "GameScene.h"


Bullet::Bullet(Scene* scene, Unit* target, int code) 
: scene(scene), target(target), code(code), timer(0.0f),
moveSpeed(800.0f)
{
	if (code == STURN_BULLET){
		ani = new Animation("image/bullet/dark", 2, 6);
	}
	else if (code == POISON_BULLET){
		ani = new Animation("image/bullet/poison", 2, 6);
	}
	addChild(ani);

	rect = ani->rect;
	v = target->moveVector;
}


Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	Entity::update(dt);

	pos += v * moveSpeed * dt;

	GameScene* GS = (GameScene*)scene;
	if (GS->player1->target == target){
		if (GS->player2->target->rectWithPos().intersects_Rect(rect, pos)){
			if (code == STURN_BULLET){
				GS->player2->target->setStatus(STURN, 1.5f);
			}
			if (code == POISON_BULLET){
				GS->player2->target->setStatus(POISON, 2.5f);
			}
			removeChild(this);
		}
	}
	else{
		if (GS->player1->target->rectWithPos().intersects_Rect(rect, pos)){
			if (code == STURN_BULLET){
				GS->player1->target->setStatus(STURN, 1.5f);
			}
			if (code == POISON_BULLET){
				GS->player1->target->setStatus(POISON, 2.5f);
			}
			removeChild(this);
		}
	}

	timer += dt;
	if (timer > 3.0f){
		removeChild(this);
	}
}