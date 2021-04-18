#include <iostream>
using namespace std;

int main()
{
    /*
    求一维数组的总和和平均值
    */
    float y[2][3] = {{1.0,3.5,5.2},{2.2,4.9,6.5}}; //
    int m,n;
    float sum=0;

    for(m=0;m<2;m++)
    {
        for(n=0;n<3;n++)
            sum +=y[m][n];
    }
    float average;
    average = sum/6;

    cout<<"数列的元素的和为："<<sum<<"平均值为："<<average<<endl;

    return 0;
}