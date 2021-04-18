/*
scanf与cin，printf与cout，的区别
*/

#include <iostream>

using namespace std;

int main()
{   //scanf需要分别为变量指定格式符，scanf使用的是变量地址，cin直接用右移运算符赋值，且使用变量名即可
    int x; scanf(" %d", &x);  // 该方法等价于：cin>>x;
    float y; scanf("%d", &y); // 该方法等价于：cin>>y;
    double z; scanf("%lf", &z); // 该方法等价于：cin>>z;
    char ch; scanf("%c", &ch); // 该方法等价于：cin>>ch;
    char str[20]; scanf("%s", str); // 该方法等价于：cin>>str;

    scanf(" %d %f %lf %c %s", &x, &y, &z, &ch,str); //该方法等价于：cin>>x>>y>>z>>ch>>str
    return 0;
}

int main()
{
    //printf和scanf一样是两个参数，第一个是格式花字符串，第二个是表达式,cout可以直接是表达式，无需指定参数字符类型，程序自动识别
    int x = 10; printf("x+5", x+5); // 该方法等价于：cout<<"x+5"<<x+5
    float y = 5.5; printf("y+1=%f", y+1); // cout << "y+1" << y+1;
    double z = 5.5; printf("z=%lf", z); // cout<< "z" << z;
    char ch = "A"; printf("ch=%c", ch); // cout << "ch"<< ch;
    char str[20]="China"; printf("%s", str); // cout <<str;

    printf("%5d,%5.2f,%5.2lf,%5c,%5s",x,y,z,ch,str);
    //cout<<x<<","<<y<<","<<z<<","<<ch<<","<<str
}