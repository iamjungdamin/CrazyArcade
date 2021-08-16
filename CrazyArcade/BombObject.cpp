#include "framework.h"
#include "BombObject.h"
#include "EffectObject.h"

BombObject::BombObject(const string& textureFilePath)
	:Object(textureFilePath)
{
	bombEffect = new EffectObject();
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

const FloatRect& BombObject::GetBoomArea()
{
	return boomArea;
}

bool BombObject::IsDamaging()
{
	return this->bombEffect->IsActive();
}

void BombObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);

	bombEffect->setPosition(this->getPosition());
	bombEffect->Update(deltaTime);

	if (this->isActive)
	{
		lifeTime -= deltaTime;
		bombEffect->SetActive(false);
	}

	if (lifeTime <= 0.f)
	{
		this->isActive = false;
		bombEffect->Start();
		lifeTime = 3.f;

		boomArea = bombEffect->getGlobalBounds();
	}
}

void BombObject::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);
}

void BombObject::Render(RenderTarget* target)
{
	Object::Render(target);

	bombEffect->Render(target);
}
