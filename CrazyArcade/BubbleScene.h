#pragma once
#include "Scene.h"
class BubbleScene : public Scene
{
public:
	BubbleScene();
	BubbleScene(stack <Scene*>* scenes);
	~BubbleScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

