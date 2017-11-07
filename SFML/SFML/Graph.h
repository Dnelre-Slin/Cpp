#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
//#include "Extras.h"

class Graph
{
private:
	//std::vector<sf::Vector2f> m_points;
	sf::RenderWindow *m_window;
	float(*m_func)(float);
	sf::Color m_color;
	sf::VertexArray m_point_map;
	size_t m_map_size;
	float m_precision;

	clock_t m_timer;

public:
	inline Graph() { }
	inline Graph(sf::RenderWindow &window, float(*func)(float), const sf::Color &color = sf::Color::Black) { set(window, func, color); }

	void set(sf::RenderWindow &window, float(*func)(float), const sf::Color &color = sf::Color::Black);
	inline void setColor(const sf::Color &color) { m_color = color; }

	inline clock_t getTimer() { return m_timer; }

	void update(const sf::Vector2f &origo, float x_spacing, float y_spacing);

	void draw(sf::RenderWindow &window, const sf::Vector2f &origo, float x_spacing, float y_spacing);
};