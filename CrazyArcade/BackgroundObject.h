#pragma once
#include "Object.h"
class BackgroundObject : public Object
{
public:
	BackgroundObject();
	BackgroundObject(const string& filePath);
	~BackgroundObject();

protected:
	Texture* backgroundTexture = nullptr;

private:
	virtual void Init();
	virtual void Init(const string& filePath);
	
public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};

