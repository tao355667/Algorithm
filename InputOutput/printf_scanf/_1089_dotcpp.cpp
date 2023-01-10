/*
scanf()
printf()
https://www.dotcpp.com/vipstudy_acm/problem/?id=1089&class=1060
*/
#include <bits/stdc++.h>

main()
{
    int N, M;
    int sum = 0;
    int temp;
    scanf("%d", &M);
    while (M--)
    {
        scanf("%d", &N);
        sum = 0;
        while (N--)
        {
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d\n", sum);
    }
}