#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;







class Point
{
	public:
	Point();
	Point(double x, double y);
	~Point();

	double get_x() const;
	double get_y() const;

	void set_x(double x);
	void set_y(double y);


	protected:
        double m_x;
        double m_y;
};
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
    int main()
{

    Point a(2.5,3.6);
    cout<<a.get_x()<<endl;
    cout<<a.get_y()<<endl;



}
