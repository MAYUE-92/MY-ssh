#include <iostream>
using namespace std;

class Complex
{
	private:
    	double real,image;//实数和虚数部分
    public:
    	Complex(double x=0,double y=0){ real=x; image=y; }//构造函数
    	Complex(Complex&c){ real = c.real; image=c.image; }//拷贝构造函数
    	void Show(){ cout<< real<<"+"<<image<<"i"<<endl; }//显示复数
    	Complex operator +(Complex c)//实现复数加减
        {
            Complex result;
            result.real = real + c.real;
            result.image = image + c.image;
            return result;
        }

        Complex & operator ++()//实现前置++
        {
            real++;image++;//规则，实部与虚部均加1
            return *this;//返回前置“++”表达式结果：加1后对象的引用
        }
        Complex operator ++(int)//后置++
        {
            Complex temp(*this);
            real++;image++;
            return temp;//返回后置++表达式的结果：加1之前的对象
        }

        // bool Complex::operator==(const Complex &x)const
        // {
        //     if(real == x.real&&image==x.image)
        //         return true;
        //     else return false;
        // }
        Complex &Complex::operator=(Complex &c)
        {
            real = c.real; image = c.image;
            return *this;
        }
};