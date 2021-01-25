/*
Модуль с тестами для чисел типа Rational_number.
*/

#include "gtest/gtest.h"
#include <string>
#include "rn_tests.h"
#include "../src/rational_number.h"


// Тесты на создание чисел типа Rational_number
TEST(RN_Constructor_test, Test1)
{
	Rational_number rat_num(35864, 9109456);
	std::string num("1/254");
	EXPECT_EQ(rat_num.get_str(), num);
}

TEST(RN_Constructor_test, Test2)
{
	Rational_number rat_num1(35864, 9109456);
	Rational_number rat_num2(rat_num1);
	EXPECT_EQ(rat_num1.get_str(), rat_num2.get_str());
}

// Тесты на сложение чисел
TEST(RN_Add_test, Test1)
{
	Rational_number rat_num1(1, 3);
	Rational_number rat_num2(1, 4);
	Rational_number rat_num = rat_num1 + rat_num2;
	ASSERT_EQ(rat_num.get_str(), std::string("7/12"));
}

TEST(RN_Add_test, Test2)
{
	Rational_number rat_num(5, 8);
	ASSERT_EQ(rat_num + 7.3, 5.0 / 8 + 7.3);
}

TEST(RN_Add_test, Test3)
{
	Rational_number rat_num1(3, 12);
	Rational_number rat_num2(1, -2);
	rat_num1 += rat_num2;
	ASSERT_EQ(rat_num1.get_str(), std::string("-1/4"));
}

TEST(RN_Add_test, Test4)
{
	Rational_number rat_num(12, 3);
	rat_num += 3;
	ASSERT_EQ(rat_num.get_str(), std::string("7/1"));
}

// Тесты на вычитание чисел
TEST(RN_Subtract_test, Test1)
{
	Rational_number rat_num1(1, 3);
	Rational_number rat_num2(1, 4);
	Rational_number rat_num = rat_num1 - rat_num2;
	ASSERT_EQ(rat_num.get_str(), std::string("1/12"));
}

TEST(RN_Subtract_test, Test2)
{
	Rational_number rat_num(5, 8);
	ASSERT_EQ(rat_num - 7.3, 5.0 / 8 - 7.3);
}

TEST(RN_Subtract_test, Test3)
{
	Rational_number rat_num1(3, 12);
	Rational_number rat_num2(1, -2);
	rat_num1 -= rat_num2;
	ASSERT_EQ(rat_num1.get_str(), std::string("3/4"));
}

TEST(RN_Subtract_test, Test4)
{
	Rational_number rat_num(12, 3);
	rat_num -= 5;
	ASSERT_EQ(rat_num.get_str(), std::string("-1/1"));
}

// Тесты на умножение чисел
TEST(RN_Multiply_test, Test1)
{
	Rational_number rat_num1(1, 3);
	Rational_number rat_num2(3, 4);
	Rational_number rat_num = rat_num1 * rat_num2;
	ASSERT_EQ(rat_num.get_str(), std::string("1/4"));
}

TEST(RN_Multiply_test, Test2)
{
	Rational_number rat_num(5, 8);
	ASSERT_EQ(rat_num * 7.3, 5.0 / 8 * 7.3);
}

TEST(RN_Multiply_test, Test3)
{
	Rational_number rat_num1(3, 12);
	Rational_number rat_num2(4, -2);
	rat_num1 *= rat_num2;
	ASSERT_EQ(rat_num1.get_str(), std::string("-1/2"));
}

TEST(RN_Multiply_test, Test4)
{
	Rational_number rat_num(12, 5);
	rat_num *= (-5);
	ASSERT_EQ(rat_num.get_str(), std::string("-12/1"));
}

// Тесты на деление чисел
TEST(RN_Divide_test, Test1)
{
	Rational_number rat_num1(1, 21);
	Rational_number rat_num2(1, 28);
	Rational_number rat_num = rat_num1 / rat_num2;
	ASSERT_EQ(rat_num.get_str(), std::string("4/3"));
}

TEST(RN_Divide_test, Test2)
{
	Rational_number rat_num(5, 8);
	ASSERT_EQ(rat_num / 7.3, 5.0 / 8 / 7.3);
}

TEST(RN_Divide_test, Test3)
{
	Rational_number rat_num1(3, 12);
	Rational_number rat_num2(1, -2);
	rat_num1 /= rat_num2;
	ASSERT_EQ(rat_num1.get_str(), std::string("-1/2"));
}

TEST(RN_Divide_test, Test4)
{
	Rational_number rat_num(15, 3);
	rat_num /= 5;
	ASSERT_EQ(rat_num.get_str(), std::string("1/1"));
}