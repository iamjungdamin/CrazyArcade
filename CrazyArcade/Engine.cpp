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
	//this->window->setVerticalSyncEnabled(true);

	Image icon;
	icon.loadFromFile("Textures/icon.jpg");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->event = new Event;
	this->clock = new Clock;
	engineClock = new Clock;

	soundSystem = new SoundSystem("Sound/blank.wav");

	soundSystem->AddMusic("Sound/login.wav", "login");
	soundSystem->AddMusic("Sound/waiting.wav", "waiting");
	soundSystem->AddMusic("Sound/patrit.wav", "patrit");

	soundSystem->AddSoundEffect("Sound/btnClick.wav", "Click");
	soundSystem->AddSoundEffect("Sound/gameStart.wav", "Start");
	soundSystem->AddSoundEffect("Sound/add.wav", "Bubble");

	this->scenes.push(new LoginScene(&scenes, window, soundSystem));
	//this->scenes.push(new PracScene(&scenes, window, soundSystem));
}

void Engine::Destroy()
{
	DELETE(clock);
	DELETE(event);
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
	while (window->pollEvent(*event))
	{
		switch (event->type)
		{
		case Event::Closed:
			window->close();
			break;

		case Event::KeyPressed:
		case Event::MouseButtonPressed:
		case Event::MouseWheelScrolled:
			if (!scenes.empty())
			{
				scenes.top()->Input(event);
			}
			break;

		default:
			break;
		}
	}
}

void Engine::Update()
{
	this->deltaTime = clock->getElapsedTime().asSeconds();
	clock->restart();

	if (engineClock->getElapsedTime().asSeconds() >= 1.f)
	{
		FPS = frame;
		frame = 0;
		engineClock->restart();
		this->elapsedTime += deltaTime;
		//cout << FPS << endl;

		//ostringstream Oss;
		//Oss << "Window FPS(" << FPS << ")";
		//window->setTitle(Oss.str());
	}
	++frame;

	this->mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));
	
	if (!scenes.empty())
	{

		if (this->scenes.top()->GetQuit())
		{
			// 현재 실행중인 scene을 종료한다
			scenes.top()->Destroy();
			scenes.top() = nullptr;
			delete scenes.top();
			scenes.pop();
			cout << "Pop Scene\n";
		}
		else
		{
			scenes.top()->Update(deltaTime);
			scenes.top()->Update(mousePosition);
		}
	}
	else
	{
		window->close();
	}
}

bool Engine::Render()
{
	if (window->isOpen())
	{
		window->clear();

		Input();
		Update();

		if (!scenes.empty())
		{
			scenes.top()->Render();
		}
		window->display();
		return true;
	}
	else
	{
		return false;
	}
}
