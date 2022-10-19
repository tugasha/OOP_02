// 136ж.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Автор: Туганов К.А.

#include <iostream> // модуль для ввода/вывода в консоль
#include <locale>   //для вывода на русском
#include <math.h> // математические функции
#include "Vector.h"// модуль с функциями
#include <exception>
#include <fstream> // работа с файлами
#include <string> //строки

// std - стандартное пространство имён
using namespace std;
// arrays - пользовательское пространство имён с функциями для работы с массивом
using namespace arrays;

int main()
{
    string file_in_name = "vector_in.txt"; // имя файла входных данных
    string file_out_name = "vector_out.txt"; // имя файла выходных данных
    

    setlocale(LC_ALL, "rus"); // локализация на русский язык

    cout << "136 Даны натуральное число n, действительные числа a1,..., an. Вычислить:" << endl;
    cout << "ж) a1 - a2 + a3 - ... + ((-1)^(n+1))*an;" << endl;

    ///string filename = "data"; // имя файла

   // int n; //число элементов массива 
   // n = 0;
   // cout << "Введите n (n > 0): "; cin >> n;

    // n должно быть натуральным числом
    //if (n > 0)
    int rows;

    rows = rowsNumber(file_in_name); //Подсчёт количества строк в файле с элементами массива
    cout << "Numbers of rows: " << rows << endl;  

    vector_int arr;// динамический массив (пока пустой)
    arr.resize(rows);//изменение размера


    // ввод массива
    input_rando_vector(arr);

 	// заполнение массива
        getArray(arr, file_in_name, rows);

        // вывод массива
        output_vector(arr);
        cout << endl;

        // вычисление суммы по условию задачи
        double result = calc_result(arr);

    //вывод массива в фаил
    otput_file(arr, file_out_name);

    cout << endl; // переход на новую строку

        // вывод полученной суммы
        cout << "Ответ = " << result << endl;

        //fout.close();
        // очищение памяти
        //arr.clear();

    return 0;
}