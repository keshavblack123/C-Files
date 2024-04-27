#include "vector2d-final.h"
#include <cmath>
#include <iostream>

using namespace std;

Vector2D::Vector2D(double x, double y) : m_x(x), m_y(y) {} //constructor

double Vector2D::getX() const {
    return m_x;
}

void Vector2D::setX(double x) {
    this->m_x = x;
}

double Vector2D::getY() const {
    return m_y;
}

void Vector2D::setY(double y) {
    this->m_y = y;
}

double Vector2D::getMagnitude() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

// Vector3D implementation

Vector3D::Vector3D (double x, double y, double z): Vector2D(x,y), m_z(z) {}

double Vector3D::getMagnitude() const {
    double old_mag = Vector2D::getMagnitude() * Vector2D::getMagnitude();
    return sqrt(old_mag + m_z * m_z);
}

int main (int argc, char ** argv)
{
    Vector2D v = Vector2D(3.0, 4.0);
    cout << v.getMagnitude() << endl;
    Vector3D v3d = Vector3D(3.0, 4.0, 12.0);
    cout << v3d.getMagnitude() << endl;
    return 0;
}