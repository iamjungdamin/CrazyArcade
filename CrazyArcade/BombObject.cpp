#include "framework.h"
#include "BombObject.h"

BombObject::BombObject(const string& textureFilePath)
	:Object(textureFilePath)
{
}

void BombObject::Destroy()
{
	Object::Destroy();
}

void BombObject::SetBubble(const Vector2f& position)
{
	setPosition(position);
	this->isActive = true;
	lifeTime = 3.f;
}

void BombObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);

	lifeTime -= deltaTime;

	if (lifeTime <= 0.f)
	{
		this->isActive = false;
	}
}

void BombObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void BombObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
