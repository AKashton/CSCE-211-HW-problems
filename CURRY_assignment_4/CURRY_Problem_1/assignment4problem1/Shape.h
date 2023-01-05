#pragma once

class Shape
{
protected:
	static const int WIDTH = 720;
	static const int HEIGHT = 480;
	float x;
	float y;
	float deltaX;
	float deltaY;
	int radius;		// If its a circle this is the radius
	int diameter;	// If its a square this is the diameter
public:
	virtual void draw() = 0; //virtual class now, used in the three derived classes to draw respective shapes. 
	void updateCoordinates();
};

