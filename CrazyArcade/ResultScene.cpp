#include "framework.h"
#include "ResultScene.h"
#include "ObstacleObject.h"
#include "BackgroundObject.h"

#include "Character.h"
#include "CrossBomb.h"

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

	soundSystem->MusicPlay("patrit");

	int activePosition[] = {
		1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
		1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1,
		1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 1, 0, 3, 0, 1, 1, 0, 0, 0, 1,
		1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
		1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
		1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
		1, 2, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 2, 1,
		1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1
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
			info.position.y = 60;
		}
		else
		{
			info.position.y = (float)60 + i * 40;
		}
		for (int j = 0; j < 15; ++j)
		{
			info.position.x = (float)40 + 40 * j;
			info.positionToMap = Vector2i(j, i);
			wallPositions.push_back(info);
		}
	}
	
	// for문이 반대인 이유는 아래쪽이 더 빠르게 그려져야 하기 때문
	for (int i = wallPositions.size() - 1; i > -1; --i)
	{
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

	players[1] = new Character(1);
	players[2] = new Character(2);

	bBomb = new CrossBomb();
	dBomb = new CrossBomb();

	timerFont.loadFromFile("Font/lucon.ttf");
	timerText.setFont(timerFont);
	timerText.setFillColor(Color::Yellow);
	timerText.setStyle(Text::Bold);
	timerText.setCharacterSize(15);
	timerText.setPosition(715, 70);
	timerText.setString("3:00");
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

		// TODO: 플레이어 위치 받아서 칸 안에 물풍선 놓기
		// getPosition() 함수 사용하여 위치받고 13행 15열으로 나눠서

		case Keyboard::LShift:
			soundSystem->EffectPlay("Bubble");
			bBomb->SetBomb(players[1]->getPosition());
			break;

		case Keyboard::RShift:
			soundSystem->EffectPlay("Bubble");
			dBomb->SetBomb(players[2]->getPosition());
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

	timer -= deltaTime;
	int min = timer / 3600;
	int sec = (timer % 3600) / 60;

	if (timer % 60 == 0)
	{
		string timerString = to_string(min) + ":" + to_string(sec);
		timerText.setString(timerString);
	}

	for (auto& p : players)
	{
		p.second->Update(deltaTime);
	}

	if (bBomb)
	{
		bBomb->Update(deltaTime);
	}

	if (dBomb)
	{
		dBomb->Update(deltaTime);
	}

	CollisionUpdate();

	if (players[1]->getState() == TRAPPED)
	{
		trappedTime += deltaTime;

		if (trappedTime > 3.f)
		{
			players[1]->setState(DIED);
			cout << players[1]->getState();

			trappedTime = 0.f;
		}
	}

	if (players[2]->getState() == TRAPPED)
	{
		trappedTime += deltaTime;

		if (trappedTime > 3.f)
		{
			players[2]->setState(DIED);
			cout << players[2]->getState();

			trappedTime = 0.f;
		}
	}
}

void ResultScene::CollisionUpdate()
{
	if (bBomb && bBomb->getState() == cbBOOM)
	{
		if (players[1]->getGlobalBounds().intersects(bBomb->getGlobalBounds()))
		{
			players[1]->setState(TRAPPED);
		}

		if (players[2]->getGlobalBounds().intersects(bBomb->getGlobalBounds()))
		{
			players[2]->setState(TRAPPED);
		}
	}

	if (dBomb && dBomb->getState() == cbBOOM)
	{
		if (players[1]->getGlobalBounds().intersects(dBomb->getGlobalBounds()))
		{
			players[1]->setState(TRAPPED);
		}

		if (players[2]->getGlobalBounds().intersects(dBomb->getGlobalBounds()))
		{
			players[2]->setState(TRAPPED);
		}
	}
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

	if (bBomb)
	{
		bBomb->Render(window);
	}

	if (dBomb)
	{
		dBomb->Render(window);
	}

	for (auto& p : players)
	{
		window->draw(*p.second);
	}

	window->draw(timerText);
}
