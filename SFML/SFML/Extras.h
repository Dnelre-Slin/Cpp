#pragma once
#include <SFML\Graphics.hpp>
#include "Polygon2D.h"

#include "Polygon2D.cpp"
#include "Line2D.cpp"
#include "Point2D.cpp"

namespace esf
{
	sf::RectangleShape getLine(const sf::Vector2f &point1, const sf::Vector2f &point2, float thickness = 1.0f, const sf::Color &color = sf::Color::White)
	{
		float length = sqrt(pow(point2.x - point1.x, 2.0f) + pow(point2.y - point1.y, 2.0f));
		float angle = (180.0f / 3.141592653589793) * atan2f(point2.y - point1.y, point2.x - point1.x);

		sf::RectangleShape rect(sf::Vector2f(length, thickness));
		rect.setPosition(point1);
		rect.setRotation(angle);
		rect.setFillColor(color);
		return rect;
	}

	sf::ConvexShape getShape(const Polygon2D &poly, const sf::Color &color = sf::Color::White)
	{
		sf::ConvexShape shape(poly.size());

		for (int i = 0; i < poly.size(); i++)
		{
			shape.setPoint(i, sf::Vector2f(poly.get(i).get().x, poly.get(i).get().y));
		}
		shape.setFillColor(color);

		return shape;
	}
}