#include "framework.h"
#include "WaitingScene.h"
#include "BackgroundObject.h"
#include "GamingScene.h"
#include "ResultScene.h"

WaitingScene::WaitingScene()
{
	Init();
}

WaitingScene::WaitingScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void WaitingScene::Init()
{
	vObjects.push_back(new BackgroundObject("Image/Bg/Waiting.png"));
}

void WaitingScene::Destory()
{
}

void WaitingScene::Input(Event* e)
{
	Scene::Input(e);

	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::F5:
			soundSystem->EffectPlay("Start");
			scenes->push(new ResultScene(scenes, window, soundSystem));
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

void WaitingScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void WaitingScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
