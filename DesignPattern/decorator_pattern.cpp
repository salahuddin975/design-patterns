#include <iostream>


class Shape
{
public:
	virtual void draw() = 0;
};

class Circle : public Shape
{
public:
	void draw(){
		std::cout << "Draw Shape: Circle." << std::endl;
	}
};

class Rectangle : public Shape
{
public:
	void draw(){
		std::cout << "Draw Shape: Rectangle." << std::endl;
	}
};

class ShapeDecorator : public Shape
{
protected:
	Shape *shape;

public:
	ShapeDecorator(Shape *shape){
		this->shape = shape;
	}

	void draw(){
		shape->draw();
	}
};

class BorderWithShapeDecorator : public ShapeDecorator
{
public:
	BorderWithShapeDecorator(Shape *shape) : ShapeDecorator(shape) { }
	
	void draw(){
		ShapeDecorator::draw();
		drawBorder();
	}

	void drawBorder(){
		std::cout << "Set Border." << std::endl;
	}
};

void decorator_pattern()
{
	Circle *circle = new Circle();
	std::cout << "\n------- Draw Circle without border --------" << std::endl;
	circle->draw();

	BorderWithShapeDecorator *circleWithBorder = new BorderWithShapeDecorator(circle);
	std::cout << "\n------- Draw Circle with border --------" << std::endl;
	circleWithBorder->draw();

	Rectangle *rectangle = new Rectangle();
	std::cout << "\n------- Draw rectangle without border --------" << std::endl;
	rectangle->draw();

	BorderWithShapeDecorator *rectangleWithBorder = new BorderWithShapeDecorator(rectangle);
	std::cout << "\n------- Draw rectangle with border --------" << std::endl;
	rectangleWithBorder->draw();

	delete circle, circleWithBorder, rectangle, rectangleWithBorder;
}
