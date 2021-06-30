#pragma once

//전방선언
class AnimationObject;

//게임 전체를 이르는 클래스
class Engine final
{
public:
	Engine();
	~Engine();

private:
	RenderWindow* window = nullptr;
	Event evt;

	Clock timer;
	float deltaTime = 0.f;

	AnimationObject* obj = nullptr;

private:
	void Init();
	void Input();
	void Update();

public:
	void Destroy();
	void Render();
};
