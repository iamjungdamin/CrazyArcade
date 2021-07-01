#pragma once

class Scene;

//���� ��ü�� �̸��� Ŭ����
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

	stack<Scene*> scenes;

private:
	void Init();
	void Input();
	void Update();

public:
	void Destroy();
	void Render();
};
