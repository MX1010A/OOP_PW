#include "pch.h"

#include <vector>

#include "CppUnitTest.h"
#include "../Shape/Shapes.h"
#include "../Shape/Shapes.cpp"
#include "../List/List.h"
#define M_PI 3.14159265358979323846

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<std::vector<double>>(const std::vector<double>& t)
{
	std::wstring result;
	result += L"{";
	for (auto& i : t)
	{
		result += ToString(i);
		result += L",";
	}
	result += L"}";
	return result;
}

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		//Tests for derived Shape classes members
		TEST_METHOD(ConstructorTestR)
		{
			const std::vector<double> expected = { 6, 9 };
			const auto test_obj = Rectangle(6, 9);
			const std::vector<double> test = { test_obj.get_width(), test_obj.get_height() };
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ConstructorTestRE)
		{
			Assert::ExpectException<std::invalid_argument>([] { Rectangle(2, -1); });
		}

		TEST_METHOD(ConstructorTestT)
		{
			const std::vector<double> expected = { 6, 9, 4 };
			const auto test_obj = Triangle(6, 9, 4);
			const std::vector<double> test = { test_obj.get_side1(), test_obj.get_side2(), test_obj.get_side3() };
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ConstructorTestTE)
		{
			Assert::ExpectException<std::invalid_argument>([] { Triangle(0, 2, -1); });
		}

		TEST_METHOD(ConstructorTestTX)
		{
			Assert::ExpectException<std::invalid_argument>([] { Triangle(4, 2, 2); });
		}

		TEST_METHOD(ConstructorTestC)
		{
			const double expected = 6;
			const auto test_obj = Circle(6);
			Assert::AreEqual(expected, test_obj.get_radius());
		}

		TEST_METHOD(ConstructorTestCE)
		{
			Assert::ExpectException<std::invalid_argument>([] { Circle(-10); });
		}

		TEST_METHOD(SetterTestR)
		{
			const std::vector<double> expected = { 4, 2 };
			auto test_obj = Rectangle(6, 9);
			test_obj.set_width(4);
			test_obj.set_height(2);
			const std::vector<double> test = { test_obj.get_width(), test_obj.get_height() };
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(SetterTestRE)
		{
			Assert::ExpectException<std::invalid_argument>([] { Rectangle(6, 9).set_height(-10); });
		}

		TEST_METHOD(SetterTestC)
		{
			const double expected = { 9 };
			auto test_obj = Circle(6);
			test_obj.set_radius(9);
			Assert::AreEqual(expected, test_obj.get_radius());
		}

		TEST_METHOD(PerimeterTestR)
		{
			const double expected = 12;
			const auto test = Rectangle(4, 2);
			Assert::AreEqual(expected, test.perimeter());
		}

		TEST_METHOD(PerimeterTestT)
		{
			const double expected = 9;
			const auto test = Triangle(4, 2, 3);
			Assert::AreEqual(expected, test.perimeter());
		}

		TEST_METHOD(PerimeterTestC)
		{
			const double expected = 8 * M_PI;
			const auto test = Circle(4);
			Assert::AreEqual(expected, test.perimeter());
		}

		TEST_METHOD(AreaTestR)
		{
			const double expected = 8;
			const auto test = Rectangle(4, 2);
			Assert::AreEqual(expected, test.area());
		}

		TEST_METHOD(AreaTestT)
		{
			const double expected = 6;
			const auto test = Triangle(5, 4, 3);
			Assert::AreEqual(expected, test.area());
		}

		TEST_METHOD(AreaTestC)
		{
			const double expected = M_PI * 16;
			const auto test = Circle(4);
			Assert::AreEqual(expected, test.area());
		}

		TEST_METHOD(BiggerTestR)
		{
			const bool expected = true;
			const auto test1 = Rectangle(6, 9);
			const auto test2 = Rectangle(4, 2);
			Assert::AreEqual(expected, test1 > test2);
		}

		TEST_METHOD(BiggerEqualTestT)
		{
			const bool expected = true;
			const auto test1 = Triangle(6, 9, 7);
			const auto test2 = Triangle(4, 2, 3);
			Assert::AreEqual(expected, test1 >= test2);
		}

		TEST_METHOD(SmallerTestC)
		{
			const bool expected = true;
			const auto test1 = Circle(4);
			const auto test2 = Circle(6);
			Assert::AreEqual(expected, test1 < test2);
		}

		TEST_METHOD(SmallerEqualTestR)
		{
			const bool expected = true;
			const auto test1 = Rectangle(4, 2);
			const auto test2 = Rectangle(4, 2);
			Assert::AreEqual(expected, test1 <= test2);
		}

		TEST_METHOD(EqualTestT)
		{
			const bool expected = true;
			const auto test1 = Triangle(6.9329, 9.392939, 7.38238);
			const auto test2 = Triangle(6.9328, 9.3929392, 7.38238);
			Assert::AreEqual(expected, test1 == test2);
		}

		TEST_METHOD(NotEqualTestC)
		{
			const bool expected = true;
			const auto test1 = Circle(6.938);
			const auto test2 = Circle(3);
			Assert::AreEqual(expected, test1 != test2);
		}

		//Tests for list members
		TEST_METHOD(ConstructorTestL)
		{
			const bool exp_bool = true;
			auto& test = List<Circle>();
			Assert::AreEqual(exp_bool, test.empty());
		}

		TEST_METHOD(PushPopBackTest)
		{
			const bool expected = true;
			auto& test = List<Circle>();
			const auto test_obj = Circle(7);
			test.push_back(test_obj);
			test.push_back(Circle(6.938));
			test.pop_back();
			Assert::AreEqual(expected, test.back() == test_obj);
		}

		TEST_METHOD(PopBackTestE)
		{
			Assert::ExpectException<std::invalid_argument>([] { List<Circle>().pop_back(); });
		}

		TEST_METHOD(PushPopFrontTest)
		{
			const bool expected = true;
			auto& test = List<Circle>();
			const auto test_obj = Circle(7);
			test.push_front(test_obj);
			test.push_front(Circle(6.938));
			test.pop_front();
			Assert::AreEqual(expected, test.front() == test_obj);
		}

		TEST_METHOD(ClearTest)
		{
			const bool expected = true;
			auto& test = List<Rectangle>();
			test.push_back(Rectangle(6, 9));
			test.push_back(Rectangle(4, 2));
			test.clear();
			Assert::AreEqual(expected, test.empty());
		}

		TEST_METHOD(InsertTest)
		{
			const bool expected = true;
			auto& test = List<Circle>();
			const auto test_obj = Circle(5);
			test.push_back(Circle(3));
			test.push_back(Circle(10));
			test.insert(test.find(0), test_obj);
			Assert::AreEqual(expected, test[1] == test_obj);
		}

		TEST_METHOD(EraseTest)
		{
			const bool expected = true;
			auto& test = List<Circle>();
			const auto test_obj = Circle(5);
			test.push_back(Circle(6));
			test.push_back(Circle(4));
			test.push_back(test_obj);
			test.erase(test.find(0));
			Assert::AreEqual(expected, test[1] == test_obj);
		}

		TEST_METHOD(AssignmentTest)
		{
			const bool exp_bool = true;
			auto& test = List<Circle>();
			test.push_back(Circle(6));
			test.push_back(Circle(4));
			const auto& expected = test;
			Assert::AreEqual(exp_bool, expected == test);
		}

		TEST_METHOD(NotEqualTest)
		{
			const bool exp_bool = true;
			auto& test1 = List<Circle>();
			test1.push_back(Circle(6));
			auto& test2 = List<Circle>();
			test2.push_back(Circle(9));
			Assert::AreEqual(exp_bool, test1 != test2);
		}
	};
}
