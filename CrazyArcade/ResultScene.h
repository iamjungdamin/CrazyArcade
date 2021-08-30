#pragma once
#include "Scene.h"

struct ObstacleInfo
{
	Vector2f position{ 0.f, 0.f };
	Vector2i positionToMap{ 0, 0 };
};

class ObstacleObject;
class Character;
class CrossBomb;

class ResultScene : public Scene
{
public:
	ResultScene();
	ResultScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	~ResultScene() = default;

private:
	vector<ObstacleObject*> walls;
	vector<ObstacleInfo> wallPositions;

	int* activeWalls = nullptr;
	map<ObstacleObject*, int> mObjects;

	map <int, Character*> players;

	CrossBomb* bBomb = nullptr;
	CrossBomb* dBomb = nullptr;
	float trappedTime = 0.f;

	Font timerFont;
	Text timerText;
	int timer = 60 * 60 * 3;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	
	virtual void Update(const float& deltaTime);
	void CollisionUpdate();

	virtual void Render();
};

