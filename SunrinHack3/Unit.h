#pragma once
#include "Entity.h"
#include "Clip.h"
#include "SkillState.h"
#include "UnitState.h"
#include "Scene.h"

struct AbilityPoint{
	float max;
	float current;

	void init(float value){
		max = current = value;
	}
};

struct Status{
	bool isStatus;
	pair<float, float> Timer;

	void update(float dt){
		if (isStatus){
			Timer.first += dt;
			if (Timer.first >= Timer.second){
				isStatus = false;
			}
		}
	}
};

enum STATUS_CODE{
	STURN,
	POISON,
	RAIN
};

enum STATE_CODE{
	STAND,
	RUN,
	ATTACK,
	KNOCKBACK,
	DIE
};

class Unit :
	public Entity
{
public:
	Unit(Scene* scene);
	~Unit();

	void render();
	void update(float dt);
	void unitCollision(float dt);
	void changeSkill(int key, SkillState* changeSkill, int code);
	void getDamage(int damage);
	void setStatus(int code, float timer);
	void changeState(int state);

	Scene* scene;
	map<int, Clip*> clips;
	map<int, UnitState*> states;
	int currentState;

	int skillNum;
	SkillState* skill[3];

	Vec2 BP;
	float BDistance;

	AbilityPoint hp;
	AbilityPoint mp;
	int damage;

	bool isRight;
	Vec2 moveVector;
	float moveSpeed;
	float knockbackPower;

	int poisonCnt;
	Status status[RAIN + 1];
	Animation* sturn;
	Animation* rain;
};

class Unit1 :
	public Unit
{
public:
	Unit1(Scene* scene);
};

class Unit2 :
	public Unit
{
public:
	Unit2(Scene* scene);
};

class Unit3 :
	public Unit
{
public:
	Unit3(Scene* scene);
};