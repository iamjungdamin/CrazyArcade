#pragma once
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

private:
	void Init();
	void Input();
	void Update();

public:
	void Destroy();
	void Render();
};
