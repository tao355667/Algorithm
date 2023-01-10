/*
scanf()
printf()
https://www.dotcpp.com/vipstudy_acm/problem/?id=1087&class=1058
*/
#include <bits/stdc++.h>

main()
{
    int a, b;
    // while (scanf("%d%d", &a, &b) == 2)
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a == 0 && b == 0)
            break;
        printf("%d\n", a + b);
    }
}