/*
scanf()
printf()
https://www.dotcpp.com/vipstudy_acm/problem/?id=1088&class=1059
*/
#include <bits/stdc++.h>

main()
{
    int N;
    int sum=0;
    int temp;
    while (scanf("%d", &N) != EOF)
    {
        if (N == 0)
            break;
        sum=0;
        while(N--)
        {
            scanf("%d",&temp);
            sum+=temp;
        }
        printf("%d\n", sum);
    }
}