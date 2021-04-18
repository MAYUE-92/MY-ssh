#include <iostream>
using namespace std;

class Circle
{
    private:
    	double R;
    public:
    	double area(); 
    //声明构造函数，两个构造函数为重载函数，第二为拷贝构造函数。
    	Circle(double r);
        Circle(Circle &);
};
//定义方法成员
double Circle::area()
{return(3.14*R*R);} 
//定义重载构造函数，对变量r进行初始化
Circle::Circle(double r=0 ) { R = r; cout<<"Circle(double r)called"<<endl; }
//定义拷贝构造函数
Circle::Circle(Circle &carea) { R = carea.R; cout<<"Circle(Circle &)called"<<endl;}

int main()
{
    Circle carea1(5.3); //此时调用构造函数Circle(double r);
    Circle carea2(carea1);//此时调用拷贝构造函数Circle(Circle &);利用已经存在的对象carea初始化carea2
    cout<<carea2.area(); //
    return 0;
}