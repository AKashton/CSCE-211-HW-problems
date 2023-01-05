#include "Square.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
using namespace std;
Square::Square()
{
	diameter = 20;

	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}
Square::Square(int value)
{
	diameter = value;
	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;

}
Square::~Square()
{
}
void Square::draw() //drawing for squares
{
	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(x - (diameter / 2), y - (diameter / 2));
	glVertex2f(x + (diameter / 2), y - (diameter / 2));
	glVertex2f(x + (diameter / 2), y + (diameter / 2));
	glVertex2f(x - (diameter / 2), y + (diameter / 2));
	glEnd();
}
