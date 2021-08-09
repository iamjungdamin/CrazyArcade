#pragma once
#include "BombObject.h"

class BubbleManager final
{
public:
	BubbleManager(const size_t& bubbleCount = 2);
	BubbleManager(const BubbleManager&) = delete;
	BubbleManager& operator=(const BubbleManager&) = delete;
	~BubbleManager() = default;

private:
	vector<BombObject*> bubbles;

public:
	void Destory();

	void AddBubble(const Vector2f& position);

	vector<BombObject*>* GetBubbles();

	void Update(const float& deltaTime);
	void Update(const Vector2f& mousePosition);

	void Render(RenderTarget* target);
};

