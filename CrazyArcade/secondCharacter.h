#pragma once
#include "AnimationObject.h"

class secondCharacter : public AnimationObject
{
public:
	secondCharacter();
	virtual ~secondCharacter();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};

