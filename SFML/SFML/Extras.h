#pragma once
#include <SFML\Graphics.hpp>
//#include "Polygon2D.h"
//
//#include "Polygon2D.cpp"
//#include "Line2D.cpp"
//#include "Point2D.cpp"


namespace esf
{
	sf::RectangleShape getLine(const sf::Vector2f &point1, const sf::Vector2f &point2, float thickness = 1.0f, const sf::Color &color = sf::Color::White);

	//sf::ConvexShape getShape(const Polygon2D &poly, const sf::Color &color = sf::Color::White);

}