#include <iostream>
using namespace std;

int main()
{
    int x;
    cout<<"请输入一个年份："<< endl;
    cin>>x;
    if ((x%100!=0 && x%4==0) || x%400==0)
    {
        cout<<x<<"是闰年";
    }
    else
    cout<<x<<"不是闰年";

    return 0;
}