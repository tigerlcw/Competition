#pragma once
#include "Scene.h"
#include "Sprite.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

	void update(float dt);

	Sprite* main;
	Sprite* logo;
	Sprite* btn_start;
	Sprite* btn_howto;
	Sprite* spr_howto;
};

