#include "Circle.h"//声明基类Circle

class BorderCircle:public Circle //公有继承
{
    public:
        double w; //宽度
        double InnerArea();//求内圆面积
        double BorderArea();//圆环面积
        void Input();//输入半径和圆环宽度
};
