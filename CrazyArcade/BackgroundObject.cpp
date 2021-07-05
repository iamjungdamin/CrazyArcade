#include "framework.h"
#include "BackgroundObject.h"

BackgroundObject::BackgroundObject()
{
}

BackgroundObject::BackgroundObject(const string& filePath)
{
	Init(filePath);
}

BackgroundObject::~BackgroundObject()
{
}

void BackgroundObject::Init()
{
}

void BackgroundObject::Init(const string& filePath)
{
	backgroundTexture = new Texture;
	backgroundTexture->setSmooth(true);
	backgroundTexture->loadFromFile(filePath);
	setTexture(*backgroundTexture);
}

void BackgroundObject::Destroy()
{
}

void BackgroundObject::Update(const float& deltaTime)
{
}
