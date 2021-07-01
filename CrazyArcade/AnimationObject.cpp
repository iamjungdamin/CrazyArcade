#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "AnimationObject.h"

AnimationObject::AnimationObject()
{
	Init();
}

AnimationObject::~AnimationObject()
{
}

void AnimationObject::Init()
{
}

void AnimationObject::Destroy()
{
	for (auto& i : vAnimation)
	{
		delete i;
	}
	vAnimation.clear();
}

void AnimationObject::Update(const float& deltaTime)
{
	elapsedTime += deltaTime;
	
	if (elapsedTime > 0.2f)
	{
		setTexture(*vAnimation.data()[keyFrame % vAnimation.size()]);
		++keyFrame;
		elapsedTime = 0.f;
	}
}
