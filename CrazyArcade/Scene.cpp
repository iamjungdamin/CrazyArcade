#include "framework.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes)
	:scenes(scenes)	//부모클래스의 생성자를 그대로 사용해라
{
	Init();
}

Scene::~Scene()
{
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
