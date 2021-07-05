#include "framework.h"
#include "LoginScene.h"
#include "BackgroundObject.h"

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

void LoginScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void LoginScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
