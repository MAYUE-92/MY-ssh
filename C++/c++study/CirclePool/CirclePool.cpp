#include <iostream>
using namespace std;

class CirclePool
{
    private:
        static double price;//单价
        double r;
    public:
        /*构造函数，初始化单价price和半径r,
        在构造函数中，不能直接对常数据对象初始化,必须使用初始化列表的形式 */
        CirclePool(double p = 0)
        {
            r = p;
        }
        double GetPrice()
        { return price; }
        //对半径进行检查
        void CheckRadius(double x)
        {
            if (x<=0)
            {
                r = 0;
                cout<<"数据输出错误"<<endl;
            }
            else r =x;
        }
        //读取检查后的半径
        double GetRadius()
        { return r; }
        //计算圆形水池的造价
        double GetCost()
        { return(3.14*r*r*price); }
};
double CirclePool::price = 10;

int main()
{
    double totalcost = 0;
    double r1,r2;
    cin>>r1>>r2;
    CirclePool pool1(r1),pool2(r2);

    pool1.CheckRadius(r1);
    totalcost += pool1.GetCost();
    pool2.CheckRadius(r1);
    totalcost += pool2.GetCost();

    cout<<totalcost<<endl;
    return 0;
}