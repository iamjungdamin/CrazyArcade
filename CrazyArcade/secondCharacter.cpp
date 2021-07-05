#include "framework.h"
#include "secondCharacter.h"

secondCharacter::secondCharacter()
{
	Init();
}

secondCharacter::~secondCharacter()
{
}

void secondCharacter::Init()
{
	Texture* tx = nullptr;
	char filePath[50];
	for (int i = 0; i < 16; i++)
	{
		sprintf(filePath, "Image/2P/trapped%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setPosition(Vector2f(80.f, 240.f));
}

void secondCharacter::Destroy()
{
	AnimationObject::Destroy();
}

void secondCharacter::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
