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

ResultScene::ResultScene(stack<Scene*>* scenes)
	:Scene(scenes)
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

	// Ÿ�� �� ������Ʈ ��ġ ���߱�
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

	// �� Ÿ�ϸʿ� �ʿ��� ������Ʈ �ؽ��ĸ� �̿��Ͽ� �ε��ϱ�
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

	// ���� ���� ����, (��ġ ���� ��ǥ, ��ġ Ÿ�ϸ�)
	ObstacleInfo info;
	for (int i = 0; i < 13; ++i)
	{
		if (i == 0)
		{
			// ù���� 60��ŭ ����
			info.position.y = 60;
		}
		else
		{
			// �ι�°�ٺ��� 40�� �þ
			info.position.y = 60 + i * 40;
		}
		// x��
		for (int j = 0; j < 15; ++j)
		{
			//ù�� 40 + ������ �̾��
			info.position.x = 40 + 40 * j;
			info.positionToMap = Vector2i(j, i);
			// ������ ���Ϳ� ����ֱ�
			wallPositions.push_back(info);
		}
	}
	
	// ������ ���� ���� ���� ������ �� ������Ʈ�� ����
	// for���� �ݴ��� ������ ũ������ �����̵� ���ӻ󿡼� ������ �Ǵ°���
	// �Ʒ����� �� ������ �׷������Ѵ�.
	for (int i = wallPositions.size() - 1; i > -1; --i)
	{
		// �׸��� �ȱ׸��� üũ�ϱ�
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