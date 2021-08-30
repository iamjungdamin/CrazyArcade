#pragma once
#include "AnimationObject.h"
#include "SoundSystem.h"

typedef pair<AnimationObject*, AnimationObject*> pairObject;

enum CROSSBOMB_STATE
{
	cbIDLE,
	cbBOOM
};

class CrossBomb : public AnimationObject
{
public:
	CrossBomb();
	CrossBomb(const CrossBomb&) = delete;
	CrossBomb& operator = (const CrossBomb&) = delete;
	virtual ~CrossBomb() = default;

private:
	vector<Texture*> bombAnimation;
	vector<Texture*> boomAnimation;
	bool isLive = true;

	float lifeTime = 3.f;

	map <string, pairObject*> bombLeafObjects;
	bool bombLeafAnimation = false;

	int state = cbIDLE;

private:
	virtual void Init();

public:
	virtual void Destroy();

	void SetBomb(const Vector2f& position);

	int getState();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

