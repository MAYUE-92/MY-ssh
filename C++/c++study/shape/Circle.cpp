#include <iostream>
using namespace std;

class Circle
{
private:
    double r;
public:
    double CArea();
    double CLen();
    void get_r();
    Circle( double c_r=0 )
    { r = c_r; }
};
double Circle::CArea(){ return(3.14*r*r); }

double Circle::CLen(){ return(3.14*2*r); }

void Circle::get_r(){
    cout<<"请输入圆形半径："<<endl;
    cin>>r;
}