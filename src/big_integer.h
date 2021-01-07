/*
Заголовочный файл с объявлением класса Big_integer. Этот класс предназначен
для работы с целыми числами с неограниченным количеством разрядов.
*/

#pragma once
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <iostream>


/**
 * Кдасс для работы с целыми числами с неограниченным количеством разрядов.
 */
class Big_integer
{
private:
	// Атрибуты класса
	char sign; // знак числа
	unsigned int size; // количество цифр в числе
	char* digits = nullptr; // массив цифр в числе

	// Метод выполяет сложение двух чисел типа Big_integer
	Big_integer add(Big_integer*);
	// Метод определяет, допустимое ли значение имеет символ
	bool check_allowability(const char);
	// Метод инициализирует нулевое число
	void create_zero();
	// Метод удаляет память, выделенную на массив digits
	void delete_memory();
	// Метод выполняет целочисленное деление двух чисел типа Big_integer
	Big_integer divide(Big_integer*);
	// Метод выполяет умножение двух чисел типа Big_integer
	Big_integer multiply(Big_integer*);
	// Метод выполняет вычитание двух чисел типа Big_integer
	Big_integer subtract(Big_integer*);

public:
	// Конструктор по умолчанию
	Big_integer();
	// Конструктор копирует число
	Big_integer(const Big_integer&);
	// Конструктор инициализирует число по строковому представлению числа
	Big_integer(const char*);
	// Конструктор инициализирует число по числу типа int
	Big_integer(long long int);
	// Конструктор инициализирует число по массиву цифр числа
	Big_integer(const char*, unsigned int, char);
	// Деструктор класса
	~Big_integer();
	// Метод инициализирует число по строковому представлению числа
	void init(const char*);
	// Метод инициализирует число по массиву цифр числа
	void init(const char*, unsigned int, char);

	// Функция вычисляет абсолютное значение числа
	friend Big_integer abs(Big_integer&);

	// Перегрузка оператора присваивания
	void operator = (const Big_integer& number)
	{
		init(number.digits, number.size, number.sign);
	}
	// Перегрузка оператора стандартного ввода
	friend std::istream& operator >> (std::istream&, Big_integer&);
	// Перегрузка оператора стандартного вывода
	friend std::ostream& operator << (std::ostream&, const Big_integer&);

	// Перегрузка арифметических операторов
	// Сложение
	// Перегрузка оператора сложения для чисел типа Big_integer
	friend Big_integer operator + (Big_integer, Big_integer);
	// Перегрузка оператора сложения для чисел типа Big_integer и int
	friend Big_integer operator + (Big_integer, int);
	// Перегрузка оператора сложения для чисел типа int и Big_integer
	friend Big_integer operator + (int, Big_integer);
	// Перегрузка оператора сложения с присваиванием += с числом типа
	// Big_integer
	Big_integer& operator += (Big_integer number)
	{
		*this = this->add(&number);
		return *this;
	}
	// Перегрузка оператора сложения с присваиванием += с числом типа int
	Big_integer& operator += (int number)
	{
		Big_integer new_number(number);
		*this = this->add(&new_number);
		return *this;
	}
	// Перегрузка оператора префиксного сложения ++
	Big_integer& operator ++ ()
	{
		Big_integer number(1);
		*this = this->add(&number);
		return *this;
	}
	// Перегрузка оператора постфиксного сложения ++
	Big_integer operator ++ (int)
	{
		Big_integer number = *this;
		++(*this);
		return number;
	}

	// Вычитание
	// Перегрузка оператора вычитания для чисел типа Big_integer
	friend Big_integer operator - (Big_integer, Big_integer);
	// Перегрузка оператора вычитания для чисел типа Big_integer и int
	friend Big_integer operator - (Big_integer, int);
	// Перегрузка оператора вычитания для чисел типа int и Big_integer
	friend Big_integer operator - (int, Big_integer);
	// Перегрузка оператора вычитания с присваиванием -= с числом типа
	// Big_integer
	Big_integer& operator -= (Big_integer number)
	{
		*this = this->subtract(&number);
		return *this;
	}
	// Перегрузка оператора вычитания с присваиванием -= с числом типа int
	Big_integer& operator -= (int number)
	{
		Big_integer new_number(number);
		*this = this->subtract(&new_number);
		return *this;
	}
	// Перегрузка оператора префиксного вычитания --
	Big_integer& operator -- ()
	{
		Big_integer number(1);
		*this = this->subtract(&number);
		return *this;
	}
	// Перегрузка оператора постфиксного вычитания --
	Big_integer operator -- (int)
	{
		Big_integer number = *this;
		--(*this);
		return number;
	}

	// Умножение
	// Перегрузка оператора умножения для чисел типа Big_integer
	friend Big_integer operator * (Big_integer, Big_integer);
	// Перегрузка оператора умножения для чисел типа Big_integer и int
	friend Big_integer operator * (Big_integer, int);
	// Перегрузка оператора умножения для чисел типа int и Big_integer
	friend Big_integer operator * (int, Big_integer);
	// Перегрузка оператора умножения с присваиванием *= с числом типа
	// Big_integer
	Big_integer& operator *= (Big_integer number)
	{
		*this = this->multiply(&number);
		return *this;
	}
	// Перегрузка оператора умножения с присваиванием *= с числом типа int
	Big_integer& operator *= (int number)
	{
		Big_integer new_number(number);
		*this = this->multiply(&new_number);
		return *this;
	}

	// Деление
	// Перегрузка оператора целочисленного деления для чисел типа Big_integer
	friend Big_integer operator / (Big_integer, Big_integer);
	// Перегрузка оператора целочисленного деления для чисел типа Big_integer
	// и int
	friend Big_integer operator / (Big_integer, int);
	// Перегрузка оператора целочисленного деления для чисел типа int и
	// Big_integer
	friend Big_integer operator / (int, Big_integer);
	// Перегрузка оператора деления с присваиванием /= с числом типа
	// Big_integer
	Big_integer& operator /= (Big_integer number)
	{
		*this = this->divide(&number);
		return *this;
	}
	// Перегрузка оператора деления с присваиванием /= с числом типа int
	Big_integer& operator /= (int number)
	{
		Big_integer new_number(number);
		*this = this->divide(&new_number);
		return *this;
	}
	// Перегрузка оператора вычисления остатка от деления для чисел типа
	// Big_integer
	friend Big_integer operator % (Big_integer, Big_integer);
	// Перегрузка оператора вычисления остатка от деления для чисел типа
	// Big_integer и int
	friend Big_integer operator % (Big_integer, int);
	// Перегрузка оператора вычисления остатка от деления для чисел типа int и
	// Big_integer
	friend Big_integer operator % (int, Big_integer);
	// Перегрузка оператора вычисления остатка от деления с присваиванием %=
	// с числом типа Big_integer
	Big_integer& operator %= (Big_integer number)
	{
		*this = *this % number;
		return *this;
	}
	// Перегрузка оператора вычисления остатка от деления с присваиванием %=
	// с числом типа int
	Big_integer& operator %= (int number)
	{
		Big_integer new_number(number);
		*this = *this % new_number;
		return *this;
	}

	// Перегрузка операторов сравнения
	// Перегрузка оператора сравнения < для чисел типа Big_integer
	friend bool operator < (Big_integer&, Big_integer&);
	// Перегрузка оператора сравнения < для чисел типа Big_integer и int
	friend bool operator < (Big_integer&, int);
	// Перегрузка оператора сравнения < для чисел типа int и Big_integer
	friend bool operator < (int, Big_integer&);
	// Перегрузка оператора сравнения <= для чисел типа Big_integer
	friend bool operator <= (Big_integer&, Big_integer&);
	// Перегрузка оператора сравнения <= для чисел типа Big_integer и int
	friend bool operator <= (Big_integer&, int);
	// Перегрузка оператора сравнения <= для чисел типа int и Big_integer
	friend bool operator <= (int, Big_integer&);
	// Перегрузка оператора сравнения > для чисел типа Big_integer
	friend bool operator > (Big_integer&, Big_integer&);
	// Перегрузка оператора сравнения > для чисел типа Big_integer и int
	friend bool operator > (Big_integer&, int);
	// Перегрузка оператора сравнения > для чисел типа int и Big_integer
	friend bool operator > (int, Big_integer&);
	// Перегрузка оператора сравнения >= для чисел типа Big_integer
	friend bool operator >= (Big_integer&, Big_integer&);
	// Перегрузка оператора сравнения >= для чисел типа Big_integer и int
	friend bool operator >= (Big_integer&, int);
	// Перегрузка оператора сравнения >= для чисел типа int и Big_integer
	friend bool operator >= (int, Big_integer&);
	// Перегрузка оператора сравнения == для чисел типа Big_integer
	friend bool operator == (Big_integer&, Big_integer&);
	// Перегрузка оператора сравнения == для чисел типа Big_integer и int
	friend bool operator == (Big_integer&, int);
	// Перегрузка оператора сравнения == для чисел типа int и Big_integer
	friend bool operator == (int, Big_integer&);
	// Перегрузка оператора сравнения != для чисел типа Big_integer
	friend bool operator != (Big_integer&, Big_integer&);
	// Перегрузка оператора сравнения != для чисел типа Big_integer и int
	friend bool operator != (Big_integer&, int);
	// Перегрузка оператора сравнения != для чисел типа int и Big_integer
	friend bool operator != (int, Big_integer&);
};

// Функция вычисляет абсолютное значение числа
Big_integer abs(Big_integer&);

// Функция вычисляет факториал числа
Big_integer factorial(unsigned int);

// Функция увеличивает размер массива
template <typename T>
int increase_array(T**, unsigned int, unsigned int);

#endif // !BIG_INTEGER_H