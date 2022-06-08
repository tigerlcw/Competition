#pragma once
#include "Scene.h"
#include "Sprite.h"

class SelectScene :
	public Scene
{
public:
	SelectScene();
	~SelectScene();

	void update(float dt);

	Sprite* select;

	Sprite* u1;
	Sprite* u2;
	Sprite* u3;

	Sprite* slt_1p;
	Sprite* slt_2p;

	int sltNum;
	int slt_1p_code;
	int slt_2p_code;
};

