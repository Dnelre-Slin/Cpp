#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Extras.h"
#include "Graph.h"
#include "Axis.h"
#include <string>
#include "Matrix.h"

void test()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	//sf::RectangleShape l1 = esf::getLine(sf::Vector2f(400, 300), sf::Vector2f(400, 200), 2.0f);
	srand((unsigned int)time(0));

	sf::RectangleShape floor = esf::getLine(sf::Vector2f(0, 250), sf::Vector2f(500, 600), 1.0f);
	floor.setFillColor(sf::Color::Green);

	sf::RectangleShape box(sf::Vector2f(100, 100));
	box.setPosition(50, 50);
	box.setFillColor(sf::Color::Cyan);

	sf::RectangleShape box2(sf::Vector2f(100, 100));
	box2.setPosition(300, 300);
	box2.setFillColor(sf::Color::Magenta);

	window.setFramerateLimit(144);

	//Polygon2D poly1(Point2D(350, 250), Point2D(300, 200), Point2D(250, 350));
	//sf::ConvexShape poly_shape = esf::getShape(poly1, sf::Color::Green);

	bool mouse_button_held = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == 0) //Left mouse button.
				{
					mouse_button_held = true;
					box2.setOrigin(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y));
				}
				else if (event.mouseButton.button == 1) //Right mouse button.
				{
					//std::cout << "Array size: " << poly1.size() << '\n';
					std::cout << floor.getOrigin().x << "  " << floor.getOrigin().y << '\n';
					box2.setOrigin(sf::Vector2f(0, 0));
					//std::cout << floor.getGlobalBounds().width << "   " << floor.getLocalBounds().width << '\n';
					//std::cout << floor.getGlobalBounds().height << "   " << floor.getLocalBounds().height << '\n';
					//std::cout << "[ (" << floor.getPosition().x << " , " << floor.getPosition().y << ")";
					//std::cout << "  ,  (" << floor.getPosition().x + floor.getGlobalBounds().width << " , " << floor.getPosition().y << ")";
					//std::cout << "  ,  (" << floor.getPosition().x << " , " << floor.getPosition().y + floor.getGlobalBounds().height << ")";
					//std::cout << "  ,  (" << floor.getPosition().x + floor.getGlobalBounds().width << " , " << floor.getPosition().y + floor.getGlobalBounds().height << ")\n";
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0)
				mouse_button_held = false;
			else if (mouse_button_held && event.type == sf::Event::MouseMoved)
			{
				//poly1 += Point2D(event.mouseMove.x, event.mouseMove.y);
				//poly_shape = esf::getShape(poly1, sf::Color::Green);
				break;
			}
		}

		//if (l1.getRotation() > 270.0f && l1.getRotation() < 270.6f)
		//	l1.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		//l1.rotate(0.5f);
		//std::cout << "Rotation: " << l1.getRotation() << '\n';

		box2.rotate(1);

		window.clear();
		window.draw(floor);
		window.draw(box);
		window.draw(box2);
		//window.draw(l1);
		//window.draw(poly_shape);
		//window.draw(shape);
		window.display();
	}
}

float mathFunc(float x)
{
	//return powf(x,2.0f);
	//return 0.5f* x + 10.0f;
	//return 3*sinf(x)+10;
	//return powf(x, 5) - 3 * powf(x, 3) + powf(x, 2) + 2 * x - 5;
	//float PI = 3.141592653589793;
	//float sum_result = 0;
	//
	//for (unsigned int n = 1; n < 1000; n++)
	//{
	//	sum_result += ((cosf((2 * PI*n) / 3) - 1) / n) * sin((2 * PI*n*x) / 3);
	//}

	//return 1 + (2 / PI) * sum_result;

	//float sum = 0;
	//for (unsigned int n = 0; n < 9; n++)
	//{
	//	sum += (n + 1)*powf(x, 10 - n);
	//}
	//return sum;

	return x;

	//return (-0.5*powf(x, 2) + 2.5 * x - 1);
}

float mFunc(float x, float *parameters, const unsigned int size)
{
	float sum = 0;
	for (register unsigned int i = 0; i < size; i++)
	{
		sum += parameters[i] * powf(x, (float)size - (float)i - 1.0f);
	}
	//std::cout << parameters[9] << " | " << parameters[10] << '\n';
	//float sum = (parameters[0] * powf(x, 10) + parameters[1] * powf(x, 9) + parameters[2] * powf(x, 8) +
	//		parameters[3] * powf(x, 7) + parameters[4] * powf(x, 6) + parameters[5] * powf(x, 5) +
	//		parameters[6] * powf(x, 4) + parameters[7] * powf(x, 3) + parameters[8] * powf(x, 2) +
	//		parameters[9] * x + parameters[10]);

	return sum;
	//return 0.5*x;
	//return sum;
}

float mFunc3(float x, float *parameters, const unsigned int size)
{
	float PI = 3.141592653589793;
	float sum_result = 0;
	
	for (unsigned int n = 1; n < 10; n++)
	{
		sum_result += ((cosf((2 * PI*n) / 3) - 1) / n) * sin((2 * PI*n*x) / 3);
	}

	return sum_result;
	//return 0.5*x;
	//return sum;
}

float mFunc2(float x, float *parameters, const unsigned int size)
{
	return 0.000001828181565f * powf(x,6.f) - 0.000165292397661f * powf(x, 5.f) + 0.005664961013645f * powf(x, 4.f) - 0.09196418128655f *powf(x, 3.f) + 0.713937621832359f * powf(x, 2.f) - 2.194517543859649f * x + 25.567042606516292f;
}

void updateParams(Axis &axis)
{
	std::vector<sf::Vector2f> temp;
	std::vector<sf::Vector2f> hum;

	Matrix tempMat;
	Matrix humMat;

	esf::readCSV(temp, hum);


	for (unsigned int i = temp.size() - 10; i < temp.size(); i++)
	{
		tempMat.add(temp[i].x - temp[temp.size() - 10].x + 1.f, temp[i].y);
		humMat.add(hum[i].x - hum[temp.size() - 10].x + 1.f, hum[i].y);
	}

	~tempMat;
	~humMat;

	std::vector<float> vf1;
	std::vector<float> vf2;
	std::vector<double> vd1 = tempMat.getGaused();
	std::vector<double> vd2 = humMat.getGaused();

	for (unsigned int i = 0; i < vd1.size(); i++)
	{
		vf1.push_back((float)vd1[i]);
		vf2.push_back((float)vd2[i]);
	}

	axis.updateParams(vf1, 0);
	axis.updateParams(vf2, 1);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	srand((unsigned int)time(0));

	window.setFramerateLimit(144);

	bool mouse_button_held = false;

	const unsigned int x_space_size = 4;
	float x_space[x_space_size] = { 1,10,60,600 };
	const unsigned int y_space_size = 4;
	float y_space[y_space_size] = { 1,10,100,1000 };


	Axis axis_cross(window, x_space, x_space_size, y_space, y_space_size, sf::Color::Black);

	Graph tempGraph(mFunc, sf::Color::Red);
	Graph humGraph(mFunc, sf::Color::Blue);
	//Graph co_graph(cosf, sf::Color::Blue);

	//axis_cross.addGraph(co_graph);

	sf::Vector2f mouse_moved(0.0f, 0.0f);

	//std::vector<std::vector<float>> mat;

	//std::vector<float> v;
	//v.push_back(powf(30, 20));
	//v.push_back(powf(20, 19));
	//v.push_back(powf(10, 18));
	//v.push_back(18);

	//mat.push_back(v);
	//v.clear();

	//v.push_back(powf(23, 20));
	//v.push_back(powf(12, 19));
	//v.push_back(powf(5, 18));
	//v.push_back(18);

	//mat.push_back(v);
	//v.clear();

	//v.push_back(powf(29, 20));
	//v.push_back(powf(21, 19));
	//v.push_back(powf(14, 18));
	//v.push_back(15);

	//mat.push_back(v);


	//matrix.m_matrix = mat;
	//matrix.add(10, 24);
	//matrix.add(100, 24);
	//matrix.add(200, 25);
	//matrix.add(300, 25);
	//matrix.add(400, 26);
	//matrix.add(500, 25);
	//matrix.add(600, 24);
	//matrix.add(700, 23);
	//matrix.add(800, 22);
	//matrix.add(900, 21);
	//matrix.add(50, 24);
	//matrix.add(55, 25);
	//matrix.add(60, 25);
	//matrix.add(65, 26);
	//matrix.add(70, 25);
	//matrix.add(75, 24);
	//matrix.add(80, 23);
	//matrix.add(85, 22);
	//matrix.add(90, 21);
	//matrix.add(95, 21);
	//matrix.add(100, 19);

	//matrix.add(13, 23);
	//matrix.add(16, 21);
	//matrix.add(19, 18);
	//matrix.add(22, 21);
	//matrix.add(25, 24);
	//matrix.add(28, 26);
	//matrix.add(11, 30);
	//matrix.add(12, 24);
	//matrix.add(13, 26);
	//matrix.add(14, 24);
	//matrix.add(15, 23);
	//matrix.add(16, 21);
	//matrix.add(17, 18);
	//matrix.add(18, 21);
	//matrix.add(19, 24);
	//matrix.add(20, 26);
	//matrix.add(21, 30);

	//matrix.add(1, 20);
	//matrix.add(3, 21);
	//matrix.add(5, 22);
	//matrix.add(7, 23);
	//matrix.add(10, 24);
	//matrix.add(13, 25);
	//matrix.add(15, 25);
	//matrix.add(18, 26);
	//matrix.add(20, 26);
	//matrix.add(23, 25);
	//matrix.add(25, 25);
	//matrix.add(28, 24);
	//matrix.add(30, 23);
	//Matrix matrix1;
	//Matrix matrix2;

	//std::cout << "DEBUG 1\n";

	//std::vector<sf::Vector2f> temp;
	//std::vector<sf::Vector2f> hum;

	//esf::readCSV(temp, hum);

	//std::cout << "DEBUG 2\n";

	//for (unsigned int i = temp.size() - 10; i < temp.size(); i++)
	//{
	//	matrix1.add(temp[i].x - temp[temp.size() - 10].x + 1.f, temp[i].y);
	//	matrix2.add(hum[i].x - hum[temp.size() - 10].x + 1.f, hum[i].y);
	//}

	//matrix1.printM();

	//std::cout << "\n\n";

	//~matrix1;
	//~matrix2;

	//matrix1.printM();

	//matrix1.printGauss();

	//std::vector<float> vf1;
	//std::vector<float> vf2;
	//std::vector<double> vd1 = matrix1.getGaused();
	//std::vector<double> vd2 = matrix2.getGaused();

	//for (unsigned int i = 0; i < vd1.size(); i++)
	//{
	//	vf1.push_back((float)vd1[i]);
	//	vf2.push_back((float)vd2[i]);
	//}

	//tempGraph.setParams(vf1);
	//humGraph.setParams(vf2);

	axis_cross.addGraph(tempGraph);
	axis_cross.addGraph(humGraph);

	updateParams(axis_cross);

	clock_t update_timer = clock();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == 0) //Left mouse button.
				{
					mouse_button_held = true;
					mouse_moved.x = (float)event.mouseButton.x;
					mouse_moved.y = (float)event.mouseButton.y;
					axis_cross.printScale();
					//axis_cross.scaleX(0.5f);
				}
				else if (event.mouseButton.button == 1) //Right mouse button.
				{
					/*axis_cross.scaleX(2.0f);*/
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == 0)
			{
				mouse_button_held = false;
			}
			else if (mouse_button_held && event.type == sf::Event::MouseMoved)  //Mouse drag.
			{
				//axis_cross.move(sf::Vector2f(event.mouseMove.x - mouse_moved.x, event.mouseMove.y - mouse_moved.y));
				mouse_moved.x = (float)event.mouseMove.x;
				mouse_moved.y = (float)event.mouseMove.y;
				break;
			}
			else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.delta > 0)
			{
				//axis_cross.scale(1.0f + (event.mouseWheelScroll.delta / 10.0f));
			}
			else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.delta < 0)
			{
				//axis_cross.scaleX(1.0f / (1.0f + (event.mouseWheelScroll.delta / 10)));
				//axis_cross.scale(1.0f / pow(1.1f,-event.mouseWheelScroll.delta));
			}
		}

		if (clock() > update_timer + 60000)
			updateParams(axis_cross);


		window.clear(sf::Color(200,200,200,255));

		axis_cross.draw();
		//window.draw(text);

		window.display();
	}

	return 0;
}