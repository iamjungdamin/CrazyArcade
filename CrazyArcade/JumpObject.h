#pragma once
#include "Object.h"

enum STATE
{
	jIDLE,
	jPATROL,
	jCHASE
};

class BulletManager;
class BubbleManager;
class WallManager;

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
	Vector2f direction{ 0.f,0.f };

	Vector2f patrolPosition = { 0.f, 0.f };
	int state = jIDLE;

	float speed = 50.f;
	float gravity = 2.f;

	BulletManager* bulletMgr = nullptr;
	float shootCoolTime = 0.1f;

	Vector2f bulletTargetPosition{ 0.f, 0.f };

	BubbleManager* bubbleMgr = nullptr;
	float addBubbleCoolTime = 0.5f;

	WallManager* wallMgr = nullptr;

public:
	virtual void Destroy();

	BulletManager* GetBulletMgr();
	BubbleManager* GetBubbleMgr();

	const Vector2f& GetDirection();
	void SetDirection(const Vector2f& direction);

	void JumpUpdate(const float& deltaTime);
	void Jump();
	void Shoot();
	void AddBubble();
	void TargetMove(const Vector2f& targetPosition);
	
	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePostion);
	virtual void Render(RenderTarget* target);
};

