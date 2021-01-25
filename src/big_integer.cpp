/*
Модуль содержит определения методов класса Big_integer.
*/

#include <cmath>
#include "big_integer.h"


/**
 * Конструктор по умолчанию.
 */
Big_integer::Big_integer() {}

/**
 * Конструктор копирует число.
 * @param number: копируемое число.
 */
Big_integer::Big_integer(const Big_integer& number)
{
	init(number.digits, number.size, number.sign);
}

/**
 * Конструктор инициализирует число по строковому представлению числа.
 * @param str: число в строковом представлении.
 */
Big_integer::Big_integer(const char* str)
{
	init(str);
}

/**
 * Конструктор инициализирует число по числу типа int.
 * @param number: число.
 */
Big_integer::Big_integer(long long int number)
{
	if (number < 0)
		sign = -1;
	else if (number > 0)
		sign = 1;
	else
	{
		// Создаем нулевое число
		create_zero();
		return;
	}
	number = std::abs(number);
	// Определяем количество цифр в числе
	size = 1;
	while (number / (int)pow(10, size) != 0)
		size++;
	// Удаляем ранее выделенную память и выделяем заново
	delete_memory();
	digits = new char[size];
	// Записываем цифры в массив
	unsigned int i = 0;
	while (i < size)
	{
		digits[i] = number % 10;
		number /= 10;
		i++;
	}
}

/**
 * Конструктор инициализирует число по массиву цифр числа.
 * @param digits: массив цифр;
 * @param size: количество цифр;
 * @param sign: знак числа.
 */
Big_integer::Big_integer(const char* digits, unsigned int size, char sign)
{
	init(digits, size, sign);
}

/**
 * Деструктор класса.
 */
Big_integer::~Big_integer()
{
	// Освобождаем память
	delete_memory();
}

/**
 * Метод выполняет сложение двух чисел типа Big_integer.
 * @param number: добавляемое число.
 * @return: сумма.
 */
Big_integer Big_integer::add(Big_integer* number)
{
	if (this->sign != number->sign && this->sign * number->sign)
	{
		// Если числа разных знаков, нужно выполнить вычитание
		Big_integer new_number = -1 * (*number);
		return this->subtract(&new_number);
	}
	// Определяем, какое из складываемых чисел больше по модулю
	Big_integer number1_abs = abs(*this);
	Big_integer number2_abs = abs(*number);
	Big_integer* min_num;
	Big_integer* max_num;
	if (number1_abs < number2_abs)
	{
		min_num = &number1_abs;
		max_num = &number2_abs;
	}
	else
	{
		min_num = &number2_abs;
		max_num = &number1_abs;
	}
	// Определяем знак суммы
	char result_sign;
	if (this->sign != 0)
		result_sign = this->sign;
	else if (number->sign != 0)
		result_sign = number->sign;
	else
		result_sign = 0;
	// Складываем цифры в обоих числах столбиком
	char* digits_in_sum = new char[max_num->size + 1];
	char sum = 0;
	unsigned int n;
	for (n = 0; n < min_num->size; n++)
	{
		sum += min_num->digits[n] + max_num->digits[n];
		if (sum >= 10)
		{
			digits_in_sum[n] = sum - 10;
			sum = 1;
		}
		else
		{
			digits_in_sum[n] = sum;
			sum = 0;
		}
	}
	// Продолжаем суммирование только с цифрами из большего числа
	for (; n < max_num->size; n++)
	{
		sum += max_num->digits[n];
		if (sum >= 10)
		{
			digits_in_sum[n] = sum - 10;
			sum = 1;
		}
		else
		{
			digits_in_sum[n] = sum;
			sum = 0;
		}
	}
	if (sum)
	{
		digits_in_sum[n] = sum;
		n++;
	}
	// Создаем число типа Big_integer и освобождаем память, выделенную на
	// массив digits_in_sum
	Big_integer result(digits_in_sum, n, result_sign);
	delete[] digits_in_sum;
	return result;
}

/**
 * Метод проверяет, является ли символ допустимым для числа Big_integer.
 * @param c: символ для проверки.
 * @return: true, если символ допустим, иначе false.
 */
bool Big_integer::check_allowability(const char c)
{
	if (c == '-' || ('0' <= c && c <= '9'))
		return true;
	return false;
}

/**
 * Метод инициализирует нулевое число.
 */
void Big_integer::create_zero()
{
	sign = 0;
	size = 1;
	digits = new char[size];
	digits[0] = 0;
}

/**
 * Метод удаляет память, выделенную на массив digits.
 */
void Big_integer::delete_memory()
{
	if (digits)
	{
		delete[] digits;
		digits = nullptr;
	}
}

/**
 * Метод выполняет целочисленное деление двух чисел типа Big_integer.
 * @param number: делитель.
 * @return: частное.
 */
Big_integer Big_integer::divide(Big_integer* number)
{
	if (*number == 0)
		// Деление на ноль
		throw std::runtime_error("Zero division error\n");
	Big_integer number1_abs = abs(*this);
	Big_integer number2_abs = abs(*number);
	if (number1_abs < number2_abs)
		// Делимое меньше делителя, потому частное равно 0
		return Big_integer((long long int)0);
	// Делимое не меньше делителя, частное надо найти
	// Определяем знак частного
	char result_sign = this->sign * number->sign;
	// Из numbers1_abs берем столько же цифр в старших разрядах, сколько их всего
	// в numbers2_abs
	char* part_digits = new char[number2_abs.size];
	for (unsigned int i = 0; i < number2_abs.size; i++)
		part_digits[i] = number1_abs.digits[number1_abs.size - number2_abs.size + i];
	Big_integer part_number(part_digits, number2_abs.size, 1);
	delete[] part_digits;
	// Делим числа столбиком
	char* reverse_digits_in_result = new char[number1_abs.size];
	int digits_count = 0; // количество цифр в частном
	// Индекс следующей цифры из number1_abs, которую нужно учесть при делении
	int next_index = number1_abs.size - number2_abs.size - 1;
	Big_integer spam;
	while (true)
	{
		if (part_number < number2_abs)
		{
			if (next_index < 0)
				// Больше нет цифр в числе numbers1_abs
				break;
			part_number *= 10;
			part_number += number1_abs.digits[next_index];
			next_index--;
			if (part_number < number2_abs)
			{
				reverse_digits_in_result[digits_count] = 0;
				digits_count++;
				continue;
			}
		}
		int digit_in_quotient = 1;
		spam = number2_abs;
		while (true)
		{
			if (spam > part_number)
			{
				digit_in_quotient--;
				spam -= number2_abs;
				part_number -= spam;
				break;
			}
			spam += number2_abs;
			digit_in_quotient++;
		}
		reverse_digits_in_result[digits_count] = digit_in_quotient;
		digits_count++;
	}
	// Переворачиваем цифры
	char* digits_in_result = new char[digits_count];
	for (int i = 0; i < digits_count; i++)
		digits_in_result[i] = reverse_digits_in_result[digits_count - i - 1];
	// Получаем частное
	Big_integer result(digits_in_result, digits_count, result_sign);
	// Очищаем мусор
	delete[] reverse_digits_in_result;
	delete[] digits_in_result;
	return result;
}

/**
 * Метод инициализирует число по строковому представлению числа.
 * @param str: число в строковом представлении.
 */
void Big_integer::init(const char* str)
{
	unsigned int i = 0;
	// Определяем знак числа
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else
		sign = 1;
	// Определяем количество цифр в числе
	while (str[i] == '0')
		i++;
	unsigned int i_start = i;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	int i_stop = i;
	size = i_stop - i_start;
	// Определяем цифры в числе
	if (size == 0)
	{
		// Создаем нулевое число
		create_zero();
		return;
	}
	// Удаляем ранее выделенную память и выделяем новую
	delete_memory();
	digits = new char[size];
	i_stop--;
	for (i = 0; i < size; i++, i_stop--)
		digits[i] = str[i_stop] - '0';
}

/**
 * Метод инициализирует число по массиву цифр числа.
 * @param digits: массив цифр;
 * @param size: количество цифр;
 * @param sign: знак числа.
 */
void Big_integer::init(const char* digits, unsigned int size, char sign)
{
	// Ищем нули в больших разрядах числа, чтобы удалить их
	int i = (int)size - 1;
	while (i > -1 && digits[i] == 0)
		i--;
	this->size = i + 1;
	if (this->size == 0)
	{
		// Создаем нулевое число
		create_zero();
		return;
	}
	this->sign = sign;
	// Удаляем ранее выделенную память и выделяем новую
	delete_memory();
	this->digits = new char[size];
	for (unsigned int i = 0; i < this->size; i++)
		this->digits[i] = digits[i];
}

/**
 * Метод выполняет умножение двух чисел типа Big_integer.
 * @param number: умножаемое число.
 * @return: произведение.
 */
Big_integer Big_integer::multiply(Big_integer* number)
{
	// Выдяляем память для массива цифр в произведении
	unsigned int result_size = this->size + number->size + 1;
	char* digits_in_prod = new char[result_size];
	for (unsigned int i = 0; i < result_size; i++)
		digits_in_prod[i] = 0;
	// Умножаем два числа столбиком
	unsigned int i, j;
	for (i = 0; i < this->size; i++)
	{
		char product = 0; // для произведения двух цифр
		int sum = 0; // для суммы произведения двух цифр с цифрой, уже записанной
		// в результрующее произведение
		for (j = 0; j < number->size; j++)
		{
			product += number->digits[j] * this->digits[i];
			if (product >= 10)
			{
				sum += digits_in_prod[j + i] + product % 10;
				product /= 10;
				if (sum >= 10)
				{
					digits_in_prod[j + i] = sum - 10;
					sum = 1;
				}
				else
				{
					digits_in_prod[j + i] = sum;
					sum = 0;
				}
			}
			else
			{
				sum += digits_in_prod[j + i] + product;
				product = 0;
				if (sum >= 10)
				{
					digits_in_prod[j + i] = sum - 10;
					sum = 1;
				}
				else
				{
					digits_in_prod[j + i] = sum;
					sum = 0;
				}
			}
		}
		sum += digits_in_prod[j + i] + product;
		if (sum >= 10)
		{
			digits_in_prod[j + i] = sum - 10;
			digits_in_prod[j + i + 1] = 1;
		}
		else
			digits_in_prod[j + i] = sum;
	}
	// Знак произведения
	char result_sign = this->sign * number->sign;
	// Создаем число типа Big_integer и освобождаем память, выделенную на
	// массив digits_in_prod
	Big_integer result(digits_in_prod, result_size, result_sign);
	delete[] digits_in_prod;
	return result;
}

/**
 * Метод выполняет вычитание двух чисел типа Big_integer.
 * @param number: вычитаемое число.
 * @return: разность.
 */
Big_integer Big_integer::subtract(Big_integer* number)
{
	if (this->sign != number->sign && this->sign * number->sign)
	{
		// Если числа разных знаков, нужно выполнить сложение
		Big_integer new_number = -1 * (*number);
		return this->add(&new_number);
	}
	// Определяем, какое из вычитаемых чисел больше по модулю, а также
	// определяем знак разности
	Big_integer number1_abs = abs(*this);
	Big_integer number2_abs = abs(*number);
	Big_integer* min_num;
	Big_integer* max_num;
	char result_sign;
	if (number1_abs < number2_abs)
	{
		min_num = &number1_abs;
		max_num = &number2_abs;
		if (this->sign > 0)
			result_sign = -1;
		else if (this->sign < 0)
			result_sign = 1;
		else
			result_sign = -number->sign;
	}
	else
	{
		min_num = &number2_abs;
		max_num = &number1_abs;
		if (this->sign > 0)
			result_sign = 1;
		else if (this->sign < 0)
			result_sign = -1;
		else
			result_sign = number->sign;
	}
	// Вычитаем цифры в обоих числах столбиком
	char* digits_in_dif = new char[max_num->size];
	char dif = 0;
	unsigned int n;
	for (n = 0; n < min_num->size; n++)
	{
		dif += max_num->digits[n] - min_num->digits[n];
		if (dif < 0)
		{
			digits_in_dif[n] = 10 + dif;
			dif = -1;
		}
		else
		{
			digits_in_dif[n] = dif;
			dif = 0;
		}
	}
	// Продолжаем вычитание только с цифрами из большего числа
	for (; n < max_num->size; n++)
	{
		dif += max_num->digits[n];
		if (dif < 0)
		{
			digits_in_dif[n] = 10 + dif;
			dif = -1;
		}
		else
		{
			digits_in_dif[n] = dif;
			dif = 0;
		}
	}
	// Создаем число типа Big_integer и освобождаем память, выделенную на
	// массив digits_in_sum
	Big_integer result(digits_in_dif, n, result_sign);
	delete[] digits_in_dif;
	return result;
}

/**
 * Перегрузка оператора стандартного ввода. Считываем по одному символу из
 * потока, проверяем, что символ допустим (является цифрой или знаком -).
 * Прекращаем чтение потока, когда встретим запрещенный символ.
 */
std::istream& operator >> (std::istream& in, Big_integer& number)
{
	const unsigned int N = 20; // исходное допустимое количество мест в числе
	unsigned int n = N; // допустимое количество мест в числе
	unsigned int size = 0; // количество символов, записанных в число
	char* str = new char[n]; // массив символов в числе
	char c; // из потока ввода читаем по одному символу
	while (in.get(c))
	{
		if (n <= size)
			// В массиве str нет свободных мест, потому переписываем символы в
			// увеличенный массив
			n = increase_array(&str, n, n + N);
		if (number.check_allowability(c))
		{
			// Если прочтенный символ допустим в числе
			str[size] = c;
			size++;
		}
		else
		{
			// Если символ не допустим, прекращаем чтение потока
			str[size] = '\0';
			break;
		}
	}
	number.init(str);
	// Освобождаем память, выделенную на str
	delete[] str;
	return in;
}

/**
 * Перегрузка оператора стандартного вывода.
 */
std::ostream& operator << (std::ostream& out, const Big_integer& number)
{
	if (number.sign < 0)
		out << '-';
	for (int i = number.size - 1; i > -1; i--)
		out << (int)number.digits[i];
	return out;
}

/**
 * Перегрузка оператора сложения двух чисел типа Big_integer.
 */
Big_integer operator + (Big_integer number1, Big_integer number2)
{
	return number1.add(&number2);
}

/**
 * Перегрузка оператора сложения двух числа типа Big_integer и int.
 */
Big_integer operator + (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1.add(&new_number);
}

/**
 * Перегрузка оператора сложения двух числа типа int и Big_integer.
 */
Big_integer operator + (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return number2.add(&new_number);
}

/**
 * Перегрузка оператора вычитания двух чисел типа Big_integer.
 */
Big_integer operator - (Big_integer number1, Big_integer number2)
{
	return number1.subtract(&number2);
}

/**
 * Перегрузка оператора вычитания двух чисел типа Big_integer и int.
 */
Big_integer operator - (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1.subtract(&new_number);
}

/**
 * Перегрузка оператора вычитания двух чисел типа int и Big_integer.
 */
Big_integer operator - (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return number2.subtract(&new_number);
}

/**
 * Перегрузка оператора умножения двух чисел типа Big_integer.
 */
Big_integer operator * (Big_integer number1, Big_integer number2)
{
	return number1.multiply(&number2);
}

/**
 * Перегрузка оператора умножения двух чисел типа Big_integer и int.
 */
Big_integer operator * (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1.multiply(&new_number);
}

/**
 * Перегрузка оператора умножения двух чисел типа int и Big_integer.
 */
Big_integer operator * (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return number2.multiply(&new_number);
}

/**
 * Перегрузка оператора целочисленного деления двух чисел типа Big_integer.
 */
Big_integer operator / (Big_integer number1, Big_integer number2)
{
	return number1.divide(&number2);
}

/**
 * Перегрузка оператора целочисленного деления двух чисел типа Big_integer
 * и int.
 */
Big_integer operator / (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1.divide(&new_number);
}

/**
 * Перегрузка оператора целочисленного деления двух чисел типа int и
 * Big_integer.
 */
Big_integer operator / (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return number2.divide(&new_number);
}

/**
 * Перегрузка оператора вычисления остатка от деления для чисел типа
 * Big_integer.
 */
Big_integer operator % (Big_integer number1, Big_integer number2)
{
	// Определяем знак результата
	int result_sign = number1.sign * number2.sign;
	// Модули числителя и знаменателя
	Big_integer number1_abs = abs(number1);
	Big_integer number2_abs = abs(number2);
	// Вычисляем целое частное
	Big_integer int_quotient = number1_abs.divide(&number2_abs);
	// Остаток
	number1_abs = number1_abs - int_quotient * number2_abs;
	number1_abs *= result_sign;
	return *(new Big_integer(number1_abs));
}

/**
 * Перегрузка оператора вычисления остатка от деления для чисел типа
 * Big_integer и int.
 */
Big_integer operator % (Big_integer& number1, int number2)
{
	Big_integer new_number(number2);
	return number1 % new_number;
}

/**
 * Перегрузка оператора вычисления остатка от деления для чисел типа int и
 * Big_integer.
 */
Big_integer operator % (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return new_number % number2;
}

/**
 * Перегрузка оператора сравнения < для чисел типа Big_integer.
 */
bool operator < (Big_integer number1, Big_integer number2)
{
	// Сначала сравниваем знаки чисел
	if (number1.sign < number2.sign)
		return true;
	if (number1.sign > number2.sign)
		return false;
	// Знаки чисел одинаковые, сравниваем количество цифр
	if (number1.size < number2.size)
	{
		if (number1.sign < 0)
			return false;
		return true;
	}
	if (number1.size > number2.size)
	{
		if (number1.sign > 0)
			return false;
		return true;
	}
	// Знаки и количество цифр в числах одинаковое, сравниваем цифры
	for (int i = number1.size - 1; i > -1; i--)
	{
		if (number1.sign * number1.digits[i] <
			number2.sign * number2.digits[i])
			return true;
		if (number1.sign * number1.digits[i] >
			number2.sign * number2.digits[i])
			return false;
	}
	return false;
}

/**
 * Перегрузка оператора сравнения < для чисел типа Big_integer и int.
 */
bool operator < (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1 < new_number;
}

/**
 * Перегрузка оператора сравнения < для чисел типа int и Big_integer.
 */
bool operator < (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return new_number < number2;
}

/**
 * Перегрузка оператора сравнения <= для чисел типа Big_integer.
 */
bool operator <= (Big_integer number1, Big_integer number2)
{
	if (number1 == number2)
		return true;
	return number1 < number2;
}

/**
 * Перегрузка оператора сравнения < для чисел типа Big_integer и int.
 */
bool operator <= (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	if (number1 == number2)
		return true;
	return number1 < new_number;
}

/**
 * Перегрузка оператора сравнения < для чисел типа int и Big_integer.
 */
bool operator <= (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	if (new_number == number2)
		return true;
	return new_number < number2;
}

/**
 * Перегрузка оператора сравнения > для чисел типа Big_integer.
 */
bool operator > (Big_integer number1, Big_integer number2)
{
	// Сначала сравниваем знаки чисел
	if (number1.sign < number2.sign)
		return false;
	if (number1.sign > number2.sign)
		return true;
	// Знаки чисел одинаковые, сравниваем количество цифр
	if (number1.size < number2.size)
	{
		if (number1.sign < 0)
			return true;
		return false;
	}
	if (number1.size > number2.size)
	{
		if (number1.sign > 0)
			return true;
		return false;
	}
	// Знаки и количество цифр в числах одинаковое, сравниваем цифры
	for (int i = number1.size - 1; i > -1; i--)
	{
		if (number1.sign * number1.digits[i] <
			number2.sign * number2.digits[i])
			return false;
		if (number1.sign * number1.digits[i] >
			number2.sign * number2.digits[i])
			return true;
	}
	return false;
}

/**
 * Перегрузка оператора сравнения > для чисел типа Big_integer и int.
 */
bool operator > (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1 > new_number;
}

/**
 * Перегрузка оператора сравнения > для чисел типа int и Big_integer.
 */
bool operator > (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return new_number > number2;
}

/**
 * Перегрузка оператора сравнения >= для чисел типа Big_integer.
 */
bool operator >= (Big_integer number1, Big_integer number2)
{
	if (number1 == number2)
		return true;
	return number1 > number2;
}

/**
 * Перегрузка оператора сравнения >= для чисел типа Big_integer и int.
 */
bool operator >= (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	if (number1 == number2)
		return true;
	return number1 > new_number;
}

/**
 * Перегрузка оператора сравнения >= для чисел типа int и Big_integer.
 */
bool operator >= (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	if (new_number == number2)
		return true;
	return new_number > number2;
}

/**
 * Перегрузка оператора сравнения == для чисел типа Big_integer.
 */
bool operator == (Big_integer number1, Big_integer number2)
{
	// Сначала сравниваем знаки чисел
	if (number1.sign != number2.sign)
		return false;
	// Знаки чисел одинаковые, сравниваем количество цифр
	if (number1.size != number2.size)
		return false;
	// Знаки и количество цифр в числах одинаковое, сравниваем цифры
	for (int i = number1.size - 1; i > -1; i--)
	{
		if (number1.sign * number1.digits[i] !=
			number2.sign * number2.digits[i])
			return false;
	}
	return true;
}

/**
 * Перегрузка оператора сравнения == для чисел типа Big_integer и int.
 */
bool operator == (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1 == new_number;
}

/**
 * Перегрузка оператора сравнения == для чисел типа int и Big_integer.
 */
bool operator == (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return new_number == number2;
}

/**
 * Перегрузка оператора сравнения != для чисел типа Big_integer.
 */
bool operator != (Big_integer number1, Big_integer number2)
{
	// Сначала сравниваем знаки чисел
	if (number1.sign != number2.sign)
		return true;
	// Знаки чисел одинаковые, сравниваем количество цифр
	if (number1.size != number2.size)
		return true;
	// Знаки и количество цифр в числах одинаковое, сравниваем цифры
	for (int i = number1.size - 1; i > -1; i--)
	{
		if (number1.sign * number1.digits[i] !=
			number2.sign * number2.digits[i])
			return true;
	}
	return false;
}

/**
 * Перегрузка оператора сравнения != для чисел типа Big_integer и int.
 */
bool operator != (Big_integer number1, int number2)
{
	Big_integer new_number(number2);
	return number1 != new_number;
}

/**
 * Перегрузка оператора сравнения != для чисел типа int и Big_integer.
 */
bool operator != (int number1, Big_integer number2)
{
	Big_integer new_number(number1);
	return new_number != number2;
}

/**
 * Функция вычисляет абсолютное значение числа.
 * @param number: число.
 * @return: абсолютное значение числа.
 */
Big_integer abs(Big_integer& number)
{
	return Big_integer(number.digits, number.size, 1);
}

/**
 * Функция вычисляет факториал числа.
 * @param number: число.
 * @return: факториал числа.
 */
Big_integer factorial(unsigned int number)
{
	if (number == 0)
		return Big_integer(1);
	Big_integer result(1);
	for (unsigned int i = 2; i <= number; i++)
		result = i * result;
	return result;
}

/**
 * Функция увеличивает размер массива.
 * @param array: массив;
 * @param size: старый размер массива;
 * @param new_size: новый размер массива.
 * @return: новый размер массива.
 */
template <typename T>
int increase_array(T** array, unsigned int size, unsigned int new_size)
{
	T* new_array = new T[new_size];
	for (unsigned int i = 0; i < size; i++)
		new_array[i] = (*array)[i];
	delete[] * array;
	*array = new_array;
	return new_size;
}