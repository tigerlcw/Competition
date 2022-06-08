#pragma once
#include "Define.h"

class Unit;

class UnitState
{
public:
	UnitState(Unit* target);
	~UnitState();

	virtual void enter();
	virtual void update(float dt);
	virtual void exit();

	Unit* target;
};

class UnitAttack :
	public UnitState
{
public:
	UnitAttack(Unit* target);
	~UnitAttack();

	void enter();
	void update(float dt);

	Vec2 v;
	pair<float, float>Timer;
};

class UnitKnockBack :
	public UnitState
{
public:
	UnitKnockBack(Unit* target);
	~UnitKnockBack();

	void enter();
	void update(float dt);

	Vec2 v;
	float power;
};

class UnitDie :
	public UnitState
{
public:
	UnitDie(Unit* target);
	~UnitDie();

	void enter();
	void update(float dt);
	pair<float, float>Timer;
};