#include "framework.h"
#include "LoginScene.h"
#include "BackgroundObject.h"
#include "WaitingScene.h"

LoginScene::LoginScene()
{
	Init();
}

LoginScene::LoginScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void LoginScene::Init()
{
	backGround = new BackgroundObject("Image/Bg/login.png");

	soundSystem->MusicPlay("login");
}

void LoginScene::Destroy()
{
	Scene::Destroy();
}

void LoginScene::Input(Event* e)
{
	Scene::Input(e);

	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::Enter:
			soundSystem->MusicStop("login");
			scenes->push(new WaitingScene(scenes, window, soundSystem));
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

void LoginScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void LoginScene::Render()
{
	Scene::Render();
}
