#pragma once
#include <vector>
#include <ostream>

class Stack {
private:
	std::vector<int> values;
	void EmptyException() const; //throws exception for empty stack

public:
	//constructors
	Stack();
	Stack(std::vector<int>);

	//methods
	std::vector<int> vector() const noexcept;
	size_t size() const noexcept;
	bool empty() const noexcept;
	void push(int const&);
	void pop();

	//overloaded operators
	friend std::ostream& operator << (std::ostream& os, Stack const&);

	void operator += (Stack const&) noexcept;
	Stack operator + (Stack const&) const noexcept;

	int operator [] (unsigned int const&) const;

	bool operator == (Stack const&) const noexcept;
	bool operator != (Stack const&) const noexcept;

	Stack operator * (int const&) const;
	Stack operator / (int const&) const;
};



