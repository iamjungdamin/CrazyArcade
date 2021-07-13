#pragma once
#include "Scene.h"

struct ObstacleInfo
{
	Vector2f position{ 0.f, 0.f };
	Vector2i positionToMap{ 0, 0 };
};

class ObstacleObject;

class ResultScene : public Scene
{
public:
	ResultScene();
	ResultScene(stack<Scene*>* scenes, RenderWindow* window);
	~ResultScene();

private:
	Music music;

	vector<ObstacleObject*> walls;
	vector<ObstacleInfo> wallPositions;

	int* activeWalls = nullptr;
	map<ObstacleObject*, int> mObjects;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

