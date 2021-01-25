/*
Модуль содержит определение методов класса Rational_number.
*/

#include <cmath>
#include "rational_number.h"


/**
 * Конструктор по умолчанию.
 */
Rational_number::Rational_number() {}

/**
 * Конструктор инициализирует число.
 * @param number: копируемое число.
 */
Rational_number::Rational_number(const Rational_number& number)
{
	init(number.numerator, number.denominator, number.sign);
}

/**
 * Конструктор инициализирует число.
 * @param numerator: числитель;
 * @param denominator: знаменатель.
 */
Rational_number::Rational_number(llint numerator, llint denominator)
{
	init(numerator, denominator);
}

/**
 * Метод выполяет сложение двух чисел типа Rational_number.
 * @param number: добавляемое число.
 * @return: сумма.
 */
Rational_number Rational_number::add(Rational_number* number)
{
	llint numerator = this->sign * this->numerator * number->denominator +
		this->denominator * number->sign * number->numerator;
	llint denominator = this->denominator * number->denominator;
	return Rational_number(numerator, denominator);
}

/**
 * Метод вычисляет double значение рационального числа.
 * @return: вещественное значение числа.
 */
double Rational_number::calculate()
{
	return 1.0 * sign * numerator / denominator;
}

/**
 * Метод выполняет деление двух чисел типа Rational_number.
 * @param number: делитель.
 * @return: частное.
 */
Rational_number Rational_number::divide(Rational_number* number)
{
	llint numerator = this->sign * this->numerator * number->sign *
		number->denominator;
	llint denominator = this->denominator * number->numerator;
	return Rational_number(numerator, denominator);
}

/**
 * Метод вычисляет наибольший общий делитель числителя и знаменателя.
 * @return: наибольший общий делитель.
 */
ullint Rational_number::find_divisor()
{
	ullint divisor = numerator <= denominator ? numerator : denominator;
	if (divisor <= 1)
		return 1;
	while (divisor > 1 && (numerator % divisor != 0 ||
		denominator % divisor != 0))
		divisor--;
	return divisor;
}

/**
 * Метод возвращает строковое представление числа.
 * @return: строковое представление числа.
 */
std::string Rational_number::get_str()
{
	std::string str = "";
	if (this->sign < 0)
		str += "-";
	str += std::to_string(this->numerator) + "/" +
		std::to_string(this->denominator);
	return str;
}

/**
 * Метод инициализирует число.
 * @param numerator: числитель;
 * @param denominator: знаменатель.
 */
void Rational_number::init(llint numerator, llint denominator)
{
	llint production = numerator * denominator;
	if (production == 0)
		sign = 0;
	else if (production < 0)
		sign = -1;
	else
		sign = 1;
	this->numerator = std::abs(numerator);
	this->denominator = std::abs(denominator);
	// Сокращаем дробь
	reduce_fraction();
}

/**
 * Метод инициализирует число.
 * @param numerator: числитель;
 * @param denominator: знаменатель;
 * @param sign: знак.
 */
void Rational_number::init(ullint numerator, ullint denominator, int sign)
{
	this->numerator = numerator;
	this->denominator = denominator;
	this->sign = sign;
	// Сокращаем дробь
	reduce_fraction();
}

/**
 * Метод выполяет умножение двух чисел типа Rational_number.
 * @param number: умножаемое число.
 * @return: произведение.
 */
Rational_number Rational_number::multiply(Rational_number* number)
{
	llint numerator = this->sign * this->numerator * number->sign *
		number->numerator;
	llint denominator = this->denominator * number->denominator;
	return Rational_number(numerator, denominator);
}

/**
 * Метод находит наибольший общий делитель числителя и знаменателя и сокращает
 * дробь.
 */
void Rational_number::reduce_fraction()
{
	// Вычисляем наибольший общий делитель
	ullint divisor = find_divisor();
	numerator /= divisor;
	denominator /= divisor;
}

/**
 * Метод выполняет вычитание двух чисел типа Rational_number.
 * @param number: вычитаемое число.
 * @return: разность.
 */
Rational_number Rational_number::subtract(Rational_number* number)
{
	llint numerator = this->sign * this->numerator * number->denominator -
		this->denominator * number->sign * number->numerator;
	llint denominator = this->denominator * number->denominator;
	return Rational_number(numerator, denominator);
}

/**
 * Перегрузка оператора стандартного ввода. Считываем по одному символу из
 * потока, проверяем, что символ допустим (является цифрой или знаком -).
 * Прекращаем чтение потока, когда встретим запрещенный символ.
 */
std::istream& operator >> (std::istream& in, Rational_number& number)
{
	llint denominator, numerator;
	char c;
	in >> numerator >> c >> denominator;
	number.init(numerator, denominator);
	return in;
}

/**
 * Перегрузка оператора стандартного вывода.
 */
std::ostream& operator << (std::ostream& out, const Rational_number& number)
{
	if (number.sign < 0)
		out << '-';
	out << number.numerator << "/" << number.denominator;
	return out;
}

// Перегрузка оператора сложения двух чисел типа Rational_number
Rational_number operator + (Rational_number number1, Rational_number number2)
{
	return number1.add(&number2);
}

// Перегрузка оператора сложения двух чисел типа Rational_number и int
Rational_number operator + (Rational_number number1, int number2)
{
	Rational_number new_number(number2, 1);
	return number1.add(&new_number);
}

// Перегрузка оператора сложения двух чисел типа int и Rational_number
Rational_number operator + (int number1, Rational_number number2)
{
	Rational_number new_number(number1, 1);
	return number2.add(&new_number);
}

// Перегрузка оператора сложения двух чисел типа Rational_number и double
double operator + (Rational_number number1, double number2)
{
	return number1.calculate() + number2;
}

// Перегрузка оператора сложения двух чисел типа double и Rational_number
double operator + (double number1, Rational_number number2)
{
	return number1 + number2.calculate();
}

// Перегрузка оператора вычитания двух чисел типа Rational_number
Rational_number operator - (Rational_number number1, Rational_number number2)
{
	return number1.subtract(&number2);
}

// Перегрузка оператора вычитания двух чисел типа Rational_number и int
Rational_number operator - (Rational_number number1, int number2)
{
	Rational_number new_number(number2, 1);
	return number1.subtract(&new_number);
}

// Перегрузка оператора вычитания двух чисел типа int и Rational_number
Rational_number operator - (int number1, Rational_number number2)
{
	Rational_number new_number(number1, 1);
	return number2.subtract(&new_number);
}

// Перегрузка оператора вычитания двух чисел типа Rational_number и double
double operator - (Rational_number number1, double number2)
{
	return number1.calculate() - number2;
}

// Перегрузка оператора вычитания двух чисел типа double и Rational_number
double operator - (double number1, Rational_number number2)
{
	return number1 - number2.calculate();
}

// Перегрузка оператора умножения двух чисел типа Rational_number
Rational_number operator * (Rational_number number1, Rational_number number2)
{
	return number1.multiply(&number2);
}

// Перегрузка оператора умножения двух чисел типа Rational_number и int
Rational_number operator * (Rational_number number1, int number2)
{
	Rational_number new_number(number2, 1);
	return number1.multiply(&new_number);
}

// Перегрузка оператора умножения двух чисел типа int и Rational_number
Rational_number operator * (int number1, Rational_number number2)
{
	Rational_number new_number(number1, 1);
	return number2.multiply(&new_number);
}

// Перегрузка оператора умножения двух чисел типа Rational_number и double
double operator * (Rational_number number1, double number2)
{
	return number1.calculate() * number2;
}

// Перегрузка оператора умножения двух чисел типа double и Rational_number
double operator * (double number1, Rational_number number2)
{
	return number1 * number2.calculate();
}

// Перегрузка оператора деления двух чисел типа Rational_number
Rational_number operator / (Rational_number number1, Rational_number number2)
{
	return number1.divide(&number2);
}

// Перегрузка оператора деления двух чисел типа Rational_number и int
Rational_number operator / (Rational_number number1, int number2)
{
	Rational_number new_number(number2, 1);
	return number1.divide(&new_number);
}

// Перегрузка оператора деления двух чисел типа int и Rational_number
Rational_number operator / (int number1, Rational_number number2)
{
	Rational_number new_number(number1, 1);
	return number2.divide(&new_number);
}

// Перегрузка оператора деления двух чисел типа Rational_number и double
double operator / (Rational_number number1, double number2)
{
	return number1.calculate() / number2;
}

// Перегрузка оператора деления двух чисел типа double и Rational_number
double operator / (double number1, Rational_number number2)
{
	return number1 / number2.calculate();
}