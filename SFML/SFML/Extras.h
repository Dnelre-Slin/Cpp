#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <sstream>
//#include "Polygon2D.h"
//
//#include "Polygon2D.cpp"
//#include "Line2D.cpp"
//#include "Point2D.cpp"


namespace esf
{
	sf::RectangleShape getLine(const sf::Vector2f &point1, const sf::Vector2f &point2, float thickness = 1.0f, const sf::Color &color = sf::Color::White);

	template <class T>
	std::string toStr(T t);
	//sf::ConvexShape getShape(const Polygon2D &poly, const sf::Color &color = sf::Color::White);

	template<class T>
	std::string toStr(T t)
	{
		std::stringstream ss;
		ss << t;
		return ss.str();
	}

}