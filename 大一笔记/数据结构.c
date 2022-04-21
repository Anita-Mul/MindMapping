********************************************************************************************************************************************************
****************************************************************数据结构和算法**************************************************************************
********************************************************************************************************************************************************	
程序设计常用五大算法
1.分治法
  将一个难以直接解决的大问题分解成规模较小的相同问题，以便分而治之
  分解：选取基准元素，将左右两侧进行划分
  解决：将左右两个问题解决
  合并：将解决好的问题合并
  1）二分法
  主要是用来解决数组中元素有序，元素位置的问题
2.动态规划法
  最优解问题
  问题中的状态必须满足无后效性，下一刻的状态只与当前的状态有关，而与当前状态的之前状态无关
  可以用贪心算法解决的问题，一般情况下都可以用动态规划。因此，不妨从 “状态”、“状态转移方程” 的角度考虑一下，使用动态规划的思路解决这道问题。
3.贪心算法
  做出在当前看来是最好的选择，是某种意义上的局部最优解
  贪心算法和动态规划相比，它既不看前面（也就是说它不需要从前面的状态转移过来），也不看后面（无后效性，后面的选择不会对前面的选择有影响），因此贪心算法时间复杂度一般是线性的，空间复杂度是常数级别的。

————————————————————————————————————————————————————————————————————————————————————————————————————————————

1.什么叫分配内存，什么叫释放内存
分配内存：操作系统把某一块内存的使用权力分配给该程序
释放内存：操作系统把分配给该程序的内存空间的使用权力收回，该程序就不能再使用这一块内存空间
附注：释放内存不是把该内存的内容清0

2.变量为什么必须得初始化：变量的本质就是内存中的一段储存空间
不初始化，该变量通常就是垃圾值

3.详细说明系统是如何执行int i = 5; 的
Vc++6.0系统请求操作系统为i分配空间
操作系统会在内存中寻找一块空闲的区域，把该区域当作i来使用
vc++6.0会把i和这块空闲区域关联起来，今后对i操作就是对这块区域的空间操作
把5存储到字母i关联的内存区域
程序终止之后，分配的空间释放掉了

附注：所谓的内存区域就是一块储存单元

4.long %ld   double  %lf   float  %f

5.内存一个字节一个编号（地址）
  指针就是地址  指针变量是存放内存单元编号的变量   指针变量和指针是两个完全不同的概念
6.静态变量是由操作系统自动分类，自动释放，程序员无法在程序运行的过程中手动分配，也无法在程序运行的过程中手动释放
  静态变量是在栈中分配的
  函数终止之后，静态变量的储存空间才会被系统释放
  
  动态变量是由程序员手动分配，手动释放，程序员可以在程序运行的过程中手动分配，也可以在程序运行的过程中手动释放
  动态变量是在堆中分配的
7.int *p; *p = 10;   错误的  p是一个不知道的垃圾值
  int *p; int **q; q = &p; 正确的
  int *p; int i = 5; p = &t; *p = 10;  正确的

8.else和离它最近的if对应
=======================================================================================
1.C语言的结构：顺序结构，选择结构，循环结构
2.逗号运算符级别最低，赋值运算符级别倒数第二
3.算法：可以没有输入，但一定要有输出
4.bit是位，0或1  byte是字节，一个字节 = 8个位
5.编译预处理不是C语言的一部分，不占运行时间，不要加分号，C语言编译的程序称为源程序，又称为编译单位，以ASCII数值储存在文本文件中
6.vc++    .c 和.obj文件是无法运行的，只有.exe文件才可以运行
7.标识符分为关键字，预定义标识符，用户标识符
C语言的标识符可以分为以下三类：
一、关键字（可以用来定义变量类型或语句中的for else之类）
如：int if else 等等
二、预定义标识符（预定义就是函数的头文件，所以包括函数和定义函数头文件的）
如:printf define scanf include等等
三、用户标识符
如：a number red 等等 

8.C语言只有八进制，十进制，十六进制，没有二进制，但在运行时，所有的
都要转化为二进制
9.C语言中的八进制以0开头，十六进制0x开头
10.小数点两边有一个是0的话，可以不用写
.1    1.
11.%两边必须要求是整数
12.运算符优先级
13.八进制转义字符\141		十六进制转义字符\x6d
14.
int x = 017;
%d  15
%o  17
%#o 017
%x  11
%#x 0x11

15.%5d   是数字加上空格一共5个格子
16.float就是保留小数点后六位
16.scanf("%2d%4d%d");  //如果输入1234567 x = 12  y = 3456   z = 7
   scanf("%2d%4d%d");  //如果输入1 234567  x = 1   y = 2345   z = 67
   scanf("%*d");  //跳过这个数据
17.如果是int取小整，+0.5变到下一位    4.6 + 0.5 = 5.1
y = (int)(x * 100 + 0.5) / 100.0  //保留两位，对第三位四舍五入
y = (int)(x * 1000 + 0.5) / 1000.0  //保留三位，对第四位四舍五入
y = (int)(x * 10000 + 0.5) / 10000.0  //保留四位，对第五位四舍五入



————————————————————————————————————————————————————————————————————————————————————————————————————————————————

数据结构的时间复杂度和时间频度
时间频度：语句执行的次数T(n)
时间复杂度：是受运算次数T(n)表达式中受n的变化影响最大的那一项n^3 + n^2 + n^1 时间复杂度就是O(n^3)

===============
   排序算法
===============   
1.冒泡排序（第一次遍历把最大的输在最后，下次这个最大的就不管了）
# include <stdio.h>
int main(void)
{
    int a[] = {900, 2, 3, -58, 34, 76, 32, 43, 56, -70, 35, -234, 532, 543, 2500};
    int n;  //存放数组a中元素的个数
    int i;  //比较的轮数
    int j;  //每轮比较的次数
    int buf;  //交换数据时用于存放中间数据
    n = sizeof(a) / sizeof(a[0]);  /*a[0]是int型, 占4字节, 所以总的字节数除以4等于元素的个数*/
    for (i=0; i<n-1; ++i)  //比较n-1轮
    {
        for (j=0; j<n-1-i; ++j)  //每轮比较n-1-i次,
        {
            if (a[j] > a[j+1])
            {
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
            }
        }
    }
    for (i=0; i<n; ++i)
    {
        printf("%d\x20", a[i]);
    }
    printf("\n");
    return 0;
}
	
2.无递归，无堆栈的快速排列法
/**
	就像题目中所描述，如果有递归，就会有堆栈，就会消耗大量内存，如何找出一个没有递归的方法是我们现在要着重解决
	首先要理解快速排序的本质，就是通过不断确定一个数的具体位置来排序的方法，如果确定了这个数，就不管了，所以就要对这个
	数进行标记，是使用book数组吗？如果使用book数组，记录下已经确定好位置的下标，也是一种记录下标的方法
	通过我仔细思考，这个问题就是分治算法，通过不断解决每个小问题，大问题得以解决，而下面的这种取负数的方法是一种更为
	巧妙的方法，先处理了每段前部分的数字，再处理每段后部分的数字，负数就是表示处理过
	

**/
#define YES 1
#define NO 0
#define ALWAYS 1

#define SWAP(x, y) (int t; t = x; x = y; y = t;)

void sort(int x[], int n) 
{
    int sorted;
    int split;
    int next;
    int key;
    
    x[n] = -1;//把这个数组里最后一个元素的下一个元素设为1，是间断点
    for(sorted = 0; sorted < n; sorted++)
    {
        while(x[sorted] > 0)  //这个循环直到第一个数字也被设成负数，就是key之前的数字全被排好
        {
            key = x[sorted];  //key之后都是定好的一个元素
            split = sorted;   //以下步骤就是找出key应该放入的地方split
            for(next = sorted + 1; x[next] > 0; next++)  //next的作用就是不断查找下一个元素
            {
                ///老泪纵横呀，我终于懂了，如果有一个元素比sorted小，这个就应该排在1号位，其余依次排在2号，3号位，最后如果有3个元素比sorted小，split
				///就该指在3，再将0和3对应的元素互换就可以了
				if(x[next] < key)//如果找出一个比key小的元素
                {
                    split++;//split含义是有split个元素比key小，还有一个含义是key应该放在split处，
                            
                    SWAP(x[split], x[next]);  //把比sorted小的元素换到他合适的位置上来
                }
            }
            SWAP(x[sorted], x[split]);
            x[split] = -x[split];
        }
        x[sorted] = -x[sorted];  //这一步的作用就是把split之前全为负数的数字设成正数，再次把split之后的数字排好
    }
}

3.快速排列
  左右指针遍历交换法
void quickSort(int *a,int m,int n)
{
    int i=m,j=n;
    int value=a[m];
    if(i<j)
    {
        while(i<j)
        {
            while(i<j&&a[j]>=value)
            {
                  j--;
            }
            if(i<j)
            {
                  a[i++]=a[j];
            }
            while(i<j&&a[i]<value)
            {
                  i++;
            }
            if(i<j)
            {
                 a[j--]=a[i];
            }
        }
        quickSort(a,m,i-1);
        quickSort(a,i+1,n);
        a[i]=value;
    }
}
int main()
{
    int a[]={9,8,7,6,5,4,3,2,1,10};
    quickSort(a,0,9);
    for(int i=0;i<10;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}

4.选择排序(选择它后面的最小值，和第一个交换)
#include <stdio.h>
int main()
{
    int i,j,t,a[11];    //定义变量及数组为基本整型
    printf("请输入10个数：\n");
    for(i=1;i<11;i++)
        scanf("%d",&a[i]);    //从键盘中输入要排序的10个数字
    for(i=1;i<=9;i++)
	{
        for (j=i+1;j<=10;j++)
		{
            if(a[i]>a[j])    //如果前一个数比后一个数大，则利用中间变量t实现两值互换
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
		}
	}
    printf("排序后的顺序是：\n");
    for(i=1;i<=10;i++)
        printf("%5d", a[i]);    //输出排序后的数组
    printf("\n");
    return 0;
}


5.插入排序
#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0


//排序，二分插入法
//二分查找是一种算法，其输入是一个有序的元素列表。如果要查找的元素包含在列表中，二分查找将返回其位置，否则返回NULL
//我懂了，就是第一个元素肯定是排好顺序的，把第二个拿出来，把第一个移到第二个，把拿出来的安到第一个
#define SIZE sizeof(int) / sizeof(char)

void sort(int input[], int n)
{
    int current, pos;
    int low, high, mid;
    int x;
	
    //不断计算已排好序的下一个元素应该插在已排好序元素中的哪一个位置，所以分为找位置和移动元素两步
	//找元素又分为小于已排好序的元素（pos = 0）  大于已排好序的元素（pos = -1不移动）   在排序元素之间（二分法寻找）
	//移动元素的话，有移动函数
	
    for(current = 1; current < n; current++)    //current相当于排序数组中元素的个数，刚开始，这个排序数组中只有一个元素input[0]
    {											//current也相当于数组中已排好序元素的下一个元素
        x = input[current];  //开始检查current元素
        pos = -1;    //如果pos = -1；意味着不要移动
        if(x < input[0])   //如果current元素比第一个元素小，让0之后的元素往后移动一格，让current元素到0上
            pos = 0;
        else if(x <= input[current - 1])  //如果这个元素小于等于最后一个元素，用二分法找到这个元素应该插到哪两个数之间
        {
            low = 0;
            high = current - 1;
            while(high - low > 1)  //因为最后找出的是pos应该在哪两个数之间，所以相减大于1
            {  //low和high是应该插到的两个数
                mid = (low + high) / 2;
                if(x >= input[mid])
                    low = mid;
                else
                    high = mid;
            }
            pos = low + 1;
        }
        if(pos >= 0)
        {
            memmove((void *)&input[pos + 1], (void *)&input[pos], SIZE *(current - pos));  //将pos后面的current - pos元素从pos移到pos+1
            input[pos] = x;  
        }
    }
}



6.希尔排序
/*
	希尔排序就是选择一个增量，如果这个增量下2个数字，就让这每两个数字排好序，不断缩小增量，直到全部排好
*/

void shellSort( long int array[], int length)
{
    int i;
    int j;
    int k;
    int gap;    //gap是分组的步长
    long int temp;   //希尔排序是在直接插入排序的基础上实现的,所以仍然需要哨兵
    for(gap=length/2; gap>0; gap=gap/2)
    {
        //以GAP为间隔分组
        for(i=0; i<gap; i++)
        {
            /*
              每一组做插入排序
            */
            for(j=i+gap; j<length; j=j+gap)
            {
                //如果当前元素比这一组中的前一个元素要小
                if(array[j] < array[j - gap])
                {
                    //记录当前这个更小的元素 temp
                    temp = array[j];    //哨兵
                    k = j - gap;
                    //把这一组中之前所有比temp大的元素都往后挪一个位置
                    while(k>=0 && array[k]>temp)
                    {
                        array[k + gap] = array[k];
                        k = k - gap;
                    }
                    //把挪出来的空位，放入temp
                    array[k + gap] = temp;
                }
            }
        }
    }
}

7.堆排序（需要用到数）
#include <stdio.h>
#include <stdlib.h>

void swap(int *arr,int i, int k) 
{
    int temp = arr[i];
    arr[i] = arr[k];
    arr[k] = temp;
}


void max_heapify(int *arr, int start, int end) 
//这个树是0开始排的
{
    //建立父节点下标和子节点下标
    int dad = start;

    int son = dad * 2 + 1;

    while (son <= end) 
    {   //若子节点下标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
        {
            son++;
        
        }

        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕,直接跳出
        {
            return;
        }   
        else 
        {   //否则交换父子节点的值再继续左右子节点值得比较
            swap(arr, dad, son);
            printf("dad=%d--son=%d\n",dad,son);
            dad = son;
            son = dad * 2 + 1;
        }
            
    }
}

void heap_sort(int *arr, int len) 
{
    int i;
    //初始化，i从最后一个父节点开始调整  先把这个树排好顺序
    for (i = len / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, i, len - 1);
        
    }

    for (i = len - 1; i > 0; i--)   //最上头是最大的，把最上头的交换到最末尾
    {
        swap(arr,0, i);

        max_heapify(arr, 0, i - 1);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,3,8,1,6};

    int len = sizeof(arr) / sizeof(int);

    heap_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
        
    printf("\n");
    
    return 0;
}

8.桶排序：有一堆按顺序排好的桶，就是把要排序的数字放到桶里，再输出桶里的东西
#include <stdio.h>
    int main()
    {
        int book[1001],i,j,t,n;
        for(i=0;i<=1000;i++)
            book[i]=0;
        scanf("%d",&n);//输入一个数n，表示接下来有n个数
        for(i=1;i<=n;i++)//循环读入n个数，并进行桶排序
        {
            scanf("%d",&t);  //把每一个数读到变量t中
            book[t]++;  //进行计数，对编号为t的桶放一个小旗子
        }
        for(i=1000;i>=0;i--)  //依次判断编号1000~0的桶
            for(j=1;j<=book[i];j++)  //出现了几次就将桶的编号打印几次
                 printf("%d ",i);
        getchar();getchar();
        return 0;
    }

10.基数排序(看不懂)
   按各位十位百位依次入桶，出来就是有序的
#include <stdio.h>
#include <string.h>

/* 获取输入数字的索引值,dec指定数字的位数,3代表百位数,order指定需要获取哪一位的索引,1代表个位,2代表十位,3代表百位 */
int get_index(int num, int dec, int order)
{
    int i, j, n;
    int index;
    int div;

    /* 根据位数,循环减去不需要的高位数字 */
    for (i=dec; i>order; i--) {
        n = 1;
        for (j=0; j<dec-1; j++)
            n *= 10;
        div = num/n;
        num -= div * n;
        dec--;
    }

    /* 获得对应位数的整数 */
    n = 1;
    for (i=0; i<order-1; i++)
        n *= 10;

    /* 获取index */
    index = num / n;

    return index;
}

/* 进行基数排序 */
void radix_sort(int array[], int len, int dec, int order)
{
    int i, j;
    int index;     /* 排序索引 */
    int tmp[len];  /* 临时数组,用来保存待排序的中间结果 */
    int num[10];   /* 保存索引值的数组 */
    memset(num, 0, 10*sizeof(int));  /* 数组初始清零 */
    memset(tmp, 0, len*sizeof(int)); /* 数组初始清零 */

    if (dec < order) /* 最高位排序完成后返回 */
        return;

    for (i=0; i<len; i++) {
        index = get_index(array[i], dec, order);  /* 获取索引值 */
        num[index]++;  /* 对应位加一 */
    }

    for (i=1; i<10; i++)
        num[i] += num[i-1]; /* 调整索引数组 */

    for (i=len-1; i>=0; i--) {
        index = get_index(array[i], dec, order);  /* 从数组尾开始依次获得各个数字的索引 */
        j = --num[index];  /* 根据索引计算该数字在按位排序之后在数组中的位置 */
        tmp[j] = array[i]; /* 数字放入临时数组 */
    }

    for (i=0; i<len; i++)
        array[i] = tmp[i];  /* 从临时数组复制到原数组 */

    printf("the %d time\n", order);
    for (i=0; i<30; i++)
        printf("%d  ", array[i]);
    printf("\n");

    /* 继续按高一位的数字大小进行排序 */
    radix_sort(array, len, dec, order+1);

    return;
}

int main(int argc, char *argv[])
{
    int i;
    int array[30] = {258, 976, 515, 337, 359, 701, 916, 494, 303, 175,
                        677, 825, 131, 560, 147, 254, 759, 814, 917, 382,
                        452, 114, 873, 585, 881, 127, 819, 658, 461, 435};

    int len = 30;  /* 测试数据个数 */
    int dec = 3;   /* 数据位数,3代表3位数 */
    int order = 1; /* 排序的位数,1代表个位、2代表十位、3代表百位 */

    printf("before\n");
    for (i=0; i<30; i++)
        printf("%d  ", array[i]);
    printf("\n");

    /* 排序函数,从个位开始 */
    radix_sort(array, len, dec, order);

    printf("final\n");
    for (i=0; i<30; i++)
        printf("%d  ", array[i]);
    printf("\n");

    return 0;
}

11.合并排序
#define SIZE sizeof(int) / sizeof(char)
/*
    合并排序：把要排序的资料分成大约相等的两组，把这两组的顺序排好后，通过合并使它成为一个全部都排好的结果
*/

void sort(int [], int);
void mergesort(int [], int [], int, int);
void merge(int [], int [], int, int, int);


void sort(int x[], int n)
{
    int *work;
    work = (int *)malloc(n * SIZE);
    mergesort(x, work, 0, n - 1);
    free(work);
}
/**
	你意识到递归的强大了吗？
	分治法：其实如果遇到分治算法，很容易就想到将数组通过不断分割成小部分，将这些小部分排好序，可是将这些小部分排好序
	        之后怎么办，就是将两个排好序的小部分排好序合成一个大部分
	这两个小部分排好序合成一个大部分的方法，可以快速排序，也可以使用从前到后指针选出最大或最小的元素方法，输入到book数组
	输入完成之后，移动到fist数组中
	
**/

void mergesort(int x[], int work[], int first, int last)  //分成两部分排序
{
    int mid;
    if(first < last)
    {
        mid = (first + last) / 2;
        mergesort(x, work, first, mid);
        mergesort(x, work, mid + 1, last);
        merge(x, work, first, mid, last);
        memove(&x[first], &work[first], (last - first + 1) * SIZE);//从word[first]所指向的区域复制count个到x的内存区域
    }
}


void merge(int x[], int work[], int first, int mid, int last)
{
    int in1 = first;
    int in2 = mid + 1;
    int out = first;
    //最后的时候分成了两部分，一部分是从first开始到mid结束，另一部分是从mid + 1开始，到last结束
    while(in1 <= mid && in2 <= last)   //这个是依次选出两个数组里较大的那个，放到work中
        work[out++] = (x[in1] <= x[in2]) ? x[in1++] : x[in2++];
    while(in1 <= mid)   //如果最后in2放完了，in1没有放完，把in1后面的全放入work中
        work[out++] = x[in1++];
    while(in2 <= last)  
        work[out++] = x[in2++];
}


12.还有一种快速排法（类似于三色旗）
//这个不就是快速排列法吗，只是把找位置的写成了一个函数
int main(void)
{
    int a[6] = {2, 1, 0, 5, 4, 3};
    QuickSort(a, 0, 5);
}

void QuickSort(int *a, int low, int high)
{
    int pos;
    
    if(low < high)
    {
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}

int FindPos(int *a, int low, int high)
{
    int val = a[low];
    
    while(low < high)
    {
        while(low < high && a[high] >= val)
            --high;
        a[low] = a[high];
        while(low < high && a[low] <= val)
            --low;
        a[high] = a[low];
    }//终止while循环之后的low和high一定是相等的
    
    a[low] = val;
    
    return high;   
}

13.用桶排序和链表实现排序
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 4
#define BUCKET_NO 16
#define LOOP_COUNT sizeof(int)*8/LENRTH
依次取出个位十位，百位排序，最后得到的就是最终的结果

struct node   //链表的形式
{
    int data;        //用来存原始数据
    int x;           //用来改变
    struct node *next;
};

struct node *head;

struct cell
{
    struct node *first;
    struct node *last;
}buckets[BUCKET_NO];

int mask = 0x0FU;    //15 先转换成十六进制，就是15，最后的U是unsigned类型
/**
	敲黑板：如果是100，转化成16进制，除16，依次取余数就是64
	   分别占0110 0100   有几个余数就是几位
	   
	   而如果是15，就占一位，就是1111，不能分开写成0001 0101
	   
**/

struct node *listgen(int [], int);
void distribute(void);
void recollect(void);
void putback(int []);

void sort(int input[], int n)
{
    int i, count;
    head = listgen(input, n);  //创建一个链表 head是头节点
    
    for(count = 1; count <= LOOP_COUNT; count++)  //初始化一个16*4的buckets表格，LOOP_COUNT是有几位数字
    {
        for(i = 0; i < BUCKET_NO; i++)    //在每一次分组之前把first和last清空成NULL，一共有BUCKET_NO个桶
            buckets[i].first = buckets[i].last = NULL;
        distribute();   
        recollect();
    }
    putback(input);
}

struct node *listgen(int input[], int n)   //创建一个链表，需要有首节点，尾节点，还要有中间存数据的遍历节点
{
    struct node *first;   //记住创建链表的时候必须是指针类型
    struct node *last;
    struct node *temp;
    int i;
    
	//初始化链表，第一个数据
    first = last = (struct node *)malloc(sizeof(struct node));
    first->data = first->x = input[0];
    first->next = NULL;
    
	//不断延伸链表
    for(i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = temp->x = input[i];   //这一步是存数据
        temp->next = NULL;                 //如果说加入一个temp。就意味着temp是最后一位元素，所以把它下一位的指针设为空
        last->next = temp;                 //把temp添加到原来last的下一位元素
        last = temp;                       //把temp设为最后一位元素
    }
    return first;
}


void distribute(void)    //把head链表里的数排好到buckets里，删去原来的head后面的链表设为空
{
    struct node *temp;
    int index;
    
    while(head != NULL)    //head现在就是一个指向一个链表首元素的地址
    {
        index = (head->x) & mask;   //取出x值的后四个数元，就是取出最后一位数字，mask所代表的数字是1111，
									//如果一个数字是0110，& 还是0110，不变，所以就取出了最后四个字节，就是最后一位数字
									
        (head->x) >>= LENGTH;       //把这个三位数向左移动一位数字，就是移动四个数位，LENGTH是4
        
		//把这个取出的位数放入桶
        if(buckets[index].first == NULL)     //如果所在的地方没数字
            buckets[index].first = buckets[index].last = head;// 就可以把first和last都设成head
        else
        {
            (buckets[index].last)->next = head;    //如果所在的地方有数字，就先把last的下一个指针设为head
            //这里其实和原来之前的一样，就是少了一步head的下一个设为NULL
			buckets[index].last = head;    //再把head设为最后一位元素
        }
        temp = head->next;         //把原来head后面的链表全设为空，意思就是删去这个链表，保留head的地址
        if(head->next != NULL)
            head->next = NULL;
        head = temp;              //使head指向下一位元素
    }
}

void recollect(void)    //把buckets里面的数据放到head里
{
    int i, j;       
    //就和连串串一样，一段一段连
    for(i = 0; i < BUCKET_NO && buckets[i].first == NULL; i++);   //找到第一个数据不是空的桶
    head = buckets[i].first;  //head先指向buckets  i 位上的第一个数据的地址，一个地址就可以找到一串，所以不用循环保存
    //把buckets[i].first后面的连好
    for(j = i + 1; j < BUCKET_NO; j++)
    {
        if(buckets[j].first != NULL)
        {
            (buckets[i].last)->next = buckets[j].first;//只要使i位上的last指向下一个有效位的首地址就行
            i = j;   //有j的++，没有i的变化
        }
    }
}

void putback(int input[])  //这个链表的输出，输入这个数据的时候就是input，更改完成以后也就是到input中
{
    struct node *temp;     
    int i;
    
    for(i = 0; head != NULL; i++)    
    {
        input[i] = head->data;  
        temp = head->next;//必须用temp交换，不可以是head = head->next;
        free(head);     //释放内存，动态分配内存以后要释放内存
        head = temp;
    }
}

14.堆排序（类二叉树）
#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0


///对了，我想说一下数组是如何存树的,横的一排一排存，按编号1234567......存，因为这个正好是个二叉树，所以就可以这样存，如果有
///残缺的二叉树，就得先补成二叉树；一个规律，父亲的儿子的下标是父亲的2倍
/*                 17（1）
        9（2）                           19（3）
    10（4）  6（5）               20(6)            4(7)
   5(8) 7(9)  8(10) 3(11)      11(12) 13(13)  16(14) 18(15)  
*/
void fix_heap(int [], int, int, int);

void sort(int old_x[], int n)
{
    ///树的元素从1开始  数组的元素从0开始
    ///x是从1开始包含树的元素
    int *x = old_x - 1;
    int temp;
    int size, i;
    
    for(i = n / 2; i >= 1; i--)   ///最下面一层肯定是当前位的最大值，n / 2的目的是从最下面一层的上面一层的而最右边元素开始处理
                                  ///例如1  3  7  15
        fix_heap(x, i, x[i], n);
    ///排大小，从数组的尾部向前处理
    ///我有收藏这个堆排序的博客，大概意思就是让最下最右的的元素和最顶上的元素交换，为啥了，不管下面的是啥，最顶上的元素一定是
    ///目前元素当中最大的，所以把最上面元素换到最底下，之后把它去掉，不看他，一直执行这个过程，就可以选出第一大，第二大，第三大
    for(size = n; size >= 2; size--)
    {
        temp = x[1];   //把最顶上的元素保存下来
        fix_heap(x, 1, x[size], size--);  //x是数组，1是爸爸节点的位置，k是目前最下且最右的元素，size--意思就是不执行最后一个，最后一个
                                          //目前是最大的
                                          //这个步骤的目的就是从树根上去调整这棵树，使它满足最大堆，最上头元素是最大
        x[size] = temp;  //让size的值是temp，最大元素
    }
}

void fix_heap(int x[], int root, int key, int bound)  ///root是顶点所在的地方，x[root]是顶点的值，bound是最大边界
{
    int father, son;
    int done;
    
    father = root;      //先让这个父亲等于这个根节点
    son = father + father;    //父亲的二倍是儿子
    done = NO;
    ///我终于知道它是什么意思了，把爸爸的值key记录下来，跟他儿子比较，如果儿子大于爸爸，就把儿子的值赋给爸爸，儿子的值不变，
    ///因为每次比较的是key，所以无关紧要，所以最后要把x[father] = key; 
    while(son <= bound && !done)       
    {
        if(son < bound && x[son + 1] > x[son])  //找出他儿子里最大的那个儿子
            son++;
        if(key < x[son])      //如果他儿子大于他爸爸
        {
            x[father] = x[son];   //就让他儿子代替他爸爸
            father = son;         //再让原来的爸爸和原来的儿子的儿子比较
        }
        else
            done = YES;   //如果儿子不大于他爸爸，结束
        son = father + father;  
    }
    x[father] = key;     
}


————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
  在一个数组中寻找特定的某个数或某几个数
============================================ 
//二分法

1.一个数组元素从小到大排号，寻找是否有x[i] = i;
int index_search(int x[]. int n)
{
    int first = 0;
    int last = n - 1;
    int middle, index; //index是查找到的元素
    index = -1;
    while(first <= last)     //每次验证的元素都是中间元素，所以两边的first和last并没有考虑到，为了使两边的元素也被考虑到，所以要加等于号
    {
        middle = (first + last) / 2;
        if(x[middle] == middle)
        {
            index = middle;
            break;
        }
        else if(x[middle] > middle)
            last = middle - 1;   //middle - 1的原因是因为上面的步骤已经证明了middle不是
        else
            first = middle + 1;
    }
    return index;
}

2.寻找两个无序数组元素中有没有两个数加起来等于用户给的数
#define YES 1 
#define NO 0

void sort(int [], int);

int fix_sum(int x[], int y[], int m, int n, int given)   //mn分别是xy数组中元素的个数
{
    int first;
    int last;
    int middle;
    int i;
    
    sort(x, m);  //先将x数组里的元素排好顺序
    
    for(i = 0; i < n; i++)
    {
        for(first = 0, last = m - 1; first <= last;  )
        {
            middle = (first + last) / 2;
            if(y[i] + x[middle] == given)
                return YES;
            else if(y[i] + x[middle] > given)
                last = middle - 1;   //这一步说明middle已经测试过了
            else
                first = middle + 1;
        }
    }
    return NO;
}


3.一个数组里的元素是无限个，并不知道有多少个，如何是用二分法找出某个特定的值
#define NOT_FOUND -1

void bound(int [], int, int *, int *)  //找出界限，并通过指针对界限进行修改
int search(int [], int, int, int)   //二分法查找

int inf_search(int x[], int GIVEN)  //相当于mian函数
{
    int left, right;
    bound(x, GIVEN, &left, &right);
    return search(x, GIVEN, left, right);
}

//我很喜欢边界选取的时候这种巧妙的方法，左闭右开，通过加等号不加等号的方法来控制，最后通过--来形成闭区间
void bound(int x[], int GIVEN, int *start, int *end)
{
    int detal = 1;  //数组中所包含元素的的个数，根据左闭右开原则，右 - 左就是元素的个数
    *start = 0;
    *end = *start + delta;
    
    while(!(x[*start] <= GIVEN && GIVEN < x[*end])) //判断给的元素在什么区间内
    {
        delta += delta; //delta的值1 2 4 8 16
        *start = *end;
        *end = *start + delta;
    }
    (*end)--;  //因为end是开区间，而用二分法要求区间是闭区间
}

int search(int x[], int GIVEN, int low, int high)
{
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(GIVEN < x[mid])
            high = mid - 1;
        else if(GIVEN > x[mid])
            low = mid + 1;
        else
            return mid;
    }
}


4.
///寻找极小值，8 10 14 15 2 6，就是从8-15依次增大，从2-6依次增大，且6 < 8，先增加突然递减再增加，总体趋势是增加
///只要能把问题分成两部分，而有办法判断解答在其中一部分的话，这个就是二分查找法
//如果说是要找到某一个数字，就得加等于号，如果是单纯比较数的大小，不用加等于号

int cyclic_min(int x[], int n)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while(left < right)    //当left < right循环最后一次之后，right = left，输出left
    {
        mid = (right + left) / 2;
        if(x[mid] < x[right])   //说明从中间到最右边一直都是增大的，最小值不在这个范围内，而且这个数组当中的元素永远也不可能相等
            right = mid;   
        else
            left = mid + 1;  ///最右边的数字小于中间的数字，mid肯定不是最小值，所以把mid排除，所以mid要加1，只要是确定的可以把它排除，就加1
    }
    return left;
}

/*
5.两个数组xy的中位数，已知有n个元素从小到大的顺序排好
void sort(int [], int);

int median(int x[], int y[], int n)
{
    int first_x = 0;
    int first_y = 0;
    int last_x = n - 1;
    int last_y = n - 1;
    int count = 0;
    int mid_x, mid_y;

    int number;
    int z[4];

    ///x = 1 4 6 7 9
    ///y = 2 3 4 5 7
    while((last_x - first_x > 1) || (last_y - first_y > 1))
    {
        mid_x = (first_x + last_x) / 2;
        mid_y = (first_y + last_y) / 2;
        if(x[mid_x] <= y[mid_y])     //如果说x最中间的数小于y最中间的数，x最中间的数左边有n / 2个，而这两个数组合起来最中间的数因该是n，所以中位数一定在两者
                                     //之间，留下0-midy  midx-lastx
                                     ///不用担心变化之后中位数不在中间因为x左边去掉多少个，y右边就去掉多少个
        {
            count = (mid_x - first_x);  //count是到目前为止，去掉比中位数小的值的总数
            first_x = mid_x;
            last_y = mid_y;
        }
        else
        {
            count = (mid_y - first_y);
            first_y = mid_y;
            last_x = mid_x;
        }
    }
    //把刚才选出来的中位数待定值放到一个数组里
    for(number = 0; first_x <= last_x; first_x++)
        z[number++] = x[first_x];
    for( ; first_y <= last_y; first_y++)
        z[number++] = y[first_y];
    sort(z, number);    //number是总共有的元素的个数
    return z[n - count - 1];
}

#define SWAP(x, y) {temp = x;\
                    x = y;\
                    y = temp;\
}  ///注意啊，这个是用大括号括起来的，不是小括号
void sort(int z[], int n)
{
    int temp; 
    switch (n)
    {
        case 4 : if(z[0] >= z[3]) SWAP(z[0], z[3]);
                 if(z[1] >= z[3]) SWAP(z[1], z[3]);
                 if(z[2] >= z[3]) SWAP(z[2], z[3]);
        case 3 : if(z[0] >= z[2]) SWAP(z[0], z[2]);
                 if(z[1] >= z[2]) SWAP(z[1], z[2]);
        case 2 : if(z[0] >= z[1]) SWAP(z[0], z[1]);
    }
}
*/

6.
///寻找中间值
///已知一个整数数组x[]有n个元素，两个相邻数的绝对值之差不超过1，而且最后一个数字比第一个数字大，是否有某一输入的值a
//这个数组总体是增大的
//我感觉如果是 low <= high 就是数组里每一个元素都能取到； 如果是low < high 有可能会娶不到high-

#define ERROR -1
int bolzano_search(int x[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    
    if(key > x[n - 1] || key < x[0])   //判断，这个数组里的元素一定是连续的整数，只要看一看0和n - 1，就知道它在不在范围内
        return ERROR;
		
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(key > x[mid])
            low = mid + 1;
        else if(k < x[mid])
            high = mid - 1;
        else
            return mid;
    }
}



7.有三个数组xyz，分别有xyz个元素，而且数组中的元素已经从小到大按顺序排好，找出值最小的共同元素

#define FOUND 1
#define NOT_FOUND 0

int search(int x[], int y[], int z[], int X, int Y, int Z, int *XX, int *YY, int *ZZ)    //XYZ是最大的元素，XXYYZZ是遍历的元素
{
    *XX = *YY = *ZZ = 0;
    while(*XX < X && *YY < Y && *ZZ < Z)
    {
        if(x[*XX] < y[*YY])
            (*XX)++;
        else if(y[*YY] < z[*ZZ])
            (*YY)++;
        else if(z[*ZZ] < x[*XX])
            (*ZZ)++;
        else
            return FOUND;
    }
    return NOT_FOUND;
}

8.寻找最小与次小元素
void first_and_second(int x[], int n, int *first, int *second)
{
    int i;
    
    if(x[0] <= x[1])
    {
        *first = x[0];
        *second = x[1];
    }
    else
    {
        *first = x[1];
        *second = x[0];
    }
    for(i = 2; i < n; i++)
    {
        if(x[i] < *first)
        {
            *second = *first;
            *first = x[i];
        }
        else if(x[i] < *second)
            *second = x[i];
    }
        
}
9.不排序求出一组数的中位数，区分奇数和偶数
#define SWAP(x, y) {int t; t = x; x = y; y = t;}
#define ALWAYS 1

void split(int [], int, int, int *);   //找出分割点是啥

int median(int  x[], int n)
{
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;
    int split_point;
    
    while(ALWAYS)
    {
        split(x, left, right, &split_point);
        if(split_point = mid)
            break;
        else if(split_point > mid)
            right = split_point - 1;
        else
            left = split_point + 1;
    }
    return (n & 0x01 != 0) ? x[mid] : (x[mid] + x[mid] + 1) / 2;   //判断是奇数还是偶数
    
}

void split(int x[], int left, int right, int *split_point)//记录边界的第一个元素，找出这个元素的位置，并排序
{
    int split_date = x[left];
    int i;
    for(*split_point = left, i = left + 1; i <= right; i++)
    {
        if(x[i] < split_date)   //这不就是简化版的快排吗？我就是觉得呀，不遍历根本求不出
        {
            (*split_point)++;
            SWAP(x[*split_point], x[i]);//管他是啥，只要让她上位就行
        }
    }
    SWAP(x[left], x[*split_point]);
}

4.
//找出两个已排好序的数组中的中位数，要求使用分治算法
#define MIN(n,m) ((n)<(m)?(n):(m))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int n = nums1Size;
    int m = nums2Size;
    
    //为什么要加1加2，自己找两个数字试一下
    int left = (n + m + 1) / 2;
    int right = (n + m + 2) / 2;
    //将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
    return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
}

/**
    start和end分别是数组中第一个和最后一个数字的下标
    k是寻找这两个数组中第k小的数，如果想要找到第k小的数字，所以得把比k
    小的数组全部排除，这个排除的过程就可以使用二分法
**/

int getKth(int nums1[], int start1, int end1, int nums2[], int start2, int end2, int k)
{
    //len1和len2分别是这两个数组的长度
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    //让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1
    //我觉得是为了保证len1永远是长度较短的那个数组
    if (len1 > len2)
        return getKth(nums2, start2, end2, nums1, start1, end1, k);

    //如果这个长度较短的数组的长度恒等于0，说明只要找出nums2中第start2 + k - 1最小的就可以
    if (len1 == 0)
        return nums2[start2 + k - 1];
    
    //如果说k == 1，意思就是找出一个最小的数
    if (k == 1)
        return MIN(nums1[start1], nums2[start2]);
    
    /**
        如果是1 3 4 5
              1 2 3 4 5 6 7 8 9 10
        其实我本质就是想寻找一个数字是否有当中位数的可能，在两个数组中，如何找到这个数呢？
        首先已知的条件是这两个数组是排好序的，我在两个数组中分别找第n / 2个数，判断这两个数中较小的，说明这个数没有可能
        是中位数，因为中位数必须要求是第n / 2个大的，意思就是这个数........，而这个最大数之前的数字不确定
    
    */
    //如果是6的话，i和j指向的分别是第三个数和第三个数呀
    int i = start1 + MIN(len1, k / 2) - 1;
    int j = start2 + MIN(len2, k / 2) - 1;

    if (nums1[i] > nums2[j])
    {
        return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
    }
    else
    {
        return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                递归的应用
============================================ 
1.汉诺塔

void hannuota(int n, char A, char B, char C)
{
	/*
		如果是1个盘子
			直接将A柱子上的盘子从A移到C
		否则
			先将A柱子上的n - 1个盘子借助C移到B
			直接将A柱子上的盘子从A移到C
			最后将B柱子上的n - 1个盘子借助A移到C
	
	*/
	if(1 == n)  //如果只是1个就是直接移
	{
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子", n, A, C);
	}
	else//大于1个的情况
	{
		//这个是以堆的形式来看的，第n个，n - 1堆，堆可以借助空的来移
		//类似于要把大象装冰箱1000可以分为1和999，把999看成一堆，记住这个是倒叙输出，中间步骤不用管，分对，咋搞
		hannuota(n - 1, A, C, B);
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子",n, A, C);
		hannuota(n - 1, B, A, C);
	}
	
}

int main(void)
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	printf("请输入要移动盘子的个数");
	scanf("%d", n);
	hannuota(int n, char A, char B, char B);
}

2.输入一个数，找出他的二进制
void to_binary(unsigned long n)
{
	int r;
	r = n % 2;    				//这个的作用是先取出它的余数
	if(n >= 2)					//只要n的值大于等于2，就会一直执行，最后一个n的值是1，且一直会执行上面那条语句，把r的值算好放在缓冲区
		to_binary(n \ 2);		
	putchar(r = 0 ? '0' : '1');//把放在缓冲区的r的值倒叙输出
	return;
}

void to_binary(unsigned long n)
{
    if(n >= 2)
        return to_binary(n / 2);
	if((n % 2) == 1)
        printf("1");
    if((n % 2) == 0)
        printf("0");   //记得二进制是倒叙输出，所以取余应该放在递归的后面
}

3.斐波那契数列（其实一种原因就是不断地压栈和出栈浪费内存，还有一个原因就是算了大量重复的数字，看下面的2被算了多次）
  -可以通过搞一个数组，记录已经算过的数字所对应的数字，避免重复计算
  -也可以动态规划，动态规划是自底而上，可以避免不必要的计算
   f = 0; g = 1;
   while(0 < n--)
   {
	   g = g + f;
	   f = g - f;
   }
                        5
			4						3
	  3           2            2         1
	2   1       1   0        1   0
  1   0
        			
unsigned long fibonacci (int n)
{
	if(n <= 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

4.二项式系数递归解
int cnr(int n, int r)
{
	if(n == r || r == 0)
		return 1;
	else
		return cnr(n - 1, r) + cnr(n - 1, r - 1);
	
}

5.数值自乘递归，m的n次方，分n是0，奇数，偶数的情况，m(13)，13 = 1101（二进制）= 2(3) + 2(2) + 2(0)8 
int R_POWER(int m,int n)
{
    /*
		可以用循环，也可以用递归，为了减少运算量
		使用二分法一部分数字是n / 2 另一部分n - n / 2
	*/
	if(n==0)
    return 1;
    else if(n==1)
    return m;
	//return R_POWER(m,n/2)*R_POWER(m,n/2)*m;//若n为奇数，7分成6 * 6，但还有一个7，所以还要*m
	//return R_POWER(m,n/2)*R_POWER(m,n/2);//若n为偶数
    return R_POWER(m,n/2)*R_POWER(m,n-n/2);
	
}

/**
	我简述一下这种方法的原理：
	首先，计算机喜欢加法，所以应该尽量减少乘法的次数，观察到每次重复所乘的数字都相同，所以可以用二分法来减少乘法的
	次数，就得分奇数和偶数，区分奇数还是偶数，可以用除以2，但用0x01UL更快速，递归的退出条件就是当n == 0，输出1
**/
第二种方法
unsigned long recursive_power(unsigned long m, unsigned long n)  //m的n次方
{
   unsigned long temp;
   if(n == 0)
	return 1;
   else if(n & 0x01UL == 0)   //同理，这个是判断它是不是偶数，这个是和1比较，偶数最后一位是0，奇数最后一位是1
   {
	   temp = recursive_power(m, n >> 1);//n >> 1是× 1/2
	   return temp * temp;  
   }
   else
	return m * recursive_power(m, n - 1);//如果是奇数，减1，就是偶数了
}


6.输出一组数的全排列，就是在一排盒子里依次放最小的数，放满之后，把从最后再拿出
int a[10], book[10], n;   //C语言全局变量在没有赋值前默认为0

void dfs(int step)   //step表示现在站在第几个盒子面前
{
    int i;
    if(step == n + 1)   //总共就有n个数，你却成了n + 1，意思就是提示该输出了，已经排好了
    {
        //输出一种排列（1-n号盒子中的扑克牌编号）
        for(i = 1; i <= n; i++)
            printf("%d", a[i]);
        printf("\n");

        return;  //返回之前的一步（最近一次调用dfs函数的地方）
    }

    /*输出结果一部分：
        1234
        1243
        1324
        1342
        1423
        1432
        */
    for(i = 1; i <= n; i++)
    {
        if(book[i] == 0)    //还是用book来判断数字是否输出过
        {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);    //到这个就是一个一个输入数据，直到输满执行上面的，输出
            book[i] = 0;      //输出完成之后，执行这个，dfs保存了book的地址，执行下面的语句，控制权交给了上一个函数
                              //所以下一步就是执行for循环，刚才已经把4的位置设成了0，所以在第3位上就是4，
        }
    }
    return;
}

int main()
{
    scanf("%d", &n);
    dfs(1);
}

7.///*** + *** = ***   且这9个数不重复

int a[10], book[10], total = 0;

void dfs(int step)  //表示站在第几个盒子前
{
    if(a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
    {
        total++;
        printf("%d%d%d + %d%d%d = %d%d%d\n",a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        return; 
    }
    
    for(i = 1; i <= 9; i++)
    {
        //如果只看第一个数字，后边默认都是排好的
        if(book[i] == 0)     //首先得看i是否是排过的数字
        {
            a[step] = i;     //如果没有排过，在第step个盒子面前把数字塞进去
            book[i] = 1;     //同时把book设为1
            dfs(step+1);     //排后面默认排好的数字
            book[i] = 0;     //如果是1，就表示，已经把这个数字塞入某一个箱子里了，为0把这张牌取出，这张牌在
			                 //这个位置的所有情况已经排好，在剩下的牌中选择最小的塞进去
        }
    }
    return;
}

int main()
{
    dfs(1);
    printf("total = %d", total / 2);  //除以2的原因是1 + 2 = 3和2 + 1 = 3是一样的
}
8.
走迷宫，最短距离，有障碍的地方不能通过
int n, m, p, q, min = 99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step)
{
    ///因为起点的坐标是1，1，他要找到点，一定往右走和往下走是最优先的选择
    int next[4][2] = {
                      {0, 1},   //往右走 
                      {1, 0},   //往下走
                      {0, -1},  //往左走
                      {-1, 0}   //往上走
                     };
    int tx, ty, k;
    
    ///我觉得，这种递归法用来判断的，就用if语句为退出的条件
    ///咱类比一个数组，数组第一个元素有1，2，3，4，5好几种选择，所以要用for循环，数组之后的元素调用递归函数，就相当于
    ///解决了之后元素的问题啦
    //判断是否达到小哈的位置
    if(x == p && y == q)
    {
        if(step < min)
            min = step;
        return ;   
    }
    
    //枚举四种走法
    for(k = 0; k <= 3; k++)
    {
        //计算下一个点的坐标
        tx = x + next[k][0];
        ty = y + next[k][1];
        
        //判断是否越界,如果越界，换下一种走法
        if(tx < 1 || tx > n || ty < 1 || ty > m)
            continue;
        
        //判断该点是否为障碍物或者已经在路径中
        if(a[tx][ty] == 0 && book[tx][ty] == 0)  ///障碍物就为0，已经做过的事，不需要再做用book法
        {
            book[tx][ty] = 1;   //标记这个点已经走过
            dfs(tx, ty, step + 1);  //测试剩余的点
            book[tx][ty] = 0;   //这个点测试完毕，结束
        }
    }
    return ;
}

int main()
{
    int i, j, startx, starty;
    
    //n为行， m为列
    scanf("%d %d", &n, &m);
    //读入迷宫
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    
    //读入起点和终点坐标
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    
    //从起点开始搜索
    book[startx][starty] = 1;   //book为1，就意为着走过这个点
    dfs(startx, starty, 0);
    
    //输出最短步数
    printf("%d", min);
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                队列的应用
============================================ 
队列就像转圈圈，栈就像把粽子包好，再剥开
链表就像一条蛇，拿着蛇头，去把它揪出来
1.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//完成一个队列，需要几个参数，肯定需要头节点和尾节点，中间圈圈里面的元素怎么存，就用数组，只要涉及到指针数组，就得
//动态分配内存
typedef struct queue
{
    int * pBase;  //这是一个指针，也就是一个数组
    int front;  //队列的头
    int rear;   //队列的尾
}QUEUE;

void init(QUEUE *);  
bool en_queue(QUEUE *, int);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool out_queue(QUEUE *,int *);
bool enput_queue(QUEUE *);

int main(void)
{
    QUEUE Q;
    init(&Q);  //&的意思是取地址
    en_queue(&Q, 1);
    
    return 0;
}


//完成队列的初始化
void init(QUEUE *pQ)   //*的意思是取地址里面对应的值
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

//判断这个队列是否是满的
bool full_queue(QUEUE *pQ)
{
    if((pQ->rear + 1) % 6 == pQ->front)
        return true;
    else
        return false;
}

//入队
bool en_queue(QUEUE * pQ, int val)
{
    if(full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1) % 6;
        return true;
    }
}

//遍历输出
void traverse_queue(QUEUE * pQ)
{
    int i = pQ->front;
    
    while(i != pQ->rear)
    {
        printf("%d",pQ->pBase[i]);
        i = (i + 1) % 6;
    }
    printf("\n");
    return;
}

//判断队列是否是空的
bool enput_queue(QUEUE *pQ)   
{
    if(pQ->front == pQ->rear)
        return true;
    else
        return false;
}


//出队
bool out_queue(QUEUE *pQ, int *pVal)
{
    if(emput_queue(pQ))    //如果首和尾指向同一位置，就不能出队
    {
        return false;
    }
    else
    {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % 6;
        return true;
    }
}


1.先将第一个数删除，再把第二个数放到最后，再把第三个数删除，把四个数放到末尾.........最后会留下一个数，把这个数也删除
typedef struct queue
{
    int data[102];
    int head;
    int tail;
}QUEUE;

int main(void)
{
    QUEUE q;
    int i;
    q.head = 0;
    q.tail = 9;
    for(i = 0; i <= 8; i++)
    {
        scanf("%d", &q.data[i]);
    }
    printf("解密后的数字为:");
    while(((q.head + 1) % 9) != q.tail)
    {
        printf("%d", q.data[q.head]);
        q.data[q.tail] = q.data[(q.head + 1) % 9];
        q.head += 2;
        q.tail++;
    }
    printf("%d", q.data[q.head]);
}


————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                栈的应用
============================================ 
1.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, *PNODE;   //p就是指针指向

typedef struct stack
{
    PNODE pTop;   //把它看成指针指向
    PNODE pBotton;
}STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK pS);

int main(void)
{
    STACK S;   
    
    init(&S);
    push(&S, 1);
    traverse(&S);
}

//类似于初始化，为pBottom和pTop分配一块内存，并把这两个指针的指向指为相同
void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));  //malloc前面的是变量pTop是什么类型，而这个是个指针，不能分配指针的大小，应该分配指针所指向变量的大小，所以是NODE
    //这个就是动态分配内存之后的套路
    if(NULL == pS->pTop)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;  //pS->pBottom->pNext = NULL  也可以写成这个，如果说是指向NULL，说明是最后一个
    }
}


//pTop和pBotton都指向同一个节点，且指针域为NULL，要造出一个新的节点，关键是要把新节点的指针域指向pTop
//指针从上往下指，数据从下往上放，最后一个指向前面所有的地址，一层一层包裹起来
void push(PSTACK pS, int val)  //第一个是地址，第二个是要添加的数据，只能添加在头上
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    
    
    //我的老天鹅，我是不是疯了，他就是把最上头的
    pNew->date = val; //先把新初始化的节点中的数据设为val
    pNew->pNext = pS->pTop;//pS->pTop不能改成pS->pBottom；pTop所含有空数据和NULL指针，也有可能不是空数据，不是NULL指针
    pS->pTop = pNew;  //pNew取代了pTop，pNew是内含指向pTop的指针和一个数据的节点
    
    return;
}


void traverse(PSTACK pS)  //输出这个里面的数据
{
    PNODE p = pS->pTop;  //首先p指向顶端的节点
    
    while(p != pS->pBottom)
    {
        printf("%d", p->date);
        p = p->pNext;  //pNext的意思是从上往下指的
    }
    printf("\n");
    
    return;
}

bool empty(PSTACK pS)  //判断是否是空,这个里头有没有数据
{
    if(pS->pTop == pS->pBottom)  
        return true;
    else
        return false;
}

//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，如果出栈失败，返回false，否则返回true
//意思就是把最上头的元素输出并删除
bool pop(PSTACK pS, int * pVal)
{
    if(empty(pS))  //pS本身存放的就是S的地址
    {
        return false;
    else
    {
        //我终于懂了，这个指针是从上往下指的
        PNODE r = pS->pTop;   
        *pVal = r->data;  //把r先指向最上头的地址就是为了输出这个元素的
        pS->pTop = r->pNext;  //再把最上头元素的地址往下移动一个 
        free(r);  //把最上头要删除的删掉，就行了
        r = NULL;
            
        return true;
    }
    
}

//clear清空，把里面的数据弄没，pTop和pBottle指向栈底元素
void clear(PSTACK pS)
{
    if(empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;  //定义指针时，要指向为NULL，防止乱指
        
        while(p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
		//上面的步骤是删除数据
		
		//下面这个步骤是使指针指向相同
        pS->pTop = pS->pBottom;
    }
}

2.
//用栈来判断一个数是不是回文数
//把中间的数之前的放到一个栈中，出栈和中间的数之后的数比较
int main(void)
{
    char a[101], s[101];
    int i, len, mid, next, top;
    
    gets(a);
    len = strlen(a);
    mid = len / 2 - 1;
    
    top = 0;
    for(i = 0; i <= mid; i++)    //他不是从第0个数开始，是从第一个数开始算的
        s[++top] = a[i];
    
    if(len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;
    
    for(i = next; i <= len - 1; i++)
    {
        if(a[i] != s[top])
            break;
		top--;
    }
    
    if(top == 0)
        printf("YES");
    else
        printf("NO");
}
3.
//拉火车
//需要用到首位的，都用队列

struct queue
{
    int data[100];
    int head;
    int tail;
};

//只需要用到尾，不需要用到首的用栈
struct stack
{
    int data[10];
    int top;
};

int main(void)
{
    struct queue q1, q2;
    struct stack s;
    int book[10];
    int i, t;

    //初始化队列
    q1.head = 1;
    q1.tail = 1;
    q2.head = 1;
    q2.tail = 1;
    //初始化栈
    s.top = 0;

    //初始化用来标记的数组，用来标记哪些牌已经在桌上
    //我的老天爷呀，这个简直是个神仙，我当时一直思考，重新建立一个数组，用来存放桌上的牌，可是如何找出一样的牌，遍历吗，
    //这个很好的解决了这个问题，直接检查对应数字的book值，就可以看出有没有这个数字
    for(i = 1; i <= 9; i++)
        book[i] = 0;
    /************************************************************************************************************************/
    //依次向队列插入6个数
    //小哼手上的6张牌
    //记得是从1开始的
    for(i = 1; i <= 6; i++)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    //小哈手上的6张牌
    for(i = 1; i <= 6; i++)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    /************************************************************************************************************************/
    while(q1.head < q1.tail && q2.head < q2.tail)    //当队列不为空的时候执行循环
    {
        t = q1.data[q1.head];   //小痕出一张牌
        if(book[t] == 0)
        {
            //小恒此轮没有赢牌
            q1.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
            //小恒此轮可以赢牌
			//head是下一次该出的数，tail是赢了的牌应该加到tail后面
            q1.head++;
            q1.data[q1.tail] = t; //tail现在是指向最后一个元素的下一个元素
            q1.tail++;
            while(s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }

            //回收桌面上牌面为t的牌
            book[s.data[s.top]] = 0;
            q1.data[q1.tail] = s.data[s.top];
            q1.tail++;
            s.top--;
        }
        //小恒手中的牌如果已经打完
        if(q1.head == q1.tail)
            break;

        /************************************************************************************************************************/
        t = q2.data[q2.head];
        if(book[t] == 0)
        {
            q2.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while(s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }

            book[s.data[s.top]] = 0;
            q2.data[q2.tail] = s.data[s.top];
            q2.tail++;
            s.top--;
        }
        
    }
    /************************************************************************************************************************/
        if(q2.head == q2.tail)
        {
            printf("小恒win");
            printf("小恒当前手中的牌是：");
            for(i = q1.head; i <= q1.tail - 1; i++)
                printf(" %d", q1.data[i]);
            if(s.top > 0)
            {
                printf("\n桌上的牌是：");
                for(i = 1; i <= s.top; i++)
                    printf(" %d", s.data[i]);
            }
            else
                printf("\n桌上已经没有牌了");
        }
        /************************************************************************************************************************/
        else
        {
            printf("小哈win");
            printf("小哈当前手中的牌是：");
            for(i = q2.head; i <= q2.tail - 1; i++)
                printf(" %d", q2.data[i]);
            if(s.top > 0)
            {
                printf("\n桌上的牌是：");
                for(i = 1; i <= s.top; i++)
                    printf(" %d", s.data[i]);
            }
            else
                printf("\n桌上已经没有牌了");
        }
        /************************************************************************************************************************/

}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                链表的应用
============================================
//如果操作对数据的进入和取出顺序有严格要求选择栈
//而且必须是先进后出的。对顺序没有要求的时候可以选用链表。  
1.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct Node
{
    int date;  //数据域
    struct Node * pNext;  //指针域
}NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int ,int);
bool delete_list(PNODE, int , int *);
void soert_list(PNODE);

int main()
{
    PNODE pHead = NULL;//等价于struct Node *pHead = NULL;  加p表示指针
    pHead = create_list();//创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
    traverse_list(pHead);
    system("color 7D");
}

PNODE create_list(void)//创建一个链表
{
    int len;    //用来存放有效节点的个数
    int i;
    int val;    //用来临时存放用户输入的节点的值

    //分配了一个不存放有效数据的头节点，记住链表的内存是用一段分一段，所以不用sizeof(NODE) * len
	///我终于懂了，有两种方法可以访问结构中的元素，不用指针和用指针，因为是要访问指针所保存地址的元素，所以是->，
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); //动态分配内存，并强制类型转换为指针类型
    if(NULL == pHead)
    {
        printf("分配失败，程序终止！\n");
        exit(-1);
    }

    PNODE pTail = pHead;    //意思就是这两个都指向同一个地址，指针代表的是地址，保存的地址相同，通过一个指针改变这个地方里的东西，另一个
						    //保存这个地址的指针里的内容也改变了
							//而在这里，指针保存的是一个结构的地址，就是一个房子里有一个数据和指向下一个房子的指针
							
    pTail->pNext = NULL;  //这个指针指向链表的尾节点


    printf("请输入您需要生成的链表节点的个数：len = ");
    scanf("%d", &len);
	//注意注意：pHead只储存了下一个房子的地址，并没有存值，
    for(i = 0; i < len; i++)
    {
        printf("请输入第%d个节点的值：",i + 1);
        scanf("%d",&val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));  //来存放输入节点中的数据    //分配空间就相当于分你一套房，所以malloc返回值是房子的地址
        if(NULL == pNew)     //如果用malloc函数，得判断内存是否分配成功，没给你分配房子，就是malloc返回值是空指针
        {
            printf("分配失败，程序终止");
            exit(-1);   //退出程序
        }
		//我懂了，两个节点通过指针相连接，这个节点当中的指针指向下一个节点的地址，当一个节点为尾节时，记得把它里面的指针设为空
        pNew->date = val;  //把val赋给pNew中的date
        pTail->pNext = pNew;   //把pnew的地址赋给末尾的地址
        pNew->pNext = NULL;    //因为末尾的指针是空指针，所以还得把末尾设成空指针
        pTail = pNew;     //把new的地址赋给tail，现在new相当于末尾了
    }
    return pHead;  //这个和这个函数没关系，main函数只是要返回链表头节点的地址
}

void traverse_list(PNODE pHead)  //头节点的地址,
{
    PNODE p = pHead->pNext;      //p指向头节点的指针域，注意不是首节点

    while(NULL != p)     //如果指针域不为空，就是不是尾节点
    {
        printf("%d ",p->date);     //输出数据
        p = p->pNext;   //p指向下一个节点的指针域
    }
    printf("\n");
    return;
}


//判读这个链表是否为空
bool is_empty(PNODE pHead)  //头节点的地址
{
    if(NULL == pHead->pNext)  //指向的下一个节点的地址是空
        return true;
    else
        return false;
}

int length_list(PNODE pHead)  //测量有几个节点
{
    PNODE p = pHead->pNext;  //记住这个变量类型
    int len = 0;

    while(NULL != p)
    {
        ++len;
        p = p->pNext;
    }

    return len;
}

//这个排序，
void soert_list(PNODE pHead)//头节点的地址,链表的排序
{
    int i = 0, j = 0, t;
    PNODE p, q;

    int len = length_list(pHead);  //调用函数测量出节点的个数

    for(p = pHead->pNext; i < len - 1; p = p->pNext)  //相当于i = 0;为什么len - 1,如果是12345排序，1和2比，1和3比。再换2和3比，最后4和5比，总共有4次
    {
        for(q = p->pNext; j < len; q = q->pNext)   //这个相当于j = i + 1，指针控制下一个元素
        {
            if(p->date > q->date)    //数据是节点的数据，完成交换
            {
                t = p->date;
                p->date = q->date;
                q->date = t;
            }
			j++;
        }
		i++;
    }
}

//插入一个元素，pos是插入啥位置， val是插入啥数字
bool insert_list(PNODE pHead, int pos, int val)  //头节点的地址
{
    int i = 0;
    PNODE p = pHead;  //把头节点的地址给p
    
	//如果想插入一个数据，就得判断想插到位置的前一个位置是否为空
    while(NULL != p && i < pos - 1)     //如果是NULL，此时的p是大框框，是最后一个节点的下一个节点&&pos是插入的位置，如果我想插入第三个位置，i最终应该是2
                                        //当i的值是2时，2<2不成立，输出i = 2，如果说是i < pos = 3,3 < 3不成立，输出i = 3
                                        //i = 0  p是表示头结点的地址，在数组中，也相当于0，所以i和p的起始位置是相同的，同时开始执行，p是用来判断此时这个位置
                                        //是否为空，由于同时执行，且i < pos - 1，所以最后执行到的位置是pos的上一个位置，并判断这个位置是否为空，如果不为空
                                        //就可以插入
    {
        p = p->pNext;   //p是大框框，pNext是小框框，如果是p->pNext是p指向下一个大框框
        ++i;
    }
    if(i > pos - 1 || NULL == p)       //如果超出了节点的个数1230，就是只要一超过，就是0 NULL，退出了while循环，所以不满足第二个条件
        return false;

    //设置一个新的节点
    PNODE pNew = (PNODE)malloc(sizeof(NODE)); //为这个要插入的数字动态分配内存，为啥了，应为链表的内存是一块一块的，你插入数字，就得分配内存


    //以下的都是套路
    if(NULL == pNew)
    {
        printf("动态分配内存失败！\n");
        exit(-1);
    }

    //开始插入
    pNew->date = val;    //把这个节点上储存上数据，val是函数输入进来的，然后设置一个新变量，把pNew插入
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;
}

//删除一个元素
bool delete_list(PNODE pHead, int pos, int * pVal)  //头节点的地址，pos是将要删除的元素，pVal是找一个指针，把删除的元素保存起来
{
    //以下步骤和上面一摸一样，主要目的就是找出需要删除的位置
    int i = 0;
    PNODE p = pHead;

    while(NULL != p->pNext && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if(i > pos - 1 || NULL == p->pNext)
        return false;


    //实现删除
    PNODE q = p->pNext; //先将q指向下一个元素的大框框
    *pVal = q->date;   //储存好要删除的数据，知道为啥要传指针吧

    p->pNext = p->pNext->pNext;//将下一个元素的大框框换成下下一个元素的大框框，更换指针的指向
    free(q);   //释放内存
    q = NULL;   //指向空指针，防止乱指

    return true;
}


2.
//如何用数组实现链表
//把数组中储存上元素，把数组元素的下一个元素的下标储存在另一个数组中，增加一个元素就在数组的最末端加，修改下标的值
int main(void)
{
    int data[101], right[101];
    int i, n, t, len;
    
    //读入已有的数
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &data[i]);
    len = n;
    
    //初始化数组right
    for(i = 2; i < n; i++)
        right[--i] = i;
    right[i] = 0;
    
    
    //直接在data末尾增加一个数
    ///需要3步，第一步，把要插入的数放在末尾  第二步，修改末尾的数的right   第三步：修改插入数的前一个数的right
    ///需要的条件，数组里的数必须从小到大排列好，首和尾无法处理，只能处理中间的
    len++;
    scanf("%d", &data[len]);
    
    //从链表的头部开始遍历
    t = 1;
    while(t != 0)
    {
        if(data[rigth[t]] > data[len])
        {
            right[len] = right[t];
            right[t]  = len;
            break;
        }
        t = right[t];
    }
    
    //输出链表中所有的数
    t = 1;
    while(t != 0)
    {
        printf("%d ", data[t]);
        t = right[t];
    }
    
    
    
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                结构的应用
============================================ 
1.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>  //包含了exit函数
#include <stdbool.h>


//定义了一个数据类型，该数据类型的名字叫做struct Arr，该数据类型含有三个成员
struct Arr
{
    int * pBase;    //储存的数组的第一个元素的地址
    int len;        //数组所能容纳的最大元素的个数
    int cnt;        //当前元素有效元素的个数

};

void init_arr(struct Arr * pArr, int length);        //初始化,通过指针才可以修改元素的值
bool append_arr();      //追加
bool insert_arr();      //插入
bool delete_arr();      //删除
int get();
bool is_empty(struct Arr * pArr);
bool is_full();
void sort_arr();        //排序
void show_arr(struct Arr * pArr);
void inversion_arr();   //倒置


int main(void)
{
    struct Arr arr;
    init_arr(&arr, 6);   //通过地址才可以改变值，定义变量的时候不是指针也是可以的，只要保证传入参数的时候取了地址就可以
    show_arr(&arr);

    return 0;
}

void init_arr(struct Arr *pArr, int length)   //
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);  //这个指针所指向的 int * pBase;数据类型是int
    if(NULL == pArr->pBase)  //如果是指针的话就是NULL，指针数组里元素为空，都是NULL
    {
        printf("动态内存分配失败!\n");
        exit(-1);// 终止整个程序
    }
}

bool is_empty(struct Arr * pArr)
{
    if(0 == pArr->cnt)    //int类型就是0
        return true;   //bool类型就有两种 true 和 false
    else
        return false;
}


void show_arr(struct Arr * pArr)
{
    if(is_empty(pArr))   //把enpty写成了函数
    {
        printf("数组为空！\n");
    }
    else
    {
        int i;
        for(i = 0; i < pArr->cnt; ++i)
            printf("%d  ", pArr->pBase[i]);
        printf("\n");
    }
}	
	

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                趣味数学问题
============================================ 
1.三色旗
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLUE 'B'
#define WHITE 'W'
#define RED 'R'
//这是一个交换函数，首先写出函数名和变量，然后就开始编这个函数了，定义中间变量，color就是main函数里的那个数组
#define swap(x,y){char temp;\
                  temp = color[x];\
                  color[x] = color[y];\
                  color[y] = temp;}

/*有一根绳子，上面有红、白、蓝三种颜色的旗子。
绳子上旗子的颜色并没有顺序，现在要对旗子进行分类，按照蓝色、白色、红色的顺序排列。
只能在绳子上进行移动，并且一次只能调换两面旗子，怎样移动才能使旗子移动的次数最少？ */

void main(void)
{
    char color[] = "RWBWWBRBWR";
    int w = 0;     //w就是white的个数
    int b = 0;     //b就是blue的个数
    int r = strlen(color) - 1;   //r就是red，意思就是从最后一个开始
    int i;

    /*for(i = 0;i < strlen(color);i++)
        printf("%c");*/
    fputs(color,stdout); //这个也可以打出正确的
    printf("\n");
	//什么意思，最后一个指针指向的是不为红的旗子
	//第一个和第二个指针实现的是把蓝色放前面，把白色放后面
	//所以第一个指针是蓝色旗子将要放到的位置
    while(w <= r)
    {
        if(color[w] == WHITE)
            w++;
        else
        {
            if(color[w] == BLUE)
            {
                swap(b, w);
                b++;
                w++;
            }
            else
            {
                while(w < r && color[r] == RED)
                    r--;
                swap(r, w);
                r--;
            }
        }
    }
    for(i = 0;i < strlen(color);i++)
        printf("%c",color[i]);
    printf("\n");
}


2.文件的加密与解密
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*敲黑板，这个程序主要是解决文件加密和解密的问题
1.用户有三个想法：加密解密退出程序，而且还解决用户的输入要使用户可以循环输入（while），所以就需要一个变量来判断用户输入的问题
  通过判断这个变量的值来解决用户的输入（if的条件语句）
2.这个太傻了，scanf("%s",Text);意思就是可以输入一个字符串，串，串，strlen必须是字符串，串，串，fgets也是字符串，串，串
*/

void main(void)
{
   int result = 1;
   int i;
   int count = 0;
   char Text[128];
   char cryptogrape[128];

   while(1)
   {
       if(result == 1)
       {
           printf("请输入要加密的密文：");
           //scanf("%s",Text);
           fgets(Text,10,stdin);//厉害了，小姿姿，这两个都可以哦
           count = strlen(Text);
           for(i = 0;i < count;i++)
           {
               cryptogrape[i] = Text[i] + i + 5;
           }
           cryptogrape[i] = '\0';  //记得在末尾加\0
           printf("加密后的密文是：%s\n",cryptograp);
       }
       else if(result == 2)
       {
           /*count = strlen(Text);
           for(i = 0;i < count;i++)
           {
               Text[i] = cryptogrape[i] - i - 5;
           }
           Text[i] = '\0';*/

           printf("解密后的密文是：%s\n",fputs(Text,stdout));
       }
       else if(result == 3)
            break;
       else
       {
           printf("请输入正确的命令符：\n");
       }
       printf("输入1加入新的明文   输入2对加密的明文进行解密  输入3退出系统\n");
       printf("请输入命令符：\n");
       scanf("%d",&result);
   }

}


3.使用结构编写一个明天日期是啥子滴程序
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date{
    int month;
    int day;
    int year;
};
bool isLeap(struct date d);
int numberOfDays(struct date d);

int main(int argc, char const *argv[])
{
    struct date today,tomorrow;    //一次可以定义多个变量哦
    printf("enter today's date (mm dd yyyy):");  //输出今天的日子
    scanf("%d %d %d",&today.month,&today.day,&today.year);

    if(today.day != numberOfDays(today))   //如果这个月的天数没有达到这个月的最大天数
    {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;

    }
    else if( today.month == 12)
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else
    {
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    printf("tomorrow's date is %i-%i-%i.\n",tomorrow.year,tomorrow.month,tomorrow.day);

}

int numberOfDays(struct date d)
{
    int days;
    const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(d.month == 2 && isLeap[d])   //如果是二月且是闰年
        days = 29;
    else
        days = daysPerMonth[d.month - 1];  //数组元素是从0开始的，这个就是判断这个月份有多少天
    return days;  //返回这个月的天数
}


bool isLeap(struct date d)     //判断是平年还是闰年，闰年是真，平年是假，注意返回值是bool类型
{
    bool leap = false;
    if((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        leap = true;
    return leap;
}

4.
    int n,m;//c1 c2数组的长度
    int i,j;//循环变量
    //n = sizeof(c1) / sizeof(char);
    n = 5;
    //m = sizeof(c2) / sizeof(char);
    m = 5;
    if(n > m)
    {
        for(i = 0;i < n;i++)
        {
            *s = c2;
            s++;
            for(j = i;j >= m && j <= n;j++)
            {
                *s = '\0';
                s++;
            }
        }
    }
    else
    {
        for(i = 0;i < m;i++)
        {
            *s = c2;
            s++;
        }
    }
    return s;


4.一个统计单词的程序
/*
  目标：1.统计输入字符的个数：空格数字啥的都算字符
        2.统计输入的行数：只要输入\n就加一
                        还有一个问题：如何判断一行是否输完：就是判断一行结尾是否有\n符号
        3.统计输入单词的个数：把单词定义为一个不含空白的字符序列（空白字符函数isspace() 头文件ctype.h
                        如果c是空白字符，isspace(c)为真，如果c不是空白字符，！isspace是真）
        4.还要可以识别结束，以前识别结束就是通过换行符和句点识别，这里可以通过提醒用户在结束是输出一个什么符号来退出程序
*/
#include <stdio.h>
#include <ctype.h>       //为isspace()函数提供原型
#include <stdbool.h>     //为bool、ture、false提供定义
#define STOP '|'
int main(void)
{
    char c;             //读入字符
    char prev;          //读入的前一个字符
    long n_chars = 0L;  //字符数
    int n_lines = 0;    //行数
    int n_words = 0;    //单词数
    int p_lines = 0;    //不完整的行数
    bool inwords = false;  //如果在单词中，inword等于ture，ture是1，false是0
    printf("请输入您要输入的英文句子（当您输入|时可以退出程序）：\n");
    prev = '\n';
    while((c = getchar()) != STOP)
    {
        n_chars ++;   //统计字符
        if(c == '\n')
            n_lines++;  //统计行
        //如果我想统计单词的个数，首先要在一个单词开头处第一个字符加1，之后经历单词的剩余部分不变，经理到第一个空白部分改变一个东西，所以就要用到开关函数
		if(!isspace(c) && !inwords)//如果不是空白字符 ！false就是真
        {
            inwords = true;
            n_words ++;  //统计单词的个数
        }
        if(isspace(c) && inwords) //如果是空白字符，如果经历过上面if语句，inword是真,这里把inwords转换成false
                                  //如果没经历过，也是false，这个语句的作用就是保证输出去的inwords都是false
        {
            inwords = false;
        }
        prev = c;
    }
    if(prev != '\n')
        p_lines = 1;//行数最多有一行不完整，因为不完整的上一行一定是输过\n，一定是完整的
    printf("characters = %ld,words = %d,lines = %d",n_chars,n_words,n_lines);
    printf("不完整的行数 = %d\n",p_lines);
    return 0;
}
	
5.炸弹人游戏把炸弹放哪里可以打倒最多的僵尸
int main()
{
    char a[20][21];
    int i, j, sum, map = 0, p, q, x, y, n, m;
    
    //n表示有多少行字符， m表示每行有多少列
    scanf("%d %d", &n, &m);
    
    //读入n行字符
    for(i = 0; i <= m - 1; i++)
        scanf("%s",a[i]);
    
    //用两重循环枚举地图中的每一点
    for(i = 0; i <= n - 1; i++)
    {
        for(j = 0; j <= m - 1; j++)
        {
            if(a[i][j] == '.')  //.的意思是空地
            {
                sum = 0;
                
                //向上统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')   //#的意思是墙
                {
                    if(a[x][y] == 'G')   //G的意思是炸弹
                        sum++;
                    x--;
                }
                
                //向下统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if(a[x][y] == 'G')
                        sum++;
                    x++;
                }
                
                //向左统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if(a[x][y] == 'G')
                        sum++;
                    y--;
                }
                
                //向右统计可以消灭的敌人数
                x = i;
                y = j;
                while(a[x][y] != '#')
                {
                    if(a[x][y] == 'G')
                        sum++;
                    y++;
                }
                
                if(sum > map)
                {
                    //如果当前点所能消灭的敌人总数大于map，则更新map
                    map = sum;
                    p = i;
                    q = j;
                }
            }
        }
    }
    printf("将炸弹放置在(%d,%d), 最多可以消灭%d个敌人\n", p, q, map);
}

6.火柴棍加法
//小恒手上有m（m <= 24）根火柴棍，可以拼出多少个A + B = C的等式
int fun(int x)
{
    int num = 0;  //用来计数的变量
    int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    while(x / 10 != 0)   //数字可能有7   17   177 之类，把最后一位之前所需要的火柴棍加起来
    {
        num += f[x % 10];
        x = x / 10;
    }
    
    num += f[x];  //加最后一位
    return num;
}

int main()
{
    int a, b, c, m, sum = 0;
    scanf("%d", &m);
    
    for(a = 0; a <= 1111; a++)      //24个数字刨去+=，还剩20个，用的最少的是1，可以有10个1，如果要分到3个位置上，一个位置
                                    //最多有4个，因为，5个1可以分到两个位置，，给第三个位置分1个，前面还有9，9 / 2 = 4
    {
        for(b = 0; b <= 1111; b++)
        {
            c = a + b;
            if(fun(a) + fun(b) + fun(c) == m - 4)
            {
                printf("%d + %d = %d\n", a, b, c);
                sum++;
            }
        }
    }
    printf("一共可以拼出%d个不同的等式", sum);
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                打空格问题
============================================ 
1.杨辉三角
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i,j;
    int k,p,m;
    int num[100][100] = {0};
    printf("请输入你想输出杨辉三角的列数：");
    scanf("%d",&n);
    //搞一个数组，输入杨辉三角所需数字
    for(i = 0;i < n;i++)
    {
        num[i][0] = 1;
        num[i][i] = 1;
        for(j = 1;j <= i;j++)
            num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
    }
    //空格和数组的输出
    for(k = 0;k < n;k++)
    {
        for(p = 0;p < n-k-1;p++)
        {
            printf(" ");
        }
        for(m = 0;m <= k;m++)
                printf("%d ",num[k][m]);
        printf("\n");
    }
}


2.打菱形问题
int main()
{
    //提醒用户输入行，并打印出菱形
    int n;//菱形的行数
    int s = 1;//*的个数
    int t2;//控制上部分每行中*的循环变量
    int t;//空格的个数
    int t1;//控制上部分每行中空格的循环变量
    int j;//控制行数
    int q;//控制下部分每行中空格的循环变量
    int p;//控制下部分每行中*的循环变量
    printf("请输入你想打印菱形的行数（必须是奇数个哦）：");
    scanf("%d",&n);
    t = (n - 1)/2;
        for(j = 0;j < (n + 1)/2;j ++)
        {
            for(t1 = 0;t1 < t;t1++)
                printf(" ");
            t--;
            for(t2 = 0;t2 < s;t2++)
                printf("*");
            s += 2;
            printf("\n");
        }
    q = 1;
    p = n - 2;
        for(j = (n - 1)/2;j > 0;j --)
        {
            for(t1 = 0;t1 < q ;t1++)
                printf(" ");
            q ++;
            for(t2 = 0;t2 < p;t2++)
                printf("*");
            p -= 2;
            printf("\n");

        }
}	


3.输出九九乘法表，共九行九列，i控制行，j控制列
int main (void)
{
   int i,j,result;
   for(j = 1;j<10;j++)
   {
       for(i = 1;i < 10;i++)
       {
          result = i*j;
          printf("%d × %d = %-4d",i,j,result);  //-4表示左对齐，占三位,就是相邻的之间有四个空格
       }
       printf("\n");

   }
}


1*1= 1  1*2= 2  1*3= 3  1*4= 4  1*5= 5  1*6= 6  1*7= 7  1*8= 8  1*9= 9
2*1= 2  2*2= 4  2*3= 6  2*4= 8  2*5=10  2*6=12  2*7=14  2*8=16  2*9=18
3*1= 3  3*2= 6  3*3= 9  3*4=12  3*5=15  3*6=18  3*7=21  3*8=24  3*9=27
4*1= 4  4*2= 8  4*3=12  4*4=16  4*5=20  4*6=24  4*7=28  4*8=32  4*9=36
5*1= 5  5*2=10  5*3=15  5*4=20  5*5=25  5*6=30  5*7=35  5*8=40  5*9=45
6*1= 6  6*2=12  6*3=18  6*4=24  6*5=30  6*6=36  6*7=42  6*8=48  6*9=54
7*1= 7  7*2=14  7*3=21  7*4=28  7*5=35  7*6=42  7*7=49  7*8=56  7*9=63
8*1= 8  8*2=16  8*3=24  8*4=32  8*5=40  8*6=48  8*7=56  8*8=64  8*9=72
9*1= 9  9*2=18  9*3=27  9*4=36  9*5=45  9*6=54  9*7=63  9*8=72  9*9=81


4.输出九九乘法表，共九行九列，i控制行，j控制列

int main()
{
    int i,j;
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            if(j<i)
                //打印八个空格，去掉空格就是左上三角形
                printf("        ");
            else
                printf("%d*%d=%2d  ",i,j,i*j);
        }

        printf("\n");
    }

    return 0;
}


1*1= 1  1*2= 2  1*3= 3  1*4= 4  1*5= 5  1*6= 6  1*7= 7  1*8= 8  1*9= 9
        2*2= 4  2*3= 6  2*4= 8  2*5=10  2*6=12  2*7=14  2*8=16  2*9=18
                3*3= 9  3*4=12  3*5=15  3*6=18  3*7=21  3*8=24  3*9=27
                        4*4=16  4*5=20  4*6=24  4*7=28  4*8=32  4*9=36
                                5*5=25  5*6=30  5*7=35  5*8=40  5*9=45
                                        6*6=36  6*7=42  6*8=48  6*9=54
                                                7*7=49  7*8=56  7*9=63
                                                        8*8=64  8*9=72
                                                                9*9=81

	
	
	
	
8.输出九九乘法表，共九行九列，i控制行，j控制列
/*
  打程序的时候是一行一行打的，所以意思就是要发现一行当中的规律，总体来说就是要打空格和两个数字，第一行有八个整体空格，往下依次减少
  第二个就是打数字
*/
int main()
{
    int i,j,n;
    for(i = 1;i <= 9;i++)
    {
        for(n=1;n<=9-i;n++)
            printf("         ");

        for(j=1;j<=i;j++)
            printf("%d×%d=%2d  ",i,j,i*j);
        printf("\n");
    }
}


                                                                1×1= 1
                                                        2×1= 2  2×2= 4
                                                3×1= 3  3×2= 6  3×3= 9
                                        4×1= 4  4×2= 8  4×3=12  4×4=16
                                5×1= 5  5×2=10  5×3=15  5×4=20  5×5=25
                        6×1= 6  6×2=12  6×3=18  6×4=24  6×5=30  6×6=36
                7×1= 7  7×2=14  7×3=21  7×4=28  7×5=35  7×6=42  7×7=49
        8×1= 8  8×2=16  8×3=24  8×4=32  8×5=40  8×6=48  8×7=56  8×8=64
9×1= 9  9×2=18  9×3=27  9×4=36  9×5=45  9×6=54  9×7=63  9×8=72  9×9=81

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
               排列组合和集合   
============================================ 
————————————————————————————————————
              子集问题
————————————————————————————————————
1.使用下标法列出一个集合的所有子集
#include <stdio.h>
#include <stdlib.h>  //malloc的头文件

void display(int *, int);



int main()
{

    set_partition(5);
}
void set_partition(int n)   //n是数组当中的最大元素
{
    int *code, *maxi;
    int i, j;

    //动态分配内存
    code = (int *)malloc(sizeof(int) * n);
    maxi = (int *)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
    {
        code[i] = 1;   //初始化这个当中的所有的元素为1
        maxi[i] = 2;   //初始化这个当中的所有的元素为2，这个是最大值
    }
    /**这个输出的结果是1111 1112（2是当位最大元素） 1121 1122 1123（3是当位最大元素，2是当位最大元素，1不是当位最大元素）
         1211 1212 1213 1221 1222 1223 1231 1232 1233 1234
         第一位的最大数字只能是1，第二位的最大数字只能是2，第三位的最大数字只能是3，第四位的最大数字只能是4
         什么意思：就是当本位数字达到最大值后，我就希望第一个没有达到最大值数字低增一位，把他后面的数字设为1，从新输入
         ，如果没有达到最大值，就让它一直递增**/

    while(1)
    {
        display(code, n);     //输出code当中的所有的元素
        for(i = n - 1; code[i] == maxi[i]; i--);      //从右往左数，找出第一个不是最大值的数字，且这个数字的下标是i
        if(i > 0)    //第一个数字不能动，必须是1
        {
            code[i]++;  
            for(j = i + 1; j < n; j++)   //j应该是i的下一位元素
            {
                code[j] = 1;//如果i不是最后一个元素，把它后面的元素初始化为1
                maxi[j] = maxi[i] +((code[i] == maxi[i] ? 1 : 0));  //如果i达到了当前位的最大值，把它的下一位的最大值设成i当前位最大值加1
            }
        }
        else
            break;
    }
    free(code);
    free(maxi);
}

void display(int *code, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%3d", *(code + i));
    printf("\n");
}

/**
	这个算法太巧妙了，我大概复述一下这个的意思，首先分为两个数组，一个数组就是正儿八经遍历每个数字的，另一个数组就是记录每个数组
	上的最大值的
	首先从末尾开始遍历，如果这个数字没有达到最大值，就让这个位置上的数字一直递增，如果达到了最大值，就让这一位数字的上一位数字递增
	，剩下的位置全部设为0
	如何确定每个位置上的最大值，总的来说一条规则就是目前为止所有数字的最大值加1，就是某个位置上的最大值
	这个算法的主要就是分治法，如何分治，就是把这个问题不断分成无数个小问题，把每一个小问题解决，大问题就得以解决，而分治法在
	这里的具体应用就是，从后往前确定一个位置上的最大值，输出这个最大位置之后的全排列
	所以就得出一个结论，以后位置上的最大值是目前这个最大值加1
**/
输出：
  1  1  1  1  1 
  1  1  1  1  2
  
  1  1  1  2  1
  1  1  1  2  2
  1  1  1  2  3
  
  1  1  2  1  1
  1  1  2  1  2
  1  1  2  1  3
  
  1  1  2  2  1
  1  1  2  2  2
  1  1  2  2  3
  
  1  1  2  3  1
  1  1  2  3  2
  1  1  2  3  3
  1  1  2  3  4
  
  1  2  1  1  1
  1  2  1  1  2
  1  2  1  1  3
  
  1  2  1  2  1
  1  2  1  2  2
  1  2  1  2  3
  
  1  2  1  3  1
  1  2  1  3  2
  1  2  1  3  3
  1  2  1  3  4
  
  1  2  2  1  1
  1  2  2  1  2
  1  2  2  1  3
  
  1  2  2  2  1
  1  2  2  2  2
  1  2  2  2  3
  
  1  2  2  3  1
  1  2  2  3  2
  1  2  2  3  3
  1  2  2  3  4
  
  1  2  3  1  1
  1  2  3  1  2
  1  2  3  1  3
  1  2  3  1  4
  
  1  2  3  2  1
  1  2  3  2  2
  1  2  3  2  3
  1  2  3  2  4
  
  1  2  3  3  1
  1  2  3  3  2
  1  2  3  3  3
  1  2  3  3  4
  
  1  2  3  4  1
  1  2  3  4  2
  1  2  3  4  3
  1  2  3  4  4
  1  2  3  4  5

2.输出一个集合所有的子集
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch[100];
    int position = 1;
    int i;
    int max;
    char line[100];

    printf("Please enter a number:");
    gets(line);
    max = atol(line);

    if(1 == max)
    {
        printf("{}\n{1}");
    }
    else
    {
        printf("{}\n");
        ch[0] = position;
        while(ch[0] != max)
        {
            //遍历输出这个集合中的元素，并且用position来控制集合中元素的个数
			printf("{");
            for(i = 0; i < position; i++)
                printf("%d ",ch[i]);
            printf("}");
            printf("\n");
			
			//集合中的元素只有两种情况，达到了最大值，没有达到最大值
            if(ch[position - 1] == max)
            {
                ch[position - 2] = ch[position - 2] + 1;
                position--;
            }
            else
            {
                ch[position] = ch[position - 1] + 1;
                position++;
            }
        }
        printf("{%d}", max);
    }
}

3.列出所有子集，字典序列
int main()
{
    int set[20];
    int n, i;
    int position;
    char line[100];

    printf("请输入您想要的数字：");
    gets(line);
    n = atoi(line);

    printf("\n{ }");
    position = 0;       //目前最右边的元素
    set[position] = 1;    //存放元素的集合

    while(1)
    {
        //遍历输出每行的元素
        printf("\n{%d",set[0]);
        for(i = 1; i <= position; i++)
            printf(", %d",set[i]);
        printf("}");

        //把每个数组中放入的元素，如果这个位置上的数字不是最大，那么，输出它的下一位数字，它的下一位数字等于这一位数字加1
        if(set[position] < n)
        {
            set[position + 1] = set[position] + 1;
            position++;
        }
        else if (position != 0)    //那么，这个else if就是当positon是数组中最大的元素的时候
            set[--position]++;  //先让position减1，再让position所对应的数字加1
        else
            break;  //是最大的元素，而且是第一个元素
    }
}


4.列出{1，2，3，4........n}所有的子集
int main()
{
    char digit[20];   //这是定义了一个char型数组，目的就是为了使用gets函数
    int i, j;
    int n;
    char line[100];

    printf("这个集合中最大的数为：");
    gets(line);
    n = atoi(line);  //把字符转换成整型

    //把这个集合中所有的位都设为0
    for(i = 0; i < n; i++)
        digit[i] = '0';

    printf("\n{ }");

    while(1)
    {
        /**
			如何输出01的全排列，还是分治法，遇到0改成1，遇到1改成0
			首先，一个位置上的情况有达到最大和没有达到最大，没有达到最大，就让他递增，如果达到最大，就上一位递增，上一位之后的设为1
			这里最大的数字只能是1，所以很好办，找到第一个为0的数字，把它改为1，如果这个数字是1，改为0，同时i++，i++的目的就是下一个
			该改为1的下标
			00000
			00001
			00010
			00011
			00100
			00101
			00110
			00111
			01000
			.......
		**/
		//经过这个部分，可以输出一个数字
        for(i = 0; i < n && digit[i] == '1'; digit[i] = '0', i++);//找到第一个为1的地方，把它设为0
        if(i == n)
            break;   
        else
            digit[i] = '1';
            
        
        //这个部分时完成输出，为什么不直接完成输出，使用循环可以先快速定位到1的位置，省时间
        //定位到第一个1的位置，完成第一个输出    
        for(i = 0; i < n && digit[i] == '0'; i++);
        printf("\n{%d", i + 1);    //i + 1的意思是实际的数组是{1，2，3，}，所以得加1
        
        
        for(j = i + 1; j < n; j++)
        {
            if(digit[j] == '1')    //寻找下一个为1的下标
                printf(",%d", j + 1);
        }
        printf("}");
    }

}
5.列出子集
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//二进制数取子集，通过01来控制元素是否输出，刚才那个是对的，这个是错的
void input_num(int two[100], int num[], int n);
int main(void)
{
    int two[100];
    int num[100];
    int one[100];
    int n;
    int i, j;

    printf("请输入集合中元素的个数：");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        printf("请输入集合中第%d个数:", i + 1);
        scanf("%d", &num[i]);
    }

    for(i = 0; i < n; i++)
    {
        two[i] = 0;
        one[i] = 1;
    }
    printf("{ }\n");

    i = n - 1;

    while((memcmp(two, one, n-1)) != 1)
    {

        if(two[i] == 1)
        {
            j = i;
            for(;j > 0;j--)
            {
                if(two[j - 1] == 0)
                {
                    two[j - 1] = 0;
                    input_num(two, num,n);
                    break;
                }
                else continue;
            }
        }
        else
        {
            two[i] = 1;
            input_num(two, num,n);
            i--;
        }
    }
}
void input_num(int two[], int num[], int n)
{
    int i;
    printf("{");
    for(i = 0;i < n;i++)
    {
        if(two[i] == 0)
            continue;
        else
            printf("%d ",num[i]);
    }
    printf("}   ");
}

————————————————————————————————————
        n个数有多少种组合方式
————————————————————————————————————
5.产生所有的排列——旋转法（**************）
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ROTATE(p) {int i, temp;\
                   temp = perm[p];\
                   for(i = p - 1; i >= 0; i--)\
                        perm[i + 1] = perm[i];\
                   perm[0] = temp;\
}

int main(void)
{
    int perm[20];
    int position;
    int n;
    int i;
    char line[100];
    printf("请输入你想要的数字：");
    gets(line);
    n = atoi(line);

    //初始化数组和位置的指向
    for(i = 0; i < n; i++)
        perm[i] = i + 1;
    position = n - 1;   //这一步初始化是当作循环条件，和下面的初始化所得到的数字一摸一样，但含义不一样

    //把元素输入数组和元素的输出
    while(position != 0)
    {
        //数组元素的输出
        printf("\n");
        for(i = 0; i < n; i++)
            printf("%d", perm[i]);

        /*分为两步，确定一个头数字和让这个头数字把最后一位放到第一位*/

        //让这个头数字把最后一位放到第一位
        position = n - 1;
        ROTATE(position);

        while(perm[position] == position + 1 && position != 0)//当这个数字当位且这个数字的位置不在第一位
        {
            position--;      //位置往前移动一位
            ROTATE(position);      //让position--后的这个位置上的数字移动到首位，把移动后的数字作为头数字
        }
    }
}


请输入你想要的数字：3

123
312
231
213
321
132

————————————————————————————————————
      一个数是哪些正整数的和
————————————————————————————————————

7.找出一个数是哪些连续正整数的和
int main(void)
{
    //这个是我通过找规律找出来的，如果是连续两个数，连续三个数
	//连续四个数，规律是如何
	int n;
    int i;
    int i1 = 3;
    int j = 2;
    int k;
    int m;
    printf("请输入这个正整数：");
    scanf("%d",&n);

    for(i = 3; i <= n; i += i1, i1 += 1)
    {
        if((n - i) % j == 0)
        {
            k = (n - i) / j;
            printf("%d = ",n);
            for(m = 1; m <= j - 1;m++)
                printf("%d + ", k + m);
            printf("%d\n",k + m);
            j += 1;

        }
        else
        {
            j += 1;
            continue;
        }
    }
}

8.找出一个数是哪些连续正整数的和
int main(void)
{
     
	 long left, right;
     long sum;
     long GIVEN;
     char line[100];

     gets(line);
     GIVEN = atol(line);  //把字符串类型转换成长整型

     for(sum = 0,left = right = 1;left < GIVEN / 2 + 1; right ++)    //先让左边和右边的值都等于1
     {
         sum += right; //相当于1 + 2 + 3 + 4.........
         while(sum > GIVEN)
         {
             sum -= left;  //相当于把上面从左开始一一刨掉，之后left++
             left++;
         }
         if(sum == GIVEN)   //如果相等，就输出
            printf("\n%ld - %ld",left, right);
     }
}
    
9.找出一个数是哪些连续正整数的和
int main()
{
    long left, right;
    long sum;
    long GIVEN;
    int count = 0;
    char line[100];
    
    //输入数字
    printf("请输入你想要的数字:");
    gets(line);
    GIVEN = atol(line);
    
    //这个程序比上一个好在此处做了优化，先通过一个循环让数字加到比GIVEN小的一个数字，只是在这里做了优化
    for(sum = 0, right = 1; sum < GIVEN; sum += right, right++); ///left和right都属于实数
    
    for(left = 1,right--; left <= GIVEN  / 2;)  //right--的目的是上一步执行完最后一次循环之后，right++，这一步让他减回来
    {
        if(sum > GIVEN)
            sum -= (left ++);  //先减去最左边的数，再++
        else
        {
            if(sum == GIVEN)
            {
                printf("\n%ld = sum from %ld to %ld", GIVEN, left, right);  //相等，输出
                count ++;  //计数器，看看程序有没有执行这一步
            }
            sum += (++right);   //加上最右边递增之后的数
        }
            
    }
    if(count > 0)
        printf("\n\nThere are %d solutions in total.",count);
    else
        printf("\n\nSorry , there is NO solution at all.");
		
		
10.找出一个数是哪些连续正整数的和
//笨蛋方法
int main(void)
{
   char line[100];
   long sum, i, j, n;

   gets(line);
   n = atol(line);  //把字符串转换成长整型

   for(i = 1; i <= n / 2; i++)
   {
       for(sum = 1,j = i + 1; j <= n / 2 + 1; j++)
       {
           sum += j;
           if(sum == n)     //让它一个一个加，通过和输入的数字进行比较
              printf("\n%ld - %ld", i, j);
       }
   }
}
————————————————————————————————————
         斐波那契数列问题
————————————————————————————————————

11.Fibonacci数列非递归解
void main(void)
{
    int n;
    int Fn;
    int i;
    int a = 1;
    int b = 1;
    printf("请输入您想要的斐波那契数：");
    scanf("%d",&n);
    if(n <= 2)
        printf("\nFn = 1\n");
    else
        for(i = 0; i < (n / 2 - 1); i++)
        {
            a = a + b;
            b = b + a;
        }
    if(n % 2 == 0)
        printf("Fn = %d",b);
    else
        printf("Fn = %d",a + b);
}

_____________________________________________
unsigned long fibonacci(int n)
{
    unsigned long f0, f1, temp;
    int i;
    if(n <= 2)
        return 1;
    else
    {
        for(f0 = f1 = 1, i = 3;i <= n;i++)  
        {
            temp = f0 + f1;//类似于交换函数
            f0 = f1;
            f1 = temp;
        }
        return f1;
    }
}
______________________________________________

int main(void)
{
    int n;          //输出n所对应的斐波那契数列
    int num[100];   //数组实现法
    int i;
    printf("请输入你想要的数字：");
    scanf("%d", &n);
    num[0] = 1;
    num[1] = 1;
    if(n == 1 || n == 2)
        printf("对应的斐波那契数为1");
    else
    {
        for(i = 2; i <= n; i++)
        {
            num[i] = num[i - 1] + num[i - 2];
        }
        printf("对应的斐波那契额数列为：%d", num[i - 2]);
    }
}



12.Fibonacci数列递归解
unsigned long fibonacci (int n)
{
	if(n <= 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

————————————————————————————————————
           二项式系数问题
————————————————————————————————————
13.二项式系数递归解
int cnr(int n, int r)
{
	if(n == r || r == 0)
		return 1;
	else
		return cnr(n - 1, r) + cnr(n - 1, r - 1);
	
}

-----------------------------------------------------
void cnr(int n, int *answer, int m)
{
   int i;
   int answer1[10];
   answer1[0] = 1;
   if(m <= n)
   {
       answer1[m] = 1;
       for(i = 0; i <= m; i++)
       {
           if(i > 0 && i < m)
               answer1[i] = answer[i] + answer[i - 1];
           printf("%d", answer1[i]);
       }
       printf("\n");
       m++;
       cnr(n, answer1, m);
   }
   else
       return;

}


int main()
{
    int answer[20];
    int m = 0;
    cnr(4, answer, m);
}


14.二项式系数加法解
           1
	1	   1 1
	2	   1 2 1
	3	   1 3 3 1
	4	   1 4 6 4 1
      r    0 1 2 3 4     
int cnr(int n, int r)
{
	int answer[MAXSIZE];
	int i, j;
	answer[0] = 1;
	for(i = 1; i <= n; i++)   //从第二行开始
	{
		如果从前往后处理，就会把之前的数字改变，导致错误
		for(answer[i] = 1,j = i - 1;j >= 1; j--)   //把这一行最后一个数字设为1，j = i - 1意思是从这个数开始处理
			answer[j] += answer[j - 1];  //这个数字等于它头上的＋它左上角的
	}
	return answer[r];  //把这一行的数字输入到一个数组中，用下标来获取这个元素
}



15.上面的方法，但是加法次数减少，没有无用的加法
#define MAXSIZE 100
unsigned long cnr(int n, int r)
{
	unsigned long c[MAXSIZE];
	int i, j;
	for(i = 0;i <= r;i++)  //把第一行的第一个，第二行的第二个都设为1，就是斜着的第一行
	{
		c[i] = 1UL;  //UL是unsigned longleix
	}
	
	
	
	//竖的第一行每次循环1往下移一个，不动
	for(i = 1; i <= n - r; i++)  //外层控制行，这个公式是推出来的，很好推
	{
		for(j = 1;j <= r;j++)    //内层控制列
			c[j] += c[j - 1];
	}
	return c[r];

}

//看到这个平行四边形没有呀，行是斜着的

1
1 1
1 2 1
  3 3 
    6

————————————————————————————————————
              质数问题
————————————————————————————————————	
15.选出质数
int main(void)
{
    unsigned long num;   //待测试的数
    unsigned long div;   //可能的约数
    bool isPrime;        //素数标识
    printf("请输入一个数字：");
    while(scanf("%lu",&num) == 1)
    {
        for(div = 2,isPrime = true;(div*div <= num);div++)  //使用了逗号运算符，每次输入都可以把isPrime设置为true
        {
            if(num % div == 0)
            {
                if(num % div != num)
                    printf("它不是素数");
                else
                    printf("它不是素数，且开根号能开尽");
                isPrime = false;
            }
        }
        if(false)
            printf("该数不是素数");
    }
}
	

17.选出质数(如何跳过倍数)
#define MAXSIZE 100
#define YES 1
#define NO 0

void main()
{
    int prime[MAXSIZE];
    int gap = 2;
    int count = 3;
    int may_be_prime = 5;//输入0-5之内的质数
    int i, is_prime;
    
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    
	//往一个数组里输入MAXSIZE个质数，count是质数计数器
	//may_be_prime要先加2，后加4
    while(count < MAXSIZE)
    {
        //跳过2和3的倍数 5  7  11  13  17  19
        may_be_prime += gap;
        gap = 6 - gap;
        is_prime = YES;
        
        //因为跳过了2和3的倍数，所以不用除prime[0]和prime[1]，直接从2开始除
        //夸奖一下，这个开关函数使用的非常好，具体操作为：如果除以某个数可以除进，就不执行某个步骤如果除不尽
        for(i = 2; prime[i] * prime[i] <= may_be_prime && is_prime; i++)
        {
            if(may_be_prime % prime[i] == 0)
                is_prime = NO;
        }
        if(is_prime)
            prime[count++] = may_be_prime;
			
	
   //如何打印十个一行
   for(i = 0;i < count;i++)
   {
       if(i % 10 == 0)
       {
            printf("\n");
       }
	   printf("%5d",prime[i]);
   }

}

   
16.选出质数
/*
	筛选出质数，首先质数除了2以外,都是奇数，奇数可以放在一个数组中，
	且与下标的关系为2i + 3,如果要筛掉这些奇数当中的合数，
	 首先这些合数肯定是奇数的倍数，
	（2n+1）(2i+3),化简得到n*(2i+3)+i
	如何得出上面的这个式子（2i+3）通过下标i找到这个奇数
	合数肯定是奇数的倍数所以（2i+3）可以乘1 2 3 4 5 6 7 8....如果乘偶数就是
	偶数了，而这个数组里没有偶数，所以必须乘以奇数
*/
void main()
{
   int sieve[201];
   int count = 1;
   int prime;
   int i, k;
   for(i = 0;i <= 200;i++)
   {
       sieve[i] = 0;    //这一步是把所有元素设为0
   }
   for(i = 0; i <= 200;i++)
   {
       if(sieve[i] == 0)
       {
           prime = i + i + 3;   //计算机喜欢加法，所以不用2i + 3
           count++;
           for(k = prime + 1;k <= 200;k += prime)  //k的初值就是2i + 3 + i，这个循环相当于循环那个n
                sieve[k] = 1;    //找到要删除的数，把他设为1
       }
   }
   for(i = 0,k = 2;i <= 200;i++)
   {
       if(sieve[i] == 0)
       {
           if(k > 10)
           {
               printf("\n");
               k = 1;
           }
           printf("%6d", 2 * i + 3);//输出的数都是奇数
           k++;
       }
   }
}	

17.还是找质数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEXT(x) x = next[x]  //找出比x大但未曾删除的下一个元素

//如果这个数是一个合数，这个数删除的过程，让m的上一个元素的下一个指针指向m的下一个元素，再把m的下一个元素的上一个指针指向m的上一个元素
//
#define REMOVE(x) {next[previous[x]] = next[x];\
                   previous[next[x]] = previous[x];\
                  }
//=不是赋值的意思，而是指向下一个元素的地址
#define INITIAL(n) {unsigned long i;\
                        for(i = 2;i <= n; i++)\
                            previous[i] = i - 1, next[i] = i + 1;\
                        previous[2] = next[n] = NULL;\
                   }
void main()
{
    unsigned long previous[1001];
    unsigned long next[1001];
    unsigned long prime, fact, i, mult;
    unsigned long n;
    unsigned long count = 0;
    char line[100],dummy; //如果想要用下面的strtoul函数，必须的先定义一个char型数组和另外一个值

    printf("请输入范围的最大值:");
    gets(line);
    n = strtoul(line, &dummy, 10);  //最后一个是转化成的进制数，意思就是把输入的字符转化成数字
    INITIAL(n);   //把previous中的元素和next中的元素初始化
    /**
      第一个数是2
      先删除        2的3次 2的4次 2的5次 2的6次
      再删除 2 * 3  2的2次 * 3  2的3次 * 3  2的4次 * 3  2的5次 * 3
      还有   2 * 5  2的2次 * 5  2的3次 * 5  2的4次 * 5  2的5次 * 5
    */


    for(prime = 2;prime * prime <= n;NEXT(prime))  //第一个测试的值是2，这层循环是控制最外边2
    {
        for(fact = prime; prime * fact <= n; NEXT(fact))  //这个控制外面的3，5
        {
            for(mult = prime * fact; mult <= n; mult *= prime)//这个是让它反复乘2
                REMOVE(mult);  //这个是要把删除的数字替换掉
        }
    }
    for(i = 2; i != NULL; NEXT(i))
    {
        if(count % 8 == 0)
            printf("\n");
        printf("%2d",i);
        count++;
    }
}
 
————————————————————————————————————
              分解因子问题
————————————————————————————————————
18.分解因子
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这个函数的意思是让符合条件的输入到数组中，count++的意思是先取值，后递增
#define SAVE_FACTOR(fact, exp){if(exp > 0)\
                                    factors[count] = fact;\
                                    exps[count++] = i;\
                              }
//因子分解72 = 2（3）* 3（2）
void main()
{
    unsigned long factors[100];
    unsigned long exps[100];
    unsigned long n, work;
    int count = 0;
    int i, k;
    char line[100], *dummy;
    
    printf("请输入最大的限度：");
    gets(line);
    n = strtoul(line, &dummy, 10); //以后要用这个函数就得写成这个形式，不要管dummy和&dummy啥意思
    
    //如果是二进制的偶数，那么最后一位肯定是0，条件为真，执行循环，如果是奇数，最后一位一定是1，因为偶数除以2一定可以除尽，work >>= 1 意思是
    //work左移一位，指的是变为原来的1/2，比如1000 = 8，100 = 4；又因为是偶数，所以除2肯定可以除尽
    //0x01UL是十六进制的1，同时这个1是一个unsigned long型
    //这个的目的就是把是2的先输出来，接下来再用奇数就比较好
    for(i = 0, work = n; (work & 0x01UL) == 0 && work > 1; work >>= 1,i++);//work是输入的数
    SAVE_FACTOR(2, i);
    
    
    for(k = 3;k <= work; k += 2)//输出的全是奇数
    {
        for(i = 0; work % k == 0 && work > 1; work /= k, i++);
        SAVE_FACTOR(k, i);
    }
    
    printf("\n%ld = ",n);
    for(i = 0; i < count; i++)
        printf("%ld(%ld)",factors[i], exps[i]);

}

19.
如果x[]的元素是3，6，2，1，4，5，2
x[]的前置和 3，9，11，12，16，21，23，
x[]的后置和 2，7，11，12，14，20，23
#include <stdio.h>
#include <stdlib.h>
//求等值首尾和
void main()
{
    int x[100];
    int n;  //数组中元素的个数
    int a,b;//相当于循环变量
    int num = 0;
    int i;
    int num_1,num_2;//相当于累和
    /*********************************************************************/
    printf("请输入您想往x数组中输入元素的个数:");
    scanf("%d",&n);
    printf("请输入您想往x数组中输入的元素:");
    for(i = 0;i < n;i++)
    {
        scanf("%d",&x[i]);
    }
    a = 0;
    b = (n - 1);
    num_1 = x[a];
    num_2 = x[b];
    /*********************************************************************/
    while(a <= (n - 1) && b >= 0)
    {
        if(num_1 > num_2)
        {
            b = b - 1;
            num_2 += x[b];
        }
        else if(num_1 < num_2)
        {
            a = a + 1;
            num_1 += x[a];
        }
        else
        {
            num += 1;
            b = b - 1;
            num_2 += x[b];
            a = a + 1;
            num_1 += x[a];

        }
    }
    printf("相等的元素个数为：%d",num);

}

20.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    int num[100] = {1,1,2,2,2,3,3,3,3};
    int k = 9;
    int *to;
    int i,j,h,q;
    h = 0;
    q = 0;
    int a,c,b;
    int *be;

    //printf("请您输入您想要的数字:");
    //fgets(num, 100, stdin);
    //k = strlen(num);  //k的值是输入的加1

    //测量开始几个数字的长度  a
	
    a = 1;
    printf("\n%d\n",num[h]);
    while(num[h] == num[h + 1])
    {
        a = a + 1;
        h++;
    }
    be = num + a - 1;

    //进行排列
    for(i = a;i < (k - 1);i = i + b)
    {
        b = 1;
        while(1)
        {
            to = num + i + b - 1;
            if(*to != *(to + 1))
            {
                if(b > a)
                {
                    a = b;
                    be = be + i - a + b;
                    break;
                }
                else break;
            }
            else b++;
        }
    }
    printf("在您输入的数字中，最长的数字为%d，对应的长度为%d",*be,a);
}


21.
    char num[100];
    int k;
    char *to;
    int i,j,h,q;
    h = 0;
    q = 0;
    int a,c,b;
    char *be;

    printf("请您输入您想要的数字:");
    fgets(num, 100, stdin);
    k = strlen(num);  //k的值是输入的加1
    //测量开始几个数字的长度  a
    a = 1;
	
22.
#include <stdio.h>
#include <stdlib.h>
//求两组数的最短距离
void main()
{
    int x[100];
    int y[100];
    int a,b;  //数组中元素的个数
    int index_x = 0,index_y = 0;
    int m,n,b;
    int i;
    /*********************************************************************/
    printf("请输入您想往x数组中输入元素的个数:");
    scanf("%d",&a);
    printf("请输入您想往x数组中输入的元素:");
    for(i = 0;i < a;i++)
    {
        scanf("%d",&x[i]);
    }

    printf("请输入您想往y数组中输入元素的个数:");
    scanf("%d",&b);
    printf("请输入您想往y数组中输入的元素:");
    for(i = 0;i < b;i++)
    {
        scanf("%d",&y[i]);
    }
    /*********************************************************************/
    if(x[0] > y[0])
        m = x[0] - y[0];
    if(y[0] > x[0])
        m = y[0] - x[0];
    /*********************************************************************/

    while((index_x < a) && (index_y < b))
    {
        if(x[index_x] < y[index_y])
        {
            n = y[index_y] - x[index_x];
            if(m > n)
                m = n;

            index_x ++;
        }
        else if(x[index_x] > y[index_y])
        {
            n = x[index_x] - y[index_y];
            if(m > n)
                m = n;
            index_y++;
        }
        else//我之前写的是else(x[index_x] == y[index_y])，频繁报错，应该只写一个else
        {
            m = 0;
            break;
        }
    }
    printf("两组数中的最短距离为:%d",m);

}

//又来敲黑板了，还有一种更机智的做法，定义函数#define min(x, y)  ((x) < (y) ? (x) : (y))
//这个不机智，反而增加了运算次数
定义函数需要注意的点里面每一次，每一个字符都得加括号，定义函数外头还要加一个括号
while(index_x < m && index_y < n)
{
	if(x[index_x] >= y[index_y])
	{
		minimun = min(minimum, x[index_x] - y[index-y]);
		index_y++;
	}
	else
	{
		minimun = min(minimum, y[index_y] - x[index-x]);
		index_x++;
	}
}
--------------------------------------------------------------------------------------------------------------------------------
1.数组中和为0的段落
//数组中和为0的段落，已知一个整数数组，其中可能有正整数，负整数和0，而且元素也不会重复出现，是否有一个子数组为0
//如果数组中的n个元素写成x1, x2......xn.若xi+x(i + 1)+....+xj = 0,考虑x1 + x2 ....+xi与x1+x2+....+xi

//看不懂
void sort(int[], int);   //先排序它的效率会提高好多

int zero_sum(int x[], int n)
{
    int i; 
    for(i = 1; i < n; i++)
    {
        x[i] += x[i + 1];
    }
    
    sort(x, n);
    for(i = 1; i < n && x[i] != x[i - 1]; i++);
    return (i == n) ? NO : YES;
}

2.
//检查元素是否相异
//已知一个数组，请写一个程序把相同的元素去掉只留一个

void sort(int [], int);
void unique(int x[], int n, int *number)
{
    int i;
    
    sort(x, n);
    *number = 1;
    
    for(i = 1; i < n; i++)
    {
        if(x[i] != x[i - 1])
            x[(*number)++] = x[i];
    }
}

3.把一个含有相同元素的数组从小到大排列
//一个数组中有n个元素，只有大约log(2,n)个值是不同的，有n - log(2, n)个值全部都一样
1233
/**
	这个题目大概的意思就是一个数组里有一个重复的数字，要进行排序。先得找出这个数字，如果两个相邻数字相同，就是这个数字，之后把这个数组里
	其他数字输入到这个数组之前，最后再补上这个数字，把这些数字进行排序，排好序的数字就在这个数组之前，之后从后往前看，如果数字不等于重复
	数字，就放在末尾，直到等于重复数字，把其他空位上都补上这个重复数字

**/
void sort(int [], int);

void dup_sort(int x[], int n)
{
    int dup;
    int count, index, i, j;
    
    for(i = 1; i < n; i++)  //找出这个重复元素
    {
        if(x[i] == x[i - 1])
        {
            dup = x[i];
            break;
        }
    }
    
    for(count = i = 0; i < n; i++)
    {
        if(x[i] != dup)
            x[count++] = x[i];   //把除了这个重复元素以外的数字都输入到x数组之前，并把dup元素也输进去，count指向的是空元素
    }
    x[count++] = dup;
    
    sort(x, count);   //最后一次执行的是count++   因为输入的是需要排序元素的个数，和下标的关系
    
    for(index = n - 1, i = count - 1; i >= 0 && x[i] != dup; i--)
        x[index--] = x[i];   //把排好序的元素从后往前数，依次放到这个数组最末端的位置，直到i所指的元素是dup
        
    if(i >= 0 && x[i] == dup)           
    {
        for(j = i + 1; j <= index; j++)
            x[j] = dup;
    }
      
}
4.
#include <math.h>

#define MIN(x, y) ((x) <= (y) ? (x) : (y))
#define SWAP(x, y) {int *t; t = x; x = y; y = t;}

//均匀重复元素排序，就是一个数组里全部元素都是重复的，且重复出现的次数相同
//一个数组有n个元素，一组有log(2, n)个元素, 有n / log(2, n)组
//一个数组中有n个元素，只有大约log(2,n)个值是不同的，有n - log(2, n)个值全部都一样

//如果第一组元素是1,4,4,5,7,8,9,9  第二组2,4,5,5,7,7,8  合并起来的数据是1，2，4，5，7，8，9  另一个数组是1,1,3,3,3,2 
//一个数组记录数字，另一个记录数字的个数

//记住这些都是全局变量
int *in1_data, *in2_data, *out_data;
int *in1_count, *in2_count, *out_count;
int number;

void LOG_sort(int [], int);
int LOG_merge(int [], int, int);
int compress(int [], int, int *, int *);
void LOG_expand(int []);
void sort(int [], int);

void LOG_sort(int x[], int n)
{
    int log_n = (int)(log((double)n) + 0.5);
    int i;
    for(i = 0; i < n; i += log_n)
        sort(x + i, MIN(log_n, n - i));       //这一步首先完成了分组，并且把每一组的元素都排好了顺序
                                              /*例如有一组元素 3 4 3 2   1 3 1 1   4 3 2 2   4 2 1 4
                                                      排序之后 2 3 3 4   1 1 1 3   2 2 3 4   1 2 4 4*/
        
    in1_date = (int *)malloc(sizeof(int) * log_n);
    in2_date = (int *)malloc(sizeof(int) * log_n);
    out_date = (int *)malloc(sizeof(int) * log_n);
    in1_count = (int *)malloc(sizeof(int) * log_n);
    in2_count = (int *)malloc(sizeof(int) * log_n);
    out_count = (int *)malloc(sizeof(int) * log_n);
    
    number = LOG_merge(x, n, log_n);   //number是互不相等的元素的个数
    LOG_expand(x);
    
    free(in1_data);
    free(in2_data);
    free(out_data);
    free(in1_count);
    free(in2_count);
    free(out_count);
}


int LOG_merge(int x[], int n, int seg_size)   //每组有seg_size个元素  
                                              /*工作是把它合并起来：合并第一组和第二组   1(3) 2(1) 3(3) 4(1)
                                                                      之后与第三组合并   1(3) 2(3) 3(4) 4(2)
                                                                          与第四组合并   1(4) 2(4) 3(4) 4(4)*/
{
    int no1, no2;
    int start, len;
    int i, j, k;
    
    no1 = compress(x, seg_size, in1_data, in1_count);   //no1是第一个组当中no1个互不相同的元素
    
    for(start = seg_size; start < n; start += len)     //第一组元素已经处理过，从第二组元素开始处理
    {
        len = MIN(seg_size, start);
        no2 = compress(x + start, len, in2_data, in2_count);  //第二个组当中no2个互不相同的元素
        
        for(i = j = k = 0; i < no1 && j < no2; )              //合并这两个片段，分别有no1和no2个元素，且in1_data, in1_count已知
                                                              //in2_data, in2_count已知，data是存数据的，count是存有多少个数据的
        {
            if(in1_data[i] < in2_data[j])
            {
                out_data[k] = in1_data[i];
                out_count[k] = in1_count[i];
                i++;
                k++;
            }
            else if(in1_data[i] > in2_data[j])
            {
                out_data[k] = in2_data[j];
                out_count[k] = in2_count[j];
                j++;
                k++;
            }
            else
            {
                out_data[k] = in1_data[i];
                out_count[k] = in1_count[i] + in2_count[j];
                i++;
                j++;
                k++;
            }
        }
        
        //这一步的主要目的就是排除如果第一段只比了一个，而第二段全比完了的情况    
        for(; i < no1; i++, k++)
        {
            out_data[k] = in1_data[i];
            out_count[k] = in1_count[i];
        }
        for(; j < no2; j++, k++)
        {
            out_data[k] = in2_data[i];
            out_count[k] = in2_count[i];
        }
        
        no1 = k;   //no1现在是合并之后互不相等的元素的个数
        //把该才合并好的数据移动到in1上
        SWAP(in1_data, out_data);
        SWAP(in1_count, out_count);
    }
    return no1;
}

int compress(int x[], int n, int *data, int *count)  //merge取一组的元素交给compress处理，data是存数据的，count是存有多少个数据的
                                                     //就是处理2 3 3 4
{
    int i;
    int no = 0;
    
    if(n == 0)
        return 0;
    else
    {
        data[0] = x[0];
        count[0] = 1;
        for(i = 1; i < n; i++)
        {
            if(x[i] == x[i - 1])
                count[no]++;
            else
            {
                data[++no] = x[i];
                count[no] = 1;
            }
        }
        no++;   //因为数组是从0开始的，所以最后要++
        return no;  //就是返回这里面有no个互不相同的元素
    }
}

void LOG_expand(int x[])  //把值依次重复展开  得到11112222333
{
    int total;            
    int i, j;
    
    for(total = i = 0; i < number; i++)   //number是互不相等的元素的个数，是全局变量 
    {
        for(j = 0; j < in1_count[i]; j++)   //in1的count和data中储存的都是全局变量
            x[total++] = in1_data[i];
    }
}

5.看到下面的数字了吧，往后移堆排序法
#include <stdio.h>
#include <stdlib.h>
#include <limit.h>     //limits.h专门用于检测整型数据数据类型的表达值范围。


//假设有三个文件，这三个文件中的数分别为，且已经从小到大排好序
/*
    1.   4    8    9   16
    2.   1    3    7   20
    3.   2    5    6   18
    
    第一次：先把412取出来，组成一个堆，按从小到大排好序，最顶上的元素就是最小值，同时记录下412所在的文件，把顶上最小值所在文件往下移一个，为3
    第二次：就是432，重复上述步骤
*/
#define MAXSIZE 20
#define YES 1
#define NO 0


void prepare(int [][MAXSIZE], int, int);
int ask_date(int [][MAXSIZE], int);
int delete_top(int *);
void insert(int, int);
void release(void);
void makeheap(void);
void siftdown(void);
void fix_heap(int);


int *heap;
int *location;
int *index;
int file_no;
int file_len;


void heap_merge(int matrix[][MAXSIZE], int m, int n, int out[])  //m个数组，每一个数组都有n个元素
{
    int out_no;
    int row;
    int temp;
    
    prepare(matrix, m, n);//为这些东西都分配好内存，并把堆积准备好
    out_no = 0;
    while((temp = delete_top(&row)) != INT_MAX)//没次取出堆积的顶端元素 delete top会返回顶端元素是在哪一列，当取出的值是int_max就停止
                  //row是所在文件，返回值是堆顶的那个最小值     //INT_MAX是limit.h中的  值是214748647
    {
        out[out_no++] = temp; //每次输出的最小值保存在一个数组中
        insert(ask_data(matrix, row), row);  //ask()从对应的列取出下一个元素，再用insert()函数把它插入到堆积中
    }
    release(); //工作全部做完之后，释放内存
}

void prepare(int matrix[][MAXSIZE], int m, int n)
{
    int i;
    heap = (int *)malloc(sizeof(int) * (m + 1));
    location = (int *)malloc(sizeof(int) * (m + 1));
    index = (int *)malloc(sizeof(int) * m);
    file_no = m;    //记录着列数
    file_len = n;   //记录着行数
    
    for(i = 1; i <= file_no; i++)    //把第一行拿出来放到堆积中， 取出m个文件中的首元素
    {
        heap[i] = matrix[i - 1][0];  //把每一行的第一个元素取出来
        location[i] = i - 1;   //记录着这个元素在heap[]中的位置0 1 2 3 4 5...
        index[i - 1] = 1;    //index里面所有的元素都为1
    }
    makeheap();//然后通过makecheap()把堆积建立起来
}

int ask_data(int matrix[][MAXSIZE], int row) //接受一个值表示列的号码，它先看看该列是否还有数据，如果有，就取出一个作为函数值
                                             //如果没有数据了，就返回INT_MAX这个值
                                             //意思就是从对应的列中取出下一个元素
                                             
{
    if(index[row] >= file_len)
        return INT_MAX;
    else
        return matrix[row][index[row]++];
}

int delete_top(int *row)       //没有真正把堆积顶上的元素去掉，而不过是取出其值，以及指出哪个值来自哪一列的信息而已
{
    *row = lacation[1];//location是所在文件
    return heap[1];//heap是值
}

void insert(int data, int row)   //data要插入的数据 row文件的个数
{
    location[1] = row;  //location是所在文件
    heap[1] = data;     //heap是值
    siftdown();
}

void release(void)
{
    free(heap);
    free(location);
    free(index);
}


void makeheap(void)     //建立一个堆积
{
    int temp;
    int size, i;
    
    for(i = file_no / 2; i >= 1; i--)  //film_no就是有多少个文件， 除以二的目的就是往上移动一列，例如1 3 7 13 
                                       //最后一直到顶上元素被排好为止，此时i = 0
        fix_heap(i);
}


void siftdown(void)    //把第一个元素向下推到合适的位置
{
    fix_heap(1);
}


void fix_heap(int root)    //把最小的值找出来放到顶上，比大小的方向全部相反，rot是倒数第二行最右边的数字，一直向左轮，直到到达顶端                              
{
    int father, son;
    int key_heap = heap[root];  //key就是取值的意思
    int key_loc = location[root];   //lacation和root都是从1开始的
    int done;
    
    father = root;
    son = father + father;
    done = NO;
    while(son <= file_no && !done)    //file_no是有几个文件，就是二叉树所能最大包含的元素的个数
    {
        if(son < file_no && heap[son + 1] < heap[son])
            son++;    //取出最小的儿子
        if(key_heap > heap[son])  //如果爸爸大于儿子
        {
            heap[father] = heap[son];
            lacation[father] = lacation[son];
            father = son;
        }
        else
            done = YES;
        son = father + father;
    }
    
    ///意思就是通过上面的操作，找到father应该呆在那里，对应father的参数有father的值和father所在的文件标号
    heap[father] = key_heap;   //father就是一个位置，找到father的位置，填上ke_heap
    lacation[father] = key_loc;  //key_loc是所在的文件
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                 语法类型  
============================================ 
1.
int main()
{
    char a, b;
    scanf("%c",&a);
    //getchar();  如果想消除换行符的影响，用getchar，如果不加getchar，下面的scanf读取的是空格，输出的也是空格
    //如果输入的是字符串，会自动跳过空白开始读取，不会产生影响，它不输出来不代表它没有，还是会保留在缓冲区中的
    scanf("%c",&b);

    printf("%c\n", a);
    printf("%c\n", b);
    printf("i love anita");

}
2.
printf("$_______\b\b\b\b\b\b\b");//\b的意思是退一格，就是退到横线最开始，输出一个数字，下划线没一个
printf("\n\t$%.2f a month is $%.2f a year.",salary,salary * 12.0);//注意乘的数是12.0符合float形式
printf("%zd\n",sizeof(int));

3.打印浮点值
  int main (void)
{

    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
    printf("%f can be written %e\n",aboat,aboat);//第一个是浮点数，第二个是指数计数法的浮点数
    //下一行要求编辑器支持c99或其中相关特性
    printf("and it's %a in hexadecimal,powers of 2 notation\n",aboat);//%a十六进制的浮点数
    printf("%f can be written %e\n",abet,abet);//第一个是双精度浮点型，第二个是指数计数法的双精度浮点型
    printf("%Lf can be written %Le\n",dip,dip);//长的双精度浮点型，长的双精度浮点型的指数型

    return 0;
}

32000.000000 can be written 3.200000e+004
and it's 0x1.f40000p+14 in hexadecimal,powers of 2 notation
2140000000.000000 can be written 2.140000e+009
0.00053 can be written 2.725000e+002

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
============================================
                 高妙函数 
============================================ 
1.
s_gets函数
char *s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);  //输入成功时，返回char型指针，指向读入字符串的内容
	
	if(ret_val)   //如果输入成功
	{
		find = strchr(st, '\n');   //可以查找字符串s中首次出现字符c的位置，返回该位置的指针，如果找不到，返回空指针
		if(find)
		{
			*find = '\0';
		}
		else                     //处理掉输入行中剩余的字符
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
————————————————————————————————————————————————————————————
char * s_gets(char * st,int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}



/*清理输入行*/
scanf会把\n留在缓冲区,下面的代码只会在输入序列中查找并删除\n
while(getchar() != '\n')
{
	continue;
}
/*只读取第一个字符*/
    char ch;
    ch = getchar();     //首先将读取的第一个字符给ch，
    while(getchar() != '\n')//再读取下一个字符，通过这个循环被弄没
        continue;
    putchar(ch);

2.百位十位个位   （/就是取左   %就是取右）
m = i / 100;
n = i / 10 % 10;
p = i % 10;


3.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char display(int hang,int lie,char ch);//按照行和列打印字符

int main()
{
   int hang1;
   int lie1;
   char ch1;
   printf("请您输入您需要的字符：");
   while((ch1 = getchar()) != '\n')
   {
       printf("请输入您所需要的行数和列数：");
       if(scanf("%d%d",&hang1,&lie1) != 2)    //记住这个scanf的返回值是正确读取元素的个数
       {
           printf("请输入正确的行数和列数");
           break;
       }
       display(hang1,lie1,ch1);
       printf("请再次输入您需要的字符：");
       if((getchar()) != '\n')
       {
           continue;
       }
   }

}
char display(int hang,int lie,char ch)
{

    int i,n;

        for(i = 0;i < lie;i++)
        {
            for(n = 0;n < hang;n++)
            {
                putchar(ch);
            }
            printf("\n");
        }

    return ch;
}



4.
#include <stdio.h>
#include <stdlib.h>

//字符串排序
void stsrt(char *strings[], int num);     //字符串排序函数
char * s_gets(char * st, int n);    //就是刚才那个输入函数


int main(void)
{
    char input[20][81];   //储存输入的数组
    char *ptstr[LIM];     //内含指针变量的数组
    int ct = 0;   //输入计数
    int k;     //输出计数
    printf("输入20句以内的话，我将按照首字母的大小进行排序");
    while(ct < 20 && s_gets(input[ct],81) != NULL && input[st][0] != '\0')   //首先行数应该少于20，输入的数组不为空，每行的首字符不为0
    {
        ptstr[ct] = input[ct];  //设计一个指针，让这个指针指向每行的首元素的地址
        ct++;
    }
    stsrt(ptstr, ct);  //字符串排列函数
    //排序后的指针
    for(k = 0;k < ct;k++)
        puts(ptstr[k]);   //排序后的指针      puts(s)；其中s为字符串字符（字符串数组名或字符串指针）
}



void stsrt(char *strings[], int num)
{
    char *temp;
    int top,seek;
    
    for(top = 0; top < num - 1; top++)
    {
        for(seek = top + 1; seek < num; seek++)
        {
            if(strcmp(strings[top], string[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
				/*该程序的巧妙是用指针来访问数组中的元素*/
				
            }
        }
    }
}


=========================================================================================================================================


=========================================================================================================================================
————————————————————
     波兰形式
————————————————————
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

//数字越大，优先级越高，这里是八进制
#define BOTTOM      '\0'    //堆栈底部
#define EOL         '\1'    //输入终了
#define LEFT_PAR    '\2'    //左括号
#define RIGHT_PAR   '\3'    //右括号
#define PLUS_MINUS  '\4'    //加或减
#define MUL_DIV     '\5'    //乘或除

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
/**
    处理：a*(b+c)/d+k
    输出：abc    输入：/d+k
    堆栈：*(+  先开始把*放入堆栈，之后把(放入堆栈，因为表示一个新的操作数开始了，+大于(所以放入
    下一个运算符：)
    因为)优先级比+低，所以输出+
               
    输出：abc+      输入：/d+k
    堆栈：*( 
    下一个运算符：)
    照上面的说法：这一对括号都要去掉(也不输出)
    
    输出：abc+      输入：d + k
    堆栈：*         下一个运算符：/
    和*相等，所以要输出*，同时把/推入堆栈，对应，最后一个else
    
    输出：abc+*d    输出：k
    堆栈：/         下一个运算符：+
    因为+的优先级比/小，所以/就被输出，但这就使堆栈空了，也就是只剩下了BOTTOM，于是不知道+可不可以计算
    ，只好把+推入堆栈，接着读到k，把它输出，接下来就是输入终了了
    输出：abc+* /k   输出：
    堆栈：+          下一个运算符：EOF
    因为除了BOTTOM之外，EOL的优先级是最低的，这就造成把x剔除并且输出：之后，堆栈空了，下一个运算符
    是EOF，因此工作结束，输出是：
    abc+* /k+
    
**/


void initial(void);
char stack_top(void);
void push(char, char);
char pop(void);

int main(void)
{
    char line[100];
    char *p;
    char opr, t;

    printf("\nCompile to Reversed Polish Program");
    printf("\n==================================");
    printf("\n\nYour Input ——>");
    p = gets(line);
    printf("\n\nAnswer is ——>");

    initial();
    for(; ; p++)
    {
        if(isalpha(*p))          //在程序中读到了输入值之后，如果对应的是个英文字母，那就是个操作数
                                 //把它输出
            printf("%c ", *p);

        else if(*p == '(')       //如果是个左括号，这就表示一个新的操作数开始了，为了要记住这个新操作数
                                 //的边界，把左括号与它的优先级推入堆栈中
            push(*p, LEFT_PAR);

        else if(!isspace(*p))    //如果得到的不是个空白符号，就依加与减，乘与除，右括号，输入终了来分类
        {
            switch(*p)
            {
                //opr就会得到对应的优先级值，这样opr中就是下一个运算符，而堆栈顶端就是在此之前被放进去
                //的那一个运算符
                case '+':
                case '-': opr = PLUS_MINUS;   //加或减4
                          break;
                case '*':
                case '/': opr = MUL_DIV;    //乘或除5
                          break;
                case ')': opr = RIGHT_PAR;   //右括号3
                          break;
                case '\0': opr = EOL;   //输入终了1
                          break;
                default : printf("***Unrecognizable char ***");  //不是以上几类，也不是操作数、右括号的话

                          exit(EXIT_FAILURE);//就是一个不能使用的符号，因此报告错误，停止处理
                                             //exit(1);
            }
            while((t = stack_top()) >= opr)   //当栈顶的符号优先级大于下一个符号优先级，输出
                printf("%c ", pop());    //输出栈顶元素，且top--,注意这是一个循环
            if(t == LEFT_PAR && opr == RIGHT_PAR)   
                (void)pop();   //只需要top--，意思就是把左括号和右括号弄没了，就表示这一对括号里的内容
                               //全部完成
            else if(opr == EOL)   //对应case'\0'，如果下一个元素是元素终了
                exit(EXIT_SUCCESS);     //成功退出
            else
                push(*p, opr);   //顶端元素优先级小于下一个运算符，把这个运算符推入堆栈
        }
    }
}

#define MAX_DEPTH 100
#define BOTTOM '\0'

static char stack[MAX_DEPTH];  //储存运算符本身
static char code[MAX_DEPTH];   //储存运算符的优先级
static int top;

void initial(void)
{
    top = 0;
    code[top] = BOTTOM;   //在堆栈底部应该先放好一个BOTTOM操作数，它具有最小的优先级，所以一开始
                          //任何运算符都会被推入堆栈，而且如果到了输入终了，就会把所有在BOTTOM上方
                          //的元素全部逼出来
}

char stack_top(void)
{
    return code[top];
}

void push(char operator, char opr_code)   //operator就是运算符，加减乘除啥的，oprcode就是它所对应的优先级数字
{
    if(++top == MAX_DEPTH)   //最开始初始化top = 0，top就是第一个可以存放数字的，最底端方的是bottom
    {
        printf("\n*** ERROR *** Stack Overflow.");  //如果达到了最大限度
        exit(1);
    }
    else
    {
        stack[top] = operator;   //把这个栈的顶端放上这个符号
        code[top]  = opr_code;   //存上这个符号的优先级数字
    }
}

char pop(void)
{
    if(top == 0)    //如果栈顶元素为0
    {
        printf("\n*** ERROR *** Stack Underflow.");
        exit(1);
    }
    else
        return stack[top--];  //返回的是栈顶的元素，之后top--
}
————————————————————
前置波兰形式
————————————————————
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE       100

#define STACK_BOTTOM    0
#define OPERAND         1
#define OPERATOR        2

int    is_opr(char );
double compute(char, double, double);
void   initial(void);
void   push_opn(double);
void   push_opr(char);
double pop_opn(void);
char   pop_opr(void);
int    stack_top(void);
/**
    前置波兰形式（只有加减乘除四个运算符，操作数只有一个数字符号）
    就是把前置形式计算出结果输出
	敲黑板：我觉得不用联合，就普通的压栈到一个数组中也可以做

**/
void main(void)
{
    double opn1, opn2;
    char   s[LINE_SIZE];
    char   opr;
    char   *p;

    printf("\nPrefix Form Evaluator");
    printf("\n=====================");
    printf("\n\nInput ——> ");
    gets(s);
    initial();   //把栈底元素设为STACK_BOTTOM 0，并把top的值设为0，top是int类型

    for(p = s; *p != '\0'; p++)   //用指针p遍历数组中的每一个元素
    {
        if(is_opr(*p))   //如果*p的值是+-*/中的一个，该符号就是运算符
            push_opr(*p);

        else if(isdigit(*p))    //判断c指定的字符是否为数字字符，'0'-'9',头文件ctype.h，是一个操作数
        {
            opn2 = *p - '0';    //opn2是数字字符所对应本来的数字，char类型
            while(stack_top() == OPERAND)  //不断地测试堆栈顶元素是不是一个数字
                                           //这个函数返回的是type值，type值是1，就是数字，type值是2，就是加减乘除
            {
                opn1 = pop_opn();   //如果栈顶元素是一个操作数，就取出放到opn1中
                opr  = pop_opr();   //取出对应的符号opr
                opn2 = compute(opr, opn1, opn2);   //计算操作数opn1和opn2在运算符opr下的结果，要记住这个加减乘除是字符的
												   //加减乘除，并不是实际的加减乘除
            }
            push_opn(opn2);  //当上一个操作数没有了匹配的另一个操作数与运算符，就用push，把它推入栈
        }
        printf("\nResult = %lf", pop_opn());  //当所有工作做完之后，结果在顶端顶端把它取出，再显示出来
    }
}

int is_opr(char opr)
{
    return opr == '+' || opr == '-' || opr == '*' || opr == '/';
}

double compute(char opr, double opn1, double opn2)
{
    double result;

    switch (opr)
    {
        case '+' : result = opn1 + opn2;
                   break;
        case '-' : result = opn1 - opn2;
                   break;
        case '*' : result = opn1 * opn2;
                   break;
        case '/' : result = opn1 / opn2;
                   break;
    }

    return result;
}

#define STACK_SIZE 100

struct item
{
    union    /*联合
               所有成员共享一个空间  同一时间只有一个成员是有效的  union的大小是其最大的成员
               存数字的时候是：operator  - / *   +
                               value           2   5
               */

    {
        double value;   //存放操作数，就是数字
        char   operator;  //运算符，就是加减乘除
    }store;

    int type;    //表示该union中的值是哪一类的变量
};

static struct item stack[STACK_SIZE];
static int    top;

void initial(void)    //为堆栈赋初值
{
    top = 0;
    stack[top].type = STACK_BOTTOM;  //表示堆栈底部的元素，既不是运算符，又不是操作数
}

void push_opn(double data)
{
    stack[++top].type = OPERAND;   //这个值是1，我想大概就是数字对应的type就是1，而且这个type和value和store
                                   //一一对应
    stack[top].store.value = data;
}

void push_opr(char opr)   //opr是加减乘除
{
    stack[++top].type = OPERATOR;  //这个值是2，加减乘除对应的值就是2，top永远是指向有数字的一块
    stack[top].store.operator = opr;  //把这个字符推入栈
}

double pop_opn(void)
{
    return stack[top--].store.value;    //取出栈顶的数字
}

char pop_opr(void)
{
    return stack[top--].store.operator;   //取出栈顶的加减乘除
}

int stack_top(void)    //测试栈顶元素的type值，type值是1，就是数字，type值是2，就是加减乘除
{
    return stack[top].type;
}

=========================================================================================================================================
————————————————————
KMP算法：寻找部分字符串
————————————————————

#include <string.h>
/**
    KMP算法：寻找部分字符串
   ————————————————————————————————————————————————————————————————————————————————————————————————————————
    
    我理解的意思：这个的目的就是寻找这个一个字符串中有没有和和首字母相同的
                  第一种情况 ABDCF
                             ABCAB
                             比较到C，C不等于D，而且C之前没有和A相同的字母，所以C所对应的值有可能是A，所以
                             往后移动两位
                  第二种情况ABCABD
                            ABCABC
                            比较到C，C不等于D，C之前有和A相同的字母，C只是有可能和A相同，而C之前的那个是绝
                            对和A相同，所以移动3位
                            
    ————————————————————————————————————————————————————————————————————————————————————————————————————————
                            
                  假设：当比较到第i个元素时[不相同],
                        移动位数的计算公式：i - next[i];
						
						
						【为了易于理解的图】
						index     0      1      2      3      4      5      6      7      8      9      10      11      12
						Pattern          A      B      C      A      B      C      A      D      A      B       C       D
						Next[]   -1      0      0      0      1      2      3      4      0      1      2       3       0
                        【实际的图】  以A打头的这个小序列是以0开始的
						index     0      1      2      3      4      5      6      7      8      9      10      11      12
						Pattern   A      B      C      A      B      C      A      D      A      B       C       D
						Next[]   -1      0      0      0      1      2      3      4      0      1      2       3       0
						最长相                         A     AB     ABC   ABCA            A      AB      ABC      
						同后缀
						
                    index-Next[]  1      1      2      3      3      3      3      3      8      8      8       8       12  
    ————————————————————————————————————————————————————————————————————————————————————————————————————————
                        
                  仔细观察下面这个数组可以发现：123号就是移动112格，减1
                                                 4567号都是移动3格
                                                 
                        假设要测试的数组：ABCABCADABFCBACDFC
                        要寻找的字符串  ：ABCABCADABCD
                        移动之后        ：        ABCABCADABCD
                                             FC不相等，所以移动8格
                        为什么有移动3  8  12 的情况？为什么不移动到跟第二个或第三个对齐？
                        因为移动的目的是测试A之后的数字有没有可能跟寻找的字符串相等
                        第一个和第二个肯定没有可能跟要寻找的字符串相等，如果相等，就输出了
						我懂了：next的目的就是找出重复单元
						        例如：4-7是重复之前单元的
								      但是8就表示这里不重复，重新开始
									  9-11又是重复的
									  12又是不重复，重新开始
									  
									  从第一个为1的数开始，到和最开始的ABCABC......不相同结束
									  所以说1-3  4-8  9-12肯定是不完整的重复Pattern序列
									  假设寻找的字符串要移到和第二个A对齐，但是在之前Next数组中知道，这个肯定是断着的，所以要移动8个格
						假设要测试的数组：ABCABCADABFCBACDFC
                        要寻找的字符串  ：ABCABCADABCD
                        移动之后        ：   ABCABCADABCD			  
						
						
                                                 
    ————————————————————————————————————————————————————————————————————————————————————————————————————————
                  
    【实际的图】  以A打头的这个小序列是以0开始的
						index     0      1      2      3      4      5      6      7      8      9      10      11      12
						par       A      B      C      A      B      C      A      D      A      B       C       D
						Next[]   -1      0      0      0      1      2      3      4      0      1      2       3       0
						最长相                         A     AB     ABC   ABCA            A      AB      ABC      
						同后缀 
    ————————————————————————————————————————————————————————————————————————————————————————————————————————
**/

void computeNext(const char par[], int next[])//next[]长度为len+1
{
	int len = strlen(par);   //par就是要测试的数组
	next[0] = -1;
	int i = 1;
	int j;
	while(par[i] != 'A')
		next[i++] = 0;
	for(j = i; j < len; j++)
	{
		if(par[j] == 'A')
			next[j] = 0;
		else
			next[j] = next[j - 1] + 1;
	}
	
	/*标准答案
	next[0] = -1;
	next[1] = 0;
	for(int i = 1; i < len; i++) //i是par下标，i+1为next下标   
	{
            if(next[i] == 0) //如果前一位无前后缀相同，那么比较0位和当前位 
                next[i+1] = par[0] == par[i] ? 1 : 0; 
            else // next[i] != 0, 指示了最长相同前后缀长度 
            { 
                if(par[next[i]] == par[i]) //next[i]恰好是下一个比较位置 
                    next[i+1] = next[i]+1; 
                else 
                    next[i+1] = par[0] == par[i] ? 1 : 0; 
            } 
	}*/
}

int kmp(char par[], char ori[]) //par就是要测试的数组  ori就是大的
{
	int count = 0;
	int next[100];
	computeNext(par, next);  //初始化next数组
 
	int len_ori = strlen(ori), len_par = strlen(par);
	int ipar = 0, iori = 0;//指示par和ori的下标
	while(iori+ipar < len_ori)//原串剩余字母已经完成最后一次匹配 或 不足以进行一次匹配
	{
		//iori指向的是第一个A的位置
		while(iori+ipar < len_ori && ipar < len_par && ori[iori+ipar] == par[ipar]) //前两个条件防止数组访问越界
			ipar++;
		if(ipar == len_par) //模式串完全匹配
			count++;
		iori += (ipar - next[ipar]);
		ipar = 0;//确定下一次比较的起点
	}
	return count;
}
int main()
{
	int n;
	n = kmp("abc","abdhgbacghdabc");
	printf("%d", n);
 
	return 0;
}

=========================================================================================================================================
……………………………………………………
    DP完全问题
……………………………………………………
————————————————————
      BM算法
————————————————————
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//这个是后续排序中好后缀表的值
//一个就是一个，两个就是两个原则
char *buf  = "abdgfabcgdab";
char *ptrn = "abcabhab";
int pLen;

int *MakeSkip(char *ptrn, int pLen);
int *MakeShift_suffix(char *ptrn, int pLen);
int *MakeShift_prefix(char *ptrn, int pLen);
int *BMSearch(char *buf, int blen, char *ptrn, int plen, int *skip, int *shift);

int main()
{

    int *skip  = NULL;
    int *shift = NULL;
    pLen = strlen(ptrn);
    skip  = MakeSkip(ptrn, pLen);
    shift = MakeShift_prefix(ptrn, pLen);
    BMSearch(buf, strlen(buf), ptrn, strlen(ptrn), skip, shift);

    return 1;
}

int *MakeSkip(char *ptrn, int pLen)//ptrn->模式串P
                                   //pLen->模式串P的长度

{
    int i;
    int len = pLen;
    char *p = ptrn;  //p是指向字符串的指针

    //为建立坏字符表，申请256个int的空间
    int *skip = (int *)malloc(256 * sizeof(int));//ASCII码各种乱七八糟字符，最大255
    if(skip == NULL)//如果动态内存分配失败
    {
        printf("malloc failed");
        return 0;
    }
    /**
        坏字符表的建立：
        BM坏顶点方法寻找字符串
        1.ABCGHDBCDABBACDBACDBC
          BCHD
          GD不相等，且BCHD中没有和G相等的，所以往后移动4格
          ABCGHDBCDABBACDBACDBC
              BCHD
          CD不相等，但是BCHD中有和C相等的，所以把两个C对齐
          ABCGHDBCDABBACDBACDBC
                BCHD

        2.如果坏字符之前没有，就是pLen
        3.如果坏字符之前有，就是移动这个坏字符走几个走到ptrn的末尾
    **/

    //初始化坏字符表，256个单元全部初始化为Len
    for(i = 0; i < 256; i++)
    {
        *(skip + i) = pLen;
    }

    //赋值，从左到右遍历ptrn， 这样如果一个字符出现两次，后面的覆盖前面的
    //不在模式中出现的字符不用再赋值，他们默认使用pLen
    while(pLen != 0)
    {
        //*ptrn就是取值，是char类型，而加一个int，是取ASCII码
		*(skip + (int)*ptrn++) = --pLen;  //首先，skip指向的是一堆乱七八糟字符的首字符，(int)*ptrn是字符的ASCII码
                                          //假设ptrn是ABCCABCAC ，首先处理的是A，意思就是A和坏字符对应
                                          //A应该移到末尾的C位置，就是移动--pLen
                                          //如果后面又有A，则后面的将覆盖前面的，这样可以排除偶然情况，具体见五分钟算法
    }
    return skip;
}

int *MakeShift_prefix(char *ptrn, int pLen)  //ptrn是那个数组，plen是数组的长度
{
    int *shift_prefix = (int *)malloc(pLen * sizeof(int));
    int *sptr  = shift_prefix + pLen - 1;
    char *pptr = ptrn + pLen - 1;
    char c;
    char *p1 = ptrn + pLen - 2, *p2, *p3;
    char *p1_1;
    int *suffix, *suffix_1;
    int num = 0;
    int max_first = 0;
    int *max_first_index;


    if(shift_prefix == NULL)   //动态内存分配失败
    {
        fprintf(stderr, "malloc failed!");
        return 0;
    }

    c = *(ptrn + pLen - 1);  //模式串中最后一个字符

    while(sptr >= shift_prefix)//sptr是给好后缀表进行赋值的指针
    {
        p1 = ptrn + pLen - 2;
        *sptr = 1;
        p1_1 = ptrn + pLen - 1;

        while(p1 >= ptrn && *p1 != c)//该空循环，寻找与最后一个字符c匹配的字符所指向的位置
            p1--;

        if(p1 < ptrn)
            *sptr = pLen;

        p2 = ptrn + pLen - 2;
        p3 = p1--;

        while(p2 >= pptr && p3 >= ptrn && *p3 == *p2);  //该空循环，判断在边界内字符串匹配到什么位置
        {
            p3--;
            p2--;

        }

        if(*p2 != *p3)
            *sptr = p2 - p3;
        else if(p2 > pptr)
        {
            num = ptrn + pLen - pptr;
            suffix = MakeShift_suffix(ptrn, pLen);  //这两个应该是全局变量
            suffix_1 = suffix;
            for(; suffix < suffix + pLen; suffix++)
            {
                if(*suffix <= num && *suffix > max_first)
                {
                    max_first = *suffix;
                    max_first_index = suffix;
                }
            }

            *sptr = suffix + pLen - max_first_index - 1;
        }
        pptr--;
        sptr--;
    }
    return shift_prefix;
}

//这是一个最长前缀表
int *MakeShift_suffix(char *ptrn, int pLen)
{
    int *shift_suffix = (int *)malloc(pLen * sizeof(int));
    int *sptr  = shift_suffix;
    char *pptr = ptrn + pLen - 1;
    char *pptr_First = pptr;
    char *pptr_index_First, *pptr_index_end;
    int num = 0;

    if(shift_suffix == NULL)   //动态内存分配失败
    {
        fprintf(stderr, "malloc failed!");
        return 0;
    }

    for(; sptr < shift_suffix + pLen; pptr_First++)
    {
        if(*pptr_First != *pptr)
            *sptr = pLen;
        else
        {
            pptr_index_First = pptr_First;
            pptr_index_end = *pptr;

            while(*pptr_index_First == *pptr_index_end)
            {
                num++;
                pptr_index_end--;
                pptr_index_First--;
            }

            *sptr = num;
        }
    }

    return shift_suffix;

}

int *BMSearch(char *buf, int blen, char *ptrn, int plen, int *skip, int *shift)
{
    int b_idx = plen;
    if(plen == 0)   //模式串的长度
    {
        return 1;
    }
    while(b_idx <= blen) //计算字符串是否匹配到了尽头,blen->文本串T长度
    {
        int p_idx = plen, skip_stride, shift_stride;
        int i = 0;
        int temp = b_idx;  //是为了不改动b_idx的值，b_idx将来用于计算移动的距离
                           //temp就是在buf里的位置

        while(buf[--temp] == ptrn[--p_idx])  //开始匹配
        {
            i++;
            if(p_idx == 0)
            {
                printf("match at %d!", b_idx);///stdout显示器。stdin键盘。stderr显示器（没有缓冲
                                                       ///立即输出）
                return 1;
            }

        }
        int *b1, *b2;
        b1 = skip;
        b2 = shift;

        skip_stride = *(b1 + (blen - i - 1));  //根据坏字符规则计算跳跃的距离

        b2 = b2 + (plen - p_idx + 1);
        for(; *b2 == 1 && *b2 < plen; b2++);
        shift_stride = *(b2);

        /*skip_stride = skip[(unsigned char)buf[temp]] - i;
        shift_stride = shift[p_idx];*/

        b_idx += (skip_stride > shift_stride) ? skip_stride:shift_stride; //取最大者
    }
    return 0;
}


=========================================================================================================================================
#define FOUND 1
#define NOT_FOUND 0

//看pat是否是text的子序列，并且把pat在text中各符号的位置记录下来
int subsequence(char text[], char pat[], int loc[])
{
    int n = strlen(text);
    int m = strlen(pat);
    int i = 0;
    int j = 0;
    int a = 0;
    
    if(m > n)
        return NOT_FOUND;
    while(i < n && j < m)   
    {
        if(text[i] < pat[j])
            i++;
        if(text[i] > pat[j])
            return NOT_FOUND;
        if(text[i] = pat[j])
        {
            loc[a++] = i;
            i++;
            j++;
        }
    }
    
    if(j == m)
        return FOUND;
    else
        return NOT_FOUND;
}


=========================================================================================================================================

#define FOUND 1
#define NOT_FOUND 0

/**
    t与p是两个字符串，把p中的每一个元素都重复写i次，就得到一个新字符串p(i)，p(i)是t的子序列吗？
    请写一个程序，找出最大的，使p(i)还是t的子序列的i，如果p根本就不是t的子序列，则程序返回0
**/

int subsequence(char [], char [], int, int []);

int max_repetition(char text[], char pat[], int loc[])
{
    int t_len = strlen(text);
    int p_len = strlen(pat);
    int low   = 1;
    int high  = t_len / p_len;  //这个元素最多有high个
    int mid;
    
    /*
        如果是t是abcabcabcabcabcabcabcabc
        p就是abc
    */
    
    //先检查p是不是t的子序列，如果不是，那么后面的操作就没有意义了
    if(subsequence(text, pat, low, loc) == NOT_FOUND)
        return NOT_FOUND;
    
    //由题意可知，i的解答必定小于或等于|t|/|p|
    while(low + 1 < high)
    {
        mid = (low + high) / 2;  //二分法
        if(subsequence(text, pat, mid, loc) == FOUND)
            low = mid;
        else
            high = mid; 
    }
    
    if(subsequence(text, pat, high, loc) == FOUND)
        return high;
    (void)subsequence(text, pat, low, loc);
    return low;
}

int subsequence(char text[], char pat[], int number, int loc[])    //number是重复寻找的次数
{
    int t_len = strlen(text);
    int p_len = strlen(pat);
    int count, index = 0;
    int i, j;
    
    if(p_len > t_len)
        return NOT_FOUND;
    for(i = j = 0; i < t_len && j < p_len; j++)
    {
        count = 0;
        do
        {
            for(; i < t_len && text[i] != pat[j]; i++);
            if(i >= t_len)
                return NOT_FOUND;
            else
            {
                loc[index++] = i++;
                count++;
            }
        }
        while(count < number)  /*
								text中找count次这个元素
                                abcabcabcabcabcabcabcabc
                                例如number = a
                                先找到第一个a，之后i不停++，找到第二个a
                               */
                                
    }
    return FOUND;
}



=========================================================================================================================================
//编辑距离
1.
就是将一个字符串转换成另一个需要的最小操作数
#include <string.h>

void edit(char [], char [], int [], int [], int *);
void edit_op(char [], char [], int [], int [], int );
void reverse(int [], int);

#define INSERT_COST   1
#define DELETE_COST   1
#define EXCHANGE_COST 2

#define MIN(x, y, z) ((x) <= (y) ? ((x) <= (z) ? (x) : (z)) : ((y) <= (z) ? (y) : (z)))

/**
       x    b    y    z    e    k
    0  1    2    3    4    5    6
a   1  2    3    4    5    6    7
b   2  3    2    3    4    5    6
c   3  4    3    4    5    6    7
d   4  5    4    5    6    7    8
e   5  6    5    6    7    6    7
f   6  7    6    7    8    7    8

       首先初始化：cost[i][0] = i   从长度为i的字符串转换成空串，需要删除i次
                   cost[0][j] = j   从空串转化成长度为j的字符串，要添加j次
       有三种模式：
       替换：把a替换成b
       增加：把abdd变为aebdd   不要管它是如何实现的
       删除：把travelling变为traveling

       求解dist(str1 + char1, str2 + char2)  //把str1 + char1转换成str2 + char2
       1.如果char1 == char2 ，不用更改，就把对角线上的抄到这个位置上
       2.如果char1 != char2
           ①str1可以直接转变为str2，这时我们只需要将char1转变为char2就行了
           ②str1 + char1可以直接转变为str2，这时我们的处理方法是插入char2
           ③str1可以直接转变为str2 + char2这时的情况是我们需要删除char1
	   
	   时隔很长时间，我再来叙述一下这个的意思
	   总共分为2种情况【上下】【对角线】
	   【上下】
	   要把下面的转换成上面的
			         aaaab
			         aaaa
			   一个字符串缺少一个，且这个位置是空的，只要把数字补进去就可以，操作数为1
					 ancbgh
					 abcbghf
			   下面字符串多了一个，把最后的删去，操作数为2
			      
	   【对角线】
					abcvgh
					abcvgh
				要把下面的转换成上面的，只需要同时在上面和下面都补上相同的数字就行，操作数为2
				这也就是如果两个数字是相同数字，对角线加2的原因

**/

void edit(char source[], char target[], int s[], int t[], int *count)
{
    //把s变成t， s是纵行， t是横行
    int s_len = strlen(source);
    int t_len = strlen(target);
    int insert_t, delete_s, exchange;
    int i, j, no;
    int **cost;   //就是那个二维数组

    /*----------------------------------------------------------------*/
	
    //我懂了，指针的指针和二维数组还是有一点不同的，先让指针的指针指向每一横行。并分配内存
	//cost[0]才是分配二维数组的内存
    cost    = (int **)malloc(sizeof(int) * (s_len + 1));
    cost[0] = (int *)malloc(sizeof(int) * (s_len + 1) * (t_len + 1));

    //令cost[i]指向这个区域中的第i列，每一列有t_len + 1个元素
    for(i = 1; i <= s_len; i++)
        cost[i] = cost[i - 1] + t_len + 1;

    /*----------------------------------------------------------------*/

    //初始化纵行和横行
    cost[0][0] = 0;
    for(i = 1; i <= s_len; i++)
        cost[i][0] = cost[i - 1][0] + 1;
    for(j = 1; j <= t_len; j++)
        cost[0][j] = cost[0][j - 1] + 1;

    /*----------------------------------------------------------------*/

   //初始化cost这个表格中的数据
    for(i = 0; i < s_len; i++)
    {
        for(j = 0; j < t_len; j++)
        {
            //记住现在的ij是在真实地点的左上对角线的
			if(source[i] == target[j])
                cost[i + 1][j + 1] = cost[i][j];  //因为cost中的元素是从1开始的
            else
            {
                insert_t = cost[i + 1][j] + INSERT_COST;  //1
                delete_s = cost[i][j + 1] + DELETE_COST;  //1
                exchange = cost[i][j] + EXCHANGE_COST;    //2
                cost[i + 1][j + 1] = MIN(insert_t, delete_s, exchange);
            }
        }
    }

    /*----------------------------------------------------------------*/

    /**
                       x    b    y    z    e    k
                    0  1    2    3    4    5    6
                a   1  2    3    4    5    6    7
                b   2  3    2    3    4    5    6
                c   3  4    3    4    5    6    7
                d   4  5    4    5    6    7    8
                e   5  6    5    6    7    6    7
                f   6  7    6    7    8    7    8

    **/

    //找出source和target相同的位置，位置存放在s[]与t[]中
    for(i = s_len, j = t_len, no = 0; i != 0 && j != 0; )
    {
        if(cost[i][j] == cost[i - 1][j] + INSERT_COST)
            i--;
        else if(cost[i][j] == cost[i][j - 1] + DELETE_COST)
            j--;
        //说明既不是上面元素加1所得，也不是左边元素加1所得，就是由对角线不变所得，意思就是找到了一个相等的元素
        else
        {
            s[no] = i - 1;
            t[no] = j - 1;
            no++;
            i--;
            j--;
        }
    }

    //因为上面的是从后往前输入到s和t中的，所以得将no个元素倒置
    reverse(s, no);
    reverse(t, no);
    *
	= no;     //函数头中有
    free(cost[0]);
    free(cost);
}

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

void edit_op(char source[], char target[], int s[], int t[], int n)   //显示修改操作
{
    int length = MAX(strlen(source), strlen(target)) + 1;
    int i, j, k;
    char *work;

    //如果source[s[0]]与target[t[0]]是相等的，删除source[0]~source[s[0] - 1],插入target[0]~target[t[0]-1]
    printf("\n\nEditing Operations are listed as Follows\n");
    work = (char *)malloc(sizeof(char) * length);  //work里是要说明应该把数组里从哪里到哪里删除或添加，所以应该取里面最大的
    for(i = j = k = 0; i < n; j = s[i] + 1, k = t[i] + 1, i++)  //注意i++是放在之后的
    {
        if(s[i] - j > 0)  //j就相当于每一次的[0]  s[i]就相当于每一次的末尾
        {
            (void)strncpy(work, &source[j], s[i] - j);  //把s[i]之前的字符串赋复制到work中，不包括s[i]
            work[s[i] - j] = '\0';  //把s[i]这个元素设为0，意思就是不动它
            printf("\nDelete \"%s\" from source string.", work);  //要删去work中的字符串
        }

        if(t[i] - k > 0)
        {
            (void)strncpy(work, &target[k], t[i] - k);
            work[t[i] - k] = '\0';
            printf("\nInsert \*%s\* to source string.", work);
        }
        printf("\nKeep \'%c\' from source string.", source[s[i]]);   //把source中不变的输出
    }
    
    //123456中相等的元素是1和4，意思就是5，6还没有动
    if(strlen(source) - j > 0)  
        printf("\ndelete \"%s\" from source string.", &source[j]);
    if(strlen(target) - k > 0)
        printf("\nInsert \"%s\" to source string.", &target[k]);
    printf("\n\nDONE! Target string generated");
    free(work);
}

#define SWAP(a, b) {t = a; a = b; b = t; }

void reverse(int x[], int n)
{
    int i, j, t;
    for(i = 0, j = n - 1; i <= j; i++, j--)
        SWAP(x[i], x[j]);
}

————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
树塔问题
有如下所示的数塔，要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？
           9
		 /   \
	   12     15
	  /  \   /  \
	 10    6     8
	/  \  / \   / \
   2    18    9    5
   
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b));
using namespace std;
int N,sum;
int a[101][101],b[101][101];
int main()
{    
	int test;
    scanf("%d",&test); //你要做test次实验
    while(test--)    
	{        
		int i,j;
        scanf("%d",&N);   //N是行数
		
        for(i=0; i<N; i++)        
		{            
			for(j=0; j<=i; j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=a[i][j];
			}
		}  
		/**
				0   1   2   3 
			  0 9
			  
			  1 12  15
			  
			  2 10  6   8
			  
			  3 2   18  9   3
		
		**/	
		
		for(int i=N-2; i>=0; i--)   //从第二行开始
		{
			for(int j=0; j<=i; j++)   //从第0列开始         
			{
				//从上往上，则(0, 0)就是最大值
				b[i][j]+=max(b[i+1][j],b[i+1][j+1]); //最关键的式子，父节点的值加上子节点中较大一个的值。            
			}   
		}
		printf("%d\n",b[0][0]); //最后要求的最大值。
	}
		return 0;
}
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————



=========================================================================================================================================
/**
    产生无重复部分的字符串（回溯）
    如果n = 5； 12321是要求的结果，12123不是
**/
#define OK 1
#define NO 0

void change(int [], int *);
void extend(int [], int *);
int  check(int [], int);
void output(int [], int);

void seq_gen(int seq[], int n)
{
    int no;
    int i;

    seq[0] = 1;
    seq[1] = 2;
    no     = 1;
    
    /*
        12321 √
        12322
        12323
        1233
        13    √
        131   √
        1311
        1312  √
        13121 √
        13122
        13123 √
        1313
        1321  √
        13211
        13212 √
        13213 √
        1322
        1323  √
        13231 √
        13232
    */
    
    while(no >= 0)                 //no则是seq[]中最后一个元素的脚码
    {
        if(check(seq, no) == OK)   //如果字符串符合条件，再看看它是否已经装满了n个元素
        {
            if(no == n - 1)        //如果是，就把它显示出来，并且修正最后一个元素的值而求得下一个组合方式
            {
                output(seq, n);
                change(seq, &no);  //change的作用是去掉最高位，并且把没有达到最大值的位上加1
            }
            else                   //如果不满n个元素，就调用extern()函数，尝试在最后面多加一个元素
                extend(seq, &no);
        }
        else                       //如果不符合条件，那就一定是最后一个元素有问题，因此通过修改最后的元素
                                   //来产生下一个可能的组合
            change(seq, &no);
    }
}

void change(int seq[], int *no)    //把最高值都去掉，在这里，最高值是3，知道找出一个不是3的位置为止
{                                  //把它加上一变成下一个值，如果在seq[]中方有123213333，就会被change
    for(; seq[*no] == 3; (*no)--); //去掉尾部的4个3，而变成12321，再把最后一个加1变成12322
    seq[*no]++;
}

void extend(int seq[], int *no)    //多加一个元素，并赋值为1
{
    seq[++(*no)] = 1;
}

/*------------------------检查一个字符串是否复合要求---------------------------*/

//检查目前的seq[]中的内容是否满足没有相邻而重复的部分字符串的条件

//如果有5个数字13232，32重复，不符合条件，5个数字最多有两个数字重复，就是5 / 2
//判断两段是否重复：假如是12341234，首先要确定是从哪个开始比较，就是no，最后一个元素的角码，
//第二要确定最后一个数字跟谁比，就是减去length，要重复开始比，就是i不断移动
int check(int seq[], int no)       //no则是seq[]中最后一个元素的脚码
{
    int length;
    int half = (no + 1) / 2;
    int i;

	for(length = 1; length <= half; length++)   //有length个数字重复
    {
        for(i = 0; i < length && seq[no - i] == seq[no - length - i]; i++);  //注意是【相邻而重复】
        if(i >= length)
            return NO;
    }
    return OK;
}

void output(int seq[], int n)    //显示seq数组里的元素
{
    int i;

    printf("\n");
    for(i = 0; i < n; i++)
        printf("%d", seq[i]);
}


=========================================================================================================================================
**********
查找算法
**********
1.静态查找
//数据集合稳定，不需要添加、删除元素的查找操作
	方法：线性表结构，可以使用顺序查找法
	      如果再对关键字进行排序，可以使用折半查找算法或斐波那契查找算法等来提高查找的效率

2.动态查找
//数据集合正在查找的过程中需要同时添加或删除元素的查找工作
	方法：二叉排序树散列表


——————————
顺序查找的优化方案
int Sq_Search(int *a, int n, int key)
{
	int i = n;
	a[0] = key;
	while(a[i] != key)
	{
		i--;
	}
	
	return i;
}

————————————
插值查找（按比例查找）
//适用于数字相差不大的，123456等，如果是1  100110 1000000  就不适用
int bin_search(int str[], int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	
	while(low <= high)
	{
		mid = low + (key - a[low] / (a[high] - a[low])) * (high - low);
		
		if(str[mid] == key)
			return mid;
		if(str[mid] < key)
			low = mid + 1;
		if(str[mid] > key)
			high = mid - 1;
	}
	
	return -1;
	
}

————————————
斐波那契查找
//斐波那契数列：1 1 2 3 5 8 13 21 34 55 89
//就是前一个数字除以后一个数字越来越接近0.618
#define FIB_MAXSIZE 100

  /**
  * 生成斐波那契数列
 * @param fib：指向存储斐波那契数列的数组的指针
  * @param size：斐波那契数列长度
 */
 void ProduceFib(int *fib, int size)
 {
     int i;

    fib[0] = 1;
    fib[1] = 1;

     for (i = 2; i < size; i++)
     {
        fib[i] = fib[i - 1] + fib[i - 2];
     }
 }

/**
  * 斐波那契查找，查找成功返回位序，否则返回-1
  * @param data：有序表数组
  * @param length：有序表元素个数
  * @param searchValue：待查找关键字
  */
  /**
        我懂了：
        斐波那契里的数字就是数组里的元素个数减1，找到比它大的最接近的斐波那契数字，把数组里的数字补成和斐波那契数字一相同
        的个数，k就是所对应的斐波那契数字，k - 1就是前半部分数字的个数，k - 2就是后半部分数字的个数  只要和k有关都得减1
  
  **/
 int FibonacciSearch(int *data, int length, int searchValue)
 {
     int low, high, mid, k, i, fib[FIB_MAXSIZE];

     low = 0;
     high = length - 1;

     ProduceFib(fib, FIB_MAXSIZE);

     k = 0;
     // 找到有序表元素个数在斐波那契数列中最接近的最大数列值
     while (high > fib[k] - 1)
     {
         k++;
     }

    // 补齐有序表
     for (i = length; i <= fib[k] - 1; i++)
     {
         data[i] = data[high];
     }
     //1 1 2 3 5 8 13 21 34 55 89
     //0 1 2 3 4 5  6 最接近的 8
     //3 5 6 7 9 10 15
     //3 5 6 7 9 10 15 15
     while (low <= high)
     {
         mid = low + fib[k - 1] - 1;   // 根据斐波那契数列进行黄金分割

         if (data[mid] == searchValue)
         {
             if (mid <= length - 1)
             {
                 return mid;
             }
             else
             {
                 // 说明查找得到的数据元素是补全值
                 return length - 1;
             }
         }

         if (data[mid] > searchValue)
         {
             high = mid - 1;
             k = k - 1;
         }

         if (data[mid] < searchValue)
         {
             low = mid + 1;
             k = k - 2;
         }
     }

     return -1;
 }

 int main()
 {
     int data[] = {1,3,5,7,9,11,13,15,17,19,21};

     int index = FibonacciSearch(data, 11, 19);
     printf("%d\n", index);

     return 0;
 }
————————————————————————————————————————————————
分块查找
#define maxSize 100

/**
    分块查找法：
    把数据分成不同的小块，分别找出小块里数据的最大值，将这些最大值排序，判断这个数字再哪两个最大值之间
    然后再在某个小块中寻找
	
	我感觉这个程序有点小小问题
**/
typedef struct
{
	int key;
	int low, high;
}IndexElem;//采用天勤定义的数据结构

int IndexSearch(IndexElem index[], int m, int r[], int key)//m = 3  意思是被分成了三块

{
	int low, high, mid, i;

	low = 0, high = m - 1;
	while (low <= high)
    {
        mid = (low + high) / 2;
        if (index[mid].key >= key)//注意这里是=，对比折半插入排序是不同的，因为此处相同表示就该在mid处查找，亦即high+1处查找
            high = mid - 1;
        else
            low = mid + 1;
    }

    i = index[high + 1].low;

	while (i <= index[high + 1].high)
	{
		if (r[i] == key)
			return i;
		i++;
	}
	return 0;
}

int main()
{
    int r[18] = {22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
    int n = 18;
    int m = 3, i, j, key = 12;
    //建立索引
    IndexElem index[maxSize] = { {22,0,5},{48,6,11},{86,12,17} };
    j = IndexSearch(index, m, r, key);
    
    if (j == 0)
        printf("Failure!");
    else
        printf("%d is %dth number", r[j], j + 1);
    system("pause");
    return 0;
}
————————————————————————————————————————————————————————————————————————————
  二叉排序树的建立，插入，删除
——二叉排序树(Binary Sort Tree)，又称二叉查找树。它是一颗空树，或者具有下列性质：
——若它的左子树不为空，则左子树上所有结点的值均小于它的根结点的值；
——若它的右子树不为空，则右子树上所有结点的值均大于它的根结点的值；
——它的左、右子树分别为二叉排序树。
                    62
				   /  \
				  58  88
				 /   /  \
				47  73  99
				       /
					  93
  构造二叉排序树的目的
提高查找和插入删除关键字的速度。
				 
#define TRUE 1
#define FALSE 0
#define  MAXSIZE 100

//二叉排序树的查找代码实现
//https://www.jianshu.com/p/c6cb2c1460d0
typedef struct BiTNode{// 二叉树的儿二叉链表结点结构
    
    int data; // 结点结构
    struct BiTNode *lchild, *rchild;  // 左右孩子指针
    
}BiTNode, * BiTree;

/**
 * 递归查找二叉排序树 T 中是否存在 key
 * 指针 f 指向 T 的 双亲，其初始调用值为NULL
 * 若查找成功，则指针 p 指向该数据元素结点，并返回TRUE
 * 若查找不成功， 则指针 p 指向查找路径上访问的最后一个结点并返回FALSE
 */
 
int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T) 
    {  // 查找不成功
        *p = f;  //指向最后一个节点
        return FALSE;
    }
    else if (key == T->data)
    {
        *p = T;
        return TRUE;
    }
    else if (key < T->data)
    {  // 在左子树中继续查找
        return SearchBST(T->lchild, key, T, p);
    }
    else
    {  // 在右子树中鸡血查找
        return SearchBST(T->rchild, key, T, p);
    }
}

//二叉排序树的插入操作
/**
    先调用查找操作将要插入的关键字进行比较
    如果在原有的二叉排序树中没有要插入的关键字，则将关键字与查找的结点p（在查找操作中返回的结点）的值进行比较
    若p为空，则插入关键字赋值给该节点；
    若小于结点p的值，则插入关键字作为结点p的左子树；
    若大于结点p的值，则插入关键字作为结点p的右子树；
**/

/**
 * 二叉排序树的插入
 * 当二叉排序树中不存在关键字等于 key 的数据元素时，插入 key 并返回TRUE
 */
int InsertBST(BiTree * T, int key)
{
    BiTree p,s;
    
    if (!SearchBST( *T, key, NULL, &p)) //p就是要插入的位置，最后要不为空
                                        //要不肯定就是在根节点
    {  // 没找到key
        
        //先初始化这个要插入的节点
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        
        if (!p)
            *T = s;  // 插入 s 为新的根结点
        else if (key < p->data)
            p->lchild = s;  //插入 s 为左孩子
        else
            p->rchild = s; // 插入 s 为右孩子
        
        return TRUE;
    }
    else
        return FALSE;
}


//二叉排序树的删除操作
///二叉排序树的意思就是通过中序遍历可以得到排好序的树

/*
    二叉排序树的删除操作相对复杂，因为不能因为删除了结点，让这颗二叉排序树变得不满足二叉排序树的性质，所以对于二叉排序树的删除存在三种情况：
    叶子结点；（很容易实现删除操作，直接删除结点即可）
    仅有左或者右子树的结点；（容易实现删除操作，删除结点后，将它的左子树或者右子树整个移动到删除结点的位置）
    左右子树都有的结点。（实现删除操作很复杂）
    对于要删除的结点同时存在左右子树的情况的解决办法
    核心思想
    将它的直接前驱或者直接后继作为删除结点的数据
*/

/**
 * 从二叉排序树中删除结点 p ， 并重接它的左/右子树
 */
int Delete(BiTree *p)
{
    BiTree q, s;
    
    if ((*p)->rchild == NULL) 
    {  // 右子树空 则只需要重接它的左子树
        
        q = *p;
        *p = (*p)->lchild;
        free(q);
        
    }
    else if ((*p)->lchild == NULL)
    {  // 左子树空 则只需要重接它的右子树
        
        q = *p;
        *p = (*p)->rchild;
        free(q);
        
    }
    else
    {  // 左右子树都不空
        
        q = *p;
        s = (*p)->lchild;
        
        while (s->rchild) 
        {  // 向右到尽头，找到待删结点的前驱
            q = s;  //q是最右边孩子的父亲
            s = s->rchild;//s最后是最右边的孩子
        }
        
        (*p)->data = s->data;  // s 指向被删除结点的直接前驱 （将被删结点前驱的值取代被删结点的值）
        
        if (q != *p) 
            q->rchild = s->lchild;  // 重接 q 的右子树
        else   //如果要替换节点的爸爸正好是p，就是爸爸右边有一长串
            q->lchild = s->lchild;  // 重接 q 的左子树
        
        free(s);
    }
    return TRUE;
}

/**
 * 二叉排序树的删除
 * 当二叉排序树中存在关键字等于 key 的数据元素时，删除该数据元素并返回TRUE
 */
int DeleteBST(BiTree * T, int key)
{
    
    if (!*T)   // 不存在关键字等于 key 的元素
        return FALSE;
    else
    {
        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}


/**
 * 中序递归遍历
 */
void InOrderTraverse(BiTree T){
    
    if (!T)
        return;
    
    InOrderTraverse(T->lchild);
    printf("%d ", T->data);
    InOrderTraverse(T->rchild);
}


int main(int argc, const char * argv[]) {
    
    int i;
    int a[10] ={62,88,58,47,35,73,51,99,37,93};
    
    BiTree T = NULL;
    for (i = 0; i < 10; i++) {  // 通过插入操作来构建二叉排序树
        InsertBST(&T, a[i]);
    }
    
    printf("中序递归遍历二叉排序树：\n");
    InOrderTraverse(T);
    printf("\n\n");
    
    DeleteBST(&T, 93);//记着要取地址
    printf("删除结点 93 后的结果为：\n");
    InOrderTraverse(T);
    printf("\n\n");
    
    printf("插入 91 后的结果为：\n");
    InsertBST(&T, 91);
    InOrderTraverse(T);
    printf("\n\n");
    return 0;
}

——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
*********
平衡二叉树
*********
//分别定义平衡因子数
#define LH +1
#define EH  0
#define RH -1
typedef int ElemType;
typedef enum {false,true} bool;
//定义二叉排序树
typedef struct BSTNode{
    ElemType data;
    int bf;//balance flag
    struct BSTNode *lchild,*rchild;
}*BSTree,BSTNode;
/**
             P
            / \
           LC  b
          /  \
         c    d
        /
       y
       
           LC  
          /  \
         c    p
        /    / \
       y    d   b

**/

//对以 p 为根结点的二叉树做右旋处理，令 p 指针指向新的树根结点
void R_Rotate(BSTree* p)
{
    BSTree lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = *p;
    *p = lc;
}
//对以 p 为根结点的二叉树做左旋处理，令 p 指针指向新的树根结点
/**
                  T
                /   \
               b    LC
                   /  \
                  n    m
                        \
                         k
                   
                    LC
                   /  \
                  T    m
                 / \    \
                b   n    k
        
**/
void L_Rotate(BSTree* p)
{
    BSTree rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = *p;
    *p = rc;
}

//对以指针 T 所指向结点为根结点的二叉树作左子树的平衡处理，令指针 T 指向新的根结点
void LeftBalance(BSTree* T)
{
    BSTree lc,rd;
    lc = (*T)->lchild;
    //查看以 T 的左子树为根结点的子树，失去平衡的原因，如果 bf 值为 1 ，
    //则说明添加在左子树为根结点的左子树中，需要对其进行右旋处理；反之，如果 bf 值为 -1，
    //说明添加在以左子树为根结点的右子树中，需要进行双向先左旋后右旋的处理
    switch (lc->bf)
    {
        case LH:
            (*T)->bf = lc->bf = EH;//首先得使他们的平衡因子改变了
            R_Rotate(T);
            break;
        case RH: 
            rd = lc->rchild;
            switch(rd->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    (*T)->bf = lc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
            break;
    }
}
//右子树的平衡处理同左子树的平衡处理完全类似
void RightBalance(BSTree* T)
{
    BSTree lc,rd;
    lc= (*T)->rchild;
    switch (lc->bf)
    {
        /**
                  T
                /   \
               b    LC
                   /  \
                  n    m
                        \
                         k
                   
                    LC
                   /  \
                  T    m
                 / \    \
                b   n    k
        
        **/
        case RH:
            (*T)->bf = lc->bf = EH;
            L_Rotate(T);
            break;
            
        case LH:
            rd = lc->lchild;
            
            switch(rd->bf)
            {
            /**
                  T
                /   \
               b    LC
                   /  \
                  rd   m
                   \     
                    y  
                    
                    
                  T
                /   \
               b    rd
                      \
                       LC
                      /  \
                     y    m   
                     
                     
                    rd
                    / \
                   T   LC
                  /   /  \
                 b   y    m     
                            
            **/
                case LH:
                    (*T)->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    (*T)->bf = lc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = LH;
                    lc->bf = EH;
                    break;
            }
            rd->bf = EH;
            R_Rotate(&(*T)->rchild);
            L_Rotate(T);
            break;
    }
}

int InsertAVL(BSTree* T,ElemType e,bool* taller)  //第二个是要插入的数据
///判断插入的过程中会不会影响这棵树的平衡
{
    //如果本身为空树，则直接添加 e 为根结点
    if ((*T)==NULL)
    {
        (*T)=(BSTree)malloc(sizeof(BSTNode));
        (*T)->bf = EH;
        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        *taller = true;
    }
    //如果二叉排序树中已经存在 e ，则不做任何处理
    else if (e == (*T)->data)
    {
        *taller = false;
        return 0;
    }
    //如果 e 小于结点 T 的数据域，则插入到 T 的【左子树】中
    else if (e < (*T)->data)
    {
        //如果插入过程，不会影响树本身的平衡，则直接结束
        if(!InsertAVL(&(*T)->lchild,e,taller))
            return 0;
        //判断插入过程是否会导致整棵树的深度 +1
        if(*taller)
        {
            //判断根结点 T 的平衡因子是多少，
            //由于是在其左子树添加新结点的过程中导致失去平衡，
            //所以当 T 结点的平衡因子本身为 1 时，
            //需要进行左子树的平衡处理，否则更新树中各结点的平衡因子数
            switch ((*T)->bf)
            {
                case LH:
                    LeftBalance(T);
                    *taller = false;
                    break;
                case  EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
            }
        }
    }
    //同样，当 e>T->data 时，需要插入到以 T 为根结点的树的右子树中，同样需要做和以上同样的操作
    else
    {
        if(!InsertAVL(&(*T)->rchild,e,taller))
            return 0;
        if (*taller)
        {
            switch ((*T)->bf)
            {
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                case EH:
                    (*T)->bf = RH;
                    *taller = true;
                    break;
                case  RH:
                    RightBalance(T);
                    *taller = false;
                    break;
            }
        }
    }
    return 1;
}
//判断现有平衡二叉树中是否已经具有数据域为 e 的结点
bool FindNode(BSTree root,ElemType e,BSTree* pos)
{
    BSTree pt = root;
    (*pos) = NULL;
    while(pt)
    {
        if (pt->data == e)
        {
            //找到节点，pos指向该节点并返回true
            (*pos) = pt;
            return true;
        }
        else if (pt->data>e)
        {
            pt = pt->lchild;
        }
        else
            pt = pt->rchild;
    }
    return false;
}
//中序遍历平衡二叉树
void InorderTra(BSTree root)
{
    if(root->lchild)
        InorderTra(root->lchild);
   
    printf("%d ",root->data);
   
    if(root->rchild)
        InorderTra(root->rchild);
}

int main()
{
    int i,nArr[] = {1,23,45,34,98,9,4,35,23};
    BSTree root=NULL,pos;
    bool taller;
    //用 nArr查找表构建平衡二叉树（不断插入数据的过程）
    for (i=0;i<9;i++)
    {
        InsertAVL(&root,nArr[i],&taller);
    }
    //中序遍历输出
    InorderTra(root);
    //判断平衡二叉树中是否含有数据域为 103 的数据
    if(FindNode(root,103,&pos))
        printf("\n%d\n",pos->data);
    else
        printf("\nNot find this Node\n");
    return 0;
}


————————————————————————
<CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />



import React, { Component } from 'react';
//导入的是手指摸上去的变化和CSS样式表
import { View, Text, TouchableOpacity, StyleSheet, Image } from 'react-native';
//这个是颜色渐变的
//import LinearGradient from 'react-native-linear-gradient';
//这个是头像的
import Avatar from '../common/Avatar';
//这个是可以检查传来的prop-types类型的
import PropTypes from 'prop-types';
//在安卓开发，需要用到dp这个单位，这个里面有设备的宽度和高度，还有一个转换公式
import { pxToDp } from '../../utils/pxToDp';
//这个是检测用户信息啥子的一堆
import utils from '../../utils/utils';

import iii from '../../asserts/images/logo.jpg';
//这个大概是统一一下样式啥的
import {
    flexColumnSpb,
    flexRowCenter,
    flexRowSpb,
    fontStyle,
    margin,
    padding,
} from '../../utils/StyleUtils';

//这个是组件触摸的时候，设置不透明度的
import { activeOpacity } from '../../constants/config';
//这个是导入啥图标的
import Icon from '../common/Icon';
import { autorun } from 'mobx';
const COLORARRAY = [
    '#E74C3C', //这个类似于橘红色
    '#6BB9F0', //天蓝色
    '#BF55EC', //紫色
    '#F84975', //粉红色
    '#2ECC71', //草绿色
    '#F9690E', //橘黄色
    '#F9BF3B', //屎黄色 *****
    '#03C9A9', //蓝绿色
    '#ff4960', //数字红
];





——————————————————————————————





import CourseXCard from './src/components/bussiness/CourseXCard';
import UserXCard from './src/components/bussiness/UserXCard';
import Avatar from './src/components/common/Avatar/index';
// class App extends Component {
//   constructor(props) {
//     super(props);
//     this.state = {};
//   }

//   componentDidMount() {
//     // 接口挂载到全局
//     RootStore.globalStore.allData.Http = Http;
//   }

//   render() {
//     return (
//       <View style={{ flex: 1 }}>
//         {/*<StatusBar translucent={true} backgroundColor={'transparent'} />*/}
//         <Provider RootStore={RootStore}>
//           <Nav />
//         </Provider>
//       </View>
//     );
//   }
// }

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {};
  }

  componentDidMount() {
    // 接口挂载到全局
    RootStore.globalStore.allData.Http = Http;
  }

  render() {
    return (
      <View >
        {/*<StatusBar translucent={true} backgroundColor={'transparent'} />*/}
        <Provider RootStore={RootStore} >
          <View style={{ display: 'flex', flexWrap: 'wrap' }}>
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
            <CourseXCard avatar={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} title={'logo设计品牌思维实战简介'} courseImage={{ uri: 'https://pic1.zhimg.com/v2-8651222ab9e9e09235fd2e3025e3eaa8_r.jpg' }} />
          </View>
        </Provider>
      </View>
    );
  }
}

————————————————————————————————————

import React, { Component } from 'react';
//导入的是手指摸上去的变化和CSS样式表
import { View, Text, TouchableOpacity, StyleSheet, Image } from 'react-native';
//这个是颜色渐变的
import LinearGradient from 'react-native-linear-gradient';
//这个是头像的
import Avatar from '../common/Avatar';
//这个是可以检查传来的prop-types类型的
import PropTypes from 'prop-types';
//在安卓开发，需要用到dp这个单位，这个里面有设备的宽度和高度，还有一个转换公式
import { pxToDp } from '../../utils/pxToDp';
//这个是检测用户信息啥子的一堆
import utils from '../../utils/utils';

import iii from '../../asserts/images/logo.jpg';
//这个大概是统一一下样式啥的
import {
    flexColumnSpb,
    flexRowCenter,
    flexRowSpb,
    fontStyle,
    margin,
    padding,
} from '../../utils/StyleUtils';

//这个是组件触摸的时候，设置不透明度的
import { activeOpacity } from '../../constants/config';
//这个是导入啥图标的
import Icon from '../common/Icon';
import { autorun } from 'mobx';
import { block } from 'react-native-reanimated';
const COLORARRAY = [
    '#E74C3C', //这个类似于橘红色
    '#6BB9F0', //天蓝色
    '#BF55EC', //紫色
    '#F84975', //粉红色
    '#2ECC71', //草绿色
    '#F9690E', //橘黄色
    '#F9BF3B', //屎黄色 *****
    '#03C9A9', //蓝绿色
    '#ff4960', //数字红
];







