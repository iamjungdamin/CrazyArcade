#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(500, 500), "Window");
	
	RectangleShape rs;

	rs.setFillColor(Color::Green);
	rs.setSize(Vector2f(100.f, 100.f));
	rs.setPosition(Vector2f(250.f, 250.f));
	rs.setOrigin(rs.getSize() / 2.f);

	while (window.isOpen())
	{
		window.clear();

		//rs.setPosition(rs.getPosition().x + .5f, rs.getPosition().y);
		window.draw(rs);
		window.display();
	}
}