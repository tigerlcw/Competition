#include "DXUT.h"
#include "UnitState.h"
#include "Unit.h"
#include "GameScene.h"


UnitState::UnitState(Unit* target) : target(target)
{
}


UnitState::~UnitState()
{
}

void UnitState::enter()
{
}

void UnitState::update(float dt)
{
}

void UnitState::exit()
{
}

UnitAttack::UnitAttack(Unit* target) : UnitState(target)
{
	Timer.second = 0.5f;
}

UnitAttack::~UnitAttack()
{
}

void UnitAttack::enter()
{
	Timer.first = 0;
	v = target->moveVector;
}

void UnitAttack::update(float dt)
{
	target->pos += v * target->moveSpeed * dt;
	target->unitCollision(dt);
	
	Timer.first += dt;
	if (Timer.first >= Timer.second){
		target->changeState(STAND);
	}
}

UnitKnockBack::UnitKnockBack(Unit* target) : UnitState(target)
{
}

UnitKnockBack::~UnitKnockBack()
{
}

void UnitKnockBack::enter()
{
	v = target->moveVector;
	power = target->knockbackPower;
}

void UnitKnockBack::update(float dt)
{
	target->pos += v * power * dt;
	target->unitCollision(dt);
	power -= power * 2 * dt;
	if (power < 50){
		target->changeState(STAND);
	}
}

UnitDie::UnitDie(Unit* target) : UnitState(target)
{
	Timer.second = 3.0f;
}

UnitDie::~UnitDie()
{
}

void UnitDie::enter()
{
	Timer.first = 0;
}

void UnitDie::update(float dt)
{
	Timer.first += dt;
	if (Timer.first >= Timer.second){

	}
}