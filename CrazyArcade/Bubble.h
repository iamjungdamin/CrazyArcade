#pragma once
#include "AnimationObject.h"
class Bubble : public AnimationObject
{
public:
	Bubble();
	virtual ~Bubble();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};

