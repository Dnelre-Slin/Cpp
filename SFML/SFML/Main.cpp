#include <SFML/Graphics.hpp>

#include "Extras.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	sf::RectangleShape l1 = esf::getLine(sf::Vector2f(400, 300), sf::Vector2f(400, 200), 2.0f);
	srand(time(NULL));

	window.setFramerateLimit(144);

	Polygon2D poly1(Point2D(350, 250), Point2D(300, 200), Point2D(250, 350));
	sf::ConvexShape poly_shape = esf::getShape(poly1, sf::Color::Green);

	bool mouse_button_held = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == 0) //Left mouse button.
					mouse_button_held = true;
				else if (event.mouseButton.button == 1) //Right mouse button.
					std::cout << "Array size: " << poly1.size() << '\n';
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0)
				mouse_button_held = false;
			else if (mouse_button_held && event.type == sf::Event::MouseMoved)
			{
				poly1 += Point2D(event.mouseMove.x, event.mouseMove.y);
				poly_shape = esf::getShape(poly1, sf::Color::Green);
				break;
			}
		}

		if (l1.getRotation() > 270.0f && l1.getRotation() < 270.6f)
			l1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		l1.rotate(0.5f);
		//std::cout << "Rotation: " << l1.getRotation() << '\n';

		window.clear();
		window.draw(l1);
		window.draw(poly_shape);
		//window.draw(shape);
		window.display();
	}

	return 0;
}