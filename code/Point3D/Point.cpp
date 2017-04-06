#include "Point.h"
#include <stdio.h>
#include <iostream>
using namespace std;
Point::Point()
{
    m_x=0;
    m_y=0;
}
Point::Point(double x, double y)
{
    m_x=x;
    m_y=y;
}

Point::~Point()
{
    //dtor
}


double Point::get_x ()const
{
    return m_x;

}
double Point::get_y() const
{
    return m_y;

}

void Point::set_x(double x)
{
    m_x=x;

}
void Point::set_y(double y)
{
    m_y=y;

}

void Point::display_point() const
{

    cout<<m_x<<","<<m_y<<endl;
}

int main()
{
    Point p(3,8);
    Point p1;
     p1.display_point();
    p.display_point();
    p.set_x(2);
    p.set_y(5);
    printf("%f\n",p.get_x());
    printf("%f\n",p.get_y());
    p.display_point();




    return 0;

}

















