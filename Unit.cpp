#include "DXUT.h"
#include "Unit.h"
#include "GameScene.h"


Unit::Unit(Scene* scene) : scene(scene), isRight(true), damage(10), currentState(STAND)
{
	spr = new Sprite("image/box.png");
	spr->visible = false;
	addChild(spr);

	states[STAND] = new UnitState(this);
	states[RUN] = new UnitState(this);
	states[ATTACK] = new UnitAttack(this);
	states[KNOCKBACK] = new UnitKnockBack(this);
	states[DIE] = new UnitDie(this);

	for (int i = 0; i < 3; i++){
		skill[i] = new SkillState(this);
	}

	for (int i = 0; i < RAIN + 1; i++){
		status[i].isStatus = false;
	}

	rect = spr->rect;
	BDistance = rect.right / 2;
}


Unit::~Unit()
{
	for (int i = 0; i < 3; i++){
		SAFE_DELETE(skill[i]);
	}

	for (auto& iter : states){
		SAFE_DELETE(iter.second);
	}
}

void Unit::update(float dt)
{
	Entity::update(dt);
	states[currentState]->update(dt);
	mp.current += dt * 2;
	if (mp.current > mp.max){
		mp.current = mp.max;
	}

	for (int i = 0; i < RAIN + 1; i++){
		if (status[i].isStatus){
			status[i].update(dt);
			if (!status[i].isStatus){
				if (i == STURN){

				}
				if (i == POISON){

				}
				if (i == RAIN){
					damage -= 10;
				}
			}
		}
	}
	if (status[POISON].isStatus){
		if (status[POISON].Timer.first >= poisonCnt){
			poisonCnt++;
			getDamage(4);
		}
	}
}

void Unit::unitCollision(float dt)
{
	GameScene* GS = (GameScene*)scene;
	for_iter(iter, GS->unitList->children){
		Unit* u = (Unit*)*iter;
		if (u == this) continue;

		if (rectWithPos().intersects_Rect(u->rect, u->pos)){
			pos -= moveVector * moveSpeed * dt;

			if (currentState == ATTACK){
				if (u->currentState == ATTACK){
					u->moveVector = moveVector;
					moveVector *= -1;
					knockbackPower = 500;
					u->knockbackPower = 500;
					getDamage(u->damage);
					u->getDamage(damage);
					u->isRight = !isRight;
					changeState(KNOCKBACK);
					u->changeState(KNOCKBACK);
				}
				else{
					u->moveVector = moveVector;
					u->knockbackPower = 1000;
					u->changeState(KNOCKBACK);
					u->getDamage(damage);
					u->isRight = !isRight;
					changeState(STAND);
				}
			}
			else{
				pos.x += moveVector.x * moveSpeed * dt;
				if (rectWithPos().intersects_Rect(u->rect, u->pos)){
					if (moveVector.x > 0){
						pos.x = u->pos.x - rect.right;
					}
					else{
						pos.x = u->pos.x + u->rect.right;
					}
				}

				pos.y += moveVector.y * moveSpeed * dt;
				if (rectWithPos().intersects_Rect(u->rect, u->pos)){
					if (moveVector.y > 0){
						pos.y = u->pos.y - rect.bottom;
					}
					else{
						pos.y = u->pos.y + u->rect.bottom;
					}
				}
			}
		}
	}
}

void Unit::changeSkill(int key, SkillState* changeSkill)
{
	SAFE_DELETE(skill[key]);
	skill[key] = changeSkill;
}

void Unit::getDamage(int damage)
{
	if (currentState == DIE) return;
	if (currentState == RAIN) return;
	hp.current -= damage;
	if (hp.current <= 0){
		changeState(DIE);
	}
}

void Unit::setStatus(int code, float timer)
{
	status[code].isStatus = true;
	status[code].Timer.first = 0;
	status[code].Timer.second = timer;

	if (code == STURN){

	}
	if (code == POISON){
		poisonCnt = 0;
	}
	if (code == RAIN){
		damage += 10;
	}
}

void Unit::changeState(int state)
{
	if (currentState == state) return;
	states[currentState]->exit();
	clips[currentState]->visible = false;
	currentState = state;
	states[currentState]->enter();
	clips[currentState]->visible = true;
	clips[currentState]->left->currentFrame = 0;
	clips[currentState]->left->update(0);
	clips[currentState]->right->currentFrame = 0;
	clips[currentState]->right->update(0);
}

Unit1::Unit1(Scene* scene) : Unit(scene)
{
	Animation* stand_left = new Animation("image/Unit/1/stand/left", 1, 0);
	Animation* stand_right = new Animation("image/Unit/1/stand/left", 1, 0);
	stand_right->scaleCenter = stand_right->center();
	stand_right->scale.x = -1;
	clips[STAND] = new Clip(this, stand_left, stand_right);
	addChild(clips[STAND]);

	Animation* run_left = new Animation("image/Unit/1/left", 4, 12);
	Animation* run_right = new Animation("image/Unit/1/left", 4, 12);
	run_right->scaleCenter = run_right->center();
	run_right->scale.x = -1;
	clips[RUN] = new Clip(this, run_left, run_right);
	clips[RUN]->visible = false;
	addChild(clips[RUN]);

	Animation* attack_left = new Animation("image/Unit/1/left", 4, 12);
	Animation* attack_right = new Animation("image/Unit/1/left", 4, 12);
	attack_right->scaleCenter = attack_right->center();
	attack_right->scale.x = -1;
	clips[ATTACK] = new Clip(this, attack_left, attack_right);
	clips[ATTACK]->visible = false;
	addChild(clips[ATTACK]);

	Animation* knockback_left = new Animation("image/Unit/1/knockback/left", 1, 0);
	Animation* knockback_right = new Animation("image/Unit/1/knockback/left", 1, 0);
	knockback_right->scaleCenter = knockback_right->center();
	knockback_right->scale.x = -1;
	clips[KNOCKBACK] = new Clip(this, knockback_left, knockback_right);
	clips[KNOCKBACK]->visible = false;
	addChild(clips[KNOCKBACK]);

	Animation* die_left = new Animation("image/Unit/1/die/left", 1, 0);
	Animation* die_right = new Animation("image/Unit/1/die/left", 1, 0);
	die_right->scaleCenter = die_right->center();
	die_right->scale.x = -1;
	clips[DIE] = new Clip(this, die_left, die_right);
	clips[DIE]->visible = false;
	addChild(clips[DIE]);

	hp.init(150);
	mp.init(50);
	moveSpeed = 200.0f;
}

Unit2::Unit2(Scene* scene) : Unit(scene)
{
	Animation* stand_left = new Animation("image/Unit/2/stand/left", 1, 0);
	Animation* stand_right = new Animation("image/Unit/2/stand/left", 1, 0);
	stand_right->scaleCenter = stand_right->center();
	stand_right->scale.x = -1;
	clips[STAND] = new Clip(this, stand_left, stand_right);
	addChild(clips[STAND]);

	Animation* run_left = new Animation("image/Unit/2/left", 4, 12);
	Animation* run_right = new Animation("image/Unit/2/left", 4, 12);
	run_right->scaleCenter = run_right->center();
	run_right->scale.x = -1;
	clips[RUN] = new Clip(this, run_left, run_right);
	clips[RUN]->visible = false;
	addChild(clips[RUN]);

	Animation* attack_left = new Animation("image/Unit/2/left", 4, 12);
	Animation* attack_right = new Animation("image/Unit/2/left", 4, 12);
	attack_right->scaleCenter = attack_right->center();
	attack_right->scale.x = -1;
	clips[ATTACK] = new Clip(this, attack_left, attack_right);
	clips[ATTACK]->visible = false;
	addChild(clips[ATTACK]);

	Animation* knockback_left = new Animation("image/Unit/2/knockback/left", 1, 0);
	Animation* knockback_right = new Animation("image/Unit/2/knockback/left", 1, 0);
	knockback_right->scaleCenter = knockback_right->center();
	knockback_right->scale.x = -1;
	clips[KNOCKBACK] = new Clip(this, knockback_left, knockback_right);
	clips[KNOCKBACK]->visible = false;
	addChild(clips[KNOCKBACK]);

	Animation* die_left = new Animation("image/Unit/2/die/left", 1, 0);
	Animation* die_right = new Animation("image/Unit/2/die/left", 1, 0);
	die_right->scaleCenter = die_right->center();
	die_right->scale.x = -1;
	clips[DIE] = new Clip(this, die_left, die_right);
	clips[DIE]->visible = false;
	addChild(clips[DIE]);

	hp.init(100);
	mp.init(100);
	moveSpeed = 400.0f;
}

Unit3::Unit3(Scene* scene) : Unit(scene)
{
	Animation* stand_left = new Animation("image/Unit/3/stand/left", 1, 0);
	Animation* stand_right = new Animation("image/Unit/3/stand/right", 1, 0);
	clips[STAND] = new Clip(this, stand_left, stand_right);
	addChild(clips[STAND]);

	Animation* run_left = new Animation("image/Unit/3/left", 4, 12);
	Animation* run_right = new Animation("image/Unit/3/right", 4, 12);
	clips[RUN] = new Clip(this, run_left, run_right);
	clips[RUN]->visible = false;
	addChild(clips[RUN]);

	Animation* attack_left = new Animation("image/Unit/3/left", 4, 12);
	Animation* attack_right = new Animation("image/Unit/3/right", 4, 12);
	clips[ATTACK] = new Clip(this, attack_left, attack_right);
	clips[ATTACK]->visible = false;
	addChild(clips[ATTACK]);

	Animation* knockback_left = new Animation("image/Unit/3/knockback/left", 1, 0);
	Animation* knockback_right = new Animation("image/Unit/3/knockback/right", 1, 0);
	clips[KNOCKBACK] = new Clip(this, knockback_left, knockback_right);
	clips[KNOCKBACK]->visible = false;
	addChild(clips[KNOCKBACK]);

	Animation* die_left = new Animation("image/Unit/3/die/left", 1, 0);
	Animation* die_right = new Animation("image/Unit/3/die/right", 1, 0);
	clips[DIE] = new Clip(this, die_left, die_right);
	clips[DIE]->visible = false;
	addChild(clips[DIE]);

	hp.init(50);
	mp.init(150);
	moveSpeed = 800.0f;
}