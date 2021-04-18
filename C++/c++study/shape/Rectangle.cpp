#include <iostream>
using namespace std;

class Rectangle
{
private:
    double w,h;
public:
    double RArea();
    double RLen();
    void get_num();
    Rectangle( double a=0,double b=0)
    { w = a; h = b; }
};
double Rectangle::RArea(){ return(w*h); }

double Rectangle::RLen(){ return((w+h)*2); }

void Rectangle::get_num(){
    cout<<"请输入长和宽："<<endl;
    cin>>w>>h;
}