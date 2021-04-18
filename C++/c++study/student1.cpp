#include <iostream>
using namespace std;

class Student
{
    private:
        char *c_name;//定义为字符型指针变量，用于接收字符串传递的地址
        int c_ID;
        int c_age;
        double c_score;
    public:
        void print();
        Student(char *name, int ID, int age, double score);
};

Student::Student(char *name, int ID, int age, double score)//char name[]形参用于接收实参传递过来的数组，实际是一个指针，必须定义接收字符串宽度
{
    c_name= name; //此处赋值，相当于是将实参的内存首地址赋值给了私有成员中的char* name指针变量
    c_ID = ID;
    c_age = age;
    c_score = score;
}

void Student::print()
{
    cout<<"姓名："<<c_name<<endl;//因c++对字符串处理的特殊机制，读取指针变量的地址，实际输出为这个字符串。要读取实际的地址的值时，需要强制转换指针类型
    cout<<"ID:"<<c_ID<<endl;
    cout<<"年龄:"<<c_age<<endl;
    cout<<"成绩:"<<c_score<<endl;  
}

int main()
{
    char name[]= "zhangsan";  //对字符串数组name进行赋值
    /*
    此时实参变量名name相当于是字符串name的首地址。
    如果直接写入字符串，而不是变量名，c++会将实参字符串看作是字符串常量
    因为构造函数中，c++将char name[] 自动编译为一个指针，也就是char* name[]，无法将一个字符串常量负值给一个字符型指针。故而报错
    */
    Student stu(name, 8, 12, 89); //不能在实参name的位置写字符串，会报错。只能间接传递
    stu.print();
    return 0;
}