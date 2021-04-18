#include <iostream>
using namespace std;

#define pie 3.14159 //定义一个符号常量pie表示圆周率的数值
int main()
{
    double r;
    cout<<"请输入圆的半径：";
    cin >> r;

    double s;
    s = r*r*pie;
    cout<<"圆的面积为："<< s <<endl;

    double len;
    len = 2*r*pie;
    cout<<"圆的周长为："<< len <<endl;

    return 0;
}