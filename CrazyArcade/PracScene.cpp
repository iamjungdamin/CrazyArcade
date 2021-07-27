#include "framework.h"
#include "PracScene.h"

#include "ButtonObject.h"
#include "Character.h"
#include "JumpObject.h"

#include "PracMap.h"
#include "Object.h"

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
		case Keyboard::Space:
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
			map->Update(mousePostion, tileNumber);
		}
	}
}

void PracScene::Update(const float& deltaTime)
{
	if (mouseCursor)
	{
		mouseCursor->Update(deltaTime);
	}
}

void PracScene::Render()
{
	if (map)
	{
		window->draw(*map);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}
}

