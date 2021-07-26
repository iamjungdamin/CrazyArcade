#pragma once
#include "Object.h"

enum hiddenItem
{
	NOTHING,
	BUBBLE,
	FLUID,
	ROLLER
};

class ObstacleObject : public Object
{
public:
	ObstacleObject();
	ObstacleObject(const string& txFilePath);
	virtual ~ObstacleObject();

private:
	Texture* texture = nullptr;
	bool isActive = true;

	int item = NOTHING;

private:
	virtual void Init();

public:
	void SetActive(bool isActive);
	bool GetActive();
	void ChangeTexture(const string& filePath);
	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};

