#include "framework.h"
#include "WaitingScene.h"
#include "BackgroundObject.h"

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
	//Music waiting;
	//waiting.openFromFile("Sound/waiting.wav");
	//waiting.play();

	vObjects.push_back(new BackgroundObject("Image/Waiting.png"));
}

void WaitingScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void WaitingScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
