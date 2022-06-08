#include "DXUT.h"
#include "MainScene.h"
#include "World.h"
#include "SelectScene.h"
#include "Asset.h"

MainScene::MainScene()
{
	main = new Sprite("image/main/main.png");
	addChild(main);

	logo = new Sprite("image/main/logo.png");
	logo->setCenter(Vec2(960, 100));
	addChild(logo);

	btn_start = new Sprite("image/main/start.png");
	btn_start->setCenter(Vec2(300, 540));
	addChild(btn_start);

	btn_howto = new Sprite("image/main/howto.png");
	btn_howto->setCenter(Vec2(1620, 540));
	addChild(btn_howto);

	spr_howto = new Sprite("image/howto.png");
	spr_howto->visible = false;
	addChild(spr_howto);

	asset.getSound(L"sound/maintitle.wav")->Play();
	asset.getSound(L"sound/stage1.wav");
	asset.getSound(L"sound/stage2.wav");
	asset.getSound(L"sound/stage3.wav");
}


MainScene::~MainScene()
{
}


void MainScene::update(float dt)
{
	Scene::update(dt);

	if (!asset.sounds[L"sound/maintitle.wav"]->IsSoundPlaying()){
		asset.sounds[L"sound/maintitle.wav"]->Play();
	}

	if (world.getKeyState(VK_LBUTTON) == -1){
		if (spr_howto->visible){
			spr_howto->visible = false;
		}
		else{
			Vec2 MP = world.getMousePos();
			Rect MR = Rect(-1, -1, 1, 1);

			if (btn_start->rectWithPos().intersects_Rect(MR, MP)){
				world.changeScene(new SelectScene());
				return;
			}
			if (btn_howto->rectWithPos().intersects_Rect(MR, MP)){
				spr_howto->visible = true;
			}
		}
	}
}