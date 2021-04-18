#include "1.h"

//extern double length,width;//声明外部全局变量：分别保存长方形养鱼池的长宽
//extern double totalCost;//声明外部全局变量：用于保存最终计算结果，即总造价

void RectCost()
{
    double cost;
    cost = length*width*10; //直接读取全局变量length和width中的数据
    totalCost+=cost;//将计算结果直接累加到全局变量totalCost中。
}

double CircleCost(double r)
{
    double cost;
    cost = 3.14*r*r*10;
    return cost;
}