// Автор: Туганов К.А.

#include <iostream>// модуль для ввода/вывода в консоль
#include <math.h>// математические функции
//#include <ctime>   // для генерации случайных чисел
#include "Vector.h"// модуль с функциями
#include <exception>
#include <fstream> // работа с файлами
#include <string> //строки


// вывод массива в консоль
void arrays::output_vector(const vector_int &v)
{	
	 if(v.empty()) throw std::invalid_argument("Empty array");
	 	for (int i = 0; i < v.size(); i++)
			std::cout << v [i] << " ";
}


// рандомное заполнение массива от 1 до n+1
void arrays::input_rando_vector(vector_int &v)
{
	if(v.empty()) throw std::invalid_argument("Empty array");
		for (int i = 0; i < v.size(); i++)
			v [i] = rand() % 100 + 1;
}

// вычисление ж) a1 - a2 + a3 - ... + ((-1)^(n+1))*an;
double arrays::calc_result(const vector_int &v)
{
	if(v.empty()) throw std::invalid_argument("Empty array");
		double sum = 0;// для сохранения промежуточной суммы
			float z = 1;

	for (int i = 0; i < v.size(); i++){
		sum += v [i] * z;// добавляем к ранее выч-ой сумме
		z = -z;
	}
	return sum;// возвращаем вычисленную сумму
}

//вывод массива в фаил
void arrays::otput_file(const vector_int& v, std::string name)
{
    if(v.empty()) throw std::invalid_argument("Empty array");
	std::ofstream fout(name);
	if (!fout.is_open()) // вызов метода is_open()
			throw std::invalid_argument("File isn't open!");//Если файл не открыт
	for (int i = 0; i < v.size(); i++) //вывод массива в фаил

		fout <<v[i] << std::endl;
	
	fout.close();
}

/// Количество строк в файле
int arrays::rowsNumber(std::string name){
    std::ifstream f(name);

    if (name == "")  throw std::invalid_argument("File's name error");
    //Если файл не открыт
    if (!f.is_open()) // вызов метода is_open()
        throw std::invalid_argument("File isn't open!");//Если файл не открыт

    std::string s;//Буферная строка 

    int k = 0;
    while (f.peek() != EOF) {
        getline(f, s);
        k++;
    }
    f.close();// Закрытие файла
    if(k == 0) throw std::invalid_argument("Empty file");
    return k;
}

/// Чтение массива из файла строк в файле
void arrays::getArray(vector_int& v, std::string name, int k){
if(v.empty()) throw std::invalid_argument("Empty array");
    v.resize(k);
    std::ifstream f(name);

    if (name == "")  throw std::invalid_argument("File's name error");
    if (!f.is_open()) // вызов метода is_open()
        throw std::invalid_argument("File isn't open!");//Если файл не открыт

    for (int i = 0; i < k; i++)//Заполнение массива
        f >> v.at(i);
       

    f.close();// Закрытие файла

}
