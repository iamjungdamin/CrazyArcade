#include "framework.h"
#include "PracScene.h"
#include "ButtonObject.h"
#include "Character.h"
#include "JumpObject.h"

PracScene::PracScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes,window,soundSystem)
{
	Init();
}

void PracScene::Init()
{
	bts["Button"] = new ButtonObject("Image/Button/check.png", "Image/Button/check2.png", { 200.f, 200.f });
	bts["Button2"] = new ButtonObject("Image/Button/check.png", "Image/Button/check2.png", { 300.f, 200.f });
	bts["Button3"] = new ButtonObject("Image/Button/check.png", "Image/Button/check2.png", { 400.f, 200.f });

	doll = new JumpObject("Image/diznidown (0).png");
	portal = new Object("Image/Bg/wall3.png");

	FloatRect viewRect{ 0.f, 0.f, 400.f, 300.f };

	//view = new View;
	portal->setPosition(600.f, 500.f);
}

void PracScene::Destroy()
{
	for (auto& b : bts)
	{
		b.second->Destroy();
	}
}

void PracScene::Input(Event* e)
{
	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::Space:
			dynamic_cast<JumpObject*>(doll)->Jump();
			break;

		//case Keyboard::Q:	//Zoom out
		//	view->zoom(1.1f);
		//	break;

		//case Keyboard::W:	//Zoom in
		//	view->zoom(0.9f);
		//	break;

		default:
			break;
		}
		break;
	}
}

void PracScene::Update(const Vector2f& mousePostion)
{
	for (auto& b : bts)
	{
		b.second->Update(mousePostion);
	}

	if (bts["Button"]->IsPressed())
	{
		//scenes->push(new PracScene(scenes, window, soundSystem));
		cout << "¹öÆ°" << endl;
	}

	if (doll)
	{
		dynamic_cast<JumpObject*>(doll)->TargetMove(mousePostion);
	}
}

void PracScene::Update(const float& deltaTime)
{
	//static bool flag = true;
	//if (flag)
	//{
	//	view->zoom(1.1f);
	//	// A==B:false, A!=B:true
	//	flag ^= true;
	//}
	//else
	//{
	//	view->zoom(0.9f);
	//	flag ^= true;
	//}

	if (doll)
	{
		//view->setCenter(doll->getPosition());
		doll->Update(deltaTime);
	}

	if (portal)
	{
		portal->Update(deltaTime);
	}

	if (portal && doll)
	{
		if (portal->getGlobalBounds().contains(doll->getPosition()))
		{
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				window->setView(window->getDefaultView());
				//scenes->push(new)
				cout << "Æ÷Å»" << endl;
			}
		}

	}
	
	//window->setView(*view);
}

void PracScene::Render()
{
	for (auto& b : bts)
	{
		b.second->Render(window);
	}

	if (portal)
	{
		portal->Render(window);
	}
	
	if (doll)
	{
		doll->Render(window);
	}

}
