#include "framework.h"
#include "ResultScene.h"
#include "ObstacleObject.h"
#include "BackgroundObject.h"

#include "Character.h"
#include "secondCharacter.h"
#include "Bubble.h"

ResultScene::ResultScene()
{
	Init();
}

ResultScene::ResultScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void ResultScene::Init()
{
	backGround = new BackgroundObject("Image/Bg/background.png");

	int activePosition[] = {
		1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
		1, 2, 1, 0, 4, 4, 4, 0, 4, 4, 4, 0, 1, 2, 1,
		1, 1, 0, 4, 0, 1, 0, 4, 0, 1, 0, 4, 0, 1, 1,
		1, 0, 4, 0, 1, 1, 1, 1, 1, 1, 1, 0, 4, 0, 1,
		1, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 1,
		1, 0, 4, 0, 1, 1, 1, 1, 1, 1, 1, 0, 4, 0, 1,
		1, 0, 4, 1, 1, 1, 0, 3, 0, 1, 1, 1, 4, 0, 1,
		1, 1, 0, 4, 0, 1, 1, 1, 1, 1, 0, 4, 0, 1, 1,
		1, 1, 1, 0, 4, 1, 1, 1, 1, 1, 4, 0, 1, 1, 1,
		1, 1, 1, 1, 0, 4, 0, 1, 0, 4, 0, 1, 1, 1, 1,
		1, 1, 0, 1, 1, 0, 4, 4, 4, 0, 1, 1, 0, 1, 1,
		1, 2, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 2, 1,
		1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,

	};

	for (int i = 0; i < 15 * 13; ++i)
	{
		if (activePosition[i] == 2)
		{
			walls.push_back(new ObstacleObject("Image/Bg/wall2.png"));
			walls.data()[i]->setOrigin(
				walls.data()[i]->getTexture()->getSize().x / 2.f, 
				walls.data()[i]->getTexture()->getSize().y / 2.f + walls.data()[i]->getTexture()->getSize().y / 4.f);

			continue;
		}
		else if (activePosition[i] == 3)
		{
			walls.push_back(new ObstacleObject("Image/Bg/wall3.png"));
			walls.data()[i]->setOrigin(walls.data()[i]->getTexture()->getSize().x / 2.f, 138);

			continue;
		}
		else if (activePosition[i] == 4)
		{
			walls.push_back(new ObstacleObject("Image/Bg/wall4.png"));
			continue;
		}
		walls.push_back(new ObstacleObject("Image/Bg/wall1.png"));
	}

	ObstacleInfo info;
	for (int i = 0; i < 13; ++i)
	{
		if (i == 0)
		{
			// 첫줄은 60만큼 띄우기
			info.position.y = 60;
		}
		else
		{
			// 두번째줄부터 40씩 늘어남
			info.position.y = 60 + i * 40;
		}
		// x축
		for (int j = 0; j < 15; ++j)
		{
			//첫줄 40 + 다음줄 이어가기
			info.position.x = 40 + 40 * j;
			info.positionToMap = Vector2i(j, i);
			// 정보를 벡터에 집어넣기
			wallPositions.push_back(info);
		}
	}
	
	// for문이 반대인 이유는 아래쪽이 더 빠르게 그려져야 하기 때문
	for (int i = wallPositions.size() - 1; i > -1; --i)
	{
		// 그릴곳 안그릴곳 체크하기
		if (activePosition[i] >= 1)
		{
			walls.data()[i]->SetActive(true);
		}
		else
		{
			walls.data()[i]->SetActive(false);
		}
		walls.data()[i]->setPosition(wallPositions.data()[i].position);
	}

	animationObjects.push_back(new Character);
	animationObjects.push_back(new secondCharacter);
	animationObjects.push_back(new Bubble);
}

void ResultScene::Destroy()
{
	Scene::Destroy();
}

void ResultScene::Input(Event* e)
{
	Scene::Input(e);

	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::RShift:
			soundSystem->EffectPlay("Bubble");
			break;

		case Keyboard::LShift:
			soundSystem->EffectPlay("Bubble");
			break;

		default:
			break;
		}
		break;

	case Event::MouseButtonPressed:
		break;

	default:
		break;
	}
}

void ResultScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void ResultScene::Render()
{
	if (backGround)
	{
		window->draw(*backGround);
	}

	for (auto& wall : walls)
	{
		if (wall->GetActive())
		{
			window->draw(*wall);
		}
		else
		{
			continue;
		}
	}

	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
		}
	}
}
