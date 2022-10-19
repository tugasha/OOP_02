// �����: ������� �.�.

#include <iostream>// ������ ��� �����/������ � �������
#include <math.h>// �������������� �������
//#include <ctime>   // ��� ��������� ��������� �����
#include "Vector.h"// ������ � ���������
#include <exception>
#include <fstream> // ������ � �������
#include <string> //������


// ����� ������� � �������
void arrays::output_vector(const vector_int &v)
{	
	 if(v.empty()) throw std::invalid_argument("Empty array");
	 	for (int i = 0; i < v.size(); i++)
			std::cout << v [i] << " ";
}


// ��������� ���������� ������� �� 1 �� n+1
void arrays::input_rando_vector(vector_int &v)
{
	if(v.empty()) throw std::invalid_argument("Empty array");
		for (int i = 0; i < v.size(); i++)
			v [i] = rand() % 100 + 1;
}

// ���������� �) a1 - a2 + a3 - ... + ((-1)^(n+1))*an;
double arrays::calc_result(const vector_int &v)
{
	if(v.empty()) throw std::invalid_argument("Empty array");
		double sum = 0;// ��� ���������� ������������� �����
			float z = 1;

	for (int i = 0; i < v.size(); i++){
		sum += v [i] * z;// ��������� � ����� ���-�� �����
		z = -z;
	}
	return sum;// ���������� ����������� �����
}

//����� ������� � ����
void arrays::otput_file(const vector_int& v, std::string name)
{
    if(v.empty()) throw std::invalid_argument("Empty array");
	std::ofstream fout(name);
	if (!fout.is_open()) // ����� ������ is_open()
			throw std::invalid_argument("File isn't open!");//���� ���� �� ������
	for (int i = 0; i < v.size(); i++) //����� ������� � ����

		fout <<v[i] << std::endl;
	
	fout.close();
}

/// ���������� ����� � �����
int arrays::rowsNumber(std::string name){
    std::ifstream f(name);

    if (name == "")  throw std::invalid_argument("File's name error");
    //���� ���� �� ������
    if (!f.is_open()) // ����� ������ is_open()
        throw std::invalid_argument("File isn't open!");//���� ���� �� ������

    std::string s;//�������� ������ 

    int k = 0;
    while (f.peek() != EOF) {
        getline(f, s);
        k++;
    }
    f.close();// �������� �����
    if(k == 0) throw std::invalid_argument("Empty file");
    return k;
}

/// ������ ������� �� ����� ����� � �����
void arrays::getArray(vector_int& v, std::string name, int k){
if(v.empty()) throw std::invalid_argument("Empty array");
    v.resize(k);
    std::ifstream f(name);

    if (name == "")  throw std::invalid_argument("File's name error");
    if (!f.is_open()) // ����� ������ is_open()
        throw std::invalid_argument("File isn't open!");//���� ���� �� ������

    for (int i = 0; i < k; i++)//���������� �������
        f >> v.at(i);
       

    f.close();// �������� �����

}
