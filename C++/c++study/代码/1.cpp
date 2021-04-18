#include <iostream>
using namespace std;

#include "2.h"
// void RectCost();
// double CircleCost(double r);

double length,width; //? 全局变量：分别保存长方形养鱼池的长宽
double r1,r2; //? 全局变量：分别保存圆形清水池和污水池的半径
double totalCost = 0; //? 全局变量：用于保存最终结果，即总造价

int main()
{
    /*下来语句将使用键盘输入原始数据，保存到对应的原始变量中*/
    cout <<"请输入长方形的长宽：";
    cin>>length>>width;
    cout<<"请输入清水池和污水池的半径：";
    cin>>r1>>r2;
    RectCost();//调用函数RectCost计算长方形言语此造价
    totalCost += CircleCost(r1);//调用CircleCost计算清水池造价
    totalCost += CircleCost(r2);//再次调用CircleCost
    cout<<"工程总造价为："<<totalCost<<endl;
    return 0;
}