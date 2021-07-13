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

ResultScene::ResultScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	music.openFromFile("Sound/patritmap.wav");
	//music.play();

	vObjects.push_back(new BackgroundObject("Image/Bg/background.png"));

	// 타일 맵 오브젝트 위치 맞추기
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

	// 위 타일맵에 필요한 오브젝트 텍스쳐를 이용하여 로드하기
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

	// 벽에 대한 정보, (위치 절대 좌표, 위치 타일맵)
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
	
	// 위에서 만든 벽에 대한 정보를 각 오브젝트에 매핑
	// for문이 반대인 이유는 크레이지 아케이드 게임상에서 렌더링 되는것이
	// 아래쪽이 더 빠르게 그려져야한다.
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

	vObjects.push_back(new Character);
	vObjects.push_back(new secondCharacter);
	vObjects.push_back(new Bubble);
}

void ResultScene::Destroy()
{
}

void ResultScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Up:
		break;

	case Keyboard::Down:
		break;

	case Keyboard::Left:
		break;

	case Keyboard::Right:
		break;

	case Keyboard::R:
		break;

	case Keyboard::F:
		break;

	case Keyboard::D:
		break;

	case Keyboard::G:
		break;
	}
}

void ResultScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);

}

void ResultScene::Render(RenderWindow* window)
{
	Scene::Render(window);
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
}
