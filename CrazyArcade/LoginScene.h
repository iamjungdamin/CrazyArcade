#pragma once
#include "Scene.h"
class LoginScene : public Scene
{
public:
	LoginScene();
	LoginScene(stack <Scene*>* scenes);
	~LoginScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

