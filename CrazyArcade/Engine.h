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

public:
	void Init();
	void Destroy();
	void Input();
	void Update();
	void Render();
};
