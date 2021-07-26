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

	// Ÿ���� ��ȣ�� ��Ƴ��� �����̳�
	vector<int> tiles;

public:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

