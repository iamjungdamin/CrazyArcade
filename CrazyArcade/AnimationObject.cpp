#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "AnimationObject.h"

AnimationObject::AnimationObject()
{
	Init();
}

void AnimationObject::Init()
{
}

void AnimationObject::Destroy()
{
	Object::Destroy();
}

void AnimationObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
}

void AnimationObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void AnimationObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
