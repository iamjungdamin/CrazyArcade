#pragma once
#include "Scene.h"

class ButtonObject;

class PracScene : public Scene
{
public:
	PracScene() = delete;
	PracScene(stack <Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	PracScene(const PracScene&) = delete;
	PracScene& operator=(const PracScene&) = delete;
	virtual ~PracScene() = default;

private:
	map<string, ButtonObject*> bts;	//buttons
	Object* doll = nullptr;
	Object* portal = nullptr;
	//View* view;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const Vector2f& mousePostion);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

