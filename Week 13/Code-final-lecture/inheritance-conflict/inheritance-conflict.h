#include <iostream>

using namespace std;

class Parent {
	public:
		Parent(string name, int x);
		void function1();
		string get_name();
	private:
		string m_name;
	protected:
		int m_x;
};

class SecondParent {
	public:
		SecondParent(string family, float y);
		void function1();
		void function2();
		float get_y();
	private:
		float m_y;
		int m_x;
	protected:
		string m_family;


};

class Child: public Parent, public SecondParent {
	public:
		Child(string name, string family, int x, float y);
		void print_child();
};
