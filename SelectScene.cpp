#include "DXUT.h"
#include "SelectScene.h"
#include "World.h"
#include "GameScene.h"
#include "Asset.h"


SelectScene::SelectScene() : sltNum(0), slt_1p_code(0), slt_2p_code(0)
{
	select = new Sprite("image/select/select.png");
	addChild(select);

	u1 = new Sprite("image/select/1.png");
	u1->pos = Vec2(34, -73);
	addChild(u1);
	
	u2 = new Sprite("image/select/2.png");
	u2->pos = Vec2(674, -36);
	addChild(u2);
	
	u3 = new Sprite("image/select/3.png");
	u3->pos = Vec2(1298, -51);
	addChild(u3);

	slt_1p = new Sprite("image/select/1p.png");
	slt_1p->visible = false;
	addChild(slt_1p);

	slt_2p = new Sprite("image/select/2p.png");
	slt_2p->visible = false;
	addChild(slt_2p);
}


SelectScene::~SelectScene()
{
}


void SelectScene::update(float dt)
{
	if (!asset.sounds[L"sound/maintitle.wav"]->IsSoundPlaying()){
		asset.sounds[L"sound/maintitle.wav"]->Play();
	}

	Scene::update(dt);

	if (world.getKeyState(VK_SPACE) == 1){
		if (sltNum == 2){
			slt_2p->visible = false;
			sltNum--;
		}
		else if (sltNum == 1){
			slt_1p->visible = false;
			sltNum--;
		}
	}

	if (world.getKeyState(VK_LBUTTON) == -1){
		Vec2 MP = world.getMousePos();
		Rect MR = Rect(-1, -1, 1, 1);

		if (u1->rectWithPos().intersects_Rect(MR, MP)){
			if (sltNum < 2){
				sltNum++;
				if (sltNum == 1){
					slt_1p->pos = Vec2(30, 150);
					slt_1p_code = 1;
					slt_1p->visible = true;
				}
				else if (sltNum == 2){
					slt_2p->pos = Vec2(30, 150);
					slt_2p_code = 1;
					slt_2p->visible = true;
				}
			}
		}
		if (u2->rectWithPos().intersects_Rect(MR, MP)){
			if (sltNum < 2){
				sltNum++;
				if (sltNum == 1){
					slt_1p->pos = Vec2(660, 150);
					slt_1p_code = 2;
					slt_1p->visible = true;
				}
				else if (sltNum == 2){
					slt_2p->pos = Vec2(660, 150);
					slt_2p_code = 2;
					slt_2p->visible = true;
				}
			}
		}
		if (u3->rectWithPos().intersects_Rect(MR, MP)){
			if (sltNum < 2){
				sltNum++;
				if (sltNum == 1){
					slt_1p->pos = Vec2(1290, 150);
					slt_1p_code = 3;
					slt_1p->visible = true;
				}
				else if (sltNum == 2){
					slt_2p->pos = Vec2(1290, 150);
					slt_2p_code = 3;
					slt_2p->visible = true;
				}
			}
		}
	}

	if (world.getKeyState(VK_RETURN) == 1){
		if (sltNum == 2){
			asset.sounds[L"sound/maintitle.wav"]->Stop();
			world.changeScene(new GameScene(slt_1p_code, slt_2p_code));
			return;
		}
	}
}