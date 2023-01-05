#pragma once
#include "Shape.h"
class Square : public Shape
{
public:
	Square(); //defualts to a diameter of 20
	Square(int value); // user chooses diameter of square
	~Square();
	void draw();
};

