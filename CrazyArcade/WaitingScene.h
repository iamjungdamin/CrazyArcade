#pragma once
#include "Scene.h"
class WaitingScene : public Scene
{
public:
	WaitingScene();
	WaitingScene(stack <Scene*>* scenes);
	~WaitingScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

