#include "framework.h"
#include "PracScene.h"
#include "ButtonObject.h"
#include "Character.h"
#include "JumpObject.h"

#include "PracMap.h"

PracScene::PracScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes,window,soundSystem)
{
	Init();
}

void PracScene::Init()
{
	vector<int> levels =
	{
		56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
		56, 111, 111, 56, 56, 56, 56, 111, 111, 56,
		111, 56, 56, 111, 56, 56, 111, 56, 56, 111,
		111, 56, 56, 56, 111, 111, 56, 56, 56, 111,
		111, 56, 56, 56, 56, 56, 56, 56, 56, 111,
		56, 111, 56, 56, 56, 56, 56, 56, 111, 56,
		56, 56, 111, 56, 56, 56, 56, 111, 56, 56,
		56, 56, 56, 111, 56, 56, 111, 56, 56, 56,
		56, 56, 56, 56, 111, 111, 56, 56, 56, 56,
		56, 56, 56, 56, 56, 56, 56, 56, 56, 56
	};

	map = new PracMap("Textures/tileSet.png", { 32,32 }, levels, { 10,10 });
}

void PracScene::Destroy()
{
}

void PracScene::Input(Event* e)
{
	switch (e->type)
	{
	case Event::KeyPressed:
		switch (e->key.code)
		{
		case Keyboard::Space:
			break;

		default:
			break;
		}
		break;
	}
}

void PracScene::Update(const Vector2f& mousePostion)
{
}

void PracScene::Update(const float& deltaTime)
{
}

void PracScene::Render()
{
	if (map)
	{
		window->draw(*map);
	}
}
