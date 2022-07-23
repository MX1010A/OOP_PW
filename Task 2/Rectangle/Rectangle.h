#pragma once
#include <string>

struct Point {
	int x;
	int y;

	//methods
	int DistanceX(int) const noexcept;
	int DistanceY(int) const noexcept;

	//overloaded operators
	bool operator == (Point) const noexcept;
	bool operator != (Point) const noexcept;
};

class Rectangle {
private: 
	int width;
	int height;
	Point vertex;

public:
	//constructors
	Rectangle();
	Rectangle(int, int, Point = { 0, 0 });

	//setters
	void setWidth(int);
	void setHeight(int);
	void setVertex(Point) noexcept;
	
	//getters
	int getWidth() const noexcept;
	int getHeight() const noexcept;
	Point getVertex() const noexcept;

	//methods
	int perimeter() const noexcept;
	int area() const noexcept;
	bool isSquare() const noexcept;

	//overloaded operators
	Rectangle operator + (Rectangle const&) noexcept;
	bool operator == (Rectangle const&) const noexcept;
	bool operator != (Rectangle const&) const noexcept;
	void operator += (Rectangle const&) noexcept;
};

