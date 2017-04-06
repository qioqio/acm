#include <iostream>
#include <cmath>
#include <fstream>
#include <istream>
#include <ostream>
using namespace std;

///////////////////////////////////////////////////////////
/*我将point 和 point3D直接写进来了，这样助教就可以直接运行我的代码了
这两个类是我之前两次实验写的。
直接粘贴进来的*/

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
///////////////////////////////////////////////////////////
/*下面就是我的Curve3D类*/

class Curve3D
{
	public://全部的方法和属性都是public类型
	Curve3D(double x=0,double y=0,double z=0);//默认的空间点是原点
    Curve3D( const Curve3D& t ) ;//浅拷贝构造函数
	~Curve3D();
	void DisplayCurve();//展示曲线中的点
	double CurveLen();//计算曲线长度
	Curve3D operator+(const Point3D& point ) const;//重载加法操作
	const Curve3D& operator=( const Curve3D& tr ) ;//重载等号操作
    Point3D* pointarray;//指针数组，数组成员是Point3D类型
	int num;//记录曲线点的个数
    Curve3D operator-(const Point3D& point ) const;//重载减法操作
    void write_txt(ofstream &os)const;
    Curve3D read_txt(ifstream &is);
    void write_binary(ofstream &os)const;
    Curve3D read_binary(ifstream &is);

};

Curve3D::~Curve3D()
{
    if(num>=1)//当曲线没有点成员时候，什么都不做
    {
        if(num==1)
        delete pointarray;//释放一个点
        else
        delete[] pointarray;//释放指针数组
    }
}
Curve3D::Curve3D(double x,double y,double z)//默认曲线包含一个点，不指明时，就是原点
{
    num=1;
    pointarray=new Point3D(x,y,z);
}
void Curve3D::DisplayCurve()//打印曲线中的点
{
     cout<<"The coordinates of the points is: "<<endl;
    for(int i=0;i<num;i++)
    cout<<pointarray[i].get_x()<<','<<pointarray[i].get_y()<<','<<pointarray[i].get_z()<<endl;
}

double Curve3D::CurveLen()//计算曲线的长度
{
    if(this->num<=1)
    {
        cout<<"The length of the curve is "<<0<<endl;
        return 0;
    }
    double ans=0;
    for(int i=1;i<num;i++)
    {
       double x=fabs(pointarray[i].get_x()-pointarray[i-1].get_x());
       double y=fabs(pointarray[i].get_y()-pointarray[i-1].get_y());
       double z=fabs(pointarray[i].get_z()-pointarray[i-1].get_z());
       ans+=sqrt(x*x+y*y+z*z);
    }
    cout<<"The length of the curve is "<<ans<<endl;
     return ans;
}
Curve3D Curve3D::operator+(const Point3D& point) const//重载加法运算符
{

    Curve3D temp;
    temp.num=this->num+1;//num加上1
    delete temp.pointarray;//删除temp的指针数组
    temp.pointarray=new Point3D[temp.num];//动态分配内存
    for(int i=0;i<temp.num-1;i++)//将曲线的点全部拷贝进去
    {
        temp.pointarray[i].set_x(this->pointarray[i].get_x());
        temp.pointarray[i].set_y(this->pointarray[i].get_y());
        temp.pointarray[i].set_z(this->pointarray[i].get_z());
    }//将最后一个点加进去
    temp.pointarray[temp.num-1].set_x(point.get_x());
    temp.pointarray[temp.num-1].set_y(point.get_y());
    temp.pointarray[temp.num-1].set_z(point.get_z());
    return temp;
}
const Curve3D& Curve3D::operator=(const Curve3D& t)
{
    if ( this != &t)//防止自己拷贝自己，导致出错。
    {
        if(num>=1)
        {
            if(num==1)
            delete pointarray;
            else
            delete[] pointarray;
        }
        pointarray=NULL;//将指针赋为空

        num = t.num;
        //当对象非空的时候进行拷贝
        if(num>=1)pointarray = new Point3D[num];
        for ( int i = 0 ; i < num ; i++ )
           pointarray[i] = t.pointarray[i] ;
    }
    return *this ;
}
Curve3D::Curve3D(const Curve3D& tr)//拷贝构造函数
{
    num = tr.num;
     if(num>=1)pointarray = new Point3D[num];
     else pointarray=NULL;//考虑对象指针为空的情况
    for ( int i = 0 ; i < num ; i++ )
        pointarray[i] = tr.pointarray[i];
}
Curve3D Curve3D::operator-(const Point3D& point) const//重载减法操作符
{
    for(int i=0;i<this->num;i++)//找到相同的点的下标i
    {
        if(point.get_x()==this->pointarray[i].get_x()
           &&point.get_y()==this->pointarray[i].get_y()
           &&point.get_z()==this->pointarray[i].get_z())
        {
             Curve3D temp;//定义tmep这个曲线，对这个曲线进行构造，使得将去下标为i的点。
             delete  temp.pointarray;
             temp.pointarray=NULL;//给指针赋值null
            temp.num=this->num-1;
            if(temp.num>=1)temp.pointarray=new Point3D[temp.num];

            for(int j=0;j<i;j++)//将下标小于i的拷贝
            {
                temp.pointarray[j].set_x(this->pointarray[j].get_x());
                temp.pointarray[j].set_y(this->pointarray[j].get_y());
                temp.pointarray[j].set_z(this->pointarray[j].get_z());
            }
            for(int j=i;j<temp.num;j++)//跳过下标为i的点，继续拷贝
            {
                temp.pointarray[j].set_x(this->pointarray[j+1].get_x());
                temp.pointarray[j].set_y(this->pointarray[j+1].get_y());
                temp.pointarray[j].set_z(this->pointarray[j+1].get_z());
            }
            return temp;
        }
    }
    //如果没有相同的点的话，就可以返回原来的曲线
    Curve3D temp=*this;
    return temp;
}



void Curve3D::write_txt(ofstream &os)const//将曲线中的点写进文件中
{
    for(int i=0;i<num;i++)
    {
        os<<pointarray[i].get_x()<<' '<<pointarray[i].get_y()<<' '<<pointarray[i].get_z()<<endl;
    }

}
Curve3D Curve3D::read_txt(ifstream &is)//将文件中点的信息读出来，存到曲线中
{
    Curve3D temp;Point3D p;
    temp=temp-p;//将temp变成没有点的曲线
    for(int i=0;i<num;i++)
    {

        double  x,y,z;
        is>>x>>y>>z;//读入点的信息。
        p.set_x(x);p.set_y(y);p.set_z(z);
        temp=temp+p;//将点加到曲线中
    }
    return temp;
}
void Curve3D::write_binary(ofstream &bout)const//将曲线的信息写进二进制文件中
{
    int object_size=sizeof(Point3D);
    for(int i=0;i<num;i++)//将曲线中的点一个个以二进制的形式写到文件中
    {
        Point3D temp(pointarray[i].get_x(),pointarray[i].get_y(),pointarray[i].get_z());

        bout.write(reinterpret_cast<char *>(&temp),object_size);
    }
}
Curve3D Curve3D::read_binary(ifstream &bin)//将二进制文件中点的信息读出来
{
    Curve3D temp;
    Point3D p;
    int object_size=sizeof(p);
    temp=temp-p;//将temp这个曲线中的原点减去,使得temp成为没有点的曲线
    while(bin.read(reinterpret_cast<char *>(&p),object_size))//将信息读入point3d中，直到读到最后
    {
        temp=temp+p;
    }

    return temp;
}





void show( Curve3D& a) //展示一个曲线对象
{
    cout<<"The num is "<<a.num<<endl;
    a.CurveLen();
    a.DisplayCurve();
    cout<<endl;

}
int main()//在main函数里面，测试这些功能
{
    Point3D point1(5,8,9);
    Point3D point2(4.5,1.9,4.8);
    Point3D point3;//这个点是原点
    Point3D point4(0,8,6);

    Curve3D a;//不带参数的构造，这时曲线a只有一个点，是原点
    show(a);

    Curve3D b(1.8,8.7,9.84);//带参数的构造，只有一个点
    show(b);

    //测试重载的加减运算符
    a=a-point3;show(a);
    a=a-point4;show(a);
    a=a+point1;show(a);
    a=a+point2;show(a);
    a=a+point3;show(a);
    a=a-point3;show(a);
    a=a-point4;show(a);

    //下面测试文件操作

    ofstream out( "curve3d1.txt",ios::app);//打开文件
    if(out.fail())//打开失败的话，输出提示信息
    {
        cerr<<"Failure to open the out.txt for output."<<endl;
        return 1;
    }

    ifstream in( "curve3d1.txt" );
    if(in.fail())//打开失败的话，输出提示信息。
    {
        cerr<<"Failure to open the in.txt for input."<<endl;
        return 1;
    }

    cout<<endl<<"I will test the file operations."<<endl;
    a.write_txt(out);//将曲线a写入到文件中
    Curve3D c=a.read_txt(in);//从文件中的读入点的信息，存到曲线c中
    a.DisplayCurve();//将a这个曲线打印出来
    c.DisplayCurve();//将c这个曲线打印出来

    in.close();out.close();//关闭文件




    //下面测试二进制文件的读写操作
    cout<<endl<<"I will test the binary file operations."<<endl;
    remove("curve3d2.txt");//先将文件删除,若不存在该文件，删除失败，接着运行，不会异常退出。


    ofstream bout( "curve3d2.txt",ios::binary|ios::app);//以追加的形式打开文本文档
    if(bout.fail())//打印失败的时候，输出提示信息
    {
        cerr<<"Failure to open the out.txt for output."<<endl;
        return 1;
    }

    a.write_binary(bout);//将a这个曲线的信息读入二进制文本
    bout.close();//关闭文件

    ifstream bin( "curve3d2.txt" ,ios::binary );//打开文件，进行读取
    if(bin.fail())//打开失败的时候，输出提示信息
    {
        cerr<<"Failure to open the in.txt for input."<<endl;
        return 1;
    }
    Curve3D d=a.read_binary(bin);//将从文件读入的信息，存入到曲线d中
    a.DisplayCurve();//将曲线a打印出来
    d.DisplayCurve();//将曲线d打印出来，进行对比
    bin.close();//关闭文件
    return 0;
}









