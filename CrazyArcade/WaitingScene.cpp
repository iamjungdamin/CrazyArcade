#include "framework.h"
#include "WaitingScene.h"
#include "BackgroundObject.h"
#include "GamingScene.h"

WaitingScene::WaitingScene()
{
	Init();
}

WaitingScene::WaitingScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

WaitingScene::~WaitingScene()
{
}

void WaitingScene::Init()
{
	music.openFromFile("Sound/waiting.wav");
	music.play();
	vObjects.push_back(new BackgroundObject("Image/Waiting.png"));
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
		music.stop();
		scenes->push(new GamingScene);
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
