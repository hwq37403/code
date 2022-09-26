 #include <iostream>
#include  <vector>
    /* 斐波那契的递归函数 */    int Fbi(int i)    {        if( i < 2 )            return i == 0 ? 0 : 1;        return Fbi(i-1)+ Fbi(i-2);/*这里Fbi就是函数自己，它在调用自己 */    }    int main()    {        int i;        for(int i = 0;i < 40;i++)            printf("%d ", Fbi(i));        return 0;    }