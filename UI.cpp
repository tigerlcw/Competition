#include "DXUT.h"
#include "UI.h"
#include "GameScene.h"


UI::UI(Scene* scene) : scene(scene)
{
	barbase = new Sprite("image/ui/hpbarbase.png");
	barbase->setCenter(Vec2(960, 70));
	addChild(barbase);

	timeText = new Text("10:10", 130, D3DXCOLOR(1, 1, 1, 1));
	timeText->setCenter(Vec2(960 - 140, 5));
	addChild(timeText);

	p1hpbar = new Sprite("image/ui/1php.png");
	p1hpbar->pos = Vec2(240, 55);
	addChild(p1hpbar);
	p1mpbar = new Sprite("image/ui/1pmp.png");
	p1mpbar->pos = Vec2(240, 85);
	addChild(p1mpbar);

	p2hpbar = new Sprite("image/ui/2php.png");
	p2hpbar->pos = Vec2(1122, 55);
	addChild(p2hpbar);
	p2mpbar = new Sprite("image/ui/2pmp.png");
	p2mpbar->pos = Vec2(1122, 85);
	addChild(p2mpbar);

	for (int i = 0; i < 3; i++){
		base_1p[i] = new Sprite("image/ui/icon_base.png");
		base_1p[i]->pos = Vec2(30 + 60 * i, 980);
		addChild(base_1p[i]);

		delay_1p[i] = new Sprite("image/ui/icon_cover.png");
		delay_1p[i]->setCenter(base_1p[i]->center());
		addChild(delay_1p[i]);

		base_2p[i] = new Sprite("image/ui/icon_base.png");
		base_2p[i]->pos = Vec2(1710 + 60 * i, 980);
		addChild(base_2p[i]);

		delay_2p[i] = new Sprite("image/ui/icon_cover.png");
		delay_2p[i]->setCenter(base_2p[i]->center());
		addChild(delay_2p[i]);
	}

	win_1p = new Sprite("image/ui/1pwin.png");
	win_1p->visible = false;
	addChild(win_1p);

	win_2p = new Sprite("image/ui/2pwin.png");
	win_2p->visible = false;
	addChild(win_2p);
}


UI::~UI()
{
}

void UI::update(float dt)
{
	Entity::update(dt);
	GameScene* GS = (GameScene*)scene;
	Unit* u1 = GS->player1->target;
	Unit* u2 = GS->player2->target;

	int minute = (int)GS->gameTime / 60;
	int second = (int)GS->gameTime % 60;
	char ch[10];

	sprintf(ch, "%.02d:%.02d", minute, second);
	timeText->text = ch;

	p1hpbar->visibleRect.left = p1hpbar->rect.right - p1hpbar->rect.right * u1->hp.current / u1->hp.max;
	p1mpbar->visibleRect.left = p1mpbar->rect.right - p1mpbar->rect.right * u1->mp.current / u1->mp.max;
	p1hpbar->pos.x = 240 + p1hpbar->visibleRect.left;
	p1mpbar->pos.x = 240 + p1mpbar->visibleRect.left;
	
	p2hpbar->visibleRect.right = p2hpbar->rect.right * u2->hp.current / u2->hp.max;
	p2mpbar->visibleRect.right = p2mpbar->rect.right * u2->mp.current / u2->mp.max;

	for (int i = 0; i < 3; i++){
		delay_1p[i]->visibleRect.top = delay_1p[i]->rect.bottom - delay_1p[i]->rect.bottom * u1->skill[i]->Timer.first / u1->skill[i]->Timer.second;
		delay_2p[i]->visibleRect.top = delay_2p[i]->rect.bottom - delay_2p[i]->rect.bottom * u2->skill[i]->Timer.first / u2->skill[i]->Timer.second;
		delay_1p[i]->pos.y = 980 + delay_1p[i]->visibleRect.top;
		delay_2p[i]->pos.y = 980 + delay_2p[i]->visibleRect.top;
	}
}