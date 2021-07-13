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
	switch (e->key.code)
	{
	case Keyboard::Escape:
		scenes->top()->EndScene();
		break;

	case Keyboard::F5:
		scenes->push(new ResultScene(scenes, window, soundSystem));
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
