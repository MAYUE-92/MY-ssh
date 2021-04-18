#include <iostream>
using namespace std;

#include "A.cpp"
#include "B.cpp"

int main(){
    A aobj;//定义1个基类对象aobj
    B bobj;//定义1个派生类对象bobj

    aobj.fun1();//调用结果：调用了基类对象的虚函数成员fun1
    aobj.fun2();//调用结果：调用了基类对象的虚函数成员fun2
    bobj.fun1();//调用结果：调用了派生类对象bobj的新增函数成员fun1
    bobj.fun2();//调用结果：调用了派生类对象bobj的新增函数成员fun2
    //结论1：通过对象名访问派生类对象的成员，将访问器新增成员（同名覆盖）
    return 0;
}