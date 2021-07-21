#pragma once
#include "Object.h"
class AnimationObject : public Object
{
public:
	AnimationObject();
	AnimationObject(const AnimationObject&) = delete;
	AnimationObject& operator = (const AnimationObject&) = delete;
	virtual ~AnimationObject() = default;

protected:
	vector<Texture*> vAnimation;
	size_t keyFrame = 0;
	float elapsedTime;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Render(RenderTarget* target);
};

