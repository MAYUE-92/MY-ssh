//函数间的参数传递
#include <iostream>
using namespace std;

void swap(int &a,int &b) // 引用传递：将形参定义为引用变量
{
    int t;
    t = a; a = b; b = t; //这3条语句可以交换a和b的值
}

int main()
{
    cout << "Exchange x and y" << endl;
    int x = 5, y = 10;
    cout << x << "," << y << endl;

    swap(x,y); //调用函数swap交换变量x和y的值
    cout << x << "," << y << endl;
    return 0;
}