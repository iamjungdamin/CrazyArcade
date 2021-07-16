#pragma once
class ButtonObject : public Sprite
{
public:
	ButtonObject() = default;
	ButtonObject(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);
	ButtonObject(const ButtonObject&) = delete;
	ButtonObject& operator = (const ButtonObject&) = delete;
	virtual ~ButtonObject() = default;

private:
	Texture* idleTexture = nullptr;
	Texture* activeTexture = nullptr;

	bool isPress = false;

public:
	void Destroy();
	bool IsPressed();
	void Update(const Vector2f& mousePostion);
	void Render(RenderTarget* target);
};

