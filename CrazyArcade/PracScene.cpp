#include "framework.h"
#include "PracScene.h"

#include "ButtonObject.h"
#include "Character.h"
#include "JumpObject.h"

#include "PracMap.h"
#include "Object.h"
#include "BulletManager.h"
#include "MonsterObject.h"
#include "BombObject.h"
#include "EffectObject.h"

#include "WallObject.h"
#include "WallManager.h"
#include "CrossBomb.h"
#include "MonsterManager.h"

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

	monsterMgr = new MonsterManager();

	bomb = new BombObject("Textures/bubble.png");
	bomb->setPosition(200.f, 200.f);

	effect = new EffectObject();

	wallMgr = new WallManager(10);

	WallObject* object = new WallObject("Textures/wall1.png", { 300.f,300.f });
	wallMgr->SetWall(object);

	object = new WallObject("Textures/wall3.png", { 400.f,500.f });
	wallMgr->SetWall(object);

	newBomb = new CrossBomb();
	newBomb->setPosition(400.f, 200.f);
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

		case Keyboard::Space:
			player->AddBubble();
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

		case Keyboard::B:
			newBomb->SetBomb(player->getPosition());
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

void PracScene::Update(const Vector2f& mousePosition)
{
	mouseCursor->setPosition(mousePosition.x + 32, mousePosition.y - 32);

	if (map)
	{
		map->Update(player);

		if (Mouse::isButtonPressed(Mouse::Right))
		{
			map->Update(mousePosition, tileNumber);
		}
	}

	if (player)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			player->Shoot();
		}
		player->Update(mousePosition);
		player->GetBulletMgr()->GetBullets();

		//for (auto& bullet : *player->GetBulletMgr()->GetBullets())
		//{
		//	for (auto& monster : monsters)
		//	{
		//		if (monster->IsActive() && bullet->IsActive())
		//		{
		//			if (bullet->getGlobalBounds().intersects(monster->getGlobalBounds()))
		//			{
		//				bullet->SetActive(false);
		//				bullet->setPosition({});
		//				monster->SetHp(monster->GetHp() - bullet->GetBulletType());
		//			}
		//		}
		//	}

		//	if (wallMgr)
		//	{
		//		wallMgr->CollisionUpdate(bullet);
		//	}
		//}
	}

	if (monsterMgr)
	{
		monsterMgr->Update(mousePosition);
		monsterMgr->UpdateWithBullet(player->GetBulletMgr());
		monsterMgr->UpdateWithObject(player);
	}

	if (bomb)
	{
		bomb->Update(mousePosition);
	}

	if (effect)
	{
		effect->Update(mousePosition);
	}

	if (wallMgr)
	{
		wallMgr->Update(mousePosition);
		wallMgr->CollisionUpdate(player);
	}

	if (newBomb)
	{
		newBomb->Update(mousePosition);
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

	if (monsterMgr)
	{
		monsterMgr->Update(deltaTime);
	}

	if (bomb)
	{
		bomb->Update(deltaTime);
	}

	if (effect)
	{
		effect->Update(deltaTime);
	}

	if (wallMgr)
	{
		wallMgr->Update(deltaTime);
	}

	if (newBomb)
	{
		newBomb->Update(deltaTime);
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

	if (monsterMgr)
	{
		monsterMgr->Render(window);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}

	if (bomb)
	{
		bomb->Render(window);
	}

	if (effect)
	{
		effect->Render(window);
	}

	if (wallMgr)
	{
		wallMgr->Render(window);
	}

	if (newBomb)
	{
		newBomb->Render(window);
	}
}
