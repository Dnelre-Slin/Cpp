#pragma once
#include <iostream>
#include <vector>

class Matrix
{
private:
	void printV(std::vector<float> &v);
public:
	std::vector<std::vector<float>> m_matrix;
	void operator~();
	void add(float x, float y);
	std::vector<float> getGaused();
	void printGauss();

	void printM();
};