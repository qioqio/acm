#include<stdio.h>
#include <Point.h>
using namespace std;

Point::Point()
{
    m_x=0;
    m_y=0;
}
Point::Point(double x,double y)
{
    m_x=x;
    m_y=y;
}
Point::~Point(){}
void  Point::set_x(double x)
{
  m_x=x;
}
void  Point::set_y(double y)
{
  m_y=y;

}

double Point::get_x()
{
  printf("%f\n",m_x);
}
double Point::get_y()
{
  printf("%f\n",m_y);
}

void Point::DisplayPoint()
{
 printf("%5.2f\n",m_x);
 printf("%5.2f\n",m_y);
}


int main(){

    class Point a;
    a.set_x(5);
    a.set_y(8);
    a.DisplayPoint();



  return 0;
}






