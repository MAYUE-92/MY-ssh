#include <iostream>
using namespace std;

int main()
{
    int x[6]={1,3,4,6,5,2};
    int a,b,min,temp;

    for(a=0;a<6-1;a++)
    {
        min=a;
        for(b=a+1;b<6;b++)
        {
            if(x[b]<x[min])
            min=b;
        }
    temp=x[a];x[a]=x[min];x[min]=temp;
    }
    for(a=0;a<6;a++)
    cout<<x[a];

    return 0;
}