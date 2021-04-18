#include <iostream>
using namespace std;

int main()
{
    int x[2][3] = {{1,3,5},{2,4,6}};
    int m,n;
    int max=x[0][0],min =x[0][0];

    for(m=0;m<2;m++)
    for(n=0;n<3;n++)
    {
        if(x[m][n]>max) max=x[m][n];
        if(x[m][n]<min) min=x[m][n];
    }
    cout<<"最大值是："<<max<<",最小值是："<<min<<endl;

    return 0;
}