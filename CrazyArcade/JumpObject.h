#pragma once
#include "Object.h"

enum STATE
{
	jIDLE,
	jPATROL,
	jCHASE
};

class JumpObject : public Object
{
public:
	JumpObject();
	JumpObject(const string& textureFilePath);
	JumpObject(const string& textureFilePath, const Vector2f& position);
	virtual ~JumpObject() = default;

private:
	Vector2f position{ 0.f,0.f };
	Vector2f velocity{ 0.f,0.f };
	Vector2f acceleration{ 0.f,0.f };

	Vector2f patrolPosition = { 0.f, 0.f };
	int state = jIDLE;

	float speed = 50.f;
	float gravity = 2.f;

public:
	virtual void Destroy();

	void JumpUpdate(const float& deltaTime);
	void Jump();
	void TargetMove(const Vector2f& targetPosition);
	
	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePostion);
	virtual void Render(RenderTarget* target);
};

