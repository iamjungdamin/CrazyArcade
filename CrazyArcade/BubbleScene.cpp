#include "framework.h"
#include "BubbleScene.h"
#include "Bubble.h"

BubbleScene::BubbleScene()
{
	Init();
}

BubbleScene::BubbleScene(stack<Scene*>* scenes)
	: Scene(scenes)
{
	Init();
}

BubbleScene::~BubbleScene()
{
}

void BubbleScene::Init()
{
	vObjects.push_back(new Bubble);
}

void BubbleScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void BubbleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
