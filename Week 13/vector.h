#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
	public:
		// This class has three constructors (see overloading)
		// regular constructor
		Vector2D (float x, float y);
		// empty constructor
		Vector2D();
		// copy constructor
		Vector2D(const Vector2D &obj);
		// destructor
		~Vector2D();
		double get_magnitude();
		float getX();
		float getY();
		void setX(float x);
		void setY(float y);
	private:
		float m_x;
		float m_y;
};

#endif