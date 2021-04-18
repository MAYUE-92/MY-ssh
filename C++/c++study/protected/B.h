#include <iostream>
using namespace std;

#include "A.h"

class B:public A
{
    public:
        void funB()
        {
            cout<<x<<endl;//正确，公有权限
            cout<<y<<endl; //错误，私有权限
            cout<<z<<endl;//正确，保护权限
        }
};   
