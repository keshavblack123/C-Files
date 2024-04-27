#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
private:
    double m_x;
    double m_y;

public:
    Vector2D(double x = 0.0, double y = 0.0);
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    double getMagnitude() const;
};

class Vector3D: public Vector2D {
private:
    double m_z;

public:
    Vector3D(double x, double y, double z);
    double getMagnitude() const;
};

#endif
