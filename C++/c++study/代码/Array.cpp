#include <iostream>
using namespace std;

int main()
{
    int m,n;
    int x[3];
    for(n=0;n<3;n++)
        cin>>x[n];  
    for(n=0;n<3;n++)
        cout<<"一维数组y："<<x[n]<<",";
        cout<<endl;

    double y[2][3];
    for(m=0;m<2;m++)
    {
        for (n=0;n<3;n++)
            cin>>y[m][n];
    }     
    for(m=0;m<2;m++)
    {   
        for(n=0;n<3;n++)
        cout<<"二维数组y："<<y[m][n]<<",";
        cout<<endl;
    }
    return 0;
}