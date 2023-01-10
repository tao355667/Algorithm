/*
scanf()
printf()
https://www.dotcpp.com/oj/problem1202.html
*/
#include <bits/stdc++.h>

main()
{
    char ch;
    int temp;
    int max;
    while (1)
    {

        if (scanf("%d", &temp) == 1)
        {
            //第一个数
            if (temp == 0)
                break;
            max = temp;
            // 2到后面的数
            while (temp != 0)
            {
                scanf("%d", &temp);
                if (temp > max)
                    max = temp;
            }
            printf("%d\n", max);
        }
        else
            break;
    }
}