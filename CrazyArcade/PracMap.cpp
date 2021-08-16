#include "framework.h"
#include "PracMap.h"

PracMap::PracMap(const string& tileSetFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize)
	:tiles(tiles), tileSize(tileSize), mapSize(mapSize)
{
	tileSet = new Texture;
	tileSet->loadFromFile(tileSetFilePath);

	//�簢�� Ÿ��
	vertices.setPrimitiveType(Quads);

	//������ ������ �̸� �����ش�
	vertices.resize(mapSize.x * mapSize.y * 4);

	InitVertices();
}

void PracMap::InitVertices()
{
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

			//�ؽ�ó�� ���� �ؽ��ڵ带 �����ش�
			quad[0].texCoords = Vector2f(texU * tileX, texV * tileY);
			quad[1].texCoords = Vector2f((texU + 1) * tileX, texV * tileY);
			quad[2].texCoords = Vector2f((texU + 1) * tileX, (texV + 1) * tileY);
			quad[3].texCoords = Vector2f(texU * tileX, (texV + 1) * tileY);
		}
	}
}

void PracMap::Update(const Vector2f& mousePosition, int tileNumber)
{
	for (unsigned int i = 0; i < mapSize.x; ++i)
	{
		for (unsigned int j = 0; j < mapSize.y; ++j)
		{
			Vertex* quad = &vertices[(i + j * mapSize.x) * 4];

			if ((mousePosition.x > quad[0].position.x && mousePosition.y > quad[0].position.y) &&
				(mousePosition.x < quad[1].position.x && mousePosition.y > quad[1].position.y) &&
				(mousePosition.x < quad[2].position.x && mousePosition.y < quad[2].position.y) &&
				(mousePosition.x > quad[3].position.x && mousePosition.y < quad[3].position.y))
			{
				tiles.data()[i + j * mapSize.x] = tileNumber;

				float tileX = (float)tileSize.x;
				float tileY = (float)tileSize.y;

				int texU = tileNumber % (tileSet->getSize().x / tileSize.x);
				int texV = tileNumber / (tileSet->getSize().x / tileSize.x);

				//�ؽ�ó�� ���� �ؽ��ڵ带 �����ش�
				quad[0].texCoords = Vector2f(texU * tileX, texV * tileY);
				quad[1].texCoords = Vector2f((texU + 1) * tileX, texV * tileY);
				quad[2].texCoords = Vector2f((texU + 1) * tileX, (texV + 1) * tileY);
				quad[3].texCoords = Vector2f(texU * tileX, (texV + 1) * tileY);
			}
		}
	}
}

const IntRect& PracMap::GetTile(int tileNumber)
{
	int count = 0;

	for (unsigned int i = 0; i < tileSet->getSize().y; i += tileSize.y)
	{
		for (unsigned int j = 0; j < tileSet->getSize().x; j += tileSize.x)
		{
			if (count == tileNumber)
			{
				imageRect = IntRect(j, i, 32, 32);
				return imageRect;
			}

			count++;
		}
	}

	return IntRect();
}

void PracMap::SaveMap(const string& mapName)
{
	ofstream out(mapName, ios::binary);

	int size = tiles.size();
	out.write((const char*)&size, sizeof(int));

	// 4����Ʈ ���ϱ� 8����Ʈ�� �ϸ� ��� �����÷ο찡 �Ͼ�� �����Ƿ�
	// ũ�Ⱑ ���� �ڷ����� �ڷ����� ū �ڷ����� �����ش�
	out.write((const char*)&tiles.data()[0], sizeof(int) * static_cast<__int64>(size));
	out.close();
}

void PracMap::LoadMap(const string& mapName)
{
	ifstream in(mapName, ios::binary);

	tiles.clear();

	int size;
	in.read((char*)&size, sizeof(int));
	tiles.resize(size);

	in.read((char*)&tiles.data()[0], sizeof(int) * static_cast<__int64>(size));
	in.close();

	InitVertices();
}

void PracMap::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = tileSet;

	target.draw(vertices, states);
}