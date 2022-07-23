#include "pch.h"
#include "framework.h"
#include "Stack.h"

void Stack::EmptyException() const { //throws exception for empty stack
	if (this->empty())
		throw std::invalid_argument("Stack is empty.");
}

//constructors
Stack::Stack() {
	values = std::vector<int>();
}

Stack::Stack(std::vector<int> values) {
	this->values = values;
}

//methods 
std::vector<int> Stack::vector() const noexcept {
	return values;
}

size_t Stack::size() const noexcept {
	return values.size();
}

bool Stack::empty() const noexcept {
	return values.empty();
}

void Stack::push(int const& number) {
	values.push_back(number);
}

void Stack::pop() {
	this->EmptyException();
	values.pop_back();
}

//overloaded operators
std::ostream& operator << (std::ostream& os, Stack const& other) {
	other.EmptyException();

	os << "[ ";
	for (int i : other.values)
		os << i << ' ';
	return os << ']';
} 

void Stack::operator += (Stack const& other) noexcept {
	values.insert(values.end(), other.values.begin(), other.values.end());
}

Stack Stack::operator + (Stack const& other) const noexcept {
	Stack result = *this; 
	result += other;
	return result;
}

int Stack::operator [] (unsigned int const& index) const { 
	this->EmptyException();
	if (index >= values.size())
		throw std::invalid_argument("Index is out of range.");

	return values[values.size() - 1 - index];
}

bool Stack::operator == (Stack const& other) const noexcept {
	return values == other.values;
}

bool Stack::operator != (Stack const& other) const noexcept {
	return values != other.values;
}

Stack Stack::operator * (int const& number) const {
	this->EmptyException();

	Stack result = *this;
	for (int &i : result.values) i *= number;
	return result;
}

Stack Stack::operator / (int const& number) const {
	this->EmptyException();
	if (number == 0)
		throw std::invalid_argument("Dividing by zero.");

	Stack result = *this;
	for (int &i : result.values) i /= number;
	return result;
}