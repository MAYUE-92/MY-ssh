#include <iostream>
#include "account.h"
#include <string.h>

using namespace std;

int main()
{
    cout<<"请输入开户信息（账号、户名、存款金额）:";
    //定义3个临时变量，用于保存账号、户名、存款金额
    int x; char str[10]; float y; 
    cin>>x>>str>>y;

    //创建对象并对数据成员进行赋值操作
    Account obj(x,str,y);
    

    int choice;
    while (true)
    {
        cout<<"1-存款\n2-取款\n3-查询余额\n0-退出\n请选择：";
        cin>>choice;
        if(choice==0) break;
        if(choice==1) obj.deposit();
        else if(choice==2) obj.withdraw();
        else if(choice==3) obj.show();
    }
    return 0;
}