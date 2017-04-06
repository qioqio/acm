#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Point.h"
#include "Point.cpp"
#ifndef POINT3D_H
#define POINT3D_H


class Point3D :public Point
{
    public:
        Point3D(double x=0,double y=0,double z=0);
        virtual ~Point3D();
        void set_z(double z);
        double get_z() const;
        void display_point() const;

    private:
        double m_z;


};

#endif // POINT3D_H
