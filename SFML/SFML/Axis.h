#pragma once
#include <vector>
#include "Extras.h"

class Axis
{
private:
	sf::RectangleShape m_x_axis;
	sf::RectangleShape m_y_axis;
	std::vector<sf::RectangleShape> m_x_axis_marks;
	std::vector<sf::RectangleShape> m_y_axis_marks;

	sf::RenderWindow *m_window;

	void setMarks(float spacing, const sf::Color &color);

public:
	Axis(sf::RenderWindow &window, const sf::Color &color = sf::Color::White);

	void setColor(const sf::Color &color);

	void scaleX(float scale_value);
	void scaleY(float scale_value);

	void draw();
};