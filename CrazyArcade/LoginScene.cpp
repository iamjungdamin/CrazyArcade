#include "framework.h"
#include "LoginScene.h"
#include "BackgroundObject.h"
#include "WaitingScene.h"

LoginScene::LoginScene()
{
	Init();
}

LoginScene::LoginScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

LoginScene::~LoginScene()
{
}

void LoginScene::Init()
{
	vObjects.push_back(new BackgroundObject("Image/login.png"));
}

void LoginScene::Destroy()
{
}

void LoginScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Escape:
		scenes->top()->EndScene();
		break;

	case Keyboard::Enter:
		scenes->push(new WaitingScene(scenes));
		break;

	default:
		break;
	}
}

void LoginScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
