#include <iostream>
using namespace std;
#include "A.cpp"

class B:public A{
    public:
    	virtual void fun1();//重新基类的虚函数成员fun1
    	void fun2();//重新基类的非虚函数成员fun2
};

void B::fun1(){ cout<<"Derived class B:virtual fun1() called."<<endl; }
void B::fun2(){ cout<<"Derived class B:non-virtual fun2() called."<<endl; }