#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle(); //defualts to a radius of 20. 
    Circle(int value); //radius value
    ~Circle(); //empty.
    void draw(); //follows the path to draw a circle.

};


