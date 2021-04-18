#include <iostream>

using namespace std;

int main()
{
    double x; //定义一个变量X
    cout << "请输入一个单位为g的数值：";
    cin >> x;
    cout << "换算结果等于：" << x*5 << "克拉,";
    cout << "等于：" << x/31.1034807 << "盎司" << endl;
    return 0;
}