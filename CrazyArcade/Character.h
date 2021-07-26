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
	Character(int player);
	virtual ~Character();

private:
	vector<Texture*> idleAnimation;
	vector<Texture*> upAnimation;
	vector<Texture*> downAnimation;
	vector<Texture*> leftAnimation;
	vector<Texture*> rightAnimation;
	vector<Texture*> trappedAnimation;
	vector<Texture*> diedAnimation;

	int player;
	
	int bubMax, fluidMax, speed;

	// TODO: 능력치 설정
	// 기본 능력치는 각각 다르고 아이템이랑 충돌시 +1씩

	int state = IDLE;
	map<int, vector<Texture*>> characterAnimation;

private:
	virtual void Init(int player = 1);

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};

