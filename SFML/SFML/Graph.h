#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
//#include "Extras.h"

class Graph
{
private:
	//std::vector<sf::Vector2f> m_points;
	float(*m_func)(float);
	sf::Color m_color;
public:
	inline Graph() { }
	inline Graph(float(*func)(float), const sf::Color &color = sf::Color::Black) { m_func = func; m_color = color; }

	void set(float(*func)(float), const sf::Color &color = sf::Color::Black);
	inline void setColor(const sf::Color &color) { m_color = color; }

	void draw(sf::RenderWindow &window, const sf::Vector2f &origo, float x_spacing, float y_spacing);
};