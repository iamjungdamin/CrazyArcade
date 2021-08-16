#include "framework.h"
#include "BubbleManager.h"
#include "MonsterObject.h"

BubbleManager::BubbleManager(const size_t& bubbleCount)
{
	for (auto i = 0; i < bubbleCount; ++i)
	{
		bubbles.push_back(new BombObject("Image/Bubble/bubble00.png"));
	}

	for (auto& bubble : bubbles)
	{
		bubble->SetActive(false);
	}
}

void BubbleManager::Destory()
{
	for (auto& bubble : bubbles)
	{
		bubble->Destroy();
	}
}

void BubbleManager::AddBubble(const Vector2f& position)
{
	for (auto& bubble : bubbles)
	{
		if (!bubble->IsActive())
		{
			bubble->SetBubble(position);
			break;
		}
		else
		{
			continue;
		}
	}
}

vector<BombObject*>* BubbleManager::GetBubbles()
{
	return &bubbles;
}

void BubbleManager::DamageBoom(Object* object)
{
	static int count = 0;

	for (auto& bubble : bubbles)
	{
		if (object && bubble->GetBoomArea().intersects(object->getGlobalBounds()) && bubble->IsDamaging())
		{
			if (dynamic_cast<MonsterObject*>(object))
			{
				dynamic_cast<MonsterObject*>(object)->SetHp(dynamic_cast<MonsterObject*>(object)->GetHp() - 1);
			}
			else
			{
				cout << "다른 오브젝트가 데미지를 입었습니다\n";
			}
		}
	}
}

void BubbleManager::Update(const float& deltaTime)
{
	for (auto& bubble : bubbles)
	{
		bubble->Update(deltaTime);
	}
}

void BubbleManager::Update(const Vector2f& mousePosition)
{
	for (auto& bubble : bubbles)
	{
		bubble->Update(mousePosition);
	}
}

void BubbleManager::Render(RenderTarget* target)
{
	for (auto& bubble : bubbles)
	{
		bubble->Render(target);
	}
}
