#include <stdio.h>

int ifnum;
void bubble_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    {
        //        int flag = 0;
        for (j = 0; j < len - 1 - i; j++)
        {
            ++ifnum;

            printf("if %d\n", ifnum);
            //            cout<<"if"<<++ifnum<<endl;
            if (arr[j] > arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                //                flag = 1;
            }
        }
        //        if(flag==0)
        //            break;
    }
}
int main()
{
    //    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int len = (int)sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    printf("ifnum=%d\n", ifnum);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}