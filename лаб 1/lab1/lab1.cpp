#include "stdafx.h"
#include "Auxil.h"                            // вспомогательные функции 
#include "Fibonachi.h"
#include <iostream>
#include <ctime>
#include <locale>

using namespace std;

#define  CYCLE  1000000                       // количество циклов  

int main(int argc, char* argv[])
{

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	cout << endl << "количество циклов:         " << CYCLE;
	cout << endl << "среднее значение (int):    " << av1 / CYCLE;
	cout << endl << "среднее значение (double): " << av2 / CYCLE;
	cout << endl << "продолжительность (у.е):   " << (t2 - t1);
	cout << endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	cout << endl;
	system("pause");

	cout << "=============\n\nФункция чисел Фиббоначи";
	clock_t  t3 = 0, t4 = 0; int a;
	cout << endl << "Введите N-ое число: ";
	cin >> a;
	t3 = clock();
	long double result = fibonachi(a);
	cout << endl << a << " число Фиббоначи = " << result;
	t4 = clock();
	cout << endl << "продолжительность (у.е):   " << (t4 - t3);
	cout << endl << "                  (сек):   "
		<< ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);
	cout << endl;
	system("pause");
	return 0;
}