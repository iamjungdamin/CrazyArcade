#include "framework.h"
#include "ButtonObject.h"

ButtonObject::ButtonObject(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position)
{
	idleTexture = new Texture;
	idleTexture->loadFromFile(idleTexturePath);

	activeTexture = new Texture;
	activeTexture->loadFromFile(activeTexturePath);

	setTexture(*idleTexture);
	setOrigin(getGlobalBounds().width / 2.f, getGlobalBounds().height / 2.f);
	setPosition(position);
}

void ButtonObject::Destroy()
{
	DELETE(idleTexture);
	DELETE(activeTexture);
}

bool ButtonObject::IsPressed()
{
	return isPress;
}

void ButtonObject::Update(const Vector2f& mousePostion)
{
	isPress = false;

	if (getGlobalBounds().contains(mousePostion))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			isPress = true;
		}
	}

	if (isPress)
	{
		setTexture(*activeTexture);
	}
	else
	{
		setTexture(*idleTexture);
	}
}

void ButtonObject::Render(RenderTarget* target)
{
	if (target)
	{
		target->draw(*this);
	}
}
