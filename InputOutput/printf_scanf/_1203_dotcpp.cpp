/*
scanf()
printf()
https://www.dotcpp.com/oj/problem1203.html
*/
#include <bits/stdc++.h>
#define pi 3.1415
main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        double rad;
        scanf("%lf", &rad);
        printf("%f\n", pi * rad * rad);
    }
}