//一个在不同作用域为函数形参指定不同默认值的演示实例
#include <iostream>
using namespace std;

void fun(int p=10); //指定文件作用域的形参默认值：10

int main()
{
    fun(); //使用文件作用域的默认值，函数fun的显示结果：10
    {
        void fun(int p=20); //指定块作用域形参默认值：20
        fun(); //使用块作用域的默认值（局部优先），fun显示结果：20
    }
    return 0;
}

void fun(int p) //因为第五行已经指定了文件的作用域的默认值，此处不能再指定
{
    cout<<p<<endl; //显示形参p接收到的实际值
}