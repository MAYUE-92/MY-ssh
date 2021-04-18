#include <iostream>
using namespace std;

class Square
{
    public:
        double a;
        double area()
            { return (a*a); }
        Square(double x=0)
            {a=x;}
};

double inner_circle_area(Square s )
{
    double r = s.a/2;
    return(3.14*r*r);
}

int main()
{
    Square obj(10);
    cout<<inner_circle_area(obj)<<endl;
    return 0;
}