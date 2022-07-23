#include "pch.h"
#include "CppUnitTest.h"
#include "../Rectangle/Rectangle.h"
#include "../Rectangle/Rectangle.cpp"
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Rectangle>(const Rectangle& t)
{
	std::wstring result;
	result += L"W: " + t.getWidth();
	result += L", H: " + t.getHeight(); 
	result += L", (", ToString(t.getVertex().x);
	result += L"; ", ToString(t.getVertex().y);
	result += L")";
	return result;
}

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		//Unit tests for default constructor
		TEST_METHOD(DefaultConstructorTestV)
		{
			bool exp_bool = true;
			Point expVertex = {0, 0};
			Rectangle testRect = Rectangle();
			Assert::AreEqual(exp_bool, expVertex == testRect.getVertex());
		}

		TEST_METHOD(DefaultConstructorTestW)
		{
			int exp_width = 0;
			Rectangle testRect = Rectangle();
			Assert::AreEqual(exp_width, testRect.getWidth());
		}

		TEST_METHOD(DefaultConstructorTestH)
		{
			int exp_height = 0;
			Rectangle testRect = Rectangle();
			Assert::AreEqual(exp_height, testRect.getHeight());
		}

		//Unit tests for constructor with parameters
		TEST_METHOD(ConstructorTestV)
		{
			bool exp_bool = true;
			Point expVertex = {6, 9};
			Rectangle testRect = Rectangle(6, 9, {6, 9});
			Assert::AreEqual(exp_bool, expVertex == testRect.getVertex());
		}

		TEST_METHOD(ConstructorTestW)
		{
			int exp_width = 6;
			Rectangle testRect = Rectangle(6, 9);
			Assert::AreEqual(exp_width, testRect.getWidth());
		}

		TEST_METHOD(ConstructorTestH)
		{
			int exp_height = 9;
			Rectangle testRect = Rectangle(6, 9);
			Assert::AreEqual(exp_height, testRect.getHeight());
		}

		TEST_METHOD(ConstructorTestDV)
		{
			bool exp_bool = true;
			Point expVertex = {0, 0};
			Rectangle testRect = Rectangle(6, 9);
			Assert::AreEqual(exp_bool, expVertex == testRect.getVertex());
		}

		TEST_METHOD(ConstructorTestIW)
		{
			Assert::ExpectException<std::invalid_argument>([] { Rectangle(-6, 9); });
		}

		TEST_METHOD(ConstructorTestIH)
		{
			Assert::ExpectException<std::invalid_argument>([] { Rectangle(6, -9); });
		}

		//Unit tests for setters
		TEST_METHOD(SetterTestV)
		{
			bool exp_bool = true;
			Point expVertex = {4, 20};
			Rectangle testRect = Rectangle(6, 9, {6, 9});
			testRect.setVertex({4, 20});
			Assert::AreEqual(exp_bool, expVertex == testRect.getVertex());
		}

		TEST_METHOD(SetterTestW)
		{
			int exp_width = 4;
			Rectangle testRect = Rectangle(6, 9);
			testRect.setWidth(4);
			Assert::AreEqual(exp_width, testRect.getWidth());
		}

		TEST_METHOD(SetterTestH)
		{
			int exp_height = 20;
			Rectangle testRect = Rectangle(6, 9);
			testRect.setHeight(20);
			Assert::AreEqual(exp_height, testRect.getHeight());
		}

		TEST_METHOD(SetterTestIW)
		{
			Assert::ExpectException<std::invalid_argument>([] { Rectangle().setWidth(-6); });
		}

		TEST_METHOD(SetterTestIH)
		{
			Assert::ExpectException<std::invalid_argument>([] { Rectangle().setHeight(-9); });
		}

		//Unit tests for methods
		TEST_METHOD(PerimeterTest) 
		{
			int exp_perimeter = 30;
			Rectangle testRect = Rectangle(6, 9);
			Assert::AreEqual(exp_perimeter, testRect.perimeter());
		}

		TEST_METHOD(AreaTest)
		{
			int exp_area = 54;
			Rectangle testRect = Rectangle(6, 9);
			Assert::AreEqual(exp_area, testRect.area());
		}

		TEST_METHOD(IsSquareTest6x9)
		{
			bool exp_isSquare = false;
			Rectangle testRect = Rectangle(6, 9);
			Assert::AreEqual(exp_isSquare, testRect.isSquare());
		}

		TEST_METHOD(IsSquareTest6x6)
		{
			bool exp_isSquare = true;
			Rectangle testRect = Rectangle(6, 6);
			Assert::AreEqual(exp_isSquare, testRect.isSquare());
		}

		//Unit tests for overloaded operators
		TEST_METHOD(EqualTestT)
		{
			bool exp_equals = true;
			Rectangle testRect1 = Rectangle(6, 9, {6, 9});
			Rectangle testRect2 = Rectangle(6, 9, {6, 9});
			Assert::AreEqual(exp_equals, testRect1 == testRect2);
		}

		TEST_METHOD(EqualTestF)
		{
			bool exp_equals = false;
			Rectangle testRect1 = Rectangle(6, 9, {6, 9});
			Rectangle testRect2 = Rectangle(4, 20, {6, 9});
			Assert::AreEqual(exp_equals, testRect1 == testRect2);
		}

		TEST_METHOD(NotEqualTestT)
		{
			bool exp_equals = true;
			Rectangle testRect1 = Rectangle(6, 9, {4, 20});
			Rectangle testRect2 = Rectangle(4, 20, {4, 20});
			Assert::AreEqual(exp_equals, testRect1 != testRect2);
		}

		TEST_METHOD(NotEqualTestF)
		{
			bool exp_equals = false;
			Rectangle testRect1 = Rectangle(6, 9, {4, 20});
			Rectangle testRect2 = Rectangle(6, 9, {4, 20});
			Assert::AreEqual(exp_equals, testRect1 != testRect2);
		}

		TEST_METHOD(PlusTest)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 6, {1, 5});
			Rectangle testRect1 = Rectangle(5, 4, {1, 3});
			Rectangle testRect2 = Rectangle(4, 3, {5, 5});
			Assert::AreEqual(exp_bool, exp_rect == testRect1 + testRect2);
		}

		TEST_METHOD(PlusEqualTestNW)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 6, {1, 5});
			Rectangle testRect = Rectangle(5, 4, {1, 5});
			testRect += Rectangle(4, 3, {5, 2});
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestSW)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 6, {-1, 5});
			Rectangle testRect = Rectangle(5, 4, {-1, 3});
			testRect += Rectangle(4, 3, {3, 5});
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestNE)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 6, {1, 1});
			Rectangle testRect = Rectangle(4, 3, {5, 1});
			testRect += Rectangle(5, 4, {1, -1});
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestSE)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 6, {1, 2});
			Rectangle testRect = Rectangle(4, 3, {5, -1});
			testRect += Rectangle(5, 4, {1, 2});
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestN)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(5, 6, { 1, 5 });
			Rectangle testRect = Rectangle(5, 4, { 1, 5 });
			testRect += Rectangle(4, 3, { 1, 2 });
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestE)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 4, { 1, 2 });
			Rectangle testRect = Rectangle(4, 3, { 5, 2 });
			testRect += Rectangle(5, 4, { 1, 2 });
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestS)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(5, 6, { -1, 5 });
			Rectangle testRect = Rectangle(5, 4, { -1, 3 });
			testRect += Rectangle(4, 3, { -1, 5 });
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestW)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(8, 4, { -1, 3 });
			Rectangle testRect = Rectangle(5, 4, { -1, 3 });
			testRect += Rectangle(4, 3, { 3, 3 });
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}

		TEST_METHOD(PlusEqualTestMatch)
		{
			bool exp_bool = true;
			Rectangle exp_rect = Rectangle(5, 4, { 3, 3 });
			Rectangle testRect = Rectangle(5, 4, { 3, 3 });
			testRect += Rectangle(4, 3, { 3, 3 });
			Assert::AreEqual(exp_bool, exp_rect == testRect);
		}
	};
}
