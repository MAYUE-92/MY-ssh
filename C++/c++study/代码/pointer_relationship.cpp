#include <iostream>
using namespace std;

int main()
{
    int x[6]={1,4,6,2,5,3};
    int *p;

    for(p=&x[0]; p<=&x[5]; p++)
    cout<<*p<<",";
    cout<<endl;
    
    return 0;
}