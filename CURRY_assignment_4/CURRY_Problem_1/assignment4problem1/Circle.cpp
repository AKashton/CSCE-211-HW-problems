#include "Circle.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
using namespace std;
Circle::Circle()
{
	radius = 20;

	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}

Circle::Circle(int value)
{
	radius = value;
	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}

Circle::~Circle()
{
}

void Circle::draw() //drawing for circles.
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
	}
	glEnd();
	
}
