#include <iostream>
using namespace std;

int main()
{
    double x;
    cout<<"输入要求解的数值";
    cin>>x;

    double sum=0;
    int n=0;
    double a=x;
    double b=1;
    double f;

    do
    {
        f= a/b;
        sum=((n%2==0)? sum+f:sum-f);
        n++;
        a *=x*x;b+=2;
    }
    while(f>=1e-5);
    cout<<sum*180/3.1415926<<endl;
    return 0;
}