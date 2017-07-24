#include "DXUT.h"
#include "SkillState.h"
#include "Unit.h"
#include "GameScene.h"
#include "BoxObject.h"
#include "CircleObject.h"
#include "Bullet.h"

SkillState::SkillState(Unit* target) : target(target), isOn(true), costMp(0), Timer(0.0f, 0.0f)
{
}


SkillState::~SkillState()
{
}

void SkillState::start()
{
	isOn = false;
	Timer.first = Timer.second;
}

void SkillState::update(float dt)
{
	if (!isOn){
		Timer.first -= dt;
		if (Timer.first < 0.0f){
			Timer.first = Timer.second;
			isOn = true;
		}
	}
}

Red::Red(Unit* target) : SkillState(target)
{
	target->hp.max += 50;
	target->hp.current += 50;
}

Red::~Red()
{
}

void Red::start()
{
}

Blue::Blue(Unit* target) : SkillState(target)
{
	target->mp.max += 50;
	target->mp.current += 50;
}

Blue::~Blue()
{
}

void Blue::start()
{
}

Yellow::Yellow(Unit* target) : SkillState(target)
{
	costMp = 20;
	Timer.first = Timer.second = 6.0f;
}

Yellow::~Yellow()
{
}

void Yellow::start()
{
	if (target->moveVector.x == 0 &&
		target->moveVector.y == 0)
		return;

	SkillState::start();

	GameScene* GS = (GameScene*)target->scene;
	target->pos += target->moveVector * 100.0f;
	target->unitCollision(0.1f);
	for_iter(iter, GS->BOList->children){
		BoxObject* bo = (BoxObject*)*iter;
		bo->collision(target, 100.0f);
	}
}

Green::Green(Unit* target) : SkillState(target)
{
	costMp = 10;
	Timer.first = Timer.second = 15.0f;
}

Green::~Green()
{
}

void Green::start()
{
	if (target->moveVector.x == 0 &&
		target->moveVector.y == 0)
		return;

	SkillState::start();

	Bullet* b = new Bullet(target->scene, target, POISON_BULLET);
	b->rotation = angle(Vec2(0, 0), target->moveVector);
	b->pos += Vec2(cos(b->rotation), sin(b->rotation)) * 100.0f;
	GameScene* GS = (GameScene*)target->scene;
	GS->bulletList->addChild(b);
}

Black::Black(Unit* target) : SkillState(target)
{
	costMp = 15;
	Timer.first = Timer.second = 15.0f;
}

Black::~Black()
{
}

void Black::start()
{
	if (target->moveVector.x == 0 &&
		target->moveVector.y == 0)
		return;

	SkillState::start();

	Bullet* b = new Bullet(target->scene, target, STURN_BULLET);
	b->rotation = angle(Vec2(0, 0), target->moveVector);
	b->pos += Vec2(cos(b->rotation), sin(b->rotation)) * 100.0f;
	GameScene* GS = (GameScene*)target->scene;
	GS->bulletList->addChild(b);
}

Orange::Orange(Unit* target) : SkillState(target)
{
	target->damage += 10;
}

Orange::~Orange()
{
}

void Orange::start()
{
}

Indigo::Indigo(Unit* target) : SkillState(target)
{
	target->moveSpeed *= 200.0f;
}

Indigo::~Indigo()
{
}

void Indigo::start()
{
}

Purple::Purple(Unit* target) : SkillState(target)
{
	costMp = 20;
	Timer.first = Timer.second = 20.0f;
}

Purple::~Purple()
{
}

void Purple::start()
{
	SkillState::start();

	GameScene* GS = (GameScene*)target->scene;
	Unit* u;
	if (GS->player1->target == target){
		u = GS->player2->target;
	}
	else{
		u = GS->player1->target;
	}

	float distance = pita(target->center(), u->center());
	if (distance < 360){
		float dir = angle(u->center(), target->center());
		u->moveVector = Vec2(cos(dir), sin(dir));
		u->knockbackPower = distance;
		u->isRight = u->pos.x > target->pos.x;
		u->changeState(KNOCKBACK);
	}
}

Rainbow::Rainbow(Unit* target) : SkillState(target)
{
	costMp = 30;
	Timer.first = Timer.second = 25.0f;
}

Rainbow::~Rainbow()
{
}

void Rainbow::start()
{
	SkillState::start();
	target->setStatus(RAIN, 3.0f);
}