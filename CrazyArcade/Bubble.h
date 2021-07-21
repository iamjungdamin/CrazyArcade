#pragma once
#include "AnimationObject.h"

enum BUBBLE_STATE
{
	bIDLE,
	bBOMB
};

class Bubble : public AnimationObject
{
public:
	Bubble();
	virtual ~Bubble();

private:
	vector<Texture*> idleAnimation;
	vector<Texture*> bombAnimation;

	int state = bIDLE;
	map<int, vector<Texture*>> bubbleAnimation;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};

