#pragma once
#include "Scene.h"
#include "Unit.h"

#define ATTACK_KEY_DELAY 0.2f

struct KeyValue{
	int up;
	int down;
	int left;
	int right;

	int skill1;
	int skill2;
	int skill3;

	void init(int up, int down, int left, int right, int skill1, int skill2, int skill3){
		this->up = up;
		this->down = down;
		this->left = left;
		this->right = right;

		this->skill1 = skill1;
		this->skill2 = skill2;
		this->skill3 = skill3;
	}
};

class Controller{
public:
	Controller(Unit* target);
	~Controller();

	void update(float dt);
	void moveControl(float dt);
	void attackControl(float dt);
	void skillControl(float dt);

	Unit* target;
	KeyValue key;
	int lastMoveKey;
	float attackEventTimer;
};

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void update(float dt);

	Controller* player1;
	Controller* player2;

	Entity* COList;
	Entity* BOList;
	Entity* unitList;
	Entity* itemList;
	Entity* bulletList;
};

