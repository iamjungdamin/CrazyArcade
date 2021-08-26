#pragma once
#include "Scene.h"

class PracMap;
class Object;
class JumpObject;
class BulletManager;
class MonsterObject;
class BombObject;
class EffectObject;
class WallObject;
class WallManager;
class CrossBomb;
class MonsterManager;

class PracScene : public Scene
{
public:
	PracScene() = delete;
	PracScene(stack <Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	PracScene(const PracScene&) = delete;
	PracScene& operator=(const PracScene&) = delete;
	virtual ~PracScene() = default;

private:
	PracMap* map = nullptr;
	int tileNumber = 111;

	Object* mouseCursor = nullptr;

	JumpObject* player;

	BombObject* bomb = nullptr;

	EffectObject* effect = nullptr;

	WallManager* wallMgr = nullptr;

	CrossBomb* newBomb = nullptr;

	MonsterManager* monsterMgr = nullptr;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const Vector2f& mousePostion);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};
