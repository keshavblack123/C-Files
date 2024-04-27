#include <iostream>

using namespace std;

class Shape {
	public:
		//virtual void print () { cout << "Shape.print()" << endl; }
		virtual void print () = 0;
		int get_sides () { return m_sides; }
	protected:
		int m_sides;
		Shape(int s) : m_sides(s) { cout << "Shape constructor" << endl; }
};

class Rectangle : public Shape {
	public:
		Rectangle (int s) : Shape(s) { }
		void print () { cout << "Rectangle.print()" << endl; }
};

int main () {
	Rectangle r = Rectangle(4);
	r.print();
	return 0;
}
