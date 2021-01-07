/*
Задача 1.
Разработать класс для представления целых чисел с неограниченным количеством
разрядов. Перегрузить для него операторы арифметики и ввода-вывода в потоки.
Для внутреннего представления числа можно использовать строку, динамический
массив и так далее. Используя разработанный класс продемонстрировать его
возможности на примере вычисления факториала числа 10000.
*/

#include <iostream>
#include "big_integer.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    // Получаем числа для арифметических действий
    std::cout << "Введите число типа Big_integer: ";
    Big_integer number1;
    std::cin >> number1;
    std::cout << "Введите число типа Big_integer: ";
    Big_integer number2;
    std::cin >> number2;
    std::cout << "Введите простое целое число: ";
    int number3;
    std::cin >> number3;
    // Выполняем арифметические действия
    // Сложение
    std::cout << number1 << " + " << number2 << " = " << number1 + number2 <<
        "\n";
    std::cout << number1 << " + " << number3 << " = " << number1 + number3 <<
        "\n";
    std::cout << number1 << " += " << number2 << " = ";
    number1 += number2;
    std::cout << number1 << "\n";
    std::cout << number1 << " += " << number3 << " = ";
    number1 += number3;
    std::cout << number1 << "\n";
    // Вычитание
    std::cout << number1 << " - " << number2 << " = " << number1 - number2 <<
        "\n";
    std::cout << number1 << " - " << number3 << " = " << number1 - number3 <<
        "\n";
    std::cout << number1 << " -= " << number2 << " = ";
    number1 -= number2;
    std::cout << number1 << "\n";
    std::cout << number1 << " -= " << number3 << " = ";
    number1 -= number3;
    std::cout << number1 << "\n";
    // Умножение
    std::cout << number1 << " * " << number2 << " = " << number1 * number2 <<
        "\n";
    std::cout << number1 << " * " << number3 << " = " << number1 * number3 <<
        "\n";
    std::cout << number1 << " *= " << number2 << " = ";
    number1 *= number2;
    std::cout << number1 << "\n";
    std::cout << number1 << " *= " << number3 << " = ";
    number1 *= number3;
    std::cout << number1 << "\n";
    // Деление
    std::cout << number1 << " / " << number2 << " = " << number1 / number2 <<
        "\n";
    std::cout << number2 << " / " << number1 << " = " << number2 / number1 <<
        "\n";
    std::cout << number1 << " /= " << number2 << " = ";
    number1 /= number2;
    std::cout << number1 << "\n";
    std::cout << number1 << " /= " << number3 << " = ";
    number1 /= number3;
    std::cout << number1 << "\n";
    // Остаток от деления
    std::cout << number1 << " % " << number2 << " = " << number1 % number2 <<
        "\n";
    std::cout << number2 << " % " << number1 << " = " << number2 % number1 <<
        "\n";
    std::cout << number1 << " %= " << number2 << " = ";
    number1 %= number2;
    std::cout << number1 << "\n";
    std::cout << number1 << " %= " << number3 << " = ";
    number1 %= number3;
    std::cout << number1 << "\n";
    // Вычисляем факториалы
    std::cout << "10! = " << factorial(10) << "\n";
    std::cout << "100! = " << factorial(100) << "\n";
    std::cout << "1000! = " << factorial(1000) << "\n";
    std::cout << "10000! = " << factorial(10000) << "\n";
    return 0;
}