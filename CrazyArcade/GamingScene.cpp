#include "framework.h"
#include "GamingScene.h"
#include "Character.h"
#include "secondCharacter.h"
#include "Bubble.h"
#include "BackgroundObject.h"

GamingScene::GamingScene()
{
	Init();
}

GamingScene::GamingScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

GamingScene::~GamingScene()
{
}

void GamingScene::Init()
{
	//Music gaming;
	//gaming.openFromFile("Sound/patritmap.wav");
	//gaming.play();

	vObjects.push_back(new BackgroundObject("Image/BackGround.png"));
	vObjects.push_back(new Character);
	vObjects.push_back(new secondCharacter);
	vObjects.push_back(new Bubble);
}

void GamingScene::Destory()
{
}

void GamingScene::Input(Event* e)
{
}

void GamingScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void GamingScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
