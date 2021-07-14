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
	vObjects.push_back(new BackgroundObject("Image/Bg/login.png"));
}

void LoginScene::Destroy()
{
}

void LoginScene::Input(Event* e)
{
	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::Escape:
			scenes->top()->EndScene();
			break;

		case Keyboard::F7:
			soundSystem->volDown();
			soundSystem->effectVolDown();
			break;

		case Keyboard::F8:
			soundSystem->volUp();
			soundSystem->effectVolUp();
			break;

		case Keyboard::Enter:
			scenes->push(new WaitingScene(scenes, window, soundSystem));
			break;

		default:
			break;
		}
		break;

	case Event::MouseButtonPressed:
		soundSystem->EffectPlay("Click");
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
