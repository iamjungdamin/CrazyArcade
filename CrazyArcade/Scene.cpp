#include "framework.h"
#include "Scene.h"

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:scenes(scenes), window(window), soundSystem(soundSystem)
{
	Init();
}

void Scene::Init()
{
}

bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	quit = true;
}

void Scene::Destroy()
{
	if (backGround)
	{
		backGround->Destroy();
	}

	for (auto& obj : animationObjects)
	{
		obj->Destroy();
	}

	for (auto& obj : staticObjects)
	{
		obj->Destroy();
	}
}

void Scene::Input(Event* e)
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

void Scene::Update(const float& deltaTime)
{
	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			obj->Update(deltaTime);
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			obj->Update(deltaTime);
		}
	}
}

void Scene::Render()
{
	if (backGround)
	{
		window->draw(*backGround);
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
