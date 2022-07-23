#include "pch.h"
#include "CppUnitTest.h"
#include "../Stack/Stack.h"
#include "../Stack/Stack.cpp"
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<std::vector<int>>(const std::vector<int> & t)
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
		//Unit tests for constructors
		TEST_METHOD(DefaultConstructorTest)
		{
			std::vector<int> expected = std::vector<int>();
			Stack test = Stack();
			Assert::AreEqual(expected, test.vector());
		}

		TEST_METHOD(ConstructorTest)
		{
			std::vector<int> expected = { 6, 9, 4, 2, 0 };
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			Assert::AreEqual(expected, test.vector());
		}

		//Unit tests for methods
		TEST_METHOD(SizeTest) {
			size_t expected = 5;
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			Assert::AreEqual(expected, test.size());
		}

		TEST_METHOD(EmptyTest) {
			bool expected = true;
			Stack test = Stack();
			Assert::AreEqual(expected, test.empty());
		}

		TEST_METHOD(PushTest) {
			bool exp_bool = true;
			Stack expected = Stack({ 6, 9, 4, 2, 0 });
			Stack test = Stack({ 6, 9, 4, 2 });
			test.push(0);
			Assert::AreEqual(exp_bool, expected == test);
		}

		TEST_METHOD(PushTestE) {
			Assert::ExpectException<std::invalid_argument>([] { Stack().push(6); });
		}

		TEST_METHOD(PopTest) {
			bool exp_bool = true;
			Stack expected = Stack({ 6, 9, 4, 2 });
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			test.pop();
			Assert::AreEqual(exp_bool, expected == test);
		}

		TEST_METHOD(PopTestE) {
			Assert::ExpectException<std::invalid_argument>([] { Stack().pop(); });
		}

		//Unit tests for overloaded operators
		TEST_METHOD(StreamTest) {
			std::string expected = "[ 6 9 4 2 0 ]";
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			std::stringstream ostream;
			ostream << test;
			Assert::AreEqual(ostream.str(), expected);
		}

		TEST_METHOD(StreamTestE) {
			Assert::ExpectException<std::invalid_argument>([] {std::stringstream ostream; ostream << Stack(); });
		}

		TEST_METHOD(PlusEqualTest) {
			bool exp_bool = true;
			Stack expected = Stack({ 6, 9, 4, 2, 0 });
			Stack test1 = Stack({ 6, 9 });
			Stack test2 = Stack({ 4, 2, 0 });
			test1 += test2;
			Assert::AreEqual(exp_bool, expected == test1);
		}

		TEST_METHOD(PlusTest) {
			bool exp_bool = true;
			Stack expected = Stack({ 6, 9, 4, 2, 0 });
			Stack test1 = Stack({ 6, 9 });
			Stack test2 = Stack({ 4, 2, 0 });
			Assert::AreEqual(exp_bool, expected == test1 + test2);
		}

		TEST_METHOD(IndexTest) {
			int expected = 9;
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			Assert::AreEqual(expected, test[3]);
		}

		TEST_METHOD(IndexTestE) {
			Assert::ExpectException<std::invalid_argument>([] { Stack() [10]; });
		}

		TEST_METHOD(IndexTestR) {
			Assert::ExpectException<std::invalid_argument>([] { Stack({ 6, 9, 4, 2, 0 }) [10]; });
		}

		TEST_METHOD(EqualTest) {
			bool expected = true;
			Stack test1 = Stack({ 6, 9, 6 });
			Stack test2 = Stack({ 6, 9, 6 });
			Assert::AreEqual(expected, test1 == test2);
		}

		TEST_METHOD(NotEqualTest) {
			bool expected = true;
			Stack test1 = Stack({ 4, 2, 0 });
			Stack test2 = Stack({ 6, 9, 6 });
			Assert::AreEqual(expected, test1 != test2);
		}

		TEST_METHOD(MultiplyTest) {
			bool exp_bool = true;
			Stack expected = Stack({ 12, 18, 8, 4, 0 });
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			Assert::AreEqual(exp_bool, expected == test * 2);
		}

		TEST_METHOD(MultiplyTestE) {
			Assert::ExpectException<std::invalid_argument>([] { Stack() * 2; });
		}

		TEST_METHOD(IntDivideTest) {
			bool exp_bool = true;
			Stack expected = Stack({ 3, 4, 2, 1, 0 });
			Stack test = Stack({ 6, 9, 4, 2, 0 });
			Assert::AreEqual(exp_bool, expected == test / 2);
		}

		TEST_METHOD(IntDivideTestE) {
			Assert::ExpectException<std::invalid_argument>([] { Stack() / 2; });
		}

		TEST_METHOD(IntDivideTestZ) {
			Assert::ExpectException<std::invalid_argument>([] { Stack({ 6, 9, 4, 2, 0 }) / 0; });
		}
	};
}
