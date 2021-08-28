#include "framework.h"
#include "CrossBomb.h"

CrossBomb::CrossBomb()
{
	Init();
}

void CrossBomb::Init()
{
	Texture* texture = nullptr;
	string filePath = "Image/Bubble/";

	for (int i = 0; i < 4; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "bubble0" + to_string(i) + ".png");
		this->bombAnimation.push_back(texture);
	}

	for (int i = 0; i < 3; ++i)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "bomb0" + to_string(i) + ".png");
		this->boomAnimation.push_back(texture);
	}

	vector<Texture*> rightMidAnimation;
	vector<Texture*> leftMidAnimation;
	vector<Texture*> upMidAnimation;
	vector<Texture*> downMidAnimation;

	for (int j = 0; j < 4; ++j)
	{
		for (int i = 1; i <= 3; ++i)
		{
			texture = new Texture;
			texture->loadFromFile(filePath + "bombMid (" + to_string(i) + ").png");

			if (j == 0)
			{
				rightMidAnimation.push_back(texture);
			}
			else if (j == 1)
			{
				leftMidAnimation.push_back(texture);
			}
			else if (j == 2)
			{
				upMidAnimation.push_back(texture);
			}
			else if (j == 3)
			{
				downMidAnimation.push_back(texture);
			}
		}
	}

	vector<Texture*> rightEndAnimation;
	vector<Texture*> leftEndAnimation;
	vector<Texture*> upEndAnimation;
	vector<Texture*> downEndAnimation;

	for (int j = 0; j < 4; ++j)
	{
		for (int i = 1; i <= 8; ++i)
		{
			texture = new Texture;
			texture->loadFromFile(filePath + "bombEnd (" + to_string(i) + ").png");

			if (j == 0)
			{
				rightEndAnimation.push_back(texture);
			}
			else if (j == 1)
			{
				leftEndAnimation.push_back(texture);
			}
			else if (j == 2)
			{
				upEndAnimation.push_back(texture);
			}
			else if (j == 3)
			{
				downEndAnimation.push_back(texture);
			}
		}
	}

	pairObject* right = new pairObject;
	right->first = new AnimationObject();
	right->first->SetAnimation(&rightMidAnimation, 0.4f);
	right->second = new AnimationObject();
	right->second->SetAnimation(&rightEndAnimation, 0.4f);

	pairObject* left = new pairObject;
	left->first = new AnimationObject();
	left->first->SetAnimation(&leftMidAnimation, 0.4f);
	left->first->setRotation(180.f);
	left->second = new AnimationObject();
	left->second->SetAnimation(&leftEndAnimation, 0.4f);
	left->second->setRotation(180.f);

	pairObject* up = new pairObject;
	up->first = new AnimationObject();
	up->first->SetAnimation(&upMidAnimation, 0.4f);
	up->first->setRotation(270.f);
	up->second = new AnimationObject();
	up->second->SetAnimation(&upEndAnimation, 0.4f); 
	up->second->setRotation(270.f);
	
	pairObject* down = new pairObject;
	down->first = new AnimationObject();
	down->first->SetAnimation(&downMidAnimation, 0.4f);
	down->first->setRotation(90.f);
	down->second = new AnimationObject();
	down->second->SetAnimation(&downEndAnimation, 0.4f);
	down->second->setRotation(90.f);

	bombLeafObjects["right"] = right;
	bombLeafObjects["left"] = left;
	bombLeafObjects["up"] = up;
	bombLeafObjects["down"] = down;

	for (auto& p : bombLeafObjects)
	{
		p.second->first->setOrigin(20.f, 20.f);
		p.second->second->setOrigin(20.f, 20.f);
	}

	isActive = false;
	isLive = false;
}

void CrossBomb::Destroy()
{
	AnimationObject::Destroy();
}

void CrossBomb::SetBomb(const Vector2f& position)
{
	this->setPosition(position);
	isLive = true;
	isActive = true;
	lifeTime = 3.f;
	keyFrame = 0;
}

void CrossBomb::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float frame = 0.f;
	frame += 0.1f;
	
	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;
	lifeTime -= deltaTime;

	if (lifeTime <= 0.f && isLive)
	{
		lifeTime = 3.f;
		isLive = false;
		keyFrame = 0;
		bombLeafAnimation = true;
	}

	if (elapsedTime >= frameTime)
	{
		if (isLive)
		{
			setTexture(*bombAnimation.data()[keyFrame % bombAnimation.size()]);
			setTextureRect({ 0,0,46,46 });
		}
		else
		{
			setTexture(*boomAnimation.data()[keyFrame % boomAnimation.size()]);
			setTextureRect({ 0,0,40,40 });
		}
		
		keyFrame++;
		elapsedTime = 0.f;
	}

	auto ggb = this->getGlobalBounds();

	if ((int)frame % 8 >= 7)
	{
		bombLeafAnimation = false;
		if (isLive == false)
		{
			isActive = false;
		}
	}
	
	if (bombLeafAnimation == true)
	{
		for (auto& p : bombLeafObjects)
		{
			p.second->first->Update(deltaTime);
			p.second->second->Update(deltaTime);

			auto midgb = p.second->first->getGlobalBounds();

			unsigned int frameInt = frame;
			p.second->first->SetKeyFrame(frameInt);
			p.second->second->SetKeyFrame(frameInt);

			if (p.first == "right")
			{
				p.second->first->setPosition({ ggb.left + ggb.width + ggb.width / 2.f, ggb.top + ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left + midgb.width + midgb.width / 2.f, midgb.top + midgb.height / 2.f });
			}
			else if (p.first == "left")
			{
				p.second->first->setPosition({ ggb.left - ggb.width / 2.f, ggb.top + ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left - midgb.width / 2.f, midgb.top + midgb.height / 2.f });
			}
			else if (p.first == "up")
			{
				p.second->first->setPosition({ ggb.left + ggb.width / 2.f, ggb.top - ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left + midgb.width / 2.f, midgb.top - midgb.height / 2.f });
			}
			else if (p.first == "down")
			{
				p.second->first->setPosition({ ggb.left + ggb.width / 2.f, ggb.top + ggb.height + ggb.height / 2.f });
				p.second->second->setPosition({ midgb.left + midgb.width / 2.f, midgb.top + midgb.height + midgb.height / 2.f });
			}
		}
	}
}

void CrossBomb::Update(const Vector2f& mousePosition)
{
	AnimationObject::Update(mousePosition);
}

void CrossBomb::Render(RenderTarget* target)
{
	AnimationObject::Render(target);
	
	if (bombLeafAnimation == true)
	{
		for (auto& p : bombLeafObjects)
		{
			p.second->first->Render(target);
			p.second->second->Render(target);
		}
	}
}
