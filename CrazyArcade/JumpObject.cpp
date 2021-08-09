#include "framework.h"
#include "JumpObject.h"
#include "BulletManager.h"
#include "BubbleManager.h"

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

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		position.x -= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		position.x += 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		position.y -= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		position.y += 3.f;
	}
	setPosition(position);

	if (bulletMgr)
	{
		bulletMgr->Update(deltaTime);
	}

	if (bubbleMgr)
	{
		bubbleMgr->Update(deltaTime);
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
