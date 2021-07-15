#pragma once
#include "Scene.h"
class LoginScene : public Scene
{
public:
	LoginScene();
	LoginScene(stack <Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	~LoginScene() = default;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

