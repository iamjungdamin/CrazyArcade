#pragma once
#include "WallObject.h"

class WallManager final
{
public:
	WallManager(const size_t& wallCount = 10);
	WallManager(const WallManager&) = delete;
	WallManager& operator=(const WallManager&) = delete;
	~WallManager() = default;

private:
	vector<WallObject*> walls;

public:
	void Destroy();

	void SetWall(WallObject* object);
	vector<WallObject*>* getWalls();

	void Update(const float& deltaTime);
	void Update(const Vector2f& mousePosition);

	void CollisionUpdate(Object* object);

	void Render(RenderTarget* target);

};

