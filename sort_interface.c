#include"sort.h"
#include<stdio.h>
void print_sort(int arr[],int len)
{
    for(int i =0;i<len;i++)
    {
        printf("%d  ",arr[i]);
    }
}
 int main()
 {
     printf("请输入一组数字\n");
     int A[MAXSIZE];
     int len=0;
     while(1)
     {
         scanf("%d",&A[i]);
         len++;
         if(len>MAXSIZE)
         break;
    }
    printf("请选择排序类型\n");
    printf("********1:   冒泡 排序  ********\n");
    printf("********2:   选择 排序  ********\n");
    printf("********3:   插入 排序  ********\n");
    printf("********4:   希尔 排序  ********\n");
    printf("********5:   快速 排序  ********\n");
    printf("********6:   堆 排序  ********\n");
    printf("********7:   归并 排序  ********\n");
    int sort_type = -1;
    scanf("%d",&sort_type);
    switch(sort_type)
    {
        case 1:
            printf("你选择了冒泡排序,结果是\n");
            Bubble_sort(A,len);
            print_sort(A,len);
            break;
        case 2:
            printf("你选择了选择排序,结果是\n");
            Select_sort(A,len);
            print_sort(A,len);
            break;
        case 3:
            printf("你选择了插入排序,结果是\n");
            Insert_sort(A,len);
            print_sort(A,len);
            break;
        case 4:
            printf("你选择了希尔排序,结果是\n");
            Shell_sort(A,len);
            print_sort(A,len);
            break;
        case 5:
            printf("你选择了快速排序,结果是\n");
            Quick_sort(A,len);
            print_sort(A,len);
            break;
        case 6:
            printf("你选择了堆排序,结果是\n");
            Heap_sort(A,len);
            print_sort(A,len);
            break;
        case 7:
            printf("你选择了归并排序,结果是\n");
            int temps[len];
            Msort(A,0,len-1,temps);
            print_sort(A,len);
            break;
        default:
            printf("输入错误\n");
            break;






    }
     
 }