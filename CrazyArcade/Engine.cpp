#include "framework.h"
#include "Engine.h"
#include "LoginScene.h"
#include "PracScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
	Destroy();
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(800, 600), "Crazy Arcade");
	this->window->setFramerateLimit(60);

	Image icon;
	icon.loadFromFile("Textures/icon.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	soundSystem = new SoundSystem("Sound/login.wav");
	soundSystem->AddSoundEffect("Sound/btnClick.wav", "Click");
	soundSystem->AddSoundEffect("Sound/gameStart.wav", "Start");
	soundSystem->AddSoundEffect("Sound/add.wav", "Bubble");
	this->scenes.push(new LoginScene(&scenes, window, soundSystem));
	//this->scenes.push(new PracScene(&scenes, window, soundSystem));
}

void Engine::Destroy()
{
	DELETE(window);

	for (size_t i = 0; i < scenes.size(); ++i)
	{
		scenes.top()->Destroy();
		scenes.top() = nullptr;
		delete scenes.top();
		scenes.pop();
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
			// 현재 실행중인 scene을 종료한다
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
