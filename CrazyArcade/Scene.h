#pragma once
#include "Object.h"
#include "BackgroundObject.h"
#include "ButtonObject.h"
#include "SoundSystem.h"

class Scene
{
public:
	Scene();
	Scene(stack <Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene() = default;

protected:
	Object* backGround = nullptr;
	vector<Object*> animationObjects;
	vector<Object*> staticObjects;

	stack <Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;
	SoundSystem* soundSystem = nullptr;

	bool quit = false;

private:
	virtual void Init();

public:
	bool GetQuit() const;
	void EndScene();
	virtual void Destroy();

	virtual void Input(Event* e);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

