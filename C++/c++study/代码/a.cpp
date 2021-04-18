#include <iostream>
using namespace std;

class Circle
{
    public:
        double r;
        double Carea();
        double Clen();
};
class Rectangle
{
    public:
        double a,b;
        double Rarea();
        double Rlen();
};

int main()
{
    Circle obj1;
    Rectangle obj2;
    
    cout<<"请输入半径：";
    cin>>obj1.r;
    cout<<endl;
    cout<<"请输入长宽";
    cin>>obj2.a>>obj2.b;

    cout<<"圆形的面积为："<<obj1.Carea()<<",周长为："<<obj1.Clen()<<endl;
    cout<<"长方形形的面积为："<<obj2.Rarea()<<",长方形的周长为："<<obj2.Rlen()<<endl;
    
    return 0;
}