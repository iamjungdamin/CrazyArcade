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
		this->idleAnimation.push_back(tx);
	}

	for (int i = 0; i < 3; i++)
	{
		sprintf(filePath, "Image/Bubble/bomb%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->bombAnimation.push_back(tx);
	}
	
	bubbleAnimation[bIDLE] = idleAnimation;
	bubbleAnimation[bBOMB] = bombAnimation;

	setPosition(Vector2f(178.f, 200.f));
}

void Bubble::Destroy()
{
	AnimationObject::Destroy();
}

void Bubble::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
	elapsedTime += deltaTime;

	if (elapsedTime > 0.2f)
	{
		for (auto& animation : bubbleAnimation)
		{
			if (animation.first == state)
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}
