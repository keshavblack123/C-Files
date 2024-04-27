#include <iostream>
#include "inheritance-conflict.h"

using namespace std;

Parent::Parent(string name, int x) : m_name(name), m_x(x) {
			cout << "Parent" << endl;
}
void Parent::function1() { cout << "Parent Function 1" << endl; }

string Parent::get_name() { return m_name; }

SecondParent::SecondParent(string family, float y) : m_family(family), m_y(y) {
		cout << "SecondParent" << endl;
}
void SecondParent::function1() { cout << "Second Parent Function 1 " << endl; }

void SecondParent::function2() { cout << "Second Parent Function 2" << endl; }

float SecondParent::get_y() { return m_y; }

Child::Child(string name, string family, int x, float y) : Parent(name,x), SecondParent(family, y) {
			cout << "Child constructor" << endl;
}
void Child::print_child () {
	cout << get_name() << " " << m_x << " " << m_family << " " << get_y() << endl;
}

int main() {
	Child c = Child("simon", "perrault", 5, 3.5f);
	c.print_child();
	c.function1();
	c.function2();
	cout << "Test" << endl;
	return 0;
}