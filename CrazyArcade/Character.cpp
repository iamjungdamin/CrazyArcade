#include "framework.h"
#include "Character.h"
#include "CrossBomb.h"

Character::Character()
{
	Init();
}

Character::Character(int player)
{
	Init(player);
}

Character::~Character()
{
}

void Character::Init(int player)
{
	Texture* tx = nullptr;
	string Folder;
	char filePath[30];

	if (player == 1)
	{
		this->player = 1;
		Folder = "Image/1P/";
	}
	else
	{
		this->player = 2;
		Folder = "Image/2P/dizniblue";
	}

	tx = new Texture;
	tx->loadFromFile(Folder + "down (0).png");
	this->idleAnimation.push_back(tx);

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "up (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(Folder + filePath);
		this->upAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "down (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(Folder + filePath);
		this->downAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "left (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(Folder + filePath);
		this->leftAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "right (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(Folder + filePath);
		this->rightAnimation.push_back(tx);
	}

	for (int i = 0; i < 16; i++)
	{
		sprintf(filePath, "trapped (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(Folder + filePath);
		this->trappedAnimation.push_back(tx);
	}

	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "die (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(Folder + filePath);
		this->diedAnimation.push_back(tx);
	}

	characterAnimation[MOVE_IDLE] = idleAnimation;
	characterAnimation[MOVE_UP] = upAnimation;
	characterAnimation[MOVE_DOWN] = downAnimation;
	characterAnimation[MOVE_LEFT] = leftAnimation;
	characterAnimation[MOVE_RIGHT] = rightAnimation;
	characterAnimation[TRAPPED] = trappedAnimation;
	characterAnimation[DIED] = diedAnimation;

	if (player == 1)
	{
		setPosition(Vector2f(100.f, 100.f));
	}
	else
	{
		setPosition(Vector2f(420.f, 380.f));
	}

	bomb = new CrossBomb();
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::AddBubble()
{
	bomb->SetBomb(this->getPosition());
	//cout << getPosition().x << ", " << getPosition().y << endl;
}

void Character::setState(int state)
{
	this->state = state;
}

int Character::getState()
{
	return this->state;
}

void Character::Update(const float& deltaTime)
{
	Object::Update(deltaTime);

	elapsedTime += deltaTime;

	if (elapsedTime > 0.2f)
	{
		for (auto& animation : characterAnimation)
		{
			if (animation.first == state)
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);
				if (state >= 0 && state <= 4)
				{
					setTextureRect({ 0,0,42,57 });
				}
				else if (state == TRAPPED)
				{
					setTextureRect({ 0,0,60,65 });
				}
				else if (state == DIED)
				{
					setTextureRect({ 0,0,70,106 });
				}
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}

	if (player == 1) {
		if (Keyboard::isKeyPressed(Keyboard::R)) {
			state = MOVE_UP;
			move({ 0.f, -2.f });
		}
		else if (Keyboard::isKeyPressed(Keyboard::F)) {
			state = MOVE_DOWN;
			move({ 0.f, 2.f });
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			state = MOVE_LEFT;
			move({ -2.f, 0.f });
		}
		else if (Keyboard::isKeyPressed(Keyboard::G)) {
			state = MOVE_RIGHT;
			move({ 2.f, 0.f });
		}
		else
		{
			keyFrame = 0;
		}
	}

	if (player == 2) {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			state = MOVE_UP;
			move({ 0.f, -2.f });
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			state = MOVE_DOWN;
			move({ 0.f, 2.f });
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			state = MOVE_LEFT;
			move({ -2.f, 0.f });
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			state = MOVE_RIGHT;
			move({ 2.f, 0.f });
		}
		else
		{
			keyFrame = 0;
		}
	}

	if (bomb)
	{
		bomb->Update(deltaTime);
	}
}

void Character::Update(const Vector2f& mousePosition)
{
	Object::Update(mousePosition);

	if (bomb)
	{
		bomb->Update(mousePosition);
	}
}

void Character::Render(RenderTarget* target)
{
	Object::Render(target);

	if (bomb)
	{
		bomb->Render(target);
	}
}
