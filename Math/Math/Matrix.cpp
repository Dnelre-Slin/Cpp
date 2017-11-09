#include "Matrix.h"

void Matrix::printV(std::vector<float>& v)
{
	std::cout << "[  ";
	for (float &f : v)
	{
		std::cout << f << "  ";
	}
	std::cout << "]\n";
}

void Matrix::operator~()
{
	for (unsigned int i = 0; i < m_matrix.size(); i++) // i is the index of the rows in the matrix.
	{
		float pos0 = m_matrix[i][i]; // Get 1 at position 0.
		for (unsigned int j = 0; j < m_matrix[i].size() - i; j++) //j is the index of the colons in the matrix.
		{
			m_matrix[i][i + j] /= pos0;
		}
		for (unsigned int k = 0; k < m_matrix.size(); k++) // k is the index of the rows below row i.
		{
			if (k != i)
			{
				float nr = m_matrix[k][i];
				for (unsigned int l = 0; l < m_matrix[k].size(); l++) // l is index of colons.
				{
					m_matrix[k][l] = m_matrix[k][l] - (m_matrix[i][l] * nr);
				}
			}
		}
	}
}

void Matrix::add(float x, float y)
{
	std::vector<float> v;
	v.push_back(powf(x, 10));
	v.push_back(powf(x, 9));
	v.push_back(powf(x, 8));
	v.push_back(powf(x, 7));
	v.push_back(powf(x, 6));
	v.push_back(powf(x, 5));
	v.push_back(powf(x, 4));
	v.push_back(powf(x, 3));
	v.push_back(powf(x, 2));
	v.push_back(x);
	v.push_back(1);
	v.push_back(y);
	m_matrix.push_back(v);
}
//void Matrix::operator~()
//{
//	for (unsigned int i = 0; i < m_matrix.size(); i++) // i is the index of the rows in the matrix.
//	{
//		float pos0 = m_matrix[i][i]; // Get 1 at position 0.
//		for (unsigned int j = 0; j < m_matrix[i].size() - i; j++) //j is the index of the colons in the matrix.
//		{
//			m_matrix[i][i + j] /= pos0;
//		}
//		for (unsigned int k = i + 1; k < m_matrix.size(); k++) // k is the index of the rows below row i.
//		{
//			float nr = m_matrix[k][i];
//			for (unsigned int l = i; l < m_matrix[k].size(); l++) // l is index of colons.
//			{
//				m_matrix[k][l] = m_matrix[k][l] - (m_matrix[i][l] * nr);
//			}
//		}
//	}
//}

void Matrix::printM()
{
	for (std::vector<float> &v : m_matrix)
	{
		printV(v);
	}
}
