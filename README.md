# BigInteger_and_RationalNumber

[![Build Status](https://travis-ci.com/timerke/BigInteger_and_RationalNumber.svg?branch=main)](https://travis-ci.com/timerke/BigInteger_and_RationalNumber)

## Класс Big_integer
Классы Big_integer предназначен для представления целых чисел с неограниченным количеством разрядов. Для класса перегружены операторы арифметики и ввода-вывода в потоки. Для внутреннего представления чисел этого типа используется динамический массив. Использование разработанного класс продемонстрировано, например, на вычислении факториала числа 10000.
## Класс Rational_number
Класс Rational_number предназначен для представления рациональных чисел, то есть чисел в виде пары целых чисел: числитель и знаменатель. Класс имеет метод сокращения дроби, то есть поиск наибольшего общего делителя и автоматическое деление на него числителя и знаменателя, если он больше 1. Для класса перегружены арифметические операции с автоматическим сокращением дроби. Использование разработанного класса продемонстрировано, например, на приближенном вычислении числа π по формуле ряда Лейбница.
