#include "framework.h"
#include "WallManager.h"
#include "JumpObject.h"
#include "Bullet.h"

WallManager::WallManager(const size_t& wallCount)
{
	for (auto i = 0; i < wallCount; ++i)
	{
		walls.push_back(new WallObject("Textures/wall3.png"));
	}
}

void WallManager::Destroy()
{
	for (auto& wall : walls)
	{
		wall->Destroy();
	}
}

void WallManager::SetWall(WallObject* object)
{
	if (object)
	{
		walls.push_back(object);
	}
}

vector<WallObject*>* WallManager::getWalls()
{
	return &walls;
}

void WallManager::Update(const float& deltaTime)
{
	for (auto& wall : walls)
	{
		wall->Update(deltaTime);
	}
}

void WallManager::Update(const Vector2f& mousePosition)
{
	for (auto& wall : walls)
	{
		wall->Update(mousePosition);
	}
}

void WallManager::CollisionUpdate(Object* object)
{
	for (auto& wall : walls)
	{
		if (object && object->IsActive())
		{
			if (dynamic_cast<Bullet*>(object))
			{
				if (dynamic_cast<Bullet*>(object)->getGlobalBounds().intersects(wall->getGlobalBounds()))
				{
					object->SetActive(false);
					object->setPosition({});
				}
			}

			if (dynamic_cast<JumpObject*>(object))
			{
				Vector2f dir = dynamic_cast<JumpObject*>(object)->GetDirection();
				if (dir.x != 0.f || dir.y != 0.f)
				{
					if (wall->getGlobalBounds().intersects(object->getGlobalBounds()))
					{
						dynamic_cast<JumpObject*>(object)->SetDirection(-dir);
					}
				}
			}
		}
	}
}

void WallManager::Render(RenderTarget* target)
{
	for (auto& wall : walls)
	{
		wall->Render(target);
	}
}
