#include <iostream>
#include <SFML/Graphics.hpp>

#include "Extras.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	//sf::RectangleShape l1 = esf::getLine(sf::Vector2f(400, 300), sf::Vector2f(400, 200), 2.0f);
	srand(time(NULL));

	sf::RectangleShape floor = esf::getLine(sf::Vector2f(0, 250), sf::Vector2f(500, 600), 1.0f);
	floor.setFillColor(sf::Color::Green);

	sf::RectangleShape box(sf::Vector2f(100, 100));
	box.setPosition(50, 50);
	box.setFillColor(sf::Color::Cyan);

	sf::RectangleShape box2(sf::Vector2f(100, 100));
	box2.setPosition(300, 300);
	box2.setFillColor(sf::Color::Magenta);

	window.setFramerateLimit(144);

	//Polygon2D poly1(Point2D(350, 250), Point2D(300, 200), Point2D(250, 350));
	//sf::ConvexShape poly_shape = esf::getShape(poly1, sf::Color::Green);

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
				{
					mouse_button_held = true;
					box2.setOrigin(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				}
				else if (event.mouseButton.button == 1) //Right mouse button.
				{
					//std::cout << "Array size: " << poly1.size() << '\n';
					std::cout << floor.getOrigin().x << "  " << floor.getOrigin().y << '\n';
					box2.setOrigin(sf::Vector2f(0, 0));
					//std::cout << floor.getGlobalBounds().width << "   " << floor.getLocalBounds().width << '\n';
					//std::cout << floor.getGlobalBounds().height << "   " << floor.getLocalBounds().height << '\n';
					//std::cout << "[ (" << floor.getPosition().x << " , " << floor.getPosition().y << ")";
					//std::cout << "  ,  (" << floor.getPosition().x + floor.getGlobalBounds().width << " , " << floor.getPosition().y << ")";
					//std::cout << "  ,  (" << floor.getPosition().x << " , " << floor.getPosition().y + floor.getGlobalBounds().height << ")";
					//std::cout << "  ,  (" << floor.getPosition().x + floor.getGlobalBounds().width << " , " << floor.getPosition().y + floor.getGlobalBounds().height << ")\n";
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0)
				mouse_button_held = false;
			else if (mouse_button_held && event.type == sf::Event::MouseMoved)
			{
				//poly1 += Point2D(event.mouseMove.x, event.mouseMove.y);
				//poly_shape = esf::getShape(poly1, sf::Color::Green);
				break;
			}
		}

		//if (l1.getRotation() > 270.0f && l1.getRotation() < 270.6f)
		//	l1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		//l1.rotate(0.5f);
		//std::cout << "Rotation: " << l1.getRotation() << '\n';

		box2.rotate(1);

		window.clear();
		window.draw(floor);
		window.draw(box);
		window.draw(box2);
		//window.draw(l1);
		//window.draw(poly_shape);
		//window.draw(shape);
		window.display();
	}

	return 0;
}