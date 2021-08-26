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

	// TODO: �ɷ�ġ ����
	// �⺻ �ɷ�ġ�� ���� �ٸ��� �������̶� �浹�� +1��

	int state = MOVE_IDLE;
	map<int, vector<Texture*>> characterAnimation;

private:
	virtual void Init(int player = 1);

public:
	virtual void Destroy();

	void AddBubble();

	virtual void Update(const float& deltaTime);
};

