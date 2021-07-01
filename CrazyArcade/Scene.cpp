#include "framework.h"
#include "Scene.h"
#include "Object.h"
#include "Character.h"
#include "Bubble.h"

Scene::Scene()
{
	Init();
}

Scene::~Scene()
{
}

void Scene::Init()
{
	vObjects.push_back(new Character);
	vObjects.push_back(new Bubble);
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
