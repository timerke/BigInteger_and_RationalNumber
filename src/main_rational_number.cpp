/*
Задача 2.
Разработать класс для представления рациональных чисел (в виде пары целых
чисел: числитель и знаменатель). Класс должен иметь метод сокращения дроби
(то есть поиск наибольшего общего делителя и автоматическое деление на него
числителя и знаменателя, если он больше 1). Перегрузить для него арифметические
операции и обеспечить автоматическое сокращение дроби. Продемонстрировать
работу класса на примере приближенного вычисления числа «Пи» по формуле ряда
Лейбница.
*/

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include <iostream>
#include "leibniz_row.h"
#include "rational_number.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	// Получаем все числа для арифметических действий
	std::cout << "Введите рациональное число: ";
	Rational_number number1;
	std::cin >> number1;
	std::cout << "Введите рациональное число: ";
	Rational_number number2;
	std::cin >> number2;
	std::cout << "Введите целое число: ";
	int number3;
	std::cin >> number3;
	std::cout << "Введите вещественное число: ";
	double number4;
	std::cin >> number4;
	// Выполняем арифметические действия с числами разных типов
	// Сложение
	std::cout << number1 << " + " << number2 << " = " <<
		number1 + number2 << "\n";
	std::cout << number1 << " + " << number3 << " = " <<
		number1 + number3 << "\n";
	std::cout << number1 << " + " << number4 << " = " <<
		number1 + number4 << "\n";
	// Вычитание
	std::cout << number1 << " - " << number2 << " = " <<
		number1 - number2 << "\n";
	std::cout << number1 << " - " << number3 << " = " <<
		number1 - number3 << "\n";
	std::cout << number1 << " - " << number4 << " = " <<
		number1 - number4 << "\n";
	// Умножение
	std::cout << number1 << " * " << number2 << " = " <<
		number1 * number2 << "\n";
	std::cout << number1 << " * " << number3 << " = " <<
		number1 * number3 << "\n";
	std::cout << number1 << " * " << number4 << " = " <<
		number1 * number4 << "\n";
	// Деление
	std::cout << number1 << " / " << number2 << " = " <<
		number1 / number2 << "\n";
	std::cout << number1 << " / " << number3 << " = " <<
		number1 / number3 << "\n";
	std::cout << number1 << " / " << number4 << " = " <<
		number1 / number4 << "\n";
	// Вычисляем число Пи с помощью ряда Лейбница
	Leibniz_row row;
	int n = 10;
	std::cout << "Число Пи с учетом n = " << n << " членов ряда Лейбница: Пи = " <<
		row.calculate_rational_pi(n) << " = " << row.calculate_double_pi(n) << "\n";

	_CrtDumpMemoryLeaks();
	return 0;
}