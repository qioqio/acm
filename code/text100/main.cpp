#include<stdio.h>

#define PI 3.14


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

	void display_point() const;

	protected:
	double m_x;
	double m_y;
};

double Point::get_x() const
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

    printf("(%lf,%lf)",m_x,m_y);
}
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
    m_x=0;
    m_y=0;
}







class Circle : public Point
{
    public:
        //Circle();
        Circle(double x=0,double y=0,double r=0);
        virtual ~Circle();
        void set_r(double r);
        double get_r() const;
        double calculate_s() const;

    protected:
        double m_r;
        double m_s;

    private:
};
Circle::Circle(double x,double y,double r)
{
    //ctor
    m_x=x;
    m_y=y;
    m_r=r;
}

void Circle::set_r(double r)
{
    m_r=r;
}

double Circle::get_r() const
{
    return m_r;
}
double Circle::calculate_s() const
{
    return PI*m_r*m_r;
}
Circle::~Circle()
{
    //dtor
}







class Cylinder : public Circle
{
    public:
        Cylinder(double x=0,double y=0,double r=0,double h=0);
        virtual ~Cylinder();
        void set_h(double h);
        double get_h() const;
        double calculate_v() const;


    protected:
        double m_h;
        double m_v;

    private:
};






Cylinder::Cylinder(double x,double y,double r,double h)
{
    //ctor
    m_x=x;
    m_y=y;
    m_r=r;
    m_h=h;
}
void Cylinder::set_h(double h)
{
    m_h=h;
}
double Cylinder::get_h() const
{
    return m_h;
}
double Cylinder::calculate_v() const
{
    return calculate_s()*m_h;
}
Cylinder::~Cylinder()
{
    //dtor
}

int main()
{
    Cylinder a(1,4,2,5);
    printf("%d\n",a.calculate_s());

    return 0;
}









