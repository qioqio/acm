#include "Point3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Point3D::Point3D(double x,double y,double z)
{
    m_x=x;
    m_y=y;
    m_z=z;
}

Point3D::~Point3D()
{
    //dtor
}
void Point3D::set_z(double z)
{

    m_z=z;

}
double Point3D::get_z() const
{
    return m_z;


}
void Point3D::display_point() const
{

    cout<<m_x<<","<<m_y<<","<<m_z<<endl;
}





 int main()
{
    double x,y,z;
    cin>>x>>y>>z;
    Point3D a(x,y,z);
    a.display_point();




}
