#pragma once
#include "Shape.h"
class Multicoloredcircle :
    public Shape
{
public:

    Multicoloredcircle(); //defualts to radius of 20
    ~Multicoloredcircle();
    Multicoloredcircle(int value); //user chooses radius
    void draw();
};

