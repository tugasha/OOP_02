// Автор: Туганов К.А.
// заголовочный файл модуля
#pragma once //контроль за то, чтобы фаил подключался строго один раз
#include <vector>
#include<fstream>
#include <string> //строки

using vector_int = std:: vector<int>;
// создаём пространство имён, в котором будут находится все наши функции

namespace arrays
{
	/// вывод массива в консоль
	void output_vector(const vector_int &v);

	/// рандомное заполнение массива от 1 до n+1
	void input_rando_vector(vector_int &v); 

 	/// вычисление ж) a1 - a2 + a3 - ... + ((-1)^(n+1))*an;
	double calc_result(const vector_int &v);

	///вывод массива в фаил
	void otput_file(const vector_int& v, std::string name);

 	/// Количество строк в файле
	int rowsNumber(std::string name);

	/// Чтение массива из файла строк в файле
	void getArray(vector_int& v, std::string name, int k);
}