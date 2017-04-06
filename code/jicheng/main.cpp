#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const double PI=3.1415;
class Point
{
	public:

	Point(double x, double y);
	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);
	protected:
        double m_x;
        double m_y;
};

Point::Point(double x, double y)
{
    m_x=x;
    m_y=y;
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
class Circle :public Point
{
public:
    Circle(double x,double y,double R);
    void set_semi(double R);
    double compute_area();

    double get_semi() const;

protected :
    double semi;
};

void Circle::set_semi(double R)
{
   semi=R;

}
double Circle::get_semi() const
{

    return semi;
}
 double Circle::compute_area()

 {

     return semi*semi*PI;
 }

Circle::Circle(double x,double y,double R):Point(x,y),semi(R)
{

}






class Cylinder :public Circle
{
public :
    Cylinder(double x,double y,double R,double H);
    void set_high(double H);
    double compute_vol();
    double get_high()const;


protected :
    double high;
};

Cylinder::Cylinder(double x,double y,double R,double H):Circle(x,y,R),high(H)
{

}
void Cylinder::set_high(double H)
{
   high=H;

}
double Cylinder::get_high()const
{
    return high;


}
 double Cylinder::compute_vol()

 {

     return semi*semi*PI*high;
 }




int main()

{
Cylinder c(2.5,36.54,5.6,5.1);
/*
第一个参数是x，第二个参数是y，第三个参数是半径，第四个参数高
*/
cout<<c.compute_vol()<<endl;
cout<<c.compute_area()<<endl;

cout<<c.get_x()<<endl;
cout<<c.get_y()<<endl;
cout<<c.get_high()<<endl;
cout<<c.get_semi()<<endl;
return 0;
}






