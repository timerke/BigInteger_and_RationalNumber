/*
Заголовочный файл с объявлением класса Rational_number для работы с
рациональными числами.
*/

#pragma once
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include <iostream>
#include <string>


// Задаем короткое название типа
typedef long long int llint;
typedef unsigned long long int ullint;

/**
 * Класс для работы с рациональными числами.
 */
class Rational_number
{
private:
	ullint numerator; // числитель
	ullint denominator; // знаменатель
	int sign; // знак

	// Метод выполяет сложение двух чисел типа Rational_number
	Rational_number add(Rational_number*);
	// Метод вычисляет double значение рационального числа
	double calculate();
	// Метод выполняет деление двух чисел типа Rational_number
	Rational_number divide(Rational_number*);
	// Метод вычисляет наибольший общий делитель числителя и знаменателя
	ullint find_divisor();
	// Метод выполяет умножение двух чисел типа Rational_number
	Rational_number multiply(Rational_number*);
	// Метод находит наибольший общий делитель числителя и знаменателя и
	// сокращает дробь
	void reduce_fraction();
	// Метод выполняет вычитание двух чисел типа Rational_number
	Rational_number subtract(Rational_number*);

public:
	// Конструктор по умолчанию
	Rational_number();
	// Конструктор инициализирует число
	Rational_number(const Rational_number&);
	// Конструктор инициализирует число
	Rational_number(llint, llint);
	// Метод возвращает строковое представление числа
	std::string get_str();
	// Метод инициализирует число
	void init(llint, llint);
	// Метод инициализирует число
	void init(ullint, ullint, int);

	// Перегрузка оператора присваивания
	void operator = (const Rational_number& number)
	{
		init(number.numerator * number.sign, number.denominator);
	}
	// Перегрузка оператора стандартного ввода
	friend std::istream& operator >> (std::istream&, Rational_number&);
	// Перегрузка оператора стандартного вывода
	friend std::ostream& operator << (std::ostream&, const Rational_number&);

	// Перегрузка арифметических операторов
	// Сложение
	// Перегрузка оператора сложения для чисел типа Rational_number
	friend Rational_number operator + (Rational_number, Rational_number);
	// Перегрузка оператора сложения для чисел типа Rational_number и int
	friend Rational_number operator + (Rational_number, int);
	// Перегрузка оператора сложения для чисел типа int и Rational_number
	friend Rational_number operator + (int, Rational_number);
	// Перегрузка оператора сложения для чисел типа Rational_number и double
	friend double operator + (Rational_number, double);
	// Перегрузка оператора сложения для чисел типа double и Rational_number
	friend double operator + (double, Rational_number);
	// Перегрузка оператора сложения с присваиванием += с числом типа
	// Rational_number
	Rational_number& operator += (Rational_number number)
	{
		*this = this->add(&number);
		return *this;
	}
	// Перегрузка оператора сложения с присваиванием += с числом типа double
	Rational_number& operator += (int number)
	{
		Rational_number new_number(number, 1);
		*this = this->add(&new_number);
		return *this;
	}
	// Перегрузка оператора префиксного сложения ++
	Rational_number& operator ++ ()
	{
		Rational_number number(1, 1);
		*this = this->add(&number);
		return *this;
	}
	// Перегрузка оператора постфиксного сложения ++
	Rational_number operator ++ (int)
	{
		Rational_number number = *this;
		++(*this);
		return number;
	}

	// Вычитание
	// Перегрузка оператора вычитания для чисел типа Rational_number
	friend Rational_number operator - (Rational_number, Rational_number);
	// Перегрузка оператора вычитания для чисел типа Rational_number и int
	friend Rational_number operator - (Rational_number, int);
	// Перегрузка оператора вычитания для чисел типа int и Rational_number
	friend Rational_number operator - (int, Rational_number);
	// Перегрузка оператора вычитания для чисел типа Rational_number и double
	friend double operator - (Rational_number, double);
	// Перегрузка оператора вычитания для чисел типа double и Rational_number
	friend double operator - (double, Rational_number);
	// Перегрузка оператора вычитания с присваиванием -= с числом типа
	// Rational_number
	Rational_number& operator -= (Rational_number number)
	{
		*this = this->subtract(&number);
		return *this;
	}
	// Перегрузка оператора вычитания с присваиванием -= с числом типа int
	Rational_number& operator -= (int number)
	{
		Rational_number new_number(number, 1);
		*this = this->subtract(&new_number);
		return *this;
	}
	// Перегрузка оператора префиксного вычитания --
	Rational_number& operator -- ()
	{
		Rational_number number(1, 1);
		*this = this->subtract(&number);
		return *this;
	}
	// Перегрузка оператора постфиксного вычитания --
	Rational_number operator -- (int)
	{
		Rational_number number = *this;
		--(*this);
		return number;
	}

	// Умножение
	// Перегрузка оператора умножения для чисел типа Rational_number
	friend Rational_number operator * (Rational_number, Rational_number);
	// Перегрузка оператора умножения для чисел типа Rational_number и int
	friend Rational_number operator * (Rational_number, int);
	// Перегрузка оператора умножения для чисел типа int и Rational_number
	friend Rational_number operator * (int, Rational_number);
	// Перегрузка оператора умножения для чисел типа Rational_number и double
	friend double operator * (Rational_number, double);
	// Перегрузка оператора умножения для чисел типа double и Rational_number
	friend double operator * (double, Rational_number);
	// Перегрузка оператора умножения с присваиванием *= с числом типа
	// Rational_number
	Rational_number& operator *= (Rational_number number)
	{
		*this = this->multiply(&number);
		return *this;
	}
	// Перегрузка оператора умножения с присваиванием *= с числом типа int
	Rational_number& operator *= (int number)
	{
		Rational_number new_number(number, 1);
		*this = this->multiply(&new_number);
		return *this;
	}

	// Деление
	// Перегрузка оператора деления для чисел типа Rational_number
	friend Rational_number operator / (Rational_number, Rational_number);
	// Перегрузка оператора деления для чисел типа Rational_number и int
	friend Rational_number operator / (Rational_number, int);
	// Перегрузка оператора деления для чисел типа int и Rational_number
	friend Rational_number operator / (int, Rational_number);
	// Перегрузка оператора деления для чисел типа Rational_number и double
	friend double operator / (Rational_number, double);
	// Перегрузка оператора деления для чисел типа double и Rational_number
	friend double operator / (double, Rational_number);
	// Перегрузка оператора деления с присваиванием /= с числом типа
	// Rational_number
	Rational_number& operator /= (Rational_number number)
	{
		*this = this->divide(&number);
		return *this;
	}
	// Перегрузка оператора деления с присваиванием /= с числом типа int
	Rational_number& operator /= (int number)
	{
		Rational_number new_number(number, 1);
		*this = this->divide(&new_number);
		return *this;
	}
};

#endif // !RATIONAL_NUMBER_H