#include "framework.h"
#include "ObstacleObject.h"

ObstacleObject::ObstacleObject()
{
	Init();
}

ObstacleObject::ObstacleObject(const string& txFilePath)
{
	texture = new Texture;
	texture->loadFromFile(txFilePath);
	setTexture(*texture);
	setOrigin(texture->getSize().x / 2.f, texture->getSize().y / 2.f);
	Init();
}

ObstacleObject::~ObstacleObject()
{
}

void ObstacleObject::Init()
{
	setPosition(100.f, 100.f);
}

void ObstacleObject::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool ObstacleObject::GetActive()
{
	return isActive;
}

void ObstacleObject::ChangeTexture(const string& filePath)
{
	texture->loadFromFile(filePath);
	setTexture(*texture);
}

void ObstacleObject::Destroy()
{
}

void ObstacleObject::Update(const float& deltaTime)
{

}
