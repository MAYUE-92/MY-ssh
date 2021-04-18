#include <iostream>
using namespace std;

int Max(int x,int y){return ((x>y)?x:y);}
double Max(double x,double y){return ((x>y)?x:y);}
int Max(int x, int y, int z)
{
    int m;
    m = (x>y)?x:y;
    m = (x>z)?m:z;
    return m;
}