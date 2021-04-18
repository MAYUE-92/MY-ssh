#include <iostream>
using namespace std;

class Square
{
    private:
        double length;
    public:
        double area()
        { return (length*length);};
    
        Square(double x = 0)
        {
            length = x;
        };
};

int main()
{
    Square obj[3] = {Square(2),Square(3),Square(4)};

    for(int x=0; x<3;x++)
    {
        cout<<obj[x].area()<<endl;
    }
    return 0;
}