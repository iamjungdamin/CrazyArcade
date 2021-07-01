#pragma once
#include "Scene.h"
class CharacterScene : public Scene
{
public:
	CharacterScene();
	CharacterScene(stack <Scene*>* scenes);
	~CharacterScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

