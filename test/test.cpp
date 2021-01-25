﻿#include "gtest/gtest.h"
#include "../src/big_integer.h"


// Тесты на создание чисел типа Big_integer
TEST(Constructor_test, Test1)
{
	const int NUMBER = 98676735;
	Big_integer big_int(NUMBER);
	ASSERT_TRUE(NUMBER == big_int);
}

TEST(Constructor_test, Test2)
{
	const char* STR_NUMBER = "-738243";
	const int NUMBER = std::stoi(STR_NUMBER, nullptr);
	Big_integer big_int(STR_NUMBER);
	ASSERT_TRUE(NUMBER == big_int);
}

TEST(Constructor_test, Test3)
{
	const int NUMBER = 8934782;
	Big_integer big_int1(NUMBER);
	Big_integer big_int2(big_int1);
	ASSERT_TRUE(NUMBER == big_int2);
}

// Тесты на сложение чисел
TEST(Add_test, Test1)
{
	const int NUMBER1 = 89363;
	const int NUMBER2 = 784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 + big_int2 == NUMBER1 + NUMBER2);
}

TEST(Add_test, Test2)
{
	const int NUMBER1 = 893363;
	const int NUMBER2 = -78904;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 + big_int2 == NUMBER1 + NUMBER2);
}

TEST(Add_test, Test3)
{
	const int NUMBER1 = -8936333;
	const int NUMBER2 = -784345;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 + big_int2 == NUMBER1 + NUMBER2);
}

TEST(Add_test, Test4)
{
	const int NUMBER1 = 8936333;
	const int NUMBER2 = 27834;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	big_int1 += big_int2;
	ASSERT_TRUE(big_int1 == NUMBER1 + NUMBER2);
}

// Тесты на сложение чисел
TEST(Subtract_test, Test1)
{
	const int NUMBER1 = 89363;
	const int NUMBER2 = 784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 - big_int2 == NUMBER1 - NUMBER2);
}

TEST(Subract_test, Test2)
{
	const int NUMBER1 = 893363;
	const int NUMBER2 = -78904;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 - big_int2 == NUMBER1 - NUMBER2);
}

TEST(Subract_test, Test3)
{
	const int NUMBER1 = -8936333;
	const int NUMBER2 = -784345;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 - big_int2 == NUMBER1 - NUMBER2);
}

TEST(Subract_test, Test4)
{
	const int NUMBER1 = -8936333;
	const int NUMBER2 = -784345;
	Big_integer big_int(NUMBER1);
	big_int -= NUMBER2;
	ASSERT_TRUE(big_int == NUMBER1 - NUMBER2);
}

// Тесты на умножение чисел
TEST(Multiply_test, Test1)
{
	const int NUMBER1 = 89363;
	const int NUMBER2 = 784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 * big_int2 == NUMBER1 * NUMBER2);
}

TEST(Multiply_test, Test2)
{
	const int NUMBER1 = 893363;
	const int NUMBER2 = -784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 * big_int2 == NUMBER1 * NUMBER2);
}

TEST(Multiply_test, Test3)
{
	const int NUMBER1 = -8933;
	const int NUMBER2 = -7345;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 * big_int2 == NUMBER1 * NUMBER2);
}

TEST(Multiply_test, Test4)
{
	const int NUMBER1 = 8933;
	const int NUMBER2 = 7345;
	Big_integer big_int(NUMBER1);
	big_int *= NUMBER2;
	ASSERT_TRUE(big_int == NUMBER1 * NUMBER2);
}

// Тесты на целочисленное деление чисел
TEST(Divide_test, Test1)
{
	const int NUMBER1 = 89363;
	const int NUMBER2 = 784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 / big_int2 == NUMBER1 / NUMBER2);
}

TEST(Divide_test, Test2)
{
	const int NUMBER1 = 893363;
	const int NUMBER2 = -784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 / big_int2 == NUMBER1 / NUMBER2);
}

TEST(Divide_test, Test3)
{
	const int NUMBER1 = -893389;
	const int NUMBER2 = -7345;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 / big_int2 == NUMBER1 / NUMBER2);
}

TEST(Divide_test, Test4)
{
	const int NUMBER1 = 893389;
	const int NUMBER2 = 75;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	big_int1 /= big_int2;
	ASSERT_TRUE(big_int1 == NUMBER1 / NUMBER2);
}

// Тесты на вычисление остатка от деления чисел
TEST(Mod_test, Test1)
{
	const int NUMBER1 = 89363;
	const int NUMBER2 = 784;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_TRUE(big_int1 % big_int2 == NUMBER1 % NUMBER2);
}

TEST(Mod_test, Test2)
{
	const int NUMBER1 = 893389;
	const int NUMBER2 = 75;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	big_int1 %= big_int2;
	ASSERT_TRUE(big_int1 == NUMBER1 % NUMBER2);
}

// Тест на вычисление факториала
TEST(Factorial_test, Test1)
{
	const int NUMBER = 20;
	const char* RESULT = "2432902008176640000";
	Big_integer big_int = factorial(NUMBER);
	Big_integer result(RESULT);
	ASSERT_TRUE(big_int == result);
}

// Тест на сравнение <
TEST(Compare_less, Test1)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_EQ(big_int1 < big_int2, NUMBER1 < NUMBER2);
}

TEST(Compare_less, Test2)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(big_int < NUMBER2, NUMBER1 < NUMBER2);
}

TEST(Compare_less, Test3)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(NUMBER2 < big_int, NUMBER2 < NUMBER1);
}

// Тест на сравнение <=
TEST(Compare_less_or_equal, Test1)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_EQ(big_int1 <= big_int2, NUMBER1 <= NUMBER2);
}

TEST(Compare_less_or_equal, Test2)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = 9032;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(big_int <= NUMBER2, NUMBER1 <= NUMBER2);
}

TEST(Compare_less_or_equal, Test3)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(NUMBER2 <= big_int, NUMBER2 <= NUMBER1);
}

// Тест на сравнение >
TEST(Compare_more, Test1)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_EQ(big_int1 > big_int2, NUMBER1 > NUMBER2);
}

TEST(Compare_more, Test2)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(big_int > NUMBER2, NUMBER1 > NUMBER2);
}

TEST(Compare_more, Test3)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(NUMBER2 > big_int, NUMBER2 > NUMBER1);
}

// Тест на сравнение >=
TEST(Compare_more_or_equal, Test1)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_EQ(big_int1 >= big_int2, NUMBER1 >= NUMBER2);
}

TEST(Compare_more_or_equal, Test2)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = 9032;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(big_int >= NUMBER2, NUMBER1 >= NUMBER2);
}

TEST(Compare_more_or_equal, Test3)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(NUMBER2 >= big_int, NUMBER2 >= NUMBER1);
}

// Тест на сравнение ==
TEST(Compare_equal, Test1)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_EQ(big_int1 == big_int2, NUMBER1 == NUMBER2);
}

TEST(Compare_equal, Test2)
{
	const int NUMBER1 = -892;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(big_int == NUMBER2, NUMBER1 == NUMBER2);
}

TEST(Compare_equal, Test3)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(NUMBER2 == big_int, NUMBER2 == NUMBER1);
}

// Тест на сравнение !=
TEST(Compare_not_equal, Test1)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int1(NUMBER1);
	Big_integer big_int2(NUMBER2);
	ASSERT_EQ(big_int1 != big_int2, NUMBER1 != NUMBER2);
}

TEST(Compare_not_equal, Test2)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(big_int != NUMBER2, NUMBER1 != NUMBER2);
}

TEST(Compare_not_equal, Test3)
{
	const int NUMBER1 = 9032;
	const int NUMBER2 = -892;
	Big_integer big_int(NUMBER1);
	ASSERT_EQ(NUMBER2 != big_int, NUMBER2 != NUMBER1);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}