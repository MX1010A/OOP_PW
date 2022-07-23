#pragma once

const int precision = 3;
bool insignificant_difference(double, double);
void check4positive(double[]);

class Shape {
public:
	//Methods
	virtual double perimeter() const noexcept = 0;
	virtual double area() const noexcept = 0;

	//Overloaded operators
	friend bool operator < (Shape const&, Shape const&) noexcept;
	friend bool operator > (Shape const&, Shape const&) noexcept;
	friend bool operator <= (Shape const&, Shape const&) noexcept;
	friend bool operator >= (Shape const&, Shape const&) noexcept;
	friend bool operator == (Shape const&, Shape const&) noexcept;
	friend bool operator != (Shape const&, Shape const&) noexcept;
};

class Rectangle : public virtual Shape {
	double width;
	double height;

public:
	//Constructor
	Rectangle(double, double);

	//Getters
	double get_width() const noexcept;
	double get_height() const noexcept;
	
	//Setters
	void set_width(double);
	void set_height(double);

	//Methods
	double perimeter() const noexcept;
	double area() const noexcept;
};

class Triangle : public virtual Shape {
	double side1;
	double side2;
	double side3;

public:
	//Constructor
	Triangle(double, double, double);

	//Getters
	double get_side1() const noexcept;
	double get_side2() const noexcept;
	double get_side3() const noexcept;

	//Methods
	double perimeter() const noexcept;
	double area() const noexcept;
};

class Circle : public virtual Shape {
	double radius;

public:
	//Constructor
	Circle(double);

	//Getters
	double get_radius() const noexcept;

	//Setters
	void set_radius(double);

	//Methods
	double perimeter() const noexcept;
	double area() const noexcept;
};