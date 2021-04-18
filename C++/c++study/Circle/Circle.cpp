#include <iostream>
using namespace std;
#include "Circle.h"

void Circle::Input()
{
    cin>>r;
    while (r<0)//检查数据合法性
    {
        cin>>r;//如果r<0,则重新输入
    }
}

double Circle::CRadius()//读取半劲
{ return r; }

double Circle::CArea()//求面积
{ return(3.14*r*r); }

double Circle::CLen()//求周长
{ return(3.14*r*2); }

Circle::Circle()//无参构造函数
{ r = 0; }

Circle::Circle(double x)//有参构造函数
{
    if(x<0) r=0;//如果r<0则，置0
    else r=x;
}

Circle::Circle(Circle&x)//拷贝构造函数
{ r = x.r;}