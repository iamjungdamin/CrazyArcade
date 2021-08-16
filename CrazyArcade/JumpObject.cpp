#include "framework.h"
#include "JumpObject.h"
#include "BulletManager.h"
#include "BubbleManager.h"
#include "WallManager.h"

JumpObject::JumpObject()
{
}

JumpObject::JumpObject(const string& textureFilePath)
	:Object(textureFilePath)
{
	bulletMgr = new BulletManager(100);
	bubbleMgr = new BubbleManager(10);
}

JumpObject::JumpObject(const string& textureFilePath, const Vector2f& position)
	: Object(textureFilePath, position)
{
	this->position = position;
	bulletMgr = new BulletManager(100);
	bubbleMgr = new BubbleManager(10);
}

void JumpObject::Destroy()
{
}

BulletManager* JumpObject::GetBulletMgr()
{
	return bulletMgr;
}

BubbleManager* JumpObject::GetBubbleMgr()
{
	return bubbleMgr;
}

const Vector2f& JumpObject::GetDirection()
{
	return this->direction;
}

void JumpObject::SetDirection(const Vector2f& direction)
{
	this->direction = direction;
	position += direction;
	setPosition(position);
}

void JumpObject::JumpUpdate(const float& deltaTime)
{
	if (position.y < 500.f)
	{
		velocity.y += gravity * speed * deltaTime;
	}
	else if (position.y > 500.f)
	{
		position.y = 500.f;
	}

	velocity += acceleration * speed * deltaTime;
	position += velocity;
}

void JumpObject::Jump()
{
	velocity.y = -20.f;
}

void JumpObject::Shoot()
{
	if (bulletMgr)
	{
		if (shootCoolTime <= 0.f)
		{
			bulletMgr->Shoot({ Math::Normalize(bulletTargetPosition,position) }, position, 600.f);
			shootCoolTime = 0.1f;
		}
	}
}

void JumpObject::AddBubble()
{
	if (bubbleMgr)
	{
		if (addBubbleCoolTime <= 0.f)
		{
			bubbleMgr->AddBubble(this->getPosition());
			addBubbleCoolTime = 0.5f;
		}
	}
}

void JumpObject::TargetMove(const Vector2f& targetPosition)
{
	float length = Math::Length(targetPosition.x - getPosition().x, targetPosition.y - getPosition().y);
	
	if (length < 300.f)
	{
		state = jCHASE;
	}
	else
	{
		state = jPATROL;
	}

	switch (state)
	{
	case jIDLE:
		break;

	case jPATROL:
		position += Math::Normalize(patrolPosition, position);
		break;

	case jCHASE:
		position += Math::Normalize(targetPosition, position);
		break;

	default:
		break;
	}

	setPosition(position);
}

void JumpObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	//JumpUpdate(deltaTime);
	shootCoolTime -= deltaTime;
	addBubbleCoolTime -= deltaTime;

	direction = { 0.f,0.f };

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		direction = { -1.f, 0.f };
		direction *= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		direction = { 1.f, 0.f };
		direction *= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		direction = { 0.f, -1.f };
		direction *= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		direction = { 0.f, 1.f };
		direction *= 3.f;
	}
	position += direction;

	setPosition(position);

	if (bulletMgr)
	{
		bulletMgr->Update(deltaTime);
	}

	if (bubbleMgr)
	{
		bubbleMgr->Update(deltaTime);
		bubbleMgr->DamageBoom(this);
	}

	if (wallMgr)
	{
		wallMgr->Update(deltaTime);
	}
}

void JumpObject::Update(const Vector2f& mousePostion)
{
	bulletTargetPosition = mousePostion;
	
	if (bulletMgr)
	{
		bulletMgr->Update(mousePostion);
	}

	if (bubbleMgr)
	{
		bubbleMgr->Update(mousePostion);
	}
}

void JumpObject::Render(RenderTarget* target)
{
	Object::Render(target);

	if (bulletMgr)
	{
		bulletMgr->Render(target);
	}

	if (bubbleMgr)
	{
		bubbleMgr->Render(target);
	}
}
