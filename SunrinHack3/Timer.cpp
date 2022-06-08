#include "DXUT.h"
#include "Timer.h"
#include "World.h"

Timer::Timer()
	:active(false)
{
	onTick = [](){};
	onFinished = [](){};

	world.timers.push_back(this);
}


Timer::~Timer(void)
{
	world.timers.remove(this);
}

void Timer::reset(float duration, int count, bool autoStart)
{
	active = autoStart;
	this->duration.first = 0;
	this->duration.second = 0;
	this->duration.second = duration;
	this->count.second = count;
}

void Timer::update(float dt)
{
	if(!active) return;

	duration.first += dt;
	if(duration.first > duration.second)
	{
		onTick();
		duration.first = 0;
		if(++count.first == count.second)
		{
			active = false;
			onFinished();
			return;
		}
	}
}