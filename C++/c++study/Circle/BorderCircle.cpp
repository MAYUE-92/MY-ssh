#include <iostream>
using namespace std;
#include "BorderCircle.h"

double BorderCircle::InnerArea()
{
    double x = CRadius();//读取半径
    return(3.14*(x-w)*(x-w));
}

double BorderCircle::BorderArea()
{
    return(CArea()-InnerArea());
}

void BorderCircle::Input()
{
    Circle::Input();//调取输入半径函数
    cin>>w;//输入边框宽度
}
