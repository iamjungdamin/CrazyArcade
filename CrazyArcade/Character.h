#pragma once
#include "AnimationObject.h"

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};

