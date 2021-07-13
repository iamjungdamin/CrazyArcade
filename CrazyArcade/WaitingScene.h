#pragma once
#include "Scene.h"
class WaitingScene : public Scene
{
public:
	WaitingScene();
	WaitingScene(stack <Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	~WaitingScene() = default;

private:
	virtual void Init();

public:
	virtual void Destory();
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

