#include "framework.h"
#include "PracScene.h"

#include "ButtonObject.h"
#include "Character.h"
#include "JumpObject.h"

#include "PracMap.h"
#include "Object.h"
#include "BulletManager.h"
#include "MonsterObject.h"

PracScene::PracScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes,window,soundSystem)
{
	Init();
}

void PracScene::Init()
{
	vector<int> levels; 

	for (int i = 0; i < 50 * 50; i++)
	{
		levels.push_back(56);
	}

	map = new PracMap("Textures/tileSet.png", { 32,32 }, levels, { 50,50 });

	mouseCursor = new Object("Textures/tileSet.png");
	mouseCursor->setOrigin({});
	mouseCursor->setTextureRect(map->GetTile(tileNumber));

	player = new JumpObject("Image/2P/diznidown (0).png", { 500,500 });

	for (int i = 0; i < 10; ++i)
	{
		monsters.push_back(new MonsterObject("Image/1P/down (0).png", Vector2f(rand() % 1080, rand() % 720)));
	}
}

void PracScene::Destroy()
{
}

void PracScene::Input(Event* e)
{
	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::LControl:
			player->Jump();
			player->setPosition(500.f, 500.f);
			break;

		case Keyboard::F1:
			map->SaveMap("Test.bin");
			break;

		case Keyboard::F2:
			map->LoadMap("Test.bin");
			break;

		case Keyboard::W:
			tileNumber += 10;

			if (tileNumber >= 56 * 23 - 1)
			{
				tileNumber = 56 * 23 - 1;
			}

			mouseCursor->setTextureRect(map->GetTile(tileNumber));
			break;

		case Keyboard::S:
			tileNumber -= 10;

			if (tileNumber <= 56)
			{
				tileNumber = 56;
			}

			mouseCursor->setTextureRect(map->GetTile(tileNumber));
			break;

		default:
			break;
		}
		break;

	case Event::MouseButtonPressed:
		break;

	case Event::MouseWheelScrolled:
		//tileNumber += e->mouseWheel.delta;

		//if (tileNumber <= 56)
		//{
		//	tileNumber = 56;
		//}
		//else if (tileNumber >= 56 * 23 - 1)
		//{
		//	tileNumber = 56 * 23 - 1;
		//}

		//mouseCursor->setTextureRect(map->GetTile(tileNumber));
		break;

	default:
		break;
	}
}

void PracScene::Update(const Vector2f& mousePostion)
{
	mouseCursor->setPosition(mousePostion.x + 32, mousePostion.y - 32);

	if (map)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			player->Shoot();
			//map->Update(mousePostion, tileNumber);
		}
	}

	if (player)
	{
		player->Update(mousePostion);
		cout << player->getPosition().x << ", " << player->getPosition().y << endl;
	}
	player->GetBulletMgr()->GetBullets();
	
	for (auto& bullet : *player->GetBulletMgr()->GetBullets())
	{
		for (auto& monster : monsters)
		{
			if (monster->IsActive() && bullet->IsActive())
			{
				if (bullet->getGlobalBounds().intersects(monster->getGlobalBounds()))
				{
					bullet->SetActive(false);
					bullet->setPosition({});
					monster->SetHp(monster->GetHp() - bullet->GetBulletType());
				}
			}
		}
	}

	for (auto& monster:monsters)
	{
		monster->Update(mousePostion);
	}
}

void PracScene::Update(const float& deltaTime)
{
	if (mouseCursor)
	{
		mouseCursor->Update(deltaTime);
	}

	if (player)
	{
		player->Update(deltaTime);
	}

	for (auto& monster : monsters)
	{
		monster->Update(deltaTime);
	}
}

void PracScene::Render()
{
	if (map)
	{
		window->draw(*map);
	}

	if (player)
	{
		player->Render(window);
	}

	for (auto& monster : monsters)
	{
		monster->Render(window);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}
}

