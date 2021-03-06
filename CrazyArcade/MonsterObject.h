#pragma once
#include "Object.h"

enum MONSTERSTATE
{
	mIDLE,
	mCHASING
};

class MonsterObject : public Object
{
public:
	MonsterObject();
	MonsterObject(const string& textureFilePath);
	MonsterObject(const string& textureFilePath, const Vector2f& position);
	MonsterObject(const MonsterObject&) = delete;
	MonsterObject& operator=(const MonsterObject&) = delete;
	~MonsterObject();

private:
	int HP = 0;
	Object* hpBar = nullptr;

	float speed = 100.f;
	Vector2f dir{ 0.f, 0.f };

	int state = mIDLE;
	int oldState = mIDLE;

	Vector2f targetPosition{};

private:
	void Init();

public:
	virtual void Destroy();

	int GetHp();
	void SetHp(const int& hp);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	void ChasingUpdate(Object* object);

	virtual void Render(RenderTarget* target);
};

