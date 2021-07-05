#pragma once
#include "Scene.h"
class GamingScene : public Scene
{
public:
	GamingScene();
	GamingScene(stack <Scene*>* scenes);
	~GamingScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

