#include <iostream>
using namespace std;

int main()
{
    double x;
    cout<<"请输入一个数值："<<endl;
    cin>>x;

    if (x!=0)
    {
        x = 1/x;
        cout<< "x的倒数为："<<x<<endl;
    }
    else
    {
        cout<<"因为x的值等于0,0没有倒数"<<endl;

    }
    return 0;
}