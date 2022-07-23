#include <array>
#include <exception>
#include "CppUnitTest.h"
#include "../FillArrayLib/FillArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<std::array<std::array<int, maxColumns>, maxRows>>(const std::array<std::array<int, maxColumns>, maxRows>& t)
{
	std::wstring result;
	result += L"{";
	for (auto& row : t)
	{
		result += L"{";
		for (auto& v : row)
		{
			result += ToString(v);
			result += L",";
		}
		result += L"},";
	}
	result += L"}";
	return result;
}

//Unit tests for FillArray2 method
namespace FillArrayUnitTest
{
	TEST_CLASS(FillArrayUnitTest)
	{
	public:
		TEST_METHOD(fillArray_0x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray2(array,0,0); });
		}
		TEST_METHOD(fillArray_0x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray2(array,0,3); });
		}
		TEST_METHOD(fillArray_3x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray2(array,3,0); });
		}
		TEST_METHOD(fillArray_21x21)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray2(array,21,21); });
		}
		TEST_METHOD(fillArray_0x21)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray2(array,0,21); });
		}
		TEST_METHOD(fillArray_21x0)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			Assert::ExpectException<std::invalid_argument>([&array]{ fillArray2(array,21,0); });
		}
		TEST_METHOD(fillArray_1x1)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{ 1 }
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 1, 1);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_1x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  1,  2}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 1, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_2x1)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  2},
					{  1}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 2, 1);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_2x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  3,  4},
					{  1,  2}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 2, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_2x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  3,  5,  6},
					{  1,  2,  4}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 2, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x2)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  5,  6},
					{  3,  4},
					{  1,  2}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 3, 2);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  6,  8,  9},
					{  3,  5,  7},
					{  1,  2,  4}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 3, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x6)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  6,  9,  12, 15, 17, 18},
					{  3,  5,  8,  11, 14, 16},
					{  1,  2,  4,  7,  10, 13}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 3, 6);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_3x7)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  6,  9,  12, 15, 18, 20, 21},
					{  3,  5,  8,  11, 14, 17, 19},
					{  1,  2,  4,  7,  10, 13, 16}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 3, 7);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_6x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  15, 17, 18},
					{  12, 14, 16},
					{  9,  11, 13},
					{  6,  8,  10},
					{  3,  5,  7},
					{  1,  2,  4}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 6, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_7x3)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  18, 20, 21},
					{  15, 17, 19},
					{  12, 14, 16},
					{  9,  11, 13},
					{  6,  8,  10},
					{  3,  5,   7},
					{  1,  2,   4}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 7, 3);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_4x4)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  10, 13, 15, 16},
					{  6,  9,  12, 14},
					{  3,  5,  8,  11},
					{  1,  2,  4,  7}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 4, 4);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_4x6)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  10, 14, 18, 21, 23, 24},
					{  6,  9,  13, 17, 20, 22},
					{  3,  5,  8,  12, 16, 19},
					{  1,  2,  4,  7,  11, 15}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 4, 6);
			Assert::AreEqual(expected, array);
		}
		TEST_METHOD(fillArray_4x7)
		{
			std::array<std::array<int, maxColumns>, maxRows> expected =
			{
				{
					{  10, 14, 18, 22, 25, 27, 28},
					{  6,  9,  13, 17, 21, 24, 26},
					{  3,  5,  8,  12, 16, 20, 23},
					{  1,  2,  4,  7,  11, 15, 19}
				}
			};
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			fillArray2(array, 4, 7);
			Assert::AreEqual(expected, array);
		}
	};
}
