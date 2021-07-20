#include "framework.h"
#include "Character.h"

Character::Character()
{
	Init();
}

Character::~Character()
{
}

void Character::Init()
{
	Texture* tx = nullptr;
	char filePath[50];

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "Image/dizniup%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->upAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "Image/diznidown%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->downAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "Image/diznileft%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->leftAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "Image/dizniright%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->rightAnimation.push_back(tx);
	}

	for (int i = 0; i < 16; i++)
	{
		sprintf(filePath, "Image/diznitrapped%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->trappedAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "Image/diznidie%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->diedAnimation.push_back(tx);
	}

	stateAnimation[UP] = upAnimation;
	stateAnimation[DOWN] = downAnimation;
	stateAnimation[LEFT] = leftAnimation;
	stateAnimation[RIGHT] = rightAnimation;
	stateAnimation[TRAPPED] = trappedAnimation;
	stateAnimation[DIED] = diedAnimation;

	setPosition(Vector2f(100.f, 100.f));
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Input()
{
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		state = UP;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		state = DOWN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		state = LEFT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		state = RIGHT;
	}
	else {
		state = IDLE;
	}
}

void Character::Update(const float& deltaTime)
{
	Input();
	elapsedTime += deltaTime;

	if (elapsedTime > 0.2f)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == state)
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}

	switch (state)
	{
	case UP:
		move({ 0.f, -2.f });
		break;

	case DOWN:
		move({ 0.f, 2.f });
		break;

	case LEFT:
		move({ -2.f, 0.f });
		break;

	case RIGHT:
		move({ 2.f, 0.f });
		break;

	default:
		move({ 0.f,0.f });
		break;
	}
}
