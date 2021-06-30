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
	window->setMouseCursorVisible(false);
	Image icon;
	icon.loadFromFile("Textures/icon.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
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

		case Event::KeyPressed:
			switch (evt.key.code)
			{
			case Keyboard::A:
				cout << "Pressed A key !!\n";
				break;

			default:
				break;
			}

		default:
			break;
		}
	}

	// Keyboard Input
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}

	// Mouse Input
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		window->setTitle("Left Click");
	}
	else if (Mouse::isButtonPressed(Mouse::Right))
	{
		window->setTitle("Right Click");
	}
	else
	{
		window->setTitle("Window");
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
