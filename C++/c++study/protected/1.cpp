#include <iostream>
using namespace std;

#include "A.h"

int main()
{
    A obj(10,20,30); 
    cout<<obj.x<<endl;//正确，公有权限
    cout<<obj.y<<endl; //错误，私有权限
    cout<<obj.z<<endl;//错误，保护权限
    return 0;
}