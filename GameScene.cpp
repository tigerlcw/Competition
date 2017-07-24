#include "DXUT.h"
#include "GameScene.h"
#include "World.h"
#include "CircleObject.h"
#include "BoxObject.h"
#include "Item.h"
#include "MainScene.h"
#include "Asset.h"


GameScene::GameScene(int _1pCode, int _2pCode) : isGame(false), gameTime(15.0f)
{
	ui = new UI(this);

	COList = new Entity();
	addChild(COList);

	BOList = new Entity();
	addChild(BOList);

	unitList = new Entity();
	addChild(unitList);

	itemList = new Entity();
	addChild(itemList);

	bulletList = new Entity();
	addChild(bulletList);

	Unit* u1;
	if (_1pCode == 3){
		u1 = new Unit1(this);
	}
	else if (_1pCode == 2){
		u1 = new Unit2(this);
	}
	else if (_1pCode == 1){
		u1 = new Unit3(this);
	}
	u1->setCenter(Vec2(100, 540));
	unitList->addChild(u1);

	Unit* u2;
	if (_2pCode == 3){
		u2 = new Unit1(this);
	}
	else if (_2pCode == 2){
		u2 = new Unit2(this);
	}
	else if (_2pCode == 1){
		u2 = new Unit3(this);
	}
	u2->setCenter(Vec2(1820, 540));
	//u2->isRight = false;
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

	//player1->target->changeSkill(0, new Black(player1->target), BLACK);
	//player1->target->skillNum++;

	player2 = new Controller(u2);
	player2->key.init(
		VK_UP,
		VK_DOWN,
		VK_LEFT,
		VK_RIGHT,
		VK_OEM_COMMA,
		VK_OEM_PERIOD,
		VK_OEM_2);
	
	stage = random(1, 3);
	stageMap = new Map(this, stage);

	if (stage == 1){
		asset.sounds[L"sound/stage1.wav"]->Play();
	}
	else if (stage == 2){
		asset.sounds[L"sound/stage2.wav"]->Play();
	}
	else if (stage == 3){
		asset.sounds[L"sound/stage3.wav"]->Play();
	}

	for (int i = 0; i < 10; i++){
		creatItem(random(RED, RAINBOW));
	}
}


GameScene::~GameScene()
{
	SAFE_DELETE(ui);
	SAFE_DELETE(stageMap);
	SAFE_DELETE(player1);
	SAFE_DELETE(player2);
}

void GameScene::render()
{
	stageMap->render();
	Scene::render();
	ui->render();
}

void GameScene::update(float dt)
{
	if (stage == 1){
		if (!asset.sounds[L"sound/stage1.wav"]->IsSoundPlaying()){
			asset.sounds[L"sound/stage1.wav"]->Play();
		}
	}
	else if (stage == 2){
		if (!asset.sounds[L"sound/stage2.wav"]->IsSoundPlaying()){
			asset.sounds[L"sound/stage2.wav"]->Play();
		}
	}
	else if (stage == 3){
		if (!asset.sounds[L"sound/stage3.wav"]->IsSoundPlaying()){
			asset.sounds[L"sound/stage3.wav"]->Play();
		}
	}

	if (ui->win_1p->visible ||
		ui->win_2p->visible){
		ui->update(dt);

		if (world.getKeyState(VK_LBUTTON) == 1){
			world.changeScene(new MainScene());
			return;
		}
		return;
	}

	player1->update(dt);
	player2->update(dt);

	Scene::update(dt);

	if (isGame){
		gameTime += dt;
	}
	else{
		gameTime -= dt;
		if (gameTime <= 0.0f){
			gameTime = 0.0f;
			isGame = true;
		}
	}

	ui->update(dt);
}

void GameScene::creatItem(int code)
{
	Item* i = new Item(code);
	while (true){
		i->pos = Vec2(random(0, 1920 - i->rect.right), random(0, 1080 - i->rect.bottom));
		bool spawn = true;
		for_iter(iter, BOList->children){
			BoxObject* bo = (BoxObject*)*iter;
			if (bo->rectWithPos().intersects_Rect(i->rect, i->pos)){
				spawn = false;
				break;
			}
		}
		if (!spawn) continue;
		for_iter(iter, COList->children){
			CircleObject* co = (CircleObject*)*iter;
			float distance = pita(i->center(), co->center());
			if (distance < i->BDistance + co->BDistance){
				spawn = false;
			}
		}
		if (!spawn) continue;
		for_iter(iter, itemList->children){
			Item* i2 = (Item*)*iter;
			float distance = pita(i->center(), i2->center());
			if (distance < i->BDistance + i2->BDistance){
				spawn = false;
			}
		}
		if (!spawn) continue;
		break;
	}
	itemList->addChild(i);
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
			if (distance < target->BDistance + i->BDistance){
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
		if (target->skill[0]->isOn && target->mp.current >= target->skill[0]->costMp){
			target->skill[0]->start();
		}
	}
	if (world.getKeyState(key.skill2) == 1){
		if (target->skill[1]->isOn && target->mp.current >= target->skill[1]->costMp){
			target->skill[1]->start();
		}
	}
	if (world.getKeyState(key.skill3) == 1){
		if (target->skill[2]->isOn && target->mp.current >= target->skill[2]->costMp){
			target->skill[2]->start();
		}
	}
}