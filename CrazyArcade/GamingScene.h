#pragma once
#include "Scene.h"
class GamingScene : public Scene
{
public:
	GamingScene();
	GamingScene(stack <Scene*>* scenes);
	~GamingScene();

private:
	Music music;

private:
	virtual void Init();

public:
	virtual void Destory();
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

