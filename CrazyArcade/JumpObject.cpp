#include "framework.h"
#include "JumpObject.h"

JumpObject::JumpObject()
{
}

JumpObject::JumpObject(const string& textureFilePath)
	:Object(textureFilePath)
{
}

JumpObject::JumpObject(const string& textureFilePath, const Vector2f& position)
	: Object(textureFilePath, position)
{
	this->position = position;
}

void JumpObject::Destroy()
{
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
	JumpUpdate(deltaTime);

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		position.x -= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		position.x += 3.f;
	}
	setPosition(position);
}

void JumpObject::Update(const Vector2f& mousePostion)
{
}

void JumpObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
