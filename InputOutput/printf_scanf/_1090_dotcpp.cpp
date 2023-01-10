/*
scanf()
printf()
https://www.dotcpp.com/vipstudy_acm/problem/?id=1090&class=1061
*/
#include <bits/stdc++.h>

main()
{
    int N, M;
    int sum = 0;
    int temp;

    while (scanf("%d", &N) == 1)
    {
        sum = 0;
        while (N--)
        {
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d\n", sum);
    }
}