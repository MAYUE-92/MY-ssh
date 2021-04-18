#include <iostream>
using namespace std;

#include "BorderCircle.h"

int main()
{
    BorderCircle obj;//定义一个派生类对象BorderCircle的对象obj
    //调用新增成员（同名覆盖）Input()函数，输入半径和边框宽度
    obj.Input();
    
    //调用基类中的CArea和CLen计算圆的面积和周长
    cout<<obj.CArea()<<","<<obj.CLen()<<endl;
    //调用新增成员InnerArea和BorderArea计算内圆面积和圆环面积
    cout<<obj.InnerArea()<<","<<obj.BorderArea()<<endl;
    return 0;
}