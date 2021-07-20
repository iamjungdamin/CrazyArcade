#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	TRAPPED,
	DIED
};

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:
	vector<Texture*> upAnimation;
	vector<Texture*> downAnimation;
	vector<Texture*> leftAnimation;
	vector<Texture*> rightAnimation;
	vector<Texture*> trappedAnimation;
	vector<Texture*> diedAnimation;

	int state = IDLE;
	map<int, vector<Texture*>> stateAnimation;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input();
	virtual void Update(const float& deltaTime);
};

