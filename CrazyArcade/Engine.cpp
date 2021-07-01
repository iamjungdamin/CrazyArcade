#include "framework.h"
#include "Engine.h"
#include "Scene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(800, 600), "Crazy Arcade");
	window->setMouseCursorVisible(true);

	//Texture bgtx;
	//bgtx.loadFromFile("Image/BackGround.png");
	//bg.setTexture(bgtx);

	Image icon;
	icon.loadFromFile("Textures/icon.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->scene = new Scene;
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
			case Keyboard::Escape:
				window->close();
				break;

			default:
				break;
			}

		default:
			break;
		}
	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds();
	timer.restart();
	Input();
	this->scene->Update(deltaTime);
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		scene->Render(window);
		window->display();
	}
}
