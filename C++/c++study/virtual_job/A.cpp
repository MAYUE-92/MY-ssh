#include <iostream>
using namespace std;

class A
{
    public:
    	virtual void fun1();//声明fun1为虚函数
    	void fun2();//fun2为普通函数，即非虚函数
};

void A::fun1(){ cout<<"Base class A: virtual fun1() called."<<endl; }
void A::fun2(){ cout<<"Base class A: non-virtual fun2() called."<<endl; }