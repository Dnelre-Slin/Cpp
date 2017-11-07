#include <iostream>
#include "Graph.h"

Graph::Graph(const Graph &other)
{
	m_points = new sf::Vector2f[2000];
	*this = other;
}

Graph &Graph::operator=(const Graph &other)
{
	m_window = other.m_window;
	m_func = other.m_func;
	m_color = other.m_color;
	m_map_size = other.m_map_size;
	m_precision = other.m_precision;

	m_timer = other.m_timer;

	m_array_size = other.m_array_size;
	for (unsigned int i = 0; i < m_array_size; i++)
	{
		m_points[i] = other.m_points[i];
	}

	return *this;
}

void Graph::set(sf::RenderWindow &window, float(*func)(float), const sf::Color &color)
{
	m_window = &window;

	m_func = func;
	m_color = color;

	m_precision = 0.1f;
	m_map_size = 2 * (size_t)round(m_window->getSize().x * (1 / m_precision));
	//m_point_map = sf::VertexArray(sf::Points, m_map_size);
	m_array_size = 2000;
	m_points = new sf::Vector2f[m_array_size];

	m_timer = clock();
}

void Graph::update(const sf::Vector2f &origo, float x_spacing, float y_spacing)
{
	float x = -(float)((m_array_size * m_precision) / 2);
	//float x = -(m_map_size * m_precision) / 4;

	for (register int i = 0; i < (int)m_array_size; i++)
	{
		//m_point_map[i].position = sf::Vector2f(x, /*origo.y - y_spacing * */m_func((x - origo.x) / x_spacing));
		m_points[i] = sf::Vector2f(x, m_func(x));
		x += m_precision;
	}
}

void Graph::draw(sf::RenderWindow &window, const sf::Vector2f &origo, float x_spacing, float y_spacing)
{
	//sf::RectangleShape draw_point(sf::Vector2f(1.0f,1.0f));
	//draw_point.setFillColor(m_color);
	//for (float x = 0.0f; x < window.getSize().x; x += 0.5f)
	//{
	//	//draw_point.setPosition(origo.x + x_spacing * x, m_func(origo.y - y_spacing * x));
	//	//draw_point.setPosition(x, m_func(origo.y - y_spacing * ((x - origo.x) / x_spacing)));
	//	draw_point.setPosition(x, origo.y - y_spacing * m_func((x - origo.x) / x_spacing));
	//	//draw_point.setPosition(x, origo.y - y_spacing * m_func(x));
	//	window.draw(draw_point);
	//}
	//float precision = 0.1f;
	//size_t map_size = (size_t)round(window.getSize().x * (1 / precision));

	//float x = 0.0f;

	//sf::VertexArray point_map(sf::Points, m_map_size);
	//for (register int i = 0; i < m_map_size; i++)
	//{
	//	point_map[i].position = sf::Vector2f(x, origo.y - y_spacing * m_func((x - origo.x) / x_spacing));
	//	point_map[i].color = m_color;
	//	x += m_precision;
	//}

	if (clock() > m_timer + 1000)
	{
		update(origo, x_spacing, y_spacing);
		m_timer = clock();
	}
	sf::VertexArray point_map(sf::Points, m_array_size);
	for (register int i = 0; i < (int)m_array_size; i++)
	{
		//std::cout << "x : " << origo.x + x_spacing * m_point_map[i].position.x << "   y: " << origo.y + y_spacing * m_point_map[i].position.y;
		point_map[i].position = sf::Vector2f(origo.x + x_spacing * m_points[i].x, origo.y + y_spacing * m_points[i].y);
		point_map[i].color = m_color;
	}
	window.draw(point_map);

	std::cout << "x : " << origo.x + x_spacing * m_points[1000].x << "   y: " << origo.y + y_spacing * m_points[1000].y << '\n';
}
