#include "Shape.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
#include "Circle.h"
using namespace std;


// This function updates the location of the shape, by adding in deltaX to the x coordinate
// and deltaY to the y coordinate.  Since the delta's can be negative this allows for moving
// up or down.
// If the center of the ball goes off the edge of the screen, reverse the direction.
void Shape::updateCoordinates() //used by all classes, no need to implement in derived classes.
{
	x += deltaX;
	y += deltaY;

	// Check if we hit the edge of the screen and if we did
	// move it back so it fits and then change the direction
	if (x >= WIDTH)
	{
		x -= deltaX;
		// deltaX is positive, so make it negative
		deltaX *= -1;
	}
	else if (x < 0)
	{
		deltaX *= -1;    // deltaX is negative, so make it positive
		x += deltaX;    // add it in so we are not off the edge
	}
	if (y >= HEIGHT)
	{
		y -= deltaY;  // Same for the Y directions
		deltaY *= -1;
	}
	else if (y < 0)
	{
		deltaY *= -1;
		y += deltaY;
	}
}