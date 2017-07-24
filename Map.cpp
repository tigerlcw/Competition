#include "DXUT.h"
#include "Map.h"
#include "GameScene.h"
#include "BoxObject.h"
#include "CircleObject.h"


Map::Map(Scene* scene, int stage) : scene(scene)
{
	GameScene* GS = (GameScene*)scene;
	if (stage == 1){
		ground = new Sprite("image/map/1stage/bg.png");
		addChild(ground);

		BoxObject* bo11 = new BoxObject(scene, "image/map/1stage/building.png");
		bo11->pos = Vec2(626, 185);
		GS->BOList->addChild(bo11);
		BoxObject* bo12 = new BoxObject(scene, "image/map/1stage/building.png");
		bo12->pos = Vec2(746, 721);
		GS->BOList->addChild(bo12);
		BoxObject* bo13 = new BoxObject(scene, "image/map/1stage/building.png");
		bo13->pos = Vec2(1658, 669);
		GS->BOList->addChild(bo13);

		BoxObject* bo21 = new BoxObject(scene, "image/map/1stage/watertank.png");
		bo21->pos = Vec2(206, 118);
		GS->BOList->addChild(bo21);
		BoxObject* bo22 = new BoxObject(scene, "image/map/1stage/watertank.png");
		bo22->pos = Vec2(1221, 854);
		GS->BOList->addChild(bo22);

		BoxObject* bo31 = new BoxObject(scene, "image/map/1stage/statueofliberty.png");
		bo31->pos = Vec2(1566, 84);
		GS->BOList->addChild(bo31);
		BoxObject* bo32 = new BoxObject(scene, "image/map/1stage/statueofliberty.png");
		bo32->pos = Vec2(152, 876);
		GS->BOList->addChild(bo32);

		CircleObject* co11 = new CircleObject(scene, "image/map/1stage/sinkhole.png");
		co11->pos = Vec2(1060, 227);
		GS->COList->addChild(co11);
	}
	else if (stage == 2){
		ground = new Sprite("image/map/2stage/bg2.png");
		addChild(ground);

		BoxObject* bo11 = new BoxObject(scene, "image/map/2stage/airp.png");
		bo11->pos = Vec2(96, 80);
		GS->BOList->addChild(bo11);
		BoxObject* bo12 = new BoxObject(scene, "image/map/2stage/airp.png");
		bo12->pos = Vec2(860, 616);
		GS->BOList->addChild(bo12);
		BoxObject* bo13 = new BoxObject(scene, "image/map/2stage/airp.png");
		bo13->pos = Vec2(542, 932);
		GS->BOList->addChild(bo13);

		BoxObject* bo21 = new BoxObject(scene, "image/map/2stage/snowman.png");
		bo21->pos = Vec2(1574, 23);
		GS->BOList->addChild(bo21);
		BoxObject* bo22 = new BoxObject(scene, "image/map/2stage/snowman.png");
		bo22->pos = Vec2(820, 52);
		GS->BOList->addChild(bo22);
		BoxObject* bo23 = new BoxObject(scene, "image/map/2stage/snowman.png");
		bo23->pos = Vec2(1336, 785);
		GS->BOList->addChild(bo23);

		BoxObject* bo31 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo31->pos = Vec2(1189, 44);
		GS->BOList->addChild(bo31);
		BoxObject* bo32 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo32->pos = Vec2(1245, 94);
		GS->BOList->addChild(bo32);
		BoxObject* bo33 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo33->pos = Vec2(546, 274);
		GS->BOList->addChild(bo33);
		BoxObject* bo34 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo34->pos = Vec2(639, 302);
		GS->BOList->addChild(bo34);
		BoxObject* bo35 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo35->pos = Vec2(1687, 1000);
		GS->BOList->addChild(bo35);
		BoxObject* bo36 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo36->pos = Vec2(246, 864);
		GS->BOList->addChild(bo36);
		BoxObject* bo37 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo37->pos = Vec2(200, 896);
		GS->BOList->addChild(bo37);
		BoxObject* bo38 = new BoxObject(scene, "image/map/2stage/crevasse.png");
		bo38->pos = Vec2(295, 906);
		GS->BOList->addChild(bo38);
	}
	else if (stage == 3){
		ground = new Sprite("image/map/3stage/bg3.png");
		addChild(ground);

		BoxObject* bo11 = new BoxObject(scene, "image/map/3stage/meteorite.png");
		bo11->pos = Vec2(1401, 122);
		GS->BOList->addChild(bo11);
		BoxObject* bo12 = new BoxObject(scene, "image/map/3stage/meteorite.png");
		bo12->pos = Vec2(1604, 800);
		GS->BOList->addChild(bo12);
		BoxObject* bo13 = new BoxObject(scene, "image/map/3stage/meteorite.png");
		bo13->pos = Vec2(444, 124);
		GS->BOList->addChild(bo13);
		BoxObject* bo14 = new BoxObject(scene, "image/map/3stage/meteorite.png");
		bo14->pos = Vec2(243, 208);
		GS->BOList->addChild(bo14);

		BoxObject* bo21 = new BoxObject(scene, "image/map/3stage/satellite.png");
		bo21->pos = Vec2(1773, 35);
		GS->BOList->addChild(bo21);
		BoxObject* bo22 = new BoxObject(scene, "image/map/3stage/satellite.png");
		bo22->pos = Vec2(1013, 89);
		GS->BOList->addChild(bo22);
		BoxObject* bo23 = new BoxObject(scene, "image/map/3stage/satellite.png");
		bo23->pos = Vec2(553, 964);
		GS->BOList->addChild(bo23);
		BoxObject* bo24 = new BoxObject(scene, "image/map/3stage/satellite.png");
		bo24->pos = Vec2(197, 873);
		GS->BOList->addChild(bo24);

		CircleObject* co11 = new CircleObject(scene, "image/map/3stage/blackhole.png");
		co11->pos = Vec2(648, 152);
		GS->COList->addChild(co11);
		CircleObject* co12 = new CircleObject(scene, "image/map/3stage/blackhole.png");
		co12->pos = Vec2(726, 620);
		GS->COList->addChild(co12);
		CircleObject* co13 = new CircleObject(scene, "image/map/3stage/blackhole.png");
		co13->pos = Vec2(1322, 909);
		GS->COList->addChild(co13);
	}
}


Map::~Map()
{
}

void Map::update(float dt)
{
	Entity::update(dt);
}