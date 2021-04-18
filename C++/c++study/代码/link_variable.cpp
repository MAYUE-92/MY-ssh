#include <iostream>
using namespace std;

inline double Exchange(double amount,double rate=6.1104)
{ return amount / rate; }


int main()
{
    int x;
    cout <<"请输入人民数量，单位元：";
    cin >> x;
    cout<<x<<"元人民币="<<Exchange(x)<<"美元"<<endl; //人民币>>美元
    cout<<x<<"元人民币="<<Exchange(x,6.9698)<<"欧元"<<endl; //人民币>>欧元
    cout<<x<<"元人民币="<<Exchange(x,9.7347)<<"英镑"<<endl; //人民币>>英镑
    cout<<x<<"元人民币="<<Exchange(x,0.78817)<<"港币"<<endl; //人民币>>港币
    return 0;
}
