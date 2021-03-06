#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	MOVE_IDLE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	TRAPPED,
	DIED
};

class CrossBomb;

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

	int state = MOVE_IDLE;
	map<int, vector<Texture*>> characterAnimation;

public:
	CrossBomb* bomb = nullptr;

private:
	virtual void Init(int player = 1);

public:
	virtual void Destroy();

	void AddBubble();

	void setState(int state);
	int getState();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Render(RenderTarget* target);
};

