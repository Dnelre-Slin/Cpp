#include "Axis.h"
#include <iostream>

//void Axis::setMarks(float spacing, const sf::Color &color)
//{
//	float line_height = 6.0f;
//
//	float mark_spot = (int)(m_y_axis.getPosition().x) % (int)(spacing);
//
//	while (mark_spot < m_window->getSize().x)
//	{
//		m_x_axis_marks.push_back(esf::getLine(sf::Vector2f(mark_spot, m_x_axis.getPosition().y - line_height / 2),
//											  sf::Vector2f(mark_spot, m_x_axis.getPosition().y + line_height / 2), 1.0f, color));
//		mark_spot += spacing;
//	}
//
//	mark_spot = (int)(m_x_axis.getPosition().y) % (int)(spacing);
//
//	while (mark_spot < m_window->getSize().y)
//	{
//		m_y_axis_marks.push_back(esf::getLine(sf::Vector2f(m_y_axis.getPosition().x - line_height / 2, mark_spot),
//											  sf::Vector2f(m_y_axis.getPosition().x + line_height / 2, mark_spot), 1.0f, color));
//
//		mark_spot += spacing;
//	}
//}

void Axis::drawXmarks(float _spacing, const sf::Color &color, float line_length, float line_thickness)
{
	sf::RectangleShape line_marker = esf::getLine(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, line_length), line_thickness, color);

	int spacing = (int)(roundf(_spacing));

	float x_mark_spot = (float)((int)(roundf(m_y_axis.getPosition().x)) % spacing);
	float y_mark_spot = (m_x_axis.getPosition().y - (line_length / 2.0f));

	while (x_mark_spot < m_window->getSize().x)
	{
		line_marker.setPosition(sf::Vector2f(x_mark_spot, y_mark_spot));
		m_window->draw(line_marker);
		x_mark_spot += spacing;
	}
}

void Axis::drawYmarks(float _spacing, const sf::Color &color, float line_length, float line_thickness)
{
	sf::RectangleShape line_marker = esf::getLine(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(line_length, 0.0f), line_thickness, color);

	int spacing = (int)(roundf(_spacing));

	float x_mark_spot = m_y_axis.getPosition().x - (line_length / 2.0f);
	float y_mark_spot = (float)((int)(roundf(m_x_axis.getPosition().y)) % spacing);

	while (y_mark_spot < m_window->getSize().y)
	{
		line_marker.setPosition(sf::Vector2f(x_mark_spot, y_mark_spot));
		m_window->draw(line_marker);
		y_mark_spot += spacing;
	}
}

Axis::Axis(sf::RenderWindow &window, const sf::Color &color, float x_mark_spacing, float y_mark_spacing)
{
	m_window = &window;

	float x_size = (float)(m_window->getSize().x);
	float y_size = (float)(m_window->getSize().y);

	m_x_axis = esf::getLine(sf::Vector2f(0.0f, y_size / 2.0f), sf::Vector2f(x_size, y_size / 2.0f), 1.0f, color);
	m_y_axis = esf::getLine(sf::Vector2f(x_size / 3.0f, 0.0f), sf::Vector2f(x_size / 3.0f, y_size), 1.0f, color);

	m_x_mark_spacing = x_mark_spacing;
	m_y_mark_spacing = y_mark_spacing;
	//setMarks(spacing, color);
}

void Axis::setColor(const sf::Color &color)
{
	m_x_axis.setFillColor(color);
	m_y_axis.setFillColor(color);
}

void Axis::scaleX(float scale_value)
{
	std::cout << scale_value << '\n';
	if ((scale_value < 1 && m_x_mark_spacing > 2.0f) ||
		(scale_value > 1 && m_x_mark_spacing < 1000.0f))
		m_x_mark_spacing *= scale_value;
	//for (sf::RectangleShape &xMark : m_x_axis_marks)
	//{
	//	xMark.setPosition((scale_value * (xMark.getPosition().x - m_y_axis.getPosition().x)) +
	//									  m_y_axis.getPosition().x, xMark.getPosition().y);
	//}
}

void Axis::scaleY(float scale_value)
{
	if ((scale_value < 1 && m_y_mark_spacing > 2.0f) ||
		(scale_value > 1 && m_y_mark_spacing < 1000.0f))
		m_y_mark_spacing *= scale_value;
	//for (sf::RectangleShape &yMark : m_y_axis_marks)
	//{
	//	yMark.setPosition(yMark.getPosition().x, (scale_value * (yMark.getPosition().y - m_x_axis.getPosition().y)) + 
	//															 m_x_axis.getPosition().y);
	//}
}

void Axis::scale(float scale_value)
{
	scaleX(scale_value);
	scaleY(scale_value);
}

void Axis::move(const sf::Vector2f & vector)
{
	m_x_axis.move(0, vector.y);
	m_y_axis.move(vector.x, 0);
}

void Axis::draw()
{
	m_window->draw(m_x_axis);
	m_window->draw(m_y_axis);

	drawXmarks(m_x_mark_spacing, m_x_axis.getFillColor());
	drawYmarks(m_y_mark_spacing, m_y_axis.getFillColor());

	//setupDraw(spacing, m_x_axis.getFillColor());

	//for (const sf::RectangleShape &xMark : m_x_axis_marks)
	//	m_window->draw(xMark);
	//for (const sf::RectangleShape &yMark : m_y_axis_marks)
	//	m_window->draw(yMark);
}
