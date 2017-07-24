#include "DXUT.h"
#include "GameScene.h"
#include "World.h"
#include "CircleObject.h"
#include "BoxObject.h"
#include "Item.h"


GameScene::GameScene()
{
	COList = new Entity();
	addChild(COList);

	BOList = new Entity();
	addChild(BOList);

	unitList = new Entity();
	addChild(unitList);

	itemList = new Entity();
	addChild(itemList);

	Unit* u1 = new Unit1(this);
	unitList->addChild(u1);

	Unit* u2 = new Unit3(this);
	unitList->addChild(u2);

	player1 = new Controller(u1);
	player1->key.init(
		'W',
		'S', 
		'A',
		'D',
		'F',
		'G',
		'H');

	player1->target->changeSkill(0, new Yellow(player1->target));

	player2 = new Controller(u2);
	player2->key.init(
		VK_UP,
		VK_DOWN,
		VK_LEFT,
		VK_RIGHT,
		VK_OEM_COMMA,
		VK_OEM_PERIOD,
		VK_OEM_2);

	BoxObject* bo = new BoxObject(this);
	bo->pos = Vec2(300, 300);
	BOList->addChild(bo);
	CircleObject* co = new CircleObject(this);
	co->pos = Vec2(600, 300);
	COList->addChild(co);
}


GameScene::~GameScene()
{
	SAFE_DELETE(player1);
	SAFE_DELETE(player2);
}

void GameScene::update(float dt)
{

	player1->update(dt);
	player2->update(dt);

	Scene::update(dt);
}

Controller::Controller(Unit* target) : target(target), lastMoveKey(0),
attackEventTimer(0.0f)
{
}

Controller::~Controller()
{
}

void Controller::update(float dt)
{
	if (target->status[STURN].isStatus) return;
	if (target->currentState == DIE) return;
	if (target->currentState != ATTACK &&
		target->currentState != KNOCKBACK){
		moveControl(dt);
		target->unitCollision(dt);
	}
	attackControl(dt);
	skillControl(dt);
}

void Controller::moveControl(float dt)
{
	Vec2 v = Vec2(0, 0);

	if (world.getKeyState(key.up) > 0){
		v.y = -1;
	}
	else if (world.getKeyState(key.down) > 0){
		v.y = 1;
	}

	if (world.getKeyState(key.left) > 0){
		v.x = -1;
		target->isRight = false;
	}
	else if (world.getKeyState(key.right) > 0){
		v.x = 1;
		target->isRight = true;
	}

	float c = sqrt(v.x * v.x + v.y * v.y);
	if (c != 0){
		v /= c;
		target->changeState(RUN);
	}
	else{
		target->changeState(STAND);
	}

	target->moveVector = v;
	target->pos += v * target->moveSpeed * dt;
}

void Controller::attackControl(float dt)
{
	if (attackEventTimer > 0.0f){
		attackEventTimer -= dt;
	}
	else{
		lastMoveKey = 0;
	}

	bool isEvent = false;

	if (world.getKeyState(key.up) == 1){
		if (lastMoveKey == key.up){
			lastMoveKey = 0;
			isEvent = true;
		}
		else{
			lastMoveKey = key.up;
			attackEventTimer = ATTACK_KEY_DELAY;
		}
	}

	if (world.getKeyState(key.down) == 1){
		if (lastMoveKey == key.down){
			lastMoveKey = 0;
			isEvent = true;
		}
		else{
			lastMoveKey = key.down;
			attackEventTimer = ATTACK_KEY_DELAY;
		}
	}

	if (world.getKeyState(key.left) == 1){
		if (lastMoveKey == key.left){
			lastMoveKey = 0;
			isEvent = true;
		}
		else{
			lastMoveKey = key.left;
			attackEventTimer = ATTACK_KEY_DELAY;
		}
	}

	if (world.getKeyState(key.right) == 1){
		if (lastMoveKey == key.right){
			lastMoveKey = 0;
			isEvent = true;
		}
		else{
			lastMoveKey = key.right;
			attackEventTimer = ATTACK_KEY_DELAY;
		}
	}

	if (isEvent){
		GameScene* GS = (GameScene*)target->scene;
		for_iter(iter, GS->itemList->children){
			Item* i = (Item*)*iter;
			float distance = pita(target->center(), i->center());
			if (distance < target->BDistance, i->BDistance){
				i->getItem(target);
			}
		}

		target->changeState(ATTACK);
		//target->setStatus(ATTACK, 1.0f);
	}
}

void Controller::skillControl(float dt)
{
	if (world.getKeyState(key.skill1) == 1){
		target->skill[0]->start();
	}
	if (world.getKeyState(key.skill2) == 1){
		target->skill[1]->start();
	}
	if (world.getKeyState(key.skill3) == 1){
		target->skill[2]->start();
	}
}