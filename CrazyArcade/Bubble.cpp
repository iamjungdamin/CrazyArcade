#include "framework.h"
#include "Bubble.h"

Bubble::Bubble()
{
	Init();
}

Bubble::~Bubble()
{
}

void Bubble::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for (int i = 0; i < 4; i++)
	{
		sprintf(filePath, "Image/Bubble/bubble%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setPosition(Vector2f(178.f, 200.f));
}

void Bubble::Destroy()
{
	AnimationObject::Destroy();
}

void Bubble::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
