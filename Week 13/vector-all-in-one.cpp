#include <iostream>
#include <cmath>

// This file shows how to declare and implement a file in a single CPP file
// Usually you want to avoid doing so, but it may be faster to type...
// ... or to write on paper (if needed)
using namespace std;
class Vector2D {
	public:
		Vector2D (float x, float y) : m_x(x), m_y(y) { }
		Vector2D () : m_x(1), m_y(1) { }
		double get_magnitude()
		{ return sqrt(m_x * m_x + m_y * m_y); }
		float getX() const { return this->m_x; }
		float getY() const { return this->m_y; }
		void setX(float x) { this->m_x = x; }
		void setY(float y) { m_y = y; }
	private:
		float m_x;
		float m_y;
};

int main (int argc, char ** argv)
{
	Vector2D v(3.0, 4.0);
	Vector2D v1;
	cout << v.get_magnitude() << ", " << v1.get_magnitude() << endl;
	return 0;
}