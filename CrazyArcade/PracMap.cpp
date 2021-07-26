#include "framework.h"
#include "PracMap.h"

PracMap::PracMap(const string& tileSetFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize)
	:tiles(tiles)
{
	tileSet = new Texture;
	tileSet->loadFromFile(tileSetFilePath);

	//사각형 타일
	vertices.setPrimitiveType(Quads);

	//정점의 개수를 미리 정해준다
	vertices.resize(mapSize.x * mapSize.y * 4);

	for (unsigned int i = 0; i < mapSize.x; ++i)
	{
		for (unsigned int j = 0; j < mapSize.y; ++j)
		{
			int tileNumber = tiles.data()[i + j * mapSize.x];

			Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

			float tileX = (float)tileSize.x;
			float tileY = (float)tileSize.y;

			int texU = tileNumber % (tileSet->getSize().x / tileSize.x);
			int texV = tileNumber / (tileSet->getSize().x / tileSize.x);

			quad[0].position = Vector2f(i * tileX, j * tileY);
			quad[1].position = Vector2f((i + 1) * tileX, j * tileY);
			quad[2].position = Vector2f((i + 1) * tileX, (j + 1) * tileY);
			quad[3].position = Vector2f(i * tileX, (j + 1) * tileY);

			//텍스처에 대한 텍스코드를 정해준다
			quad[0].texCoords = Vector2f(texU * tileX, texV * tileY);
			quad[1].texCoords =Vector2f((texU + 1) * tileX, texV * tileY);
			quad[2].texCoords =Vector2f((texU + 1) * tileX, (texV + 1) * tileY);
			quad[3].texCoords =Vector2f(texU * tileX, (texV + 1) * tileY);
		}
	}
}

void PracMap::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = tileSet;

	target.draw(vertices, states);
}
