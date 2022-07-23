#include "pch.h"
#include "framework.h"
#include "Rectangle.h"
#include <stdexcept>
#include <typeinfo>
#include <string>

///////////////////////////////////////////////// =| Point structure |= //////////////////////////////////////////////////

//methods
int Point::DistanceX(int x) const noexcept {
	if (this->x < x)
		return x - this->x;
	else
		return this->x - x;
}

int Point::DistanceY(int y) const noexcept {
	if (this->y < y)
		return y - this->y;
	else
		return this->y - y;
}

//overloaded operators
bool Point::operator == (Point point) const noexcept {
	return x == point.x && y == point.y;
}

bool Point::operator != (Point point) const noexcept {
	return x != point.x || y != point.y;
}

///////////////////////////////////////////////// =| Rectangle class |= //////////////////////////////////////////////////

//constructors
Rectangle::Rectangle() {
	this->width = 0;
	this->height = 0;
	this->vertex = { 0, 0 };
}

Rectangle::Rectangle(int width, int height, Point vertex) {
	if (width < 0 || height < 0)
		throw std::invalid_argument("Invalid rectangle size.");
	this->width = width;
	this->height = height;
	this->vertex = vertex;
}

//setters
void Rectangle::setWidth(int newWidth) {
	if(newWidth < 0)
		throw std::invalid_argument("Invalid rectangle size.");
	width = newWidth;
}

void Rectangle::setHeight(int newHeight) {
	if (newHeight < 0)
		throw std::invalid_argument("Invalid rectangle size.");
	height = newHeight;
}

void Rectangle::setVertex(Point newVertex) noexcept {
	vertex = newVertex;
}

//getters
int Rectangle::getWidth() const noexcept {
	return width;
}

int Rectangle::getHeight() const noexcept {
	return height;
}

Point Rectangle::getVertex() const noexcept {
	return vertex;
}

//methods
int Rectangle::perimeter() const noexcept {
	return 2 * width + 2 * height;
}

int Rectangle::area() const noexcept {
	return width * height;
}

bool Rectangle::isSquare() const noexcept {
	return width == height;
}

//overloaded operators
Rectangle Rectangle::operator + (Rectangle const& rectangle) noexcept {
	Rectangle result = *this;
	result += rectangle;
	return result;
}

bool Rectangle::operator == (Rectangle const& rectangle) const noexcept {
	return width == rectangle.width && height == rectangle.height 
		&& vertex == rectangle.vertex;
}

bool Rectangle::operator != (Rectangle const& rectangle) const noexcept {
	return width != rectangle.width || height != rectangle.height
		|| vertex != rectangle.vertex;
}

void Rectangle::operator += (Rectangle const& rectangle) noexcept {
	//*this is on W
	if (vertex.x < rectangle.vertex.x)
		width = vertex.DistanceX(rectangle.vertex.x) + rectangle.width;
	//*this is on E
	else if (vertex.x > rectangle.vertex.x) {
		width = vertex.DistanceX(rectangle.vertex.x) + width;
		vertex.x = rectangle.vertex.x;
	}
	else //*this is on the same X coords with &rectangle
		width = std::max(width, rectangle.width);

	//*this is on N
	if (vertex.y > rectangle.vertex.y)
		height = vertex.DistanceY(rectangle.vertex.y) + rectangle.height;
	//*this is on S
	else if (vertex.y < rectangle.vertex.y) {
		height = vertex.DistanceY(rectangle.vertex.y) + height;
		vertex.y = rectangle.vertex.y;
	}
	else //*this is on the same Y coords with &rectangle
		height = std::max(height, rectangle.height);
}
