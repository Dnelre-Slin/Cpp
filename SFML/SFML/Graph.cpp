#include <iostream>
#include "Graph.h"

void Graph::set(float(*func)(float), const sf::Color &color)
{
	m_func = func;
	m_color = color;
}

void Graph::draw(sf::RenderWindow &window, const sf::Vector2f &origo, float x_spacing, float y_spacing)
{
	sf::RectangleShape draw_point(sf::Vector2f(1.0f,1.0f));
	draw_point.setFillColor(m_color);
	for (float x = 0.0f; x < window.getSize().x; x += 0.5f)
	{
		//draw_point.setPosition(origo.x + x_spacing * x, m_func(origo.y - y_spacing * x));
		//draw_point.setPosition(x, m_func(origo.y - y_spacing * ((x - origo.x) / x_spacing)));
		draw_point.setPosition(x, origo.y - y_spacing * m_func((x - origo.x) / x_spacing));
		//draw_point.setPosition(x, origo.y - y_spacing * m_func(x));
		window.draw(draw_point);
	}
}
