#include <iostream>
#include "account.h"

using namespace std;

//存款方法
void Account::deposit()
{
    cout<<"请输入存款金额：";
    float x; cin>>x;
    money += x;
    show();
}

//定义取款方法
void Account::withdraw()
{
    cout<<"请输入取款金额：";
    float x; cin>>x;
    if(money<x) cout<<"余额不足";
    else money -= x;
    show();
}

//余额查询
void Account::show()
{
    cout<<"账号"<<a_num<<"的余额为："<<money<<"元\n\n";
}