#include "DXUT.h"
#include "Item.h"
#include "Unit.h"

Item::Item(int code) : code(code)
{
	spr = new Sprite();
	addChild(spr);

	rect = spr->rect;
	BDistance = rect.right / 2;
}


Item::~Item()
{
}


void Item::getItem(Unit* target)
{
	if (target->skillNum < 2){
		SkillState* skill = nullptr;
		if (code == RED){
			skill = new Red(target);
		}
		else if (code == BLUE){
			skill = new Blue(target);
		}
		else if (code == YELLOW){
			skill = new Yellow(target);
		}
		else if (code == GREEN){
			skill = new Green(target);
		}
		else if (code == BLACK){
			skill = new Black(target);
		}
		else if (code == ORANGE){
			skill = new Orange(target);
		}
		else if (code == INDIGO){
			skill = new Indigo(target);
		}
		else if (code == PURPLE){
			skill = new Purple(target);
		}
		else if (code == RAINBOW){
			skill = new Rainbow(target);
		}

		if (skill){
			target->changeSkill(target->skillNum++, skill);
			removeChild(this);
		}
	}
}