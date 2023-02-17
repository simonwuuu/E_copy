#include"sort.h"
void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    L->r[i] = arr[j];
    L->r[j] = temp;
    
}

// 排序算法
void Bubble_sort(int arr[],int len)
{
    int i,j;
    bool exchange_flag = true;
    for(i=0; i<len-1 && exchange_flag; i++)
    {
        exchange_flag = false;
        for(j=len-1;j>=i;j--)
        {
            if(arr[j]<L->arr[j-1])
            {
                swap(arr,j,j-1);
                exchange_flag = true;
            }
        }
    }
}

void Select_sort(int arr[],int len)
{
    int i,j,min;
    for(i=0;i<len-1;i++)
    {
        min = i;
        for(j=i+1;j<len;j++)
        {
            if(arr[min]>arr[j])
            {
                min =j;
                swap(arr,i,j);
            }
        }
    }
}

void Insert_sort(int arr[],int len)
{
    int i,j,insert_pos;
    int temp;
    for(i=0;i<len;i++)
    {
        insert_pos = i;
        temp = arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(arr[insert_pos]<arr[j])
           {
            insert_pos = j;
            arr[j+1] = arr[j];
            } 
        }
        arr[insert_pos] = temp;
    }
}

void Shell_sort(int arr[],int len)
{
    int i, j, k, tmp;
	int gap = len;
 
	do{	
		//gap的选择可以有多中方案，如gap = gap/2,这里使用的是业界统一实验平均情况最好的，收敛为1
		gap = gap / 3 + 1;
		for (i = gap; i < len; i += gap)  //分成len/gap组
		{
			//每组使用插入排序
			k = i;
			tmp = arr[k];
			for (j = i - gap; (j >= 0) && (arr[j] > tmp); j -= gap){
				arr[j + gap] = arr[j];
				k = j;
			}
			arr[k] = tmp; 
		}
	} while (gap > 1);
}


//快速排序：
/*
选择一个基准，将基准移动到数据中间，使得左边的数据都小于基准，右边的数都大于基准
递归划分，当数据元素等于1个的就是一个的时候就是有序的了
*/

int partion(int arr[], int low, int high)
{
    int privot = arr[low];          //选择第一个元素作为基准
    //推动左右指针向中间移动，即将基准移动到中间，low和high中的某一个一定是指向基准的
    while (low < high)
    {
        while ((low < high) && arr[high] >= privot)             //如果右边的数比基准大，则不用移动，否则将其交换到左边去
            high--;
        swap(arr, low, high);
        while ((low < high) && arr[low] <= privot)
            low++;
        swap(arr, low, high);
    }
    return low;         //当low=high的时候则停止划分，由于low和high在移动的过程中，总有一个是指向基准的，这里返回，low其实就是基准在数组中的索引
}
//递归划分，当划分到一个元素的时候，子数组就是有序的
void QSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int idx = partion(arr, low, high);
        //递归划分划分左右子数组，让左右子数组有序
        QSort(arr, low, idx-1);
        QSort(arr, idx+1, high);
    }
}

void Quick_sort(int arr[],int len)
{
     QSort(arr, 0, len - 1);
}

 
void heapify(int tree[], int n, int p)
/*
n表示树的节点个数
p表示要处理的当前节点的下标
该函数的功能是：面对一个仅有节点p为，不符合堆的性质的情况。如果在节点p插入一个新元素，插入比其子节点小的数，就破坏了堆的性质（父节点大于子节点），因此需要对堆进行调整：
调整的思路是如果：
    如果子节点比父节点大，则将其与子节点交换，使得父节点位置满足堆的性质，但是由于交换可能会破坏子节点的堆的性质，因此要递归地对子节点进行堆化
    因为是递归，所以要考虑递归的出口，当节点p达到最后一个叶子节点为止
*/
{
    //递归出口
    if (p >= n)return;          //到达最后一个叶子节点
    //计算左右节点的索引，完全二叉树满足的性质
    int c1 = 2 * p + 1;
    int c2 = 2 * p + 2;
    int max =-1;
    //判断父节点和左右孩子节点中的最大值
    if (c1 < n && tree[c1] > tree[p])
        max = c1;
    if (c2<n && tree[c2] > tree[p])   //c1,c2小于n防止叶子节点c1,c2不满足而越界
        if(max = !-1 && tree[c2]>tree[c1])  //将子结点中最大的那个索引给max
             max=c2;
 
    if (max != -1)    //交换,叶就是说子树不满足堆父大于子的情况，交换，由于交换改变了子树的父节点，因此需要对子树要调整
    {
        swap(tree, max, p);     
        heapify(tree, n, max);//同时对特的子树叶同时做一个heapify
    }
    
}
void build_heap(int tree[], int n,)
/*
面对对于一个完全无序的数组，如何构建出一个堆：
思路：从最后一个节点的父节点开始做heapfy，直到根节点，就可以将无序数组组织成堆的形式
*/
 
{ 
     
    int last_node = n - 1;
    int parent = (last_node-1) / 2;     //父节点的位置计算
    for (int i = parent; i >= 0; i--)
    {
        heapify(tree, n, i);
    }
    return;
}
 
 
/*
堆排序：
堆排序将问题分解成了2个步骤：
先建立一个堆，在依据堆顶为最大值的性质，循环抽出堆顶最大值交换到堆的末尾位置，有序序列，由于抽出最大值破坏了堆的性质，因此要重新heapify
而在建立堆的过程中，首先面临的是一堆无序的数，需要从最后一个节点的父节点开始heapify，才能使得整个数组变成堆，其中heapify的过程就是递归将调整父节点子节点的过程
*/
 
 
void Heap_sort(int tree[], int n)
{
    //先建立堆
    build_heap(tree, n);
    //由于堆顶总是放的是最大值，因此我们将堆顶元素与堆的最后一个元素做交换
    //做交换后，前面的n-1个数的堆的性质被破坏，重新做一个heapify
    for (int i = n - 1; i >= 0; i--)        //从最后一个元素开始交换
    {
        swap(tree, i, 0);
        heapify(tree, i, 0);     //i==n-1，前面的n-1个元素构成的堆被破坏，重新从堆顶heapify,
    }
}










//归并排序
/*
使用分治思想：
假设两个子数组是有序的，将其按照有序序列合并，合并组成新的有序数组，再与其他部分合并
*/
void merge(int arr[], int low, int mid, int high, int temp[])
{
    int i = low;         //左子数组开始位置
    int j = mid + 1;    //右子数组开始位置
    int t = 0;          //临时空间指针
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[t++] = arr[i++];
        else
            temp[t++] = arr[j++];
    }
    //将左边剩余元素填充进temp中
    while (i <= mid)
        temp[t++] = arr[i++];
    //将右边子数组剩余部分填充到temp中
    while (j <= high)
        temp[t++] = arr[j++];
 
    //将融合后的数据拷贝到原来的数据对应的子空间中
    t = 0;
    while (low <= high)
    {
        arr[low++] = temp[t++];
    }
    
}
void Msort(int arr[], int low, int high, int temp[])
{
    if (low < high)             //只有low==high为一个元素的时候不用再细分自分组，融合
    {
        int mid = (low + high) / 2;
        //左子数组融合排序
        MSort(arr, low, mid, temp);
        //右子数组融合排序
        MSort(arr, mid + 1, high, temp);
        //已经排序好的子数组有序融合
        merge(arr, low, mid, high, temp);
    }
 
}