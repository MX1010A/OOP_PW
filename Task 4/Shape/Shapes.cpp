#include "pch.h"
#include "framework.h"
#include "Shapes.h"

#define M_PI 3.14159265358979323846
#include <cmath>
#include <stdexcept>

bool insignificant_difference(double num1, double num2) {
	return std::fabs(num1 - num2) < std::pow(0.1, precision);
}

void check4positive(double num) {
	if (num <= 0) throw std::invalid_argument("Invalid input.");
}

////////////////////////////// =| Shape |= //////////////////////////////

//Overloaded operators
bool operator < (Shape const& shape1, Shape const& shape2) noexcept {
	const auto area1 = shape1.area();
	const auto area2 = shape2.area();

	if (insignificant_difference(area1, area2)) return false;
	return area1 < area2;
}

bool operator > (Shape const& shape1, Shape const& shape2) noexcept {
	const auto area1 = shape1.area();
	const auto area2 = shape2.area();

	if (insignificant_difference(area1, area2)) return false;
	return area1 > area2;
}

bool operator <= (Shape const& shape1, Shape const& shape2) noexcept {
	const auto area1 = shape1.area();
	const auto area2 = shape2.area();

	if (insignificant_difference(area1, area2)) return true;
	return area1 <= area2;
}

bool operator >= (Shape const& shape1, Shape const& shape2) noexcept {
	const auto area1 = shape1.area();
	const auto area2 = shape2.area();

	if (insignificant_difference(area1, area2)) return true;
	return area1 >= area2;
}

bool operator == (Shape const& shape1, Shape const& shape2) noexcept {
	const auto area1 = shape1.area();
	const auto area2 = shape2.area();

	if (insignificant_difference(area1, area2)) return true;
	return area1 == area2;
}

bool operator != (Shape const& shape1, Shape const& shape2) noexcept {
	const auto area1 = shape1.area();
	const auto area2 = shape2.area();

	if (insignificant_difference(area1, area2)) return false;
	return area1 != area2;
}

//////////////////////////// =| Rectangle |= ////////////////////////////

//Constructor
Rectangle::Rectangle(double width, double height) {
	if (width <= 0 || height <= 0)
		throw std::invalid_argument("Invalid input.");

	this->width = width;
	this->height = height;
}

//Getters
double Rectangle::get_width() const noexcept {
	return width;
}

double Rectangle::get_height() const noexcept {
	return height;
}

//Setters
void Rectangle::set_width(double new_width) {
	check4positive(new_width);
	width = new_width;
}

void Rectangle::set_height(double new_height) {
	check4positive(new_height);
	height = new_height;
}

//Methods
double Rectangle::perimeter() const noexcept{
	return width * 2 + height * 2;
}

double Rectangle::area() const noexcept {
	return width * height;
}
//////////////////////////// =| Triangle |= /////////////////////////////

//Constructor
Triangle::Triangle(double side1, double side2, double side3) {
	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
		throw std::invalid_argument("Invalid input.");
	if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
		throw std::invalid_argument("Input lines cannot be a triangle.");

	this->side1 = side1;
	this->side2 = side2;
	this->side3 = side3;
}

//Getters
double Triangle::get_side1() const noexcept {
	return side1;
}

double Triangle::get_side2() const noexcept {
	return side2;
}

double Triangle::get_side3() const noexcept {
	return side3;
}

//Methods
double Triangle::perimeter() const noexcept {
	return side1 + side2 + side3;
}

double Triangle::area() const noexcept {
	double p = this->perimeter() / 2;
	return std::sqrt(p * (p - side1) * (p - side2) * (p - side3)); //Heron`s formula
}

////////////////////////////// =| Circle |= /////////////////////////////

//Constructor
Circle::Circle(double radius) {
	check4positive(radius);
	this->radius = radius;
}

//Getters
double Circle::get_radius() const noexcept {
	return radius;
}

//Setters
void Circle::set_radius(double new_radius) {
	check4positive(new_radius);
	radius = new_radius;
}

//Methods
double Circle::perimeter() const noexcept {
	return 2 * M_PI * radius;
}

double Circle::area() const noexcept {
	return M_PI * radius * radius;
}