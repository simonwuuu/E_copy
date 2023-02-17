#include<stdio.h>
#define MAXSIZE 10     /*     最大排序个数    */
typedef struct
{
    int r[MAXSIZE];
    int length;
}SqList;

void swap(int arr[],int i,int j);

void heapify(int tree[], int n, int p);
void build_heap(int tree[], int n);

int partion(int arr[], int low, int high);
void QSort(int arr[], int low, int high);

void merge(int arr[], int low, int mid, int high, int temp[]);

// 排序算法
void Bubble_sort(int arr[],int len);
void Select_sort(int arr[],int len);
void Insert_sort(int arr[],int len);
void Shell_sort(int arr[],int len);
void Quick_sort(int arr[],int len);
void Heap_sort(int tree[],int len);
void Msort(int arr[], int low, int high, int temp[]);