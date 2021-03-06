#pragma once

class Object;

class PracMap : public Drawable, public Transformable
{
public:
	PracMap() = default;
	PracMap(const string& tileSetFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize);
	PracMap(const PracMap&) = delete;
	PracMap& operater(const PracMap&) = delete;
	~PracMap() = default;

private:
	// 타일 텍스쳐 이미지
	Texture* tileSet = nullptr;

	// 타일들의 정점을 모아놓은 컨테이너
	VertexArray vertices;

	Vector2u tileSize;
	Vector2u mapSize;

	// 타일의 번호를 모아놓은 컨테이너
	vector<int> tiles;

	IntRect imageRect;

private:
	void InitVertices();

public:
	void Update(const Vector2f& mousePosition, int tileNumber);
	void Update(Object* object);

	const IntRect& GetTile(int tileNumber);

	void SaveMap(const string& mapName);
	void LoadMap(const string& mapName);

	virtual void draw(RenderTarget& target, RenderStates states) const;
};

