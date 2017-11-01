#include "Axis.h"
#include <iostream>

void Axis::setMarks(float spacing, const sf::Color &color)
{
	float line_height = 6.0f;

	float mark_spot = (int)(m_y_axis.getPosition().x) % (int)(spacing);

	while (mark_spot < m_window->getSize().x)
	{
		m_x_axis_marks.push_back(esf::getLine(sf::Vector2f(mark_spot, m_x_axis.getPosition().y - line_height / 2),
											  sf::Vector2f(mark_spot, m_x_axis.getPosition().y + line_height / 2), 1.0f, color));
		mark_spot += spacing;
	}

	mark_spot = (int)(m_x_axis.getPosition().y) % (int)(spacing);

	while (mark_spot < m_window->getSize().y)
	{
		m_y_axis_marks.push_back(esf::getLine(sf::Vector2f(m_y_axis.getPosition().x - line_height / 2, mark_spot),
											  sf::Vector2f(m_y_axis.getPosition().x + line_height / 2, mark_spot), 1.0f, color));

		mark_spot += spacing;
	}
}

Axis::Axis(sf::RenderWindow &window, const sf::Color &color)
{
	m_window = &window;

	m_x_axis = esf::getLine(sf::Vector2f(0.0f, m_window->getSize().y / 2), sf::Vector2f(m_window->getSize().x, m_window->getSize().y / 2), 1.0f, color);
	m_y_axis = esf::getLine(sf::Vector2f(m_window->getSize().x / 3, 0.0f), sf::Vector2f(m_window->getSize().x / 3, m_window->getSize().y), 1.0f, color);

	float spacing = 30.0f; // 15 pixels between marks.
	setMarks(spacing, color);
}

void Axis::setColor(const sf::Color &color)
{
	m_x_axis.setFillColor(color);
	m_y_axis.setFillColor(color);
}

void Axis::scaleX(float scale_value)
{
	//for (sf::RectangleShape &xMark : m_x_axis_marks)
	//	xMark.move(scale_value * (m_y_axis.getPosition().x - xMark.getPosition().x), 0.0f);	
	for (sf::RectangleShape &xMark : m_x_axis_marks)
	{
		//std::cout << (m_y_axis.getPosition().x - xMark.getPosition().x) << '\n';
		//xMark.move(scale_value * (m_y_axis.getPosition().x - xMark.getPosition().xdc), 0.0f);
		xMark.setPosition((scale_value * (xMark.getPosition().x - m_y_axis.getPosition().x)) +
										  m_y_axis.getPosition().x, xMark.getPosition().y);
	}
}

void Axis::scaleY(float scale_value)
{
	for (sf::RectangleShape &yMark : m_y_axis_marks)
		yMark.move(0.0f, scale_value * (m_x_axis.getPosition().y - yMark.getPosition().y));
}

void Axis::draw()
{
	m_window->draw(m_x_axis);
	m_window->draw(m_y_axis);

	for (const sf::RectangleShape &xMark : m_x_axis_marks)
		m_window->draw(xMark);
	for (const sf::RectangleShape &yMark : m_y_axis_marks)
		m_window->draw(yMark);
}
