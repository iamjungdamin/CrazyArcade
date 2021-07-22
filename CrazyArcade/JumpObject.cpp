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
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		position.y -= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		position.y += 3.f;
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
