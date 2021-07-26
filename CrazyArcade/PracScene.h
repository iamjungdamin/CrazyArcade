#pragma once
#include "Scene.h"

class PracMap;

class PracScene : public Scene
{
public:
	PracScene() = delete;
	PracScene(stack <Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	PracScene(const PracScene&) = delete;
	PracScene& operator=(const PracScene&) = delete;
	virtual ~PracScene() = default;

private:
	PracMap* map = nullptr;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const Vector2f& mousePostion);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

