#pragma once

class PracMap : public Drawable, public Transformable
{
public:
	PracMap() = default;
	PracMap(const string& tileSetFilePath, const Vector2u& tileSize, const vector<int>& tiles, const Vector2u& mapSize);
	PracMap(const PracMap&) = delete;
	PracMap& operater(const PracMap&) = delete;
	~PracMap() = default;

private:
	// Ÿ�� �ؽ��� �̹���
	Texture* tileSet = nullptr;

	// Ÿ�ϵ��� ������ ��Ƴ��� �����̳�
	VertexArray vertices;

	Vector2u tileSize;
	Vector2u mapSize;

	// Ÿ���� ��ȣ�� ��Ƴ��� �����̳�
	vector<int> tiles;

	IntRect imageRect;

private:
	void InitVertices();

public:
	void Update(const Vector2f& mousePosition, int tileNumber);

	const IntRect& GetTile(int tileNumber);

	void SaveMap(const string& mapName);
	void LoadMap(const string& mapName);

	virtual void draw(RenderTarget& target, RenderStates states) const;
};
