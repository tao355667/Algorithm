/*
scanf()
printf()
https://www.dotcpp.com/vipstudy_acm/problem/?id=1086&class=1057
*/
#include <bits/stdc++.h>

main()
{
    int a, b, n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
    }
}