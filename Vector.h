// �����: ������� �.�.
// ������������ ���� ������
#pragma once //�������� �� ��, ����� ���� ����������� ������ ���� ���
#include <vector>
#include<fstream>
#include <string> //������

using vector_int = std:: vector<int>;
// ������ ������������ ���, � ������� ����� ��������� ��� ���� �������

namespace arrays
{
	/// ����� ������� � �������
	void output_vector(const vector_int &v);

	/// ��������� ���������� ������� �� 1 �� n+1
	void input_rando_vector(vector_int &v); 

 	/// ���������� �) a1 - a2 + a3 - ... + ((-1)^(n+1))*an;
	double calc_result(const vector_int &v);

	///����� ������� � ����
	void otput_file(const vector_int& v, std::string name);

 	/// ���������� ����� � �����
	int rowsNumber(std::string name);

	/// ������ ������� �� ����� ����� � �����
	void getArray(vector_int& v, std::string name, int k);
}