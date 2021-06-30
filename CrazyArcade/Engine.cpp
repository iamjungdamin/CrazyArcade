#include "framework.h"
#include "Engine.h"
#include "AnimationObject.h"

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
	window->setMouseCursorVisible(true);
	Image icon;
	icon.loadFromFile("Textures/icon.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	AnimationObject* obj1 = new AnimationObject;
	obj1->setPosition(100.f, 0.f);
	obj.push_back(obj1);
	obj.push_back(new AnimationObject);
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

	for (auto& o : obj) {
		o->Update(deltaTime);
	}
	timer.restart();
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();

		for (auto& o : obj)
		{
			window->draw(*o);
		}

		window->display();
	}
}
