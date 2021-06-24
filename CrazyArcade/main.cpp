#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(500, 500), "Window");
	
	Sprite sp;
	Texture tx;
	tx.loadFromFile("Textures/hi.png");

	sp.setScale(1.2f, 1.2f);
	sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f);
	sp.setTexture(tx);
	sp.setPosition(250.f, 250.f);

	while (window.isOpen())
	{
		window.clear();

		window.draw(sp);

		window.display();
	}
}