#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "Scene.h"
#include "Text.h"

class UI :
	public Entity
{
public:
	UI(Scene* scene);
	~UI();

	void update(float dt);

	Scene* scene;

	Text* timeText;

	Sprite* barbase;
	Sprite* p1hpbar;
	Sprite* p1mpbar;
	Sprite* p2hpbar;
	Sprite* p2mpbar;

	Sprite* base_1p[3];
	Sprite* icon_1p[3];
	Sprite* delay_1p[3];
	Sprite* base_2p[3];
	Sprite* icon_2p[3];
	Sprite* delay_2p[3];

	Sprite* win_1p;
	Sprite* win_2p;
};

