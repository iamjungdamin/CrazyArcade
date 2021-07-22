#pragma once
#include "SoundSystem.h"

class Scene;

//���� ��ü�� �̸��� Ŭ����
class Engine final
{
public:
	Engine();
	Engine(const Engine&) = delete;
	Engine& operator= (const Engine&) = delete;
	~Engine();

private:
	RenderWindow* window = nullptr;
	SoundSystem* soundSystem = nullptr;

	Event evt;
	Vector2f mousePosition{ 0.f, 0.f };

	Clock timer;
	float deltaTime = 0.f;

	stack<Scene*> scenes;

private:
	void Init();
	void Input();
	void Update();

public:
	void Destroy();
	void Render();
};
