#include <iostream>
#include <SFML/Graphics.hpp>

#include "Extras.h"
#include "Graph.h"
#include "Axis.h"
#include <string>

void test()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	//sf::RectangleShape l1 = esf::getLine(sf::Vector2f(400, 300), sf::Vector2f(400, 200), 2.0f);
	srand((unsigned int)time(0));

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
					box2.setOrigin(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y));
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
}

float mathFunc(float x)
{
	//return powf(x,2.0f);
	//return 0.5f* x + 10.0f;
	//return 3*sinf(x)+10;
	//return powf(x, 5) - 3 * powf(x, 3) + powf(x, 2) + 2 * x - 5;
	//float PI = 3.141592653589793;
	//float sum_result = 0;
	//
	//for (unsigned int n = 1; n < 100; n++)
	//{
	//	sum_result += ((cosf((2 * PI*n) / 3) - 1) / n) * sin((2 * PI*n*x) / 3);
	//}

	//return 1 + (2 / PI) * sum_result;

	float sum = 0;
	for (unsigned int n = 0; n < 9; n++)
	{
		sum += (n + 1)*powf(x, 10 - n);
	}
	return sum;

	//return x;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	srand((unsigned int)time(0));

	window.setFramerateLimit(144);

	bool mouse_button_held = false;

	Axis axis_cross(window, sf::Color::Black);

	Graph graph(window, mathFunc, sf::Color::Red);
	//Graph co_graph(cosf, sf::Color::Blue);

	axis_cross.addGraph(graph);
	//axis_cross.addGraph(co_graph);

	sf::Vector2f mouse_moved(0.0f, 0.0f);

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
					mouse_moved.x = (float)event.mouseButton.x;
					mouse_moved.y = (float)event.mouseButton.y;
					axis_cross.printScale();
					//axis_cross.scaleX(0.5f);
				}
				else if (event.mouseButton.button == 1) //Right mouse button.
				{
					/*axis_cross.scaleX(2.0f);*/
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0)
			{
				mouse_button_held = false;
			}
			else if (mouse_button_held && event.type == sf::Event::MouseMoved)  //Mouse drag.
			{
				axis_cross.move(sf::Vector2f(event.mouseMove.x - mouse_moved.x, event.mouseMove.y - mouse_moved.y));
				mouse_moved.x = (float)event.mouseMove.x;
				mouse_moved.y = (float)event.mouseMove.y;
				break;
			}
			else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.delta > 0)
			{
				axis_cross.scale(1.0f + (event.mouseWheelScroll.delta / 10.0f));
			}
			else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.delta < 0)
			{
				//axis_cross.scaleX(1.0f / (1.0f + (event.mouseWheelScroll.delta / 10)));
				axis_cross.scale(1.0f / pow(1.1f,-event.mouseWheelScroll.delta));
			}
		}


		window.clear(sf::Color(200,200,200,255));

		axis_cross.draw();

		window.display();
	}

	return 0;
}