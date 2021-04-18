#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    int *p;
    /* 函数malloc返回所分配内存的首地址，其类型为“void”，需转为“int*” */
    p = (int *)malloc(10*sizeof(int));//动态分配一个含有10个元素的int型数组

    for(int n=0;n<10;n++)
    {
        *(p+n) = n*n;
        printf("%d\n",p[n]);
    }
    free(p);
    system("pause");
    return 0;
}