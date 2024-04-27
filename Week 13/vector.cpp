#include <iostream>
#include <cmath>
#include "vector.h"

using namespace std;

Vector2D::Vector2D (float x, float y) : m_x(x), m_y(y)
{
	cout << "Calling constructor!" << endl;
}

Vector2D::Vector2D() : m_x(1), m_y(1)
{
	cout << "Calling empty constructor!" << endl;
}
Vector2D::Vector2D(const Vector2D &obj)
{
	// note the difference in notation
	// this is a pointer while obj is a reference
	this->m_x = obj.m_x;
	this->m_y = obj.m_y;
	cout << "Calling copy constructor!" << endl;
}

Vector2D::~Vector2D()
{
	// nothing to do here
	// usually, we'd delete any pointers stored within this
	cout << "Calling destructor!" << endl;
}

double Vector2D::get_magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y);
}

float Vector2D::getX()
{
	return m_x;
}

float Vector2D::getY()
{
	return this->m_y;
}

void Vector2D::setX(float x)
{
	this->m_x = x;
}


void Vector2D::setY(float y)
{
	m_y = y;
}

void change_vector (Vector2D & v) {
	v.setX(0.0);
	v.setY(0.0);
}

int main (int argc, char ** argv)
{
	Vector2D v = Vector2D(3.0, 4.0);
	Vector2D v1;
	Vector2D v2 = Vector2D();
	Vector2D v3(5.0, 6.0);
	Vector2D v4 = v1;
	change_vector(v);
	cout << v.get_magnitude() << endl;
	return 0;
}