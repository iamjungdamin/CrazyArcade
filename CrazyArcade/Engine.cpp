#include "framework.h"
#include "Engine.h"
#include "LoginScene.h"

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
	this->window->setFramerateLimit(60);
	window->setMouseCursorVisible(true);

	Image icon;
	icon.loadFromFile("Textures/icon.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	soundSystem = new SoundSystem("Sound/login.wav");
	soundSystem->AddSoundEffect("Sound/btnClick.wav", "Click");
	soundSystem->AddSoundEffect("Sound/gameStart.wav", "Start");
	soundSystem->AddSoundEffect("Sound/add.wav", "Bubble");
	this->scenes.push(new LoginScene(&scenes, window, soundSystem));
}

void Engine::Destroy()
{
	if (window)		//if (window != nullptr)
	{
		delete window;
	}
	soundSystem->Destroy();
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
			if (!scenes.empty())
			{
				scenes.top()->Input(&evt);
			}
			break;

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
	if (!scenes.empty())
	{
		scenes.top()->Update(deltaTime);

		if (this->scenes.top()->GetQuit())
		{
			// ���� �������� scene�� �����Ѵ�
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else
	{
		window->close();
	}
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		if (!scenes.empty())
		{
			scenes.top()->Render();
		}
		else
		{
			window->close();
		}
		window->display();
	}
}
