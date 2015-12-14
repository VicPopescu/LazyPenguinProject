#ifndef VECTOR2D_H
#define VECTOR2D_H


#include <math.h>//using math operations


class Vector2D
{
public:
        //passing x,y from constructor to m_x,m_y:
        Vector2D(float x, float y): m_x(x), m_y(y){}

        //returning values
        float getX() {return m_x;}
        float getY() {return m_y;}

        void setX(float x) {m_x = x;}
        void setY(float y) {m_y = y;}

        /* VECTOR LENGTH */
        float length() {return sqrt(m_x * m_x + m_y * m_y);}


        /* VECTOR ADDITION */
        //overloading "+" operator to make easy to add two vectors together
        Vector2D operator+(const Vector2D& v2) const
        {
            return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
        }

        friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
        {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;

            return v1;
        }


        /* VECTOR MULTIPLY BY A SCALAR NR */
        //overloading "*" operator
        Vector2D operator*(float scalar)
        {
            return Vector2D(m_x * scalar, m_y * scalar);
        }

        Vector2D& operator*=(float scalar)
        {
            m_x *= scalar;
            m_y *= scalar;

            return *this;
        }


        /* SUBSTRACTION OF TWO VECTORS */
        //similar to addition
        Vector2D operator-(const Vector2D& v2) const
        {
            return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
        }

        friend Vector2D& operator-=(Vector2D& v1, const Vector2D v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;

            return v1;

        }




private:

        float m_x;
        float m_y;
};

#endif // VECTOR2D_H
