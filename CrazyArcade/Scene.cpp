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
	for (auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : vObjects)
	{
		window->draw(*obj);
	}
}
