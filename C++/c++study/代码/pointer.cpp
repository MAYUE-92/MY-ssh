#include <iostream>
using namespace std;

int main()
{
    int x[6]={1,4,6,2,5,3}; 
    int *p, *p1, *p2;

    p = &x[0]; //将指针变量p指向第0个元素
    for(int n=0;n<6;n++)
    cout<<*(p+n)<<",";
    cout<<endl;

    int d; //定义一个int型变量d
    p1 = p+1; //将指针变量p1指向第1个元素
    p2 = p+4; //将指针变量p2指向第4个元素
    d = p2-p1; //指针变量之间的差值等于等于其所指向数组下标之间的差值，及4-1
    cout<<d<<endl;//显示结果为3

    d = &x[4]-&x[1]; //数组元素地址之间的差值等于其下标之间的差值，及4-1
    cout<<d<<endl; //显示结果为3
    return 0;
}