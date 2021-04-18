#include <iostream>
using namespace std;

int main()
{
    int x;
    cout <<"请输入一个数字："<< endl;
    cin >> x;
    if(x == 1) cout <<"Today is Monday!"<<endl;
    else if (x==2) cout <<"Today is Tuesday!"<<endl;
    else if (x==3) cout <<"Today is Thursday!"<<endl;
    else if (x==4) cout <<"Today is Wednesday!"<<endl;
    else if (x==5) cout <<"Today is Friday!"<<endl;
    else if (x==6) cout <<"Today is Saturday!"<<endl;
    else if (x==7) cout <<"Today is Sunday!"<<endl;
    else cout<<"数值超出1-7的范围"<<endl;

    return 0;
}


/*
Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday，
*/