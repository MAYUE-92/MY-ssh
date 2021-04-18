# include <iostream>

using namespace std;

int main()
{
    /*
    c语言风格，将变量x,y初始化为int类型，其中x=10，
    y没有赋值，y的值可能是以前的程序遗留下的，是不确定的
    */
    int x=10,y;

    /*
    c++风格，使用面向对象的方式赋值
    */
   int x(10),y;

   return 0;
}

int main()
{
    /* 
    c语言的符号常量，例如定义pie的值为3.14
    */
   #define pie 3.14

    /* 
    c++语言引入了新的概念：常变量
    意思为初始化后数值不能改变的变量为常变量。
    1、使用const关键字定义
    2、定义常变量必须初始化
    3、常变量只能读取和显示，不能改变，不能被再次赋值
    */
   const int x=5;
   return 0;
}