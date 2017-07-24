#pragma once
#include "Define.h"

class Unit;

class SkillState
{
public:
	SkillState(Unit* target);
	virtual ~SkillState();

	virtual void start();
	virtual void update(float dt);

	Unit* target;
	int costMp;
	bool isOn;
	pair<float, float>Timer;
};

class Red :
	public SkillState
{
public:
	Red(Unit* target);
	~Red();

	void start();
};

class Blue :
	public SkillState
{
public:
	Blue(Unit* target);
	~Blue();

	void start();
};

class Yellow :
	public SkillState
{
public:
	Yellow(Unit* target);
	~Yellow();

	void start();
};

class Green :
	public SkillState
{
public:
	Green(Unit* target);
	~Green();

	void start();
};

class Black :
	public SkillState
{
public:
	Black(Unit* target);
	~Black();

	void start();
};

class Orange :
	public SkillState
{
public:
	Orange(Unit* target);
	~Orange();

	void start();
};

class Indigo :
	public SkillState
{
public:
	Indigo(Unit* target);
	~Indigo();

	void start();
};

class Purple :
	public SkillState
{
public:
	Purple(Unit* target);
	~Purple();

	void start();
};

class Rainbow :
	public SkillState
{
public:
	Rainbow(Unit* target);
	~Rainbow();

	void start();
};