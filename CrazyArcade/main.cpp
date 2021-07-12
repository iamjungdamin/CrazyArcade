#include "framework.h"
#include "Engine.h"

int main()
{
	//RenderWindow window(VideoMode(600, 600), "Window");
	//window.setFramerateLimit(60);
	//Event evt;

	//Texture tx;
	//tx.loadFromFile("Image/diznidown00.png");
	//Sprite sp;
	//sp.setPosition(0, 300);
	//sp.setTexture(tx);
	//sp.setOrigin(sp.getGlobalBounds().width / 2.f, sp.getGlobalBounds().height / 2.f);

	//Vertex vertice[5] =
	//{
	//	Vertex(Vector2f(100,100)),
	//	Vertex(Vector2f(400,100)),
	//	Vertex(Vector2f(400,400)),
	//	Vertex(Vector2f(100,400)),
	//	Vertex(Vector2f(100,100))
	//};

	//while (window.isOpen())
	//{
	//	window.clear();

	//	while (window.pollEvent(evt))
	//	{
	//		switch (evt.type) {
	//		case Event::Closed:
	//			window.close();
	//			break;

	//		default:
	//			break;
	//		}
	//	}
	//	/* Update */
	//	sp.move(Vector2f(1.f, 0));

	//	vertice[0] = Vertex(Vector2f(sp.getGlobalBounds().left, sp.getGlobalBounds().top), Color::Red);
	//	vertice[1] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width, sp.getGlobalBounds().top), Color::Red);
	//	vertice[2] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width, sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Red);
	//	vertice[3] = Vertex(Vector2f(sp.getGlobalBounds().left, sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Red);
	//	vertice[4] = vertice[0];

	//	/* Render */
	//	window.draw(sp);
	//	window.draw(vertice, 5, LineStrip);
	//	window.display();
	//}

	Engine engine;
	engine.Render();

	engine.Destroy();
}
