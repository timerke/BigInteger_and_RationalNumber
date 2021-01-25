/*
Модуль содержит формулу для ряда Лейбница.
*/

#include "leibniz_row.h"


/**
 * Конструктор по умолчанию.
 */
Leibniz_row::Leibniz_row() {}

/**
 * Метод вычисляет вещественное значение числа Пи.
 * @param n: количество членов ряда, которые нужно учесть.
 * @return: значение числа Пи.
 */
double Leibniz_row::calculate_double_pi(unsigned int n)
{
	return 4 * calculate_double_row(n);
}

/**
 * Метод вычисляет вещественное значение ряда.
 * @param n: количество членов ряда, которые нужно учесть.
 * @return: значение ряда.
 */
double Leibniz_row::calculate_double_row(unsigned int n)
{
	double row = 0;
	for (unsigned int i = 0; i <= n; i++)
	{
		double sign = i % 2 ? -1.0 : 1.0;
		row += sign / (2.0 * i + 1.0);
	}
	return row;
}

/**
 * Метод вычисляет рациональное значение числа Пи.
 * @param n: количество членов ряда, которые нужно учесть.
 * @return: значение числа Пи.
 */
Rational_number Leibniz_row::calculate_rational_pi(unsigned int n)
{
	Rational_number value = calculate_rational_row(n);
	return 4 * value;
}

/**
 * Метод вычисляет рациональное значение ряда.
 * @param n: количество членов ряда, которые нужно учесть.
 * @return: значение ряда.
 */
Rational_number Leibniz_row::calculate_rational_row(unsigned int n)
{
	Rational_number row(0, 1);
	for (unsigned int i = 0; i <= n; i++)
	{
		int sign = i % 2 ? -1 : 1;
		Rational_number row_part(sign, 2 * i + 1);
		row = row + row_part;
	}
	return row;
}