#include "DXUT.h"
#include "Clip.h"
#include "Unit.h"

Clip::Clip(Unit* target, Animation* left, Animation* right) : target(target), left(left), right(right)
{
	left->visible = false;
	addChild(left);
	addChild(right);
}


Clip::~Clip()
{
}

void Clip::update(float dt)
{
	Entity::update(dt);
	if (visible){
		if (target->isRight){
			if (!right->visible){
				left->visible = false;
				right->visible = true;
				right->currentFrame = 0;
				right->update(0);
			}
		}
		else{
			if (!left->visible){
				right->visible = false;
				left->visible = true;
				left->currentFrame = 0;
				left->update(0);
			}
		}
	}
}