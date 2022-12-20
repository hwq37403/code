//抽屉原理

#include<stdio.h>

int main(void)
{
    long long n;
    long long a;
    long long sum;
    long long max=-1;
    long long m;
    long long i;

    scanf("%lld",&m);

    while (m--)
    {
        scanf("%lld",&n);
        max = -1;//可以这样先给max附一个初值
        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%lld",&a);
            sum += a;
            if (a>max)
            {
                max = a;
            }
        }

        if ((sum - max) >= (max - 1))//把最多的当成隔板，则其他糖果最少要max-1颗来填补空缺
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}