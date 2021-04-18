#include <iostream>
using namespace std;

int main()
{
    int N; //定义一个int变量N
    cin >> N; //键盘输入要显示数列的前多少项，将数值保存在变量N中

    int *p = new int[N]; //动态创建包含N个元素的数组，用于保存数列的前N项
    p[0] = 0; p[1] = 1; //指定数列的前2项

    int n; //为循环语句定义好循环变量n
    for(n=2; n<N;n++) //使用循环结构计算处剩余的数列项
        p[n] = p[n-1] + p[n-2];//每一项等于其前2项之和
    
    for(n=0; n<N;n++) //使用循环结构遍历显示数组
    {
        cout << p[n] << ","; //各数列项用逗号隔开
        if((n+1)%5 == 0) cout<<endl; //一行显示5项，每5项一次换行
    }

    delete[]p; //数组使用结束，动态释放其内存空间
    return 0;
}