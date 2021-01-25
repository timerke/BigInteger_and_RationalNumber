/*
Заголовочный файл для класса Leibniz_row для работы с рядом Лейбница.
*/

#pragma once
#ifndef LEIBNIZ_ROW_H
#define LEIBNIZ_ROW_H

#include "rational_number.h"


/**
 * Класс для работы с рядом Лейбница.
 */
class Leibniz_row
{
public:
	// Конструктор по умолчанию
	Leibniz_row();
	// Метод вычисляет вещественное значение числа Пи
	double calculate_double_pi(unsigned int);
	// Метод вычисляет вещественное значение ряда
	double calculate_double_row(unsigned int);
	// Метод вычисляет рациональное значение числа Пи
	Rational_number calculate_rational_pi(unsigned int);
	// Метод вычисляет рациональное значение ряда
	Rational_number calculate_rational_row(unsigned int);
};

#endif // !LEIBNIZ_ROW_H

