#include "framework.h"
#include "Engine.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(500, 500), "Window");
}

void Engine::Destroy()
{
	if (window)		//if (window != nullptr)
	{
		delete window;
	}
}

void Engine::Input()
{
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
			window->close();
			break;

		default:
			break;
		}
	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds();
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		window->display();
	}
}
