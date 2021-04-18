#include <iostream>
using namespace std;

void fun(int p=10);//在申明函数fun时，指定文件作用域的形参p的默认值为10

int main()
{
	fun(); //使用文件作用域的默认值，函数fun的显示结果为10
	{
		void fun(int p=20);//再次申明函数fun，将具有块作用域的形参p的默认值为20
		fun(); //使用块作用域（局部优先），fun的显示结果为20
	}
	return 0;
}

void fun(int p) //在申明函数时，已经指定了p的默认值，此时不能再指定
{
	cout<<p<<endl; //显示形参p接收到的实参值
}