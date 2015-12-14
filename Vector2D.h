#ifndef VECTOR2D_H
#define VECTOR2D_H


#include <math.h>//using math operations


class Vector2D
{
public:
        //passing x,y from constructor to m_x,m_y
        Vector2D(float x, float y): m_x(x), m_y(y){}

        //returning values
        float getX() {return m_x;}
        float getY() {return m_y;}

        void setX(float x) {m_x = x;}
        void setY(float y) {m_y = y;}


private:

        float m_x;
        float m_y;
};

#endif // VECTOR2D_H
