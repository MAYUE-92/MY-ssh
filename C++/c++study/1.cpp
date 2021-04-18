#include <iostream>
using namespace std;

void func(int num,bool *a)
{
    
    for(int n=2; n<=num; n++)
    {
        if (num%n==0)
        {
            *a = false;
            break;
        }
    }
}

int main()
{
    int num;
    bool b=true;
    
    cout<<"请输入一个大于2的整数:";  cin>>num;  cout<<endl;
    func(num,&b);
    if (b== false)
    {
        cout<<num<<"不是素数";
    }
    else
    {
        cout<<num<<"是素数";
    }  
    return 0;
}
