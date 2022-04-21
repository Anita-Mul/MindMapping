1.求最大子序和
int maxSubArray(int* nums, int numsSize)
{
    int MaxSum, Sum, i, m, j = 0, h = 0, EndSum;
    m = nums[0];
    for(i = 0; (i < numsSize) && (nums[i] < 0); i++)  //i是第一个大于0的数
    {
        if(nums[i] > m)
            m = nums[i];
    }
    if(i == numsSize)
        return m;
    else
    {
        EndSum = nums[i];

        while((i != numsSize) && (j != numsSize) && (h != numsSize))
        {
            MaxSum = Sum = nums[i];
            for(j = i + 1; j < numsSize; j++)
            {
                Sum = Sum + nums[j];
                if(Sum < 0)
                    break;
                if(Sum > MaxSum)
                    MaxSum = Sum;
            }

            if(MaxSum > EndSum)
                EndSum = MaxSum;

            for(h = j; (nums[h] < 0) && (h < numsSize); h++);
            i = j;
        }
    }
    return EndSum;
}

void main()
{
    int nums[] = {-1,-5,-6,2,-8,9,-1,-2,-3,10,5,4};
    printf("%d", maxSubArray(nums,12));
}


------------------------------------
贪心算法
就是从第一个数字开始，遇到小于0的就跳过

int maxSubArray(int* nums, int numsSize)
{
	//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = nums[0];
        int sum = 0;
		int i;
        for (i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return result;
    }
  
}

-----------------------------------------------------------------------

    int maxSubArray(int *nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;   //是一个无穷小的数
        int numsSize = sizeof(nums);
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }

    int maxSubArrayHelper(int *nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无线循环
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
		
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
		
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
    }
	
	//贪心算法
    int findMaxCrossingSubarray(int *nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;   //是一个无穷小的数
        int sum = 0;
		int i;
        for (i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};


=====================================================================================
用递归加分治法找出数组中第一大和第二大的数
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
 
void max(int str[],int lo,int hi,int *x1,int *x2)//包括lo，不包括hi 
{
	if(lo+2==hi)//两个元素 lo，lo+1 ,不包括hi 
	{
		x1=str[lo];
		x2=str[lo+1];
		if(x1<x2) swap(&x1,&x2);
		return;
	}
	if(lo+3==hi)//三个元素  lo，lo+1,lo+2 ，不包括hi 
	{
		x1=str[lo];
		x2=str[lo+1];
		if(x1<x2) swap(&x1,&x2);
		if(str[lo+2]>x2)
		{
			x2=str[lo+2];
			if(x1<x2) swap(&x1,&x2);
		}
		return;
	}
	int mi=(lo+hi)/2;
	
	int xl1,xl2;
	max(str,lo,mi,xl1,xl2);
	
	int xr1,xr2;
	max(str,mi,hi,xr1,xr2);
	
	if(xl1>xr1)
	{
		x1=xl1;
		x2=(xl2>xr1) ? xl2 : xr1;
	}
	else
	{
		x1=xr1;
		x2=(xr2>xl1) ? xr2 : xl1;
	}
	printf("合并：%d %d\n",x1,x2);
}

int main() 
{
	int str[13]={1,28,2,5,4,6,9,8,19,17,10,29,20};
	int x1=0;
	int x2=0;
	max(str,0,13,&x1,&x2);
	printf("%d %d",x1,x2);
	return 0;
}






=====================================================================================





求众数，超过半数的数就是众数（摩尔排序：就是我有5个人，你有三个人，我让我的三个人跟你打，抵消，我最后还有2个人，所以我赢）

int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i] == key)		//如果元素和标记元素相同，计数加一
            count++;
        else		//否则减一
            count--;
        
        if(count <= 0)		//当计数小于等于零时，更换标记
        {
            key = nums[i+1];
        }
        
    }
    return key;		//遍历结束后，一定为多数
}
————————————————

==========================================================================
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0
#define ALWAYS 1

#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void sort(int x[], int n)
{
    int sorted;
    int split;
    int next;
    int key;

    x[n] = -1;
    for(sorted = 0; sorted < n; sorted++)
    {
        while(x[sorted] > 0)  
        {
            key = x[sorted];  
            split = sorted;   
            for(next = sorted + 1; x[next] > 0; next++)  
            {
                
				if(x[next] < key)
                {
                    split++;

                    SWAP(x[split], x[next]);  
                }
            }
            SWAP(x[sorted], x[split]);
            x[split] = -x[split];
        }
        x[sorted] = -x[sorted];  
    }
}


int* twoSum(int *nums, int numsSize, int target, int* returnSize)
{
    int *nums1;
    int n;
    for(n = 0; n < numsSize; n++)
        nums1[nums[n]] = n;

    sort(nums,numsSize);

    int i = 0, j = n - 1;
    while(i != j)
    {
        if(nums[i] + nums[j] < target)
        {
            i++;
        }

        else if(nums[i] + nums[j] == target)
        {
            returnSize[0] = nums1[nums[i]];
            returnSize[1] = nums1[nums[j]];
            return returnSize;
        }
        else
            j--;
    }
}

int main()
{
    int nums[] = {2,4,1,6,7};
    int returnSize[10];
    twoSum(nums,5,9,returnSize);
    printf("%d %d",returnSize[0], returnSize[1]);
}


==========================================================================
#include <malloc.h>
#include <stdbool.h>
用链表实现两个数字相加

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}*PNODE,NODE;

PNODE creat_list(void)
{
    int len;
    int i;
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("动态内存分配失败");
        exit(-1);
    }

    PNODE pTail = pHead;
    pHead->next = NULL;
    printf("请您输入您想要的节点个数：");
    scanf("%d",&len);

    for(i = 0; i < len; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败");
            exit(-1);
        }

        printf("请输入第%d个节点的值：",i + 1);
        scanf("%d",&val);

        pNew->data = val;
        pNew->next = NULL;

        pTail->next = pNew;
        pTail = pNew;
    }
    return pHead;

}

PNODE addTwoNumbers(PNODE L1, PNODE L2)
{
    int number = 0;
    int index1, index2;
    PNODE FirstList = (PNODE)malloc(sizeof(NODE));
    if(FirstList == NULL)
    {
        printf("动态内存分配失败");
        exit(-1);
    }
    PNODE EndList = FirstList;
    EndList->next = NULL;

    L1 = L1->next;
    L2 = L2->next;
    if(L1 != NULL && L2 != NULL)
    {
        index1 = L1->data;
        index2 = L2->data;
        if(index1 + index2 >= 10)
        {
            number = ((index1 + index2 + number) / 10) % 10;
        }

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败");
            exit(-1);
        }
        pNew->data = (index1 + index2) % 10;
        pNew->next = NULL;
        EndList->next = pNew;
        EndList = pNew;
    }

    L1 = L1->next;
    L2 = L2->next;

    while(L1 != NULL && L2 != NULL)
    {

        index1 = L1->data;
        index2 = L2->data;

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败");
            exit(-1);
        }
        pNew->data = (index1 + index2 + number) % 10;
        pNew->next = NULL;
        EndList->next = pNew;
        EndList = pNew;

        if(index1 + index2 + number >= 10)
        {
            number = ((index1 + index2 + number) / 10) % 10;
        }
        else
            number = 0;

        L1 = L1->next;
        L2 = L2->next;
    }

    if(L1 == NULL && L2 != NULL)
    {
        while(L2 != NULL)
        {
            PNODE pNew = (PNODE)malloc(sizeof(NODE));
            if(pNew == NULL)
            {
                printf("动态内存分配失败");
                exit(-1);
            }
            pNew->data = (L2->data + number) % 10;
            pNew->next = NULL;
            EndList->next = pNew;
            EndList = pNew;

            if(L2->data + number >= 10)
            {
                number = ((L2->data + number) / 10) % 10;
            }

            L2 = L2->next;
        }
        if(number != 0)
        {
            PNODE pNew = (PNODE)malloc(sizeof(NODE));
            if(pNew == NULL)
            {
                printf("动态内存分配失败");
                exit(-1);
            }
            pNew->data = number;
            pNew->next = NULL;
            EndList->next = pNew;
            EndList = pNew;
        }
    }
    if(L2 == NULL && L1 != NULL)
    {
        while(L1 != NULL)
        {
            PNODE pNew = (PNODE)malloc(sizeof(NODE));
            if(pNew == NULL)
            {
                printf("动态内存分配失败");
                exit(-1);
            }
            pNew->data = (L1->data + number) % 10;
            pNew->next = NULL;
            EndList->next = pNew;
            EndList = pNew;

            if(L1->data + number >= 10)
            {
                number = ((L1->data + number) / 10) % 10;
            }

            L1 = L1->next;
        }
        if(number != 0)
        {
            PNODE pNew = (PNODE)malloc(sizeof(NODE));
            if(pNew == NULL)
            {
                printf("动态内存分配失败");
                exit(-1);
            }
            pNew->data = number;
            pNew->next = NULL;
            EndList->next = pNew;
            EndList = pNew;
        }
    }
    if(number != 0)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败");
            exit(-1);
        }
        pNew->data = number;
        pNew->next = NULL;
        EndList->next = pNew;
        EndList = pNew;
    }
    return FirstList;
}


int main(void)
{
    printf("请倒序输入一个数字\n");
    PNODE pHead1 = creat_list();


    printf("请倒序输入一个数字\n");
    PNODE pHead2 = creat_list();

    printf("这两个数字相加的结果是：\n");
    PNODE answer = addTwoNumbers(pHead1,pHead2);

    while(answer != NULL)
    {
        answer = answer->next;
        printf("%d", answer->data);
    }
}



========================================================================================================================================================
判断一个数是不是回文数

直接前一个后一个的判断
int num = 189981;
    int n;

    int first, end;

    first = num / 100000;
    end = num % 10;
    n = 100000;

    while(first == end && num / 100 != 0 && num / 10 != 0)
    {
        num = (num - n * first - end) / 10;
        n = n / 100;
        first = num / n;
        end = num % 10;
    }

    if((num % 10) == (num / 10) || num / 10 == 0)
        printf("此数是回文数");
    else
        printf("此数不是回文数");
		
--------------------------------------------------------------
#define true 1
#define false 0
//倒叙把一个数输入到k中，判断和之前的数字相不相同
int huiwenshu(int n)
{
	int p;
	p = n;
	int k = 0;
	while(p != 0)
	{
		k = k * 10 + p % 10;
		p = p / 10;
	}
	
	if(k == n)
		return true;
	else
		return false;
}


=====================================================================================================================================================
建立一个三维表，求出最长公共子序列
#include <malloc.h>

void Longest(char *L1, char *L2, char *L3)
{
   int m = strlen(L1), n = strlen(L2), h = strlen(L3);
   int d[10][10][10];
   int i, j, k, i1 = 0;
   int t;
   int count = 0;

   d[0][0][0] = 0;

   for(i = 1; i <= m; d[i][0][0] = 0, i++);
   for(j = 1; j <= n; d[0][j][0] = 0, j++);
   for(k = 1; k <= h; d[0][0][k] = 0, k++);

   for(i = 1; i <= m; i++)
   {
       for(j = 1; j <= n; j++)
       {
           for(k = 1; k <= h; k++)
           {
               if(L1[i - 1] == L2[j - 1] && L1[i - 1] == L3[k - 1] && L3[k - 1] == L2[j - 1])
                    d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
               else
                    d[i][j][k] = 0;
                printf("%d\n",d[i][j][k]);

               if(d[i][j][k] > count)
               {
                   count = d[i][j][k];
                   i1 = i;
               }
           }
       }
   }

   if(count != 0)
   {
       printf("相同的子串为：\n");
       for(i = i1 - count;i < i1 ; i++)
       {
           printf("%c",L1[i]);
       }
   }
   else
   {
       printf("这三个数组里没有相同的元素");
   }
}


int main()
{
    char L1[] = "KGIBCDY";
    char L2[] = "FABC";
    char L3[] = "ABCE";
    int i;
    Longest(L1,L2,L3);

}


======================================================================================================================================================

#include <malloc.h>

//连接两个链表
typedef struct ListNode
{
    int data;
    struct ListNode *next;
}*PNODE,NODE;

PNODE creat_list(void)
{
    int point;
    int i;
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->next = NULL;

    printf("请输入你需要的节点个数：");
    scanf("%d", &point);

    for(i = 0; i < point; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }

        printf("请你输入第%d个节点的数字：\n", i + 1);
        scanf("%d", &val);

        pNew->data = val;
        pNew->next = NULL;

        pTail->next = pNew;
        pTail = pNew;
    }

    return pHead;
}


int main(void)
{
   PNODE P1 = creat_list();
   PNODE P2 = creat_list();
   PNODE P3_head = (PNODE)malloc(sizeof(NODE));
   if(P3_head == NULL)
   {
        printf("动态内存分配失败！");
        exit(-1);
   }

   PNODE P3_tail = P3_head;
   P3_tail->next = NULL;


   P1 = P1->next;
   P2 = P2->next;
   while(P1 != NULL && P2 != NULL)
   {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }

        pNew->data = P1->data;
        pNew->next = NULL;
        P3_tail->next = pNew;
        P3_tail = pNew;

        PNODE pNew1 = (PNODE)malloc(sizeof(NODE));
        if(pNew1 == NULL)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }

        pNew1->data = P1->data;
        pNew1->next = NULL;
        P3_tail->next = pNew1;
        P3_tail = pNew1;

        P1 = P1->next;
        P2 = P2->next;
   }

   if(P1 != NULL && P2 == NULL)
   {
       PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }

        pNew->data = P1->data;
        pNew->next = NULL;
        P3_tail->next = pNew;
        P3_tail = pNew;

        P1 = P1->next;
   }

   if(P2 != NULL && P1 == NULL)
   {
       PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }

        pNew->data = P2->data;
        pNew->next = NULL;
        P3_tail->next = pNew;
        P3_tail = pNew;

        P2 = P2->next;
   }

   while(P3_head != NULL)
   {
       P3_head = P3_head->next;
       printf("%d",P3_head->data);
   }
}



======================================================================================================================================================
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
int search_val(int *s, int val, int first, int end)
{
    int mid;
    mid = (first + end) / 2;
    if(val > s[mid])
    {
        if(first == end)
            return mid + 1;
        else
            return search_val(s, val, mid + 1, end);
    }
    if(val < s[mid])
    {
        if(first == end)
        {
            if(first == 0)
                return 0;
            else
                return mid - 1;
        }
        else
            return search_val(s, val, first, mid - 1);
    }
    if(val == s[mid])
        return mid;
}

int main()
{
    int s[] = {1,3,5,6};
    int val = 2;
    printf("%d",search_val(s, val, 0, 3));
}


======================================================================================================================================================
外观数列
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221


1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。


int number = 1; //记录数组最终有多少数字

void beautiful(int *s, int n)
{
    int num[20];
    int m = 0; //遍历整个数组
    int i = 1; //记录当前有多少个重复数字
    int j = 0; //输入到num数组中的
    int p;

    if(n == 0)   //n是这样的递归执行几次
    {
        for(p = 0; p < number; p++)
           printf("%d",s[p]);
    }
    else
    {
        while(m < number)
        {
            while(s[m] == s[m + 1])
            {
                i++;
                m++;
            }

             num[j++] = i;
             num[j++] = s[m];
             m++;
             i = 1;
        }

        number = j;

        n = n - 1;
        return beautiful(num,n);
    }

}

int main()
{
    int i;
    int num[20] = {1};
    beautiful(num, 4);

}

=======================================================================================================================================
//最后一个单词的长度
int lengthOfLastWord(char * s)
{
    int i;
    int n = strlen(s);
    int m = 0;
    for(i = 0; i < n && s[i] != ' '; i++);
    if(i == n)
        return 0;
    else
    {
        while(i < n)
        {
            i++;
            m = 0;
            while(s[i] != ' ' && i < n)
            {
                m++;
                i++;
            }
        }
        return m;
    }
}

=======================================================================================================================================
一个数开平方
int mySqrt(int x, int first, int last)
{
    int mid = (first + last) / 2;
    if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
        return mid;
    else if(mid * mid > x)
        return mySqrt(x, first, mid - 1);
    else
        return mySqrt(x, mid + 1, last);
}

int main()
{
    int num = 12;
    printf("%d",mySqrt(num,0,num));
}


=======================================================================================================================================

删除重复元素（收藏，这个是错的）
typedef struct ListNode
{
    int data;
    struct ListNode *next;
}*PNODE,NODE;

PNODE creat_list(void)
{
    int point;
    int i;
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->next = NULL;

    printf("请输入你需要的节点个数：");
    scanf("%d", &point);

    for(i = 0; i < point; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }

        printf("请你输入第%d个节点的数字：\n", i + 1);
        scanf("%d", &val);

        pNew->data = val;
        pNew->next = NULL;

        pTail->next = pNew;
        pTail = pNew;
    }

    return pHead;
}

PNODE delete_list(PNODE pHead)
{
    /*PNODE pAnswer = (PNODE)malloc(sizeof(NODE));
    if(pAnswer == NULL)
    {
        printf("动态内存分配失败");
        exit(-1);
    }
    PNODE pAnswer_Tail = pAnswer;
    PNODE p = pAnswer;
    pAnswer_Tail->next = NULL;*/

    PNODE pHead1 = pHead;
    PNODE p = pHead;
    pHead = pHead->next;

    while(pHead->next != NULL)
    {
        while(pHead->data == pHead->next->data  && pHead->next != NULL)
        {
            pHead = pHead->next;
            //free(pHead);
            //pHead = NULL;
        }
        pHead1->next = pHead;
        //pAnswer_Tail->next->next = NULL;
        pHead1 = pHead1->next;
        while(p != NULL)
        {
            p = p->next;
            printf("%d", p->data);
        }

        pHead = pHead->next;
    }
    if(pHead->data != pHead1->data)
    {
        pHead1->next = pHead;
        pHead1->next->next = NULL;
    }
    else
        pHead1->next = NULL;
    while(p != NULL)
        {
            p = p->next;
            printf("%d", p->data);
        }

    return p;

}



int main()
{
    PNODE pHead = creat_list();
    PNODE pAnswer = delete_list(pHead);

    while(pAnswer != NULL)
    {
        pAnswer = pAnswer->next;
        printf("%d", pAnswer->data);
    }

}



=======================================================================================================================================

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。


示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。


/**
 * j指向当前遍历的值，i指向当前遍历过的值中的最小值，max表示当前的最大利润。
 * 当prices[j] < prices[i]，更新i，否则判断prices[j] - prices[i]是否大于max，然后更新max
 */

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    for(int i = 0, j = 0; j < pricesSize; j++){		
        if(prices[j] < prices[i]){
            i = j;
	}else if(prices[j] - prices[i] > max){
            max = prices[j] - prices[i];
        }
    ｝
    return max;
}

=================================================================================================
股票问题

1.
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。


示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。


示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

*贪心算法
如果是第一天买进，可以第二天卖出的话，第二天可以同时买进的
可以通过局部利益最大，就是整体利益最大
如果是递增 1   4    6   7  第一天买进，第二天卖出，第二天买进，第三天卖出。。。
和第一天买进第四天卖出的结果相同

int maxProfit(int* prices, int pricesSize)
{
	int res = 0;
	int len = pricesSize;
	int i = 0;
	int diff;
	
	for(i = 0; i < len - 1; i++)
	{
		diff = prices[i + 1] - prices[i];
		if(diff > 0)
			res += diff;
	}
	return res;
}

*动态规划
分为两列，第一列是卖出可以得到多少钱，第二列是买入可以得到多少钱
数据： 7  1  5  3  6  4  

        0      -7
		0      -1
		4      -1
        4       1
        7       4	

原来没有钱                                         买入得到的钱是负的
如果卖出，可以得到-6 块钱，还不如不卖呢	           如果买入，会亏一块钱，比原来少，买了它	
如果卖出，可以得到四块钱，比原来多，所以就要卖了   如果买入，会亏六块钱，不买
如果卖出，挣两块钱，没有原来多，所以不卖           如果卖出，还会余下一块钱，所以买
如果卖出，可以得到七块钱，卖                       如果买入，会亏两块钱，不买

int maxProfit(int* prices, int pricesSize)
{
	int len = pricesSize;
	int i;
	if(len < 2)
		return 0;
	int dp[len][2];
	
	dp[0][0] = 0;
	dp[0][1] = -prices[0];
	
	for(int i = 1; i < len; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	
	return dp[len - 1][0];
}

————————————————————————————————————————————————————————————————————————————————
位操作
概念

如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位

a⊕0=aa \oplus 0 = aa⊕0=a


如果我们对相同的二进制位做 XOR 运算，返回的结果是 0

a⊕a=0a \oplus a = 0a⊕a=0


XOR 满足交换律和结合律

a⊕b⊕a=(a⊕a)⊕b=0⊕b=ba \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = ba⊕b⊕a=(a⊕a)⊕b=0⊕b=b



所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。


给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1


示例 2:

输入: [4,1,2,1,2]
输出: 4

int singleNumber(int* nums, int numsSize){
    if(numsSize == 1){
        return nums[0];
    }
    int a = 0;
    for(int i = 0;i < numsSize ;i++){
        a ^= nums[i];
    }
    return a;
}


————————————————————————————————————————————————————————————————————————————————
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

*双指针快慢法
struct ListNode 
{
    int val;
    struct ListNode *next;
};
 
bool hasCycle(struct ListNode *head) 
{
    if(head == null || head.next == NULL)
		return false;
	struct ListNode slow = head;
	struct ListNode fast = head.next;
	while(slow != fast)
	{
		if(fast == NULL || fast.next == NULL)
			return false;
		slow = slow.next;
		fast = fast.next;
	}
	return true;
}

__________________________________________________________________________________________________________________

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]



struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


/**
	因为我的目的是从下往上遍历左节点，以各个左节点为起点，开始不断输出它的右边
**/

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode* st[1000] = {0};  //struct TreeNode*  就是st数组里每个元素的类型
    int *nums = malloc(sizeof(int) * 1000);
    int p = -1, index = 0;

    while(root != NULL || p != -1)
    {
        while(root != NULL)
        {
            st[++p] = root;
            root = root->left;
        }
		
        if(p != -1)
        {
            root = st[p--];
            nums[index++] = root->val;
            root = root->right;
        }
    } 

    *returnSize = index;
    return nums;  
}

__________________________________________________________________________________________________________________
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。不会

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
	二叉树的内存分配
	分为两种情况
	struct TreeNode*       这种情况的意思就是 树是一个类似于链表的结构 所以每一个树节点都是一个指针类型
	struct TreeNode**      这种情况的意思就是 一个数组里储存着储存着很多树结点  每一个树节点都是一个指针
	
	所以分配内存要分配两次，一次是给数组里这个位置分配内存，还有一个是给这个结点分配内存

*/


struct TreeNode** create(int start,int end,int*m)   //m是这个数组里有几个位置
// 返回所有从start开始到end结束这些数所能构成的二叉搜索树，并通过间接赋值输出这些二叉树的数目

{
    struct TreeNode **p,**lefts,**rights;
    int a,i,b,j,k,count = 0;   
		
	
    if(start > end) 
    {              
        //这个空也在数组里占一个位置
		p = (struct TreeNode**)malloc(sizeof(struct TreeNode*)); //二级指针只指向一个一级指针
        *p = NULL; 
        *m = 1; 
        return p;
    } 
    
    if(start == end)             //当子树个数为一时的特殊情况
    {
         p = (struct TreeNode**)malloc(sizeof(struct TreeNode*));   //二级指针只指向一个一级指针
        *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*p)->left = (*p)->right = NULL;   //当子树为1时的赋值
        (*p)->val = start;
        *m = 1;
        return p;
    }                         //为了减少循环量，不写也可以
	
	//这个给p分配的内存就是在数组里分配10000个位置
    p=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);//设置一个足够大的分配内存空间来存储左右子树的各种情况
	
    
	for(i = start;i<=end;i++)
    {
        //下面这两步的目的就是确定根节点i 和它的左右子树 ab就是数组里有多少个位置
		//当完成下面两步之后，lefts 和 rights就是两个二维数组，每一行分别是一种情况
		lefts = create(start,i-1,&a);
        rights = create(i+1,end,&b);     //递归生成左右子树s
        
        for(k = 0;k<a;k++)
        {
            for(j=0;j<b;j++)          //两个for循环链接两个子树s        
            {
                //因为刚才已经分配了位置，所以现在只要分配结点就行
				p[count] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                p[count]->val = i;
                p[count]->left = lefts[k];
                p[count]->right = rights[j];      
                count++; //记录个数
            }
        } 
    }
     *m = count;
    return p;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize){
    struct TreeNode** p;
    if(n == 0) 
    {
        *returnSize = 0;
        return NULL;
    }       //当n为0的特殊情况
    p = create(1,n,returnSize);  //调用函数计算
    return p;
}//结束

=====================================================================================================================

翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9

输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

Please look this, this is left_right type that our speak 
struct TreeNode* invertTree(struct TreeNode* root)
{
    
    struct TreeNode* tmpNode;
    
    if(root)
    {   
       tmpNode = invertTree(root->left);
       root->left = invertTree(root->right);
       root->right = tmpNode;
    }
    
    return root;   
}


————————————————————————————————————————————————————————————————————————————————
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return root;
		
    //记住树是通过指针相连，只要左右换了，就是左边所有的和右边所有的都换了
	struct TreeNode *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left != NULL)
    {
        invertTree(root->left);
    }
    if(root->right != NULL)
    {
        invertTree(root->right);
    }
    return root;
}

=====================================================================================================================
/**
    给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：


	每个节点都有 0 个或是 2 个子节点。
	数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
	每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。


    在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。

     

    示例：

    输入：arr = [6,2,4]
    输出：32
    解释：
    有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。

        24            24
       /  \          /  \
      12   4        6    8
     /  \               / \
    6    2             2   4
    
    我来大概重复一下这道题的意思：
    父节点的值就是左子树叶节点最大的 × 右子树叶节点最大的，何为叶节点，就是数组里的值，何为父节点，就是求出来的值
    所以首先要取出数组里最大的数
    如果这个数在左右两边
    如果这个数在中间 
     
    因为节点值等于左边的叶子节点的最大值 * 右边叶子结点的最大值  所以要使叶子结点尽量放在高处，这样只有比它高的结点会影响，而比他矮的不会被影响	 

**/

/*
为了保证最后输出的结果最小，分析可知尽量让数值大的分布在较高的节点处，
这样计算非叶节点值的时候会用到这个较大数值的次数就相对比较少了。
以此分析，以最大数值为分界点，
把树分为左子树和右子树，分别计算非叶节点的和即可。
*/

//找最大的就是找最大的所对应的下标
int GetMaxIdx(int *arr, int arrSize)
{
    int max = arr[0];
    int out = 0;
    for (int i = 0; i < arrSize; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
            out = i;
        }
    }   
    return out;
}

//递归其实就是看父节点和两个孩子的情况
int CalcMin(int *arr, int arrSize)
{
    /* 1、得到数组中最大成员序号 */
    
    //特殊情况：如果只有两个元素，返回他们的乘积
    if (arrSize == 2) 
    {
        return arr[0] * arr[1];
    }
    
    //如果有1个元素，就没有这种情况
    if (arrSize == 1) 
    {
        return 0;
    }
    
    int finalOut = 0x7fff;
	
    //取出这个里面的最大值的下标
    int Idx = GetMaxIdx(arr, arrSize);
    
    for (int i = 0; i < arrSize; i++)  //这个循环的目的就是找出有没有这个数，我觉着没用
    {
        if (arr[i] == arr[Idx]) 
        {
            int out = 0;
            int maxIdx = i;
            
            /* 最大数值在两端点的情况 */
            if (maxIdx == 0) 
            {
                //找出剩下的最大值
                int secMax = GetMaxIdx(arr + 1, arrSize - 1);
                
                //out的意思就是根节点的值
                out = (arr + 1)[secMax] * arr[maxIdx];
                out += CalcMin(arr + 1, arrSize - 1);
                
                return out;
            }
            else if (maxIdx == arrSize - 1) 
            {
                int secMax = GetMaxIdx(arr, arrSize - 1);
                out  = arr[secMax] * arr[maxIdx];
                out += CalcMin(arr, arrSize - 1);
                
                return out;
            } 
            
            //最大数值在中间的情况
            else 
            {
                int leftMax = GetMaxIdx(arr, maxIdx); // 左侧最大值【索引】
                int rightMax = GetMaxIdx(arr + maxIdx + 1, arrSize - maxIdx - 1); // 右侧最大值索引
                int left = arr[leftMax];
                int right = (arr + maxIdx + 1)[rightMax];
                
                /* 根据次大的数值选择最大数值位于左子树还是右子树 */
                if (left > right) 
                { 
                    out = left * arr[maxIdx]; //次大数值在左侧，那最大数值放在右子树。
                    //遍历右子树
                    out += CalcMin(arr + maxIdx, arrSize - maxIdx);
                    //遍历左子树
                    out += CalcMin(arr, maxIdx);
                } 
                else if (left < right) 
                {
                    out = right * arr[maxIdx]; //次大数值在右侧，那最大元素放在左子树
                    out += CalcMin(arr + maxIdx + 1, arrSize - maxIdx - 1);
                    out += CalcMin(arr, maxIdx + 1);
                } 
                else 
                {   // 如果次大数值在最大数值的两侧都有，那就都计算一遍比较哪种比较小
                    out = left * arr[maxIdx];
                    out += CalcMin(arr + maxIdx, arrSize - maxIdx);
                    out += CalcMin(arr, maxIdx);
                    
                    int tmpOut = left * arr[maxIdx];
                    tmpOut += CalcMin(arr + maxIdx + 1, arrSize - maxIdx - 1);
                    tmpOut += CalcMin(arr, maxIdx + 1);
                    
                    if (tmpOut < out) 
                    {
                        out = tmpOut;
                    }
                }
            }
            //不断选出里面的最小值
            if (finalOut > out) 
            {
                finalOut = out;
            }
        }
    }  
    return finalOut;
}

int mctFromLeafValues(int* arr, int arrSize)
{
    int out;
    out = CalcMin(arr, arrSize);
    return out;
}

=====================================================================================================================
给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：


	该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）


如果不存在祖父节点值为偶数的节点，那么返回 0 。

                 6
			/         \
		   7           8
		 /   \       /   \
       [2]   [7]   [1]   [3]
	   /    / \            \
	  9    1   4           [5]


 

int sumEvenGrandparent(struct TreeNode* root) 
{
        if (root == NULL) 
			return 0;
        int temp = 0;
        if (root->val % 2 == 0) 
		{
            if (root->left != NULL) 
			{
                if (root->left->left != NULL) 
					temp += root->left->left->val;
                if (root->left->right != NULL) 
					temp += root->left->right->val;
            }
            if (root->right != NULL) 
			{
                if (root->right->left != NULL) 
					temp += root->right->left->val;
                if (root->right->right != NULL) 
					temp += root->right->right->val;
            }
        }
        return temp + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
}


__________________________________________________________________________________________________________________
深度优先遍历（就是检查每一个节点）
class Solution {
private:
    int ans = 0;
    
public:
    void dfs(int gp_val, int p_val, TreeNode* node) {
        if (!node) {
            return;
        }
        if (gp_val % 2 == 0) {
            ans += node->val;
        }
        dfs(p_val, node->val, node->left);
        dfs(p_val, node->val, node->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(1, 1, root);
        return ans;
    }
};

————————————————————————————————————————————————————————————————————————————————
广度优先遍历
首先检查一个节点是否是偶数，如果是，输出它的孙子
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) 
	{
        //建立一个队列
		queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) 
		{
            TreeNode* node = q.front();
            q.pop();
            if (node->val % 2 == 0) 
			{
                if (node->left) 
				{
                    if (node->left->left) 
					{
                        ans += node->left->left->val;
                    }
                    if (node->left->right) 
					{
                        ans += node->left->right->val;
                    }
                }
				
                if (node->right) 
				{
                    if (node->right->left) 
					{
                        ans += node->right->left->val;
                    }
                    if (node->right->right) 
					{
                        ans += node->right->right->val;
                    }
                }
            }
            if (node->left) 
			{
                q.push(node->left);
            }
            if (node->right) 
			{
                q.push(node->right);
            }
        }
        return ans;
    }
};


=====================================================================================================================
给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。

注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。

//一定要记住向下三角形和回溯三角形
int dfs(struct TreeNode* root,int target)
{
    if(root->left != NULL && dfs(root->left, target)) 
		root->left = NULL;
		
    if(root->right != NULL && dfs(root->right,target)) 
		root->right = NULL;
		
    if(root->left == NULL && root->right == NULL && root->val == target) 
		return 1;
		
    return 0;
}
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
{
    if (dfs(root, target)) 
		return NULL;
    return root;
}


=====================================================================================================================
给你一棵二叉树，请你返回层数最深的【叶子节点】的和。
                       1
                     /   \
                    2     5
                  /  \  /  \
                3    6 4    9
                           / \
                          10 12

            中间竖杠的目的是把它分为左子树和右子树
            前序遍历：1 2 3 6 5  4  9  10 12      
            后序遍历：3 6 2 4 10 12 9  5  1			
			中序遍历：3 2 6 1 4  5  10 9 12
错的精彩
int maxDeepth;

void calcSum(struct TreeNode* root, int deep, int* sumNode) 
{
    if(root == NULL)
        return ;
    if(deep > maxDeepth)
    {
        maxDeepth = deep;
        //printf("%d ", maxDeepth);
    }

    calcSum(root->left, deep + 1, sumNode);
    calcSum(root->right, deep + 1, sumNode);
    
    

    //这条语句什么时候执行，不是等前序遍历都遍历完时返回，而是只要一个结点的左右孩子都为空时，后序遍历的这条语句就开始执行了
    //所以说有可能中间输出，那就错啦，我要的是前序遍历全部完时输出
    /*
        50
           \
           54
          /  \
         98   6
               \
               34
        
        比如说这个，当前面执行完时  root->val = 98, 此时maxDeepth = 2 ，所以要输出，这就错啦
        我仔细想了一下，必须先求出深度，才可以这样计算

        不要灰心，有个想法很正确，就是前序遍历求出的最大值可以在后序遍历一直存在
    */
    printf("%d ", maxDeepth);
    if(deep == maxDeepth)
        *sumNode += root->val; 
    printf(" （%d）【%d】[%d] \n", *sumNode, root->val, deep);
      
}


int deepestLeavesSum(struct TreeNode* root)
{
    int sumNode = 0;
    maxDeepth = 0;
    calcSum(root, 0, &sumNode);
    return sumNode;
}


——————————————————————————————————————————————————————————————————————————————————

void calcSum(struct TreeNode* root, int deep, int* maxDeepth, int* sumNode) 
{
   //深度就是从1开始  
   
   /*
		下面这种方法很巧妙
		如果deep > *maxDeepth  就意为着前面计算的sumNode都不算
		sumNode得从root->val开始从新算
   */	
    if (root == NULL) 
	{
        return;
    }
    if(deep > *maxDeepth) 
	{
        *maxDeepth = deep;
        *sumNode = root->val;
    }
	else if(deep == *maxDeepth) 
	{
        *sumNode += root->val;
    }
    //printf("\ndeep %d, sum %d", *maxDeepth, *sumNode);
    calcSum(root->left,deep+1,maxDeepth,sumNode);
    calcSum(root->right,deep+1,maxDeepth,sumNode);
}
int deepestLeavesSum(struct TreeNode* root)
{
    int sumNode =0;
    int maxDeepth = 0;
    calcSum(root,0,&maxDeepth,&sumNode);
    //printf("\nsumNode = %d", sumNode);
    return sumNode;
}

=====================================================================================================================
有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到 n 各不相同。

 

游戏从「一号」玩家开始（「一号」玩家为红色，「二号」玩家为蓝色），最开始时，

「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；

「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。

「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。

 

之后两位玩家轮流进行操作，每一回合，玩家选择一个他之前涂好颜色的节点，将所选节点一个 未着色 的邻节点（即左右子节点、或父节点）进行染色。

如果当前玩家无法找到这样的节点来染色时，他的回合就会被跳过。

若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ??。

 

现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true；若无法获胜，就请返回 false。

————————————————————————————————————————————————————————————————————————————————
就是一个人着一次色，下一次着色必须根据已经着色的地方接着着
可以根据已经着色的地方向四周扩散

/**
    根据第一个涂红的点可以分为三部分：左孩子的一堆  右孩子的一堆  剩下的所有
    如果选择了左孩子，就将左孩子下面的所有涂成蓝色  剩下两部分涂成红色
    剩下同理 
**/

相当于这样
     O
	 |
	 O
	/ \
   O   O


struct TreeNode *g_firstPlayer;

//找到这个点下面所有的个数,包括这个节点
int CalcNodeNum(struct TreeNode *root)
{
    if (root != NULL) 
        return 1 + CalcNodeNum(root->left) + CalcNodeNum(root->right);
}

//找到这个点和它上面所有的个数
int CalcAndFind(struct TreeNode *root, int toFind)
{
    int output = 0;
    int output = 0;
    if (root == NULL) 
    {
        return output;
    }
    if (root->val == toFind) 
    {
        g_firstPlayer = root;
        return output;
    } 
    
	//这是左右递归裸露函数
	//设置全局变量num 在主函数中初始化num为0
	
	/**
	
	num++;
    CalcAndFind(root->left, toFind);
    CalcAndFind(root->right, toFind);
    return num;
	
	**/
    
	//这是左右递归非裸露函数
	return (1 + CalcAndFind(root->left, toFind) + CalcAndFind(root->right, toFind));
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x)
{   
    g_firstPlayer = NULL;
	
	//记住一个特殊情况，就是当root是根节点的时候
    if (x == root->val) 
    {
        /* 1、如果第一个玩家选择的是第一个根节点 */
        /* 1.1、左子节点下节点总数 */
        int left = CalcNodeNum(root->left);
        
        /* 1.2、右子节点下节点总数 */
        int right = n - left - 1;  //去掉左边的个数和根节点
        if (left == right) 
            return false;

        else 
            return true;
    } 
	
	//如果root不是根节点
    else 
    {
        /* 2、第一个玩家选择非第一个根节点 */
        /* 2.1、第一个玩家选择节点的根节点 */
        int Root = CalcAndFind(root, x);   
        /* 2.2、第一个玩家选择节点的左子节点 */
        int Left = CalcNodeNum(g_firstPlayer->left);
        /* 2.3、第一个玩家选择节点的右子节点 */
        int Right = CalcNodeNum(g_firstPlayer->right);
         printf("Root = %d, Right = %d, Left = %d", Root, Right, Left);
         
        //加1的目的就是为了加上那个根节点
        if (Root > Left + Right + 1 || Right > Root + Left + 1|| Left > Root + Right + 1) 
        {
            return true;
        }  
        else 
        {
            return false;
        }
    }
}

=====================================================================================================================
二叉树寻路
就是在一棵完全二叉树中，奇数行顺序不变，偶数行反着来，找到一个点的路径

因为以1为根节点层次编号的满二叉树可以对应到位的表示，所以用位运算的思路即可。
因为每层的顺序在变，所以每次需要对首位外的其它位取反。
举例14=1110b，
先将14右移，变为111b(7)，然后对除第一位外所有位取反变为100b，即它的根节点4，
同理100b(4)，右移变为10b(2)，对除第一位外所有位取反变为11b，即它的根节点3
一直到1结束。


先开始这个二进制所有位都为0
0000 0000 0000 0000 
第一行   0000 0000 0000 0001
第二行   位数向后移动一位，补齐前面的，排列组合01  
		 0000 0000 0000 0010
         0000 0000 0000 0011
第n行同理  所以说每一行最大的数字就是 1 1111.....第一个1是上一行向后移动一个的，不能变
                       最小的数字就是 1 0000
所以才有上面的结论  << >>相当于除2  乘2

二叉树图


									   1
									  /  \
									 /    \
									/      \
								   /        \
								  /          \
								 /            \
								/              \
							   /                \
							  /                  \
						     /                    \
							/                      \
						   /                        \
						  /                          \
						 2                            3
					   /   \                        /   \
					  /     \                      /     \
					 /       \                    /       \
				    /         \                  /         \
				   /           \                /           \
				  4             5              6             7
				/   \         /   \          /   \         /   \
			   /     \       /     \        /     \       /     \         
			  8       9     10     11      12     13     14     15
			/  \    /  \   /  \   /  \    /  \   /  \   /  \   /  \
		   16  17  18  19 20  21 22  23  24  25 26  27 28  29 30  31
 


int* pathInZigZagTree(int label, int* returnSize)
{
    int count = 0;
    int tmp = label;
    //确认returnSize
    while (tmp != 0){
        tmp >>= 1;
        count++;
    }
    *returnSize = count;
    int *ret = (int *)malloc(sizeof(int)*count);
    //从末置位开始写入
    for( int i = count - 1; i > -1;i--){
        ret[i]=label;
        //将label的值右移一位，层数上升
        label >>= 1;
        //异或操作，实现题目中的反转顺序，如果没有交叉顺序的话不需要这一步操作就可以得到其父节点。
		/*
			假设label = 1000   (int)pow(2, i - 1) - 1 = 111; 由下表可知，当b为1时，a取反 
			真值表 
			 a   b   a ^ b
			 1   0     1
	     	(1   1     0)
			 0   0     0
			(0   1     1)

		*/
        label ^= (int)pow(2,i-1)-1; //(int)pow(2,i-1)的意思就是上一行总共的数字，也就是总共的二进制数位，减1就是除了第一位的
    }
    return ret;

}

=====================================================================================================================
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

 

示例：
		1
	  /   \
     0     1 
	/ \   / \
   0   1 0   1

输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

左右递归非裸露函数

int _sumRootToLeaf(struct TreeNode *root, int num) 
{
    int sum = 0; 
    /**
        这一步是啥意思了：就是把num向左移一位，空出来的位补上root->val
    **/
    num = (num << 1) + root->val;  
    if (root->left == NULL && root->right == NULL)
        return num; 
    if (root->left) 
        sum += _sumRootToLeaf(root->left, num);
    if (root->right) 
        sum += _sumRootToLeaf(root->right, num);
    return sum; 
}

int sumRootToLeaf(struct TreeNode *root) 
{   
    //这个的意思就是判断根节点是否存在，存在输出算出的结果，不存在输出0
    return root ? _sumRootToLeaf(root, 0) : 0;
}

__________________________________________________________________________________________________________________int num;
左右递归裸露函数

int num;
void _sumRootToLeaf(struct TreeNode *root, int sum)
{
    if(root == NULL)
        return;

    sum = (sum << 1) + root->val;
	
    //得先对sum做如上操作，才是属于这个函数的sum
    if(root->left == NULL && root->right == NULL)
        num += sum;

    _sumRootToLeaf(root->left, sum);
    _sumRootToLeaf(root->right, sum);

}


int sumRootToLeaf(struct TreeNode *root)
{
    int sum = 0;
    num = 0;
    _sumRootToLeaf(root, sum);
    return num;
}

==================================================================================================================================================


最深叶节点的最近公共祖先
给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。

回想一下：


	叶节点 是二叉树中没有子节点的节点
	树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
	如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。


 

示例 1：

要注意啊，返回值不是[1,2,3]这个数组，而是一个树根

输入：root = [1,2,3]
输出：[1,2,3]


示例 2：

输入：root = [1,2,3,4]
输出：[4]


示例 3：

输入：root = [1,2,3,4,5]
输出：[2,4,5]


//下面的dep就是此结点的深度
//下面的fa就是记录这个结点之下 左边等于右边的结点
struct info{
    int dep;
    struct TreeNode* fa;
 };

struct info getDeep(struct TreeNode* root)
{
    struct info res={0,NULL};
    if (!root) 
		return res;
    else
    {
        struct info l,r;
        l = getDeep(root->left);
        r = getDeep(root->right);
		
		/*
			我应该如何说呢，下面这些相当于后序遍历当中的回溯
			
		*/
        if (l.dep==r.dep)
        {
            res.dep = l.dep + 1; //因为要回溯，回溯的含义是这这个结点的深度
            res.fa = root;
        }
        else
        {
            if (l.dep < r.dep)
            {
                res.fa = r.fa;
                res.dep = r.dep+1;
            }
            else
            {
                res.fa = l.fa;
                res.dep = l.dep+1;
            }
        }
    }
    return res;
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
{
    struct info res = getDeep(root);
    return res.fa;
}





=====================================================================================================================

节点与其祖先之间的最大差值
给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

 


输入：[8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。

class Solution 
{
    int res = Integer.MIN_VALUE;  //这个形式的存在是很有意义的了，在全局中存在，且可以修改
	
	
    public int maxAncestorDiff(TreeNode root) 
	{
        if (root == null) return 0;
        //如果当前节点没有子节点，则直接返回
        helper(root, root.val, root.val);
        return res;
    }

    /**
     * 每条从根节点到叶子节点的路径中的最大值和最小值，并求出差值更新全局变量
     */
    private void helper(TreeNode node, int max, int min) 
	{
        if (node == null) 
			return;
        max = Math.max(node.val, max);
        min = Math.min(node.val, min);
        //到达叶子节点，求最大差值
		//因为要求必须是祖先和子孙之间的关系，所以必须在到达一条线的末尾进行判断，太巧妙了
        if (node.left == null && node.right == null) 
		{
            res = Math.max(res, Math.abs(max - min));
        }
        helper(node.left, max, min);
        helper(node.right, max, min);
    }
}


java

=====================================================================================================================
反转等价二叉树
我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。

只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。

编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1 && !root2)
        return true;

    if(root1 == NULL || root2 == NULL || root1->val != root2->val)
        return false;

    return ((flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right)) || (flipEquiv(root1->right,root2->left)&&flipEquiv(root1->left,root2->right))) ;

}

=====================================================================================================================
完全二叉树
给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）


每个顶点入队的层次遍历，只要用脑子算这道题的时候是一行一行算的，就用层序遍历，只要
用到层序遍历，就要用入队出队的方法

bool isCompleteTree(struct TreeNode* root) 
{
    struct TreeNode *Queue[2000];
    int front=0,back=0;
    if(root) 
		Queue[back++]=root;
		
    //层次遍历
    while(front<back)
    {
        int cnt=back-front;//一层的结点数目，上一层的结点数目
        for(int i=0;i<cnt;i++)
        {
            //让它下一层的结点入队列
			root=Queue[front++];
            if(root)
            {
                Queue[back++]=root->left;
                Queue[back++]=root->right;
            }
            else//结点为null时
            {
                while(front<back)//将这一层的节点数全部进行判断
                {
					if(Queue[front++]!=NULL)//出现不为null的情况即为false
                        return false; 
                }
            }

        }
    }
    return true;
}

——————————————————————————————————————————————————————————————————————————————————
不进行层次遍历的代码
天哪，这个太厉害了，自己画画图一目了然
之后如果要进行一层一层的遍历，就用这个方法，设置头尾指针，先加入根节点到队列中，然后加这个根节点的孩子到队列中，尾指针不断移动......
如果事物完全二叉树，一旦出现空，则它之后都是空，如果出现不是空的情况就是非完全二叉树

bool isCompleteTree(struct TreeNode* root) 
{
    struct TreeNode *Queue[200];
    int front=-1,rear=-1;
    Queue[++rear]=root;
    while(front<rear)
    {
        root=Queue[++front];//DeQueue出队列过程
        if(root!=NULL)
        {
            Queue[++rear]=root->left;
            Queue[++rear]=root->right;
        }
        else
        {
            while(front<rear)
            {
                if(Queue[++front]!=NULL)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

=====================================================================================================================

单值二叉树
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。

bool helper(struct TreeNode* root,int val)
{
	/*
		我的目的就是不断检查每个结点的值是否是val，这个过程可以用递归来实现
		如果不是，返回false
		而return helper(root->left, val) && helper(root->right, val);
		这个就可以达到目的
	*/
	if(root==NULL) 
	    return true;
		
    if(root->val!=val) 
	    return false;
		
    return helper(root->left,val) && helper(root->right,val);
}
bool isUnivalTree(struct TreeNode* root)
{
   
    if(root==NULL) 
		return true;
    return helper(root,root->val);
}

=====================================================================================================================
反转二叉树以匹配先序遍历
**
    voyage是给定的先序遍历的数组
    root是给定的一棵树
    看是否能通过交换这棵树中一个结点的左右儿子使这棵树的先序遍历和voyage相匹配
    并把这个结点输入到returnSize数组中
    
    如果可以，则返回翻转的所有节点的值的列表。你可以按任何顺序返回答案。
    如果不能，则返回列表 [-1]。

**/


int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int)*voyageSize);
    
    //保存树结点的栈，因为树是通过链表储存的，通过指针来找到下一个结点，所以每一个结点的类型是struct TreeNode *
    //栈的储存形式有数组也有链表，数组本质就是指针，链表刚才说也是通过指针寻找，所以栈的类型就是struct TreeNode **
    //如果是数组的话，就可以把栈想象成一排柜子，根据数组的下标可以找到这个柜子，根据柜子里面储存的地址又可以找到这个结点
    //下面的内存分配就可以看成是stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*voyageSize)
    //内存的分配就是分配柜子的大小，柜子总共的大小由所装物品的类型struct TreeNode *和所装物品的多少voyageSize决定
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*voyageSize);
    int i;
    int top = 0;
    stack[0] = root;
    int flipcunt = 0;
    
    for(i = 0;  i < voyageSize; i++)
    {
        if(top < 0 || stack[top]->val != voyage[i])   //如果top < 0意思就是说这个点的左右孩子都和voyage里面的不相等
                                                      //还有一种情况就是这个结点就不相等  这两种情况都是不符合题意的
													  //如果top < 0，就不可能有stack[top]->val这种形式的写法
        {
            ret[0] = -1;
            *returnSize = 1;
            return ret;
        }
        root = stack[top--];
     
        /*
            因为入栈是先进后出，应该是先看一个节点的左孩子，再看一个结点的右孩子的，因为栈刚好是相反，所以是先右后左
            这个下面的意思就是如果这个结点左右孩子的顺序和值刚好和voyage相同的情况
            同样注意呀：每个if之后都有一个continue，意思就是这两个只能执行一个
        */
        if(NULL != root->left && root->left->val == voyage[i+1])  //如果这个结点的左孩子不为空，且这个左孩子和yoyage中的相同
        {
            if(NULL != root->right)  //如果这个点的右孩子不为空
            {
                stack[++top] = root->right;  //把原来放根节点的地方放上右孩子
            }
            stack[++top] = root->left;  //栈的下一位放上左孩子
            continue; //注意这个
        }
        
        /*
            这个下面的意思就是如果这个结点左右孩子的顺序和值刚好和voyage相反的情况
            如果相反，这个结点就要入ret中了
        
        */
        
        if(NULL != root->right && root->right->val == voyage[i+1])  //如果这个结点的右孩子不为空，且这个右孩子和yoyage中的相同
        {
            if(NULL != root->left)   //如果这个点的左孩子不为空      
            {
                ret[flipcunt++] = root->val;  
                stack[++top] = root->left;
            }
            stack[++top] = root->right;
            continue; //注意这个
        }        
    }
	
    *returnSize = flipcunt;  //*returnSize是返回这个数组的大小
    return ret;

}


=====================================================================================================================
如何移动金币使得每个结点都分配有一个金币
/*
       示例1：输出2
                3         ans = 2      返回 0
              /   \
             0     0      0 返回 -1    0 返回 -1
          
       示例2：输出3
                0         ans = 3      返回 0
              /   \
             3     0      3 返回 2（它多出来两个金币，先移到父节点处，需要两步）   0 返回 -1（它需要一个金币，从父节点移到这里需要一步）  两步加一步 = 3
       
       示例3：输出2
                1         ans = 2      返回 0
              /   \
             0     2      0 返回 -1    0 返回 1                 
       
       示例4：输出4
                1         ans = 2      返回 0     ans = 4
              /   \
             0     0      0 返回 1    0 返回 -1   ans = 2
              \
               3          左边没有返回0   3返回2   
*/

int ans;

//以结点为单位，确定递归函数的含义
//结点需要的金币数
//L左边需要的金币数   R右边需要的金币数
int dfs(struct TreeNode* node)
{
    if(node == NULL)
        return 0;

    int L = dfs(node->left);  //左边需要的金币数
    int R = dfs(node->right); //右边需要的金币数
    int absL = L > 0 ? L : -L;
    int absR = R > 0 ? R : -R;

    ans += (absL + absR);          //所要移动的步数
    return node->val + L + R - 1;  

}


int distributeCoins(struct TreeNode* root) 
{
    ans = 0;
    dfs(root);
    return ans;
}

=====================================================================================================================
/*
    最大二叉树：
    最大树定义：一个树，其中每个节点的值都大于其子树中的任何其他值。
    给出最大树的根节点 root。
    
	把val值插入到这棵树中
	这个记录上一个结点好巧妙呀
	只要涉及二叉树的增删就得记录上一个结点

*/


struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
    struct TreeNode *dummy = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    dummy->val = -1;
    dummy->right = root;
    dummy->left = NULL;

    struct TreeNode *prev = dummy;
    struct TreeNode *curr = root;
    
    while(curr != NULL && curr->val > val)  //找到这个点应该添加的位置
    {
        prev = curr;  //这个是curr的上一个结点
        curr = curr->right;
    }
    
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = curr;
	node->right = NULL;
	
    prev->right = node;
    
    return dummy->right;
}

=====================================================================================================================
二叉树的堂兄弟结点
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。


//这两个结点的e父节点
struct TreeNode* x_f = NULL;
struct TreeNode* y_f = NULL;
bool isCousins(struct TreeNode* root, int x, int y)
{
    int x_depth = find_depth_x(NULL, root, x);
    int y_depth = find_depth_y(NULL, root, y);
    return (x_f != y_f && x_depth == y_depth);
}


/**
	一棵树可以分为三部分：父结点  左孩子   右孩子
	函数里面的操作是对父节点的操作  递归的操作是测试这个结点的左孩子和有孩子是否满足题意
	如果递归root->left 当这个为空时，说明左孩子不满足题意 
	如果递归root->right 当这个为空时，说明右孩子不满足题意
	最后返回-1时，表明左右孩子都不满足题意
**/
int find_depth_x(struct TreeNode* f_node, struct TreeNode* root, int node_val)
{
    /*
		记住，寻找和回溯的过程可以看成是线性的，何为线性的
		就是一条路走到黑，可以把这个二叉树分为多个这样的一条路，那么，如果说这条路没有找到
		就返回-1表示，如果ret = -1就表明不符合题意，只要一出现大于0的情况，就说明需要开始回溯了	
	*/
	if (root == NULL)  
		return -1;   //为什么不是0，0表示深度是0，而-1表示这个深度根本不存在
    if (root->val == node_val) 
	{
        x_f = f_node;
        return 0;
    }
    int ret;
	//找到这个点，只有一条路
    if ((ret = find_depth_x(root, root->left,  node_val)) >= 0) return ret+1;   //这个返回值是左右孩子返回给父节点的东西
    if ((ret = find_depth_x(root, root->right, node_val)) >= 0) return ret+1;
           
    return -1;
}
int find_depth_y(struct TreeNode* f_node, struct TreeNode* root, int node_val)
{
    if (root == NULL)  return -1;
    if (root->val == node_val) {
        y_f = f_node;
        return 0;
    }
    int ret;
    if ((ret = find_depth_y(root, root->left,  node_val)) >= 0) return ret+1;
    if ((ret = find_depth_y(root, root->right, node_val)) >= 0) return ret+1;       
    return -1;
}


=====================================================================================================================
/*
    二叉树的垂序遍历
    啥意思就是左右儿子的位置取开区间，看包括在这个范围内的结点有多少，把这个范围内的结点从上到下输出来
    例1：
             3
            / \
           9  20
              / \
             15  7

         输入：[3,9,20,null,null,15,7]
         输出：[[9],[3,15],[20],[7]]
         
    例2：
                1
              /   \
             /     \
            /       \
           2         3
          / \       / \
         4   5     6   7
         
         输入：[1,2,3,4,5,6,7]
         输出：[[4],[2],[1,5,6],[3],[7]]
    
    （1）使用结构体，表示节点的位置和坐标
    （2）采用多关键字排序，首先按照x坐标进行排序，然后按照y坐标进行排序，最后按照值大小进行排序
    （3）进行遍历
*/

typedef struct Node
{
    int val;
    int xPos;
    int yPos;
} Node;

int num = 0;

//排序函数
int cmp(const void *temp1, const void *temp2)
{
    Node *node1 = (Node *)temp1;
    Node *node2 = (Node *)temp2;
    if (node1->xPos == node2->xPos)      //如果这两个点横坐标相同
    {
        if (node1->yPos == node2->yPos)  //纵坐标相同
        {
            return node1->val - node2->val; //横坐标相同，纵坐标也相同，不就是一个点，返回0
        }
        return node2->yPos - node1->yPos;//纵坐标不相同，按纵坐标从小到大排序
    }
    return node1->xPos - node2->xPos;    //横坐标不相同，按横坐标从大到小排序
}

//初始化 node 和 num 的值
void dfs(struct TreeNode *root, int x, int y, Node *node)
{
    if (root == NULL)
    {
        return;
    }
    
    //num是全局变量，初值为0
    node[num].val = root->val;
    node[num].xPos = x;
    node[num].yPos = y;
    num++;
    dfs(root->left, x - 1, y - 1, node);
    dfs(root->right, x + 1, y - 1, node);
}
int **verticalTraversal(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int tempXPos = 0;
    int i = 0;
    int m = 0;
    int colSize = 0;
    int cur = 0;
    int *columnSizes=NULL;
    *returnSize = 0;
    int **result = NULL;
    
    Node *node = (Node *)malloc(sizeof(Node) * 1000);  //储存横纵坐标的
    num = 0;
    dfs(root, 0, 0, node);
    
    //这是一个排序函数
    /*
        int (*cmp)(const void *,const void *);
        qsort(*s, n, sizeof(s[0]), cmp);

        其中第一个参数s是一个地址，即参与排序的首地址；
        n是需要排序的数量；
        sizeof(s[0])则是每一个元素占用的空间大小；
        指向函数的指针，用于确定排序的顺序
    
    */
    //排好序之后 num数组里的值按从左到右从上到下的顺序排好
    qsort(node, num, sizeof(Node), cmp);
    
    tempXPos = node[0].xPos;
    result = (int **)malloc(sizeof(int *) * num);
    columnSizes = (int *)malloc(sizeof(int)*num);
    
    for (i = 0; i < num; i++)
    {
        if (tempXPos != node[i].xPos)  //i和它前面的数字的横坐标不相同
        {
            columnSizes[*returnSize] = i - cur;   //储存每一行有多少个数字
            result[*returnSize] = (int *)malloc(sizeof(int) * (i - cur));  //应该给这一行分配多少内存  i - cur是这一行元素的个数
            
            m = 0;  //m是在第几列
            for (int j = cur; j < i; j++)  //完成每行数字的输入
            {
                result[*returnSize][m] = node[j].val;
                m++;
            }
            *returnSize = *returnSize + 1;  //这个是在第几行
            cur = i;  //cur是每个小组的第一个数字下标  也就是第一个和它右边不相同的横坐标的数字的下标
            tempXPos = node[i].xPos;  //重新更换下标值
        }
    }
    //如果横坐标的值是12333333  上面的一堆只是如果横坐标有变化，才可以完成输出，所以最后的3并没有输出来
    columnSizes[*returnSize] = num - cur;   //i值和num的值是相同的 
    result[*returnSize] = (int *)malloc(sizeof(int) * (num - cur));
    m = 0;
    for (int j = cur; j < i; j++)   
    {
        result[*returnSize][m] = node[j].val;
        m++;
    }
    *returnSize = *returnSize + 1;  //行数是从0开始的，最终的行数是从1开始的，所以最后的行数得加1
    *returnColumnSizes=columnSizes; //储存每一行有多少个数字
    free(node);  //刚才按从左到右从上到下排好序的数组
    return result;
}

=====================================================================================================================
二叉树剪枝
https://leetcode-cn.com/problems/binary-tree-pruning/
给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)


void ss(struct TreeNode* root)
{
    /**
        恍然大悟：这就是小橘子的魅力
        首先：第一点 通过下面这两步可以找到所有的结点
             第二点  如果是在下面这两步上面所写意思就是从上往下   下面所写就是从上往下
        ss(root->right);  这一步是找到所有结点的右节点
        ss(root->left);   这一步是找到所有节点的左节点

        观察这道题目  应该选择从下往上  所以递归写上面  如果找到一个结点它本身为0，且没有左右孩子，就删除，如果要删除这个结点，就得取地址，如果不
        取地址，就得根据它的父节点，将他父节点的孩子设为NULL的形式将这个结点删除，所以才有下面的形式
    **/
    if(!root)
        return;
    
    ss(root->right);

    if(root->right && root->right->val == 0 && !root->right->left && !root->right->right)
        root->right=NULL;

    ss(root->left);

    if(root->left && root->left->val == 0 && !root->left->left && !root->left->right)
        root->left=NULL;
}
struct TreeNode* pruneTree(struct TreeNode* root)
{
    /*
        我懂了：这里为什么不传地址，因为如果传地址，目的就是为了改变变量所包含的内容，也就是为了改变root的指向
        而这里并不需要改变root的指向，需要改变的是root所包含左孩子或右孩子的指向，可以直接改
    */
    ss(root);
    return root;
}


=====================================================================================================================
二叉树中所有距离为k的结点

给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。
返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。
 //找到这个结点的父亲结点
void getParNode(struct TreeNode* curNode, struct TreeNode* targetNode, struct TreeNode** pareNode) 
{
    if (curNode == NULL) 
    {
        return;
    }
    if (curNode->left == targetNode || curNode->right == targetNode) 
    {
        *pareNode = curNode;
        return;
    }
    getParNode(curNode->left, targetNode, pareNode);
    getParNode(curNode->right, targetNode, pareNode);
}



//找到这个结点下面的目标结点
//curNode是目标结点  distCnt是走到这个结点需要的步数  returnSize是数组元素的个数  valK是可以走的步数  distRst是保存最终结果的数组
void preOrderCnt(struct TreeNode* curNode, int* distCnt, int* returnSize, int valK, int* distRst) 
{
    int tempDist = 0;
    if (curNode == NULL) 
    {
        return;
    }

    (*distCnt)++;      //先递增，因为传到下面的函数中就是distCnt
    tempDist = *distCnt;  

    if (*distCnt == (valK + 1))  //因为刚才递增过，所以是valK + 1
    {
        if (*returnSize < 500) 
        {
            distRst[*returnSize] = curNode->val;  //把这个结点的值输入到这个数组中
            *returnSize = *returnSize + 1;        //数组的长度递增1
        }
    }
    //因为传的是指针，会改变distCnt的值，所以要记录下来distCnt之前的值
    preOrderCnt(curNode->left, distCnt, returnSize, valK, distRst);
    *distCnt = tempDist;
    preOrderCnt(curNode->right, distCnt, returnSize, valK, distRst);
}

int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize) 
{
    struct TreeNode* pareNode = NULL;
    struct TreeNode* tempTarget = NULL;
    int distCnt = 0;
    static int distRst[500] = {0};
    int pareNum = 0;

    *returnSize = 0;

    getParNode(root, target, &pareNode);  //找到目标节点的父节点pareNode，因为要改变pareNode的指向，所以要取地址
    tempTarget = target;

    //找到这个结点下面的目标节点
	preOrderCnt(target, &distCnt, returnSize, K, distRst);
    distCnt = 0;

    while (pareNode != NULL)  //目标节点的父节点pareNode，如果父节点是空，就代表是根结点
    {
        pareNum++;     //记录走的步数，因为pareNode是它的e父节点，从target走到pareNode需要一步，所以在之前需要递增

        //这个就是找父节点，父节点的父节点。。。。。，直到找到最后，把最后的输入到disRst中，break结束
        if (pareNum == K) 
        {
            //returnSize指向的是第一个可以填充数据的位置
            distRst[*returnSize] = pareNode->val;
            (*returnSize)++;
            break;
        } 


        //说的简单一点，就是处理需要拐一个弯再走一步才可以到达的，先从这个结点到达它的父节点，再从这个父结点到它另一个儿子
		//为啥不和下面写的合并，因为下面是(K - pareNum - 1) > 0   这里输出的是right的
        else if (pareNum == K - 1) 
        {
            if (pareNode->left == tempTarget && pareNode->right != NULL) 
            {
                distRst[*returnSize] = pareNode->right->val;
                (*returnSize)++;
            } 
            else if (pareNode->right == tempTarget && pareNode->left != NULL) 
            {
                distRst[*returnSize] = pareNode->left->val;
                (*returnSize)++;
            }
            //break;
        }

        //记住pareNode是它的父结点
        //拐一步输出它兄弟结果
        if (pareNode->left == tempTarget && (K - pareNum - 1) > 0)  //这个减一的目的就是k减去pareNode->right的一步，意思就是输出right以下的
        {
            //记得之前disCnt又被设为0
            preOrderCnt(pareNode->right, &distCnt, returnSize, (K - pareNum - 1), distRst);//第四个参数就是从这个结点开始，需要走的步数
            distCnt = 0;
        } 
        else if (pareNode->right == tempTarget && (K - pareNum - 1) > 0) 
        {
            preOrderCnt(pareNode->left, &distCnt, returnSize, (K - pareNum - 1), distRst);
            distCnt = 0;
        }
        
        //tempTarget储存原来父亲的结点
        tempTarget = pareNode;
        pareNode = NULL;   //因为之后要修改它，所以先让它指向空
        
        //pareNode储存tempTarget父亲的结点
        getParNode(root, tempTarget, &pareNode);
    }

    return distRst;
}

=====================================================================================================================
具有最深结点的最小子树——这是一个二叉树
就是找到最深的结点，输出它的父亲
/*
    下面这种写法是如果左子树等于右子树，则是最大深度
    我的想法记录下每一条路线的长度，如果有大于，则更新这个路线
    同时记录每一个结点的父节点，更新路线的同时更新这个父节点
*/


操操操  只要涉及左右儿子和父结点的就用左右非裸露函数呀
int max(int a, int b)
{
    return a > b ? a : b;
}

int depth(struct TreeNode *node)
{
    if(node == NULL ) 
        return 0;
    return max(depth(node->left),depth(node->right)) + 1;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
{
         int diff = depth(root->left) - depth(root->right);
		 
         if(diff==0) 
            return root;
			
         else if(diff > 0)   //说明左边的深度大于右边的深度
         {
             return subtreeWithAllDeepest(root->left);
         }
         else               //说明左边的深度小于右边的e深度
         {
            return subtreeWithAllDeepest(root->right);
         }
}

————————————————————————————————————————————————————————————————————————————————————————————
我写的，也不知哪里错

struct TreeNode *father;
int deepest;

void GetIt(struct TreeNode *root, int deep, struct TreeNode *father)
{
    
    if(root == NULL)
        return ;
    
    if(root->left == NULL && root->right == NULL)
    {
        if(deep > deepest)
        {
            deepest = deep;
            &father = &root;
        }
    }
    GetIt(root->left, deep + 1, root);
    GetIt(root->right, deep + 1, root);
}



struct TreeNode *subtreeWithAllDeepest(struct TreeNode *root)
{
    TreeNode *father = NULL;
    int deepest = 0;
    
    GetIt(root, 0, NULL);
    
    return father;
}


=====================================================================================================================
叶子相似的树
判断两个树的从左到右的叶子是否相同
/*思路，先把两个root的叶子结点分别存在两个数组里面，然后再比较这两个数组的元素是否一致*/
void ordertraversal(struct TreeNode* root, int* leaf, int* count)
{
    if(root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            leaf[*count] = root->val;
            (*count)++;
        }
        ordertraversal(root->left, leaf, count); //这里的count就不用&count，因为这里的count相当于指针了
        ordertraversal(root->right, leaf, count);
    } 
}
    
  
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) 
{
    int leaf1[100] = {0}, leaf2[100] = {0}, i = 0, j = 0, count1 = 0, count2 = 0;
    ordertraversal(root1, leaf1, &count1);  //这种一般都要传地址，count的地址，传值就会出错
    ordertraversal(root2, leaf2, &count2); 
    while(i < count1 && j < count2 && count1 == count2 && leaf1[i++] == leaf2[j++]);

    //因为最后无论两个相不相等，i和j都要递增  所以要判断(leaf1[--i] != leaf2[--j])
	//否则如果一棵树是1  另一棵树是2就不行
    if((i < count1 || j < count2) || (leaf1[--i] != leaf2[--j])) 
        return false;
    else 
        return true;
}

=====================================================================================================================
根据前序和后序遍历构造二叉树
标准左右非裸露函数
struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize)
{
    if (pre == NULL || post == NULL || preSize <= 0)  //preSize和postSize是相等的
    {
        return NULL;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int i;
    root->val = pre[0];
    if (preSize == 1) 
    {
        root->left  = NULL;
        root->right = NULL;
    } 
    else 
    {
        for (i = 0; i < preSize - 1; i++) 
        {
            //找到中序遍历中这个点的位置
			if (post[i] == pre[1]) 
            {
                break;
            }
        }

        /*
                        1
                     /    \
                    2     5
                  /  \  /  \
                3    6 4   9
                         /  \
                        10  12

            中间竖杠的目的是把它分为左子树和右子树
            前序遍历： 1 2 3 6 | 5 4 9 10 12      1右边的2是1的左孩子
            后序遍历：3 6 2 | 4 10 12 9 5 1       1左边的5是1的右孩子
            i的意思是2在后序遍历中的位置，就是2
            pre + 1的意思是左子树根节点的位置  i + 1的意思是左子树有3个结点
            pre + i + 2的意思是右子树根节点的位置  preSize - i - 2的意思是右子树有5个结点

        */
        root->left  = constructFromPrePost(pre + 1, i + 1, post, i + 1);
        root->right = constructFromPrePost(pre + i + 2, preSize - i - 2, post + i + 1, preSize - i - 2);
    }
    return root;
}


=====================================================================================================================
所有可能的满二叉树
给出结点的个数，输出所有可能的满二叉树
排列组合
struct TreeNode** allPossibleFBT(int N, int* returnSize)
{
    int cnt = 0, cntL, cntR, sum = 0;
    struct TreeNode **forest = NULL, **newForest = NULL, **lForest, **rForest;
    if (N == 1) 
    {
        forest = calloc(1, sizeof(struct TreeNode*));
        forest[0] = calloc(1, sizeof(struct TreeNode));
        *returnSize = 1;
        return forest;
    }
    if (N%2 != 0) //结点的个数是奇数
    {
        for (int i = 1; i < N-1; i += 2) //因为是满二叉树，所以是i += 2;
        {
            //下面这步是实现左右子树结点的分配
            //lForest是左子树所有可能情况的二维数组    rForest是右子树所有可能情况的二维数组  
            //cntL是左子树可能情况的个数     cntL是右子树可能情况的个数 
            lForest = allPossibleFBT(i, &cntL);   //假设左边结点的个数是i
            rForest = allPossibleFBT(N - 1 - i, &cntR);  //右边结点的个数是N - 1 - i
            sum += cntL * cntR;   //排列组合  目的是知道分配多少内存

            newForest = realloc(forest, sum*sizeof(struct TreeNode*));

            if (newForest == NULL)    //如果动态内存分配失败
            {
                free(forest);
                return NULL;
            }
            
            //forest是输进来这个结点的二维数组
            forest = newForest;
            for (int j = 0; j < cntL; j++) 
            {
                for (int k = 0; k < cntR; k++) 
                {
                    //因为就是只存一个struct TreeNode的内存
                    forest[cnt] = calloc(1, sizeof(struct TreeNode));
                    forest[cnt]->left = lForest[j];
                    forest[cnt]->right = rForest[k];
                    cnt++;
                }
            }
        }
    }
    //返回二维数组的行数
    *returnSize = cnt;
    return forest;
}

=====================================================================================================================
//递增顺序查找树
/*
给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
*/

//呜呜呜呜呜  它说我这个超出时间限制
struct TreeNode* _increasingBST(struct TreeNode* root)
{
    if((root->left == NULL && root->right == NULL) || (root->left == NULL))
    {
        return root;
    }

    if(root->right == NULL)
    {
        root->left->right = root;
        return root->left;
    }

    
    struct TreeNode* tmp_left = _increasingBST(root->left);
    struct TreeNode* tmp_right = _increasingBST(root->right);
    struct TreeNode* tmp_left1 = tmp_left;
	
    while(tmp_left1->right != NULL)
        tmp_left1 = tmp_left1->right;
    tmp_left1->right = root;

    return tmp_left;
    
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    return _increasingBST(root);
}

——————————————————————————————————————————————————————————————————————————————————
/*
    
	中序遍历
	它的脑子是用金子做的吗
    我来简述以下它的意思
    下面这个函数的第二个参数是中序遍历root结点的下一个结点
    这个函数的意思就是先把root结点的左边弄成线线的，弄成线线的同时把最底下的右边弄成root，记得是指针，现在root就变成了它左边线线的最底端
    所以要把root的左边设置成NULL
    现在要处理root的右边了，记住pre是中序遍历它的下一个点，也就是root的父节点，如果右边是空的，就设成pre，如果右边不是空的，就让右边变成线线的
 */
struct TreeNode* _increasingBST(struct TreeNode* root, struct TreeNode* pre)
{
    if(!root)
    {
        return pre;
    }
    
    struct TreeNode* tmp = _increasingBST(root->left, root);
    root->left = NULL;
    if(root->right)
    {
        root->right = _increasingBST(root->right, pre);
    }
    else
    {
        root->right = pre;
    }
    return tmp;
}

struct TreeNode* increasingBST(struct TreeNode* root) 
{
    return _increasingBST(root, NULL);
}


——————————————————————————————————————————————————————————————————————————————————
=====================================================================================================================
非裸露函数 + 递归法 + 结点判断

//记住它给的是搜索二叉树，在L 和 R范围内的和
int rangeSumBST(struct TreeNode* root, int L, int R)
{
        //天哪，我就是一个笨蛋，我咋地就没想见了，root = NULL不要想那么多，就假设右一个结点，这个结点是NULL，应该返回啥就是啥
		if(root == NULL)
        {
            return 0;
        }
        if(root->val > R)
        {
            return rangeSumBST(root->left, L, R);
        } 
        else if(root->val < L)
        {
            return rangeSumBST(root->right, L, R);
        } 
        else 
        {
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
		
}


=====================================================================================================================
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    
	//咱们来用逻辑理解一下，给了一个结点，首先要判断这个结点是不是空，接着再判断这个结点里的数据和给的数据相不相同，如果不相同，检查它的两个子树每一个点
	if(root == NULL)
        return NULL;
    if(root->val == val)
        return root;
    else if(root->val > val)
        return searchBST(root->left, val);  //返回它左子树查找的结果
    else
        return searchBST(root->right, val); //返回它右子树查找的结果
}

=====================================================================================================================
二叉搜索树结点的最小距离
//搜索二叉树中中序遍历的结果就是从小到大的顺序
int min;
struct TreeNode* pre;

//这个是main函数
int minDiffInBST(struct TreeNode* root)
{
    min = 0x3f3f3f3f;
    pre = NULL;
    dfs(root);
    return min;
}

int dfs(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    dfs(root->left);
    if (pre != NULL) 
    {
        if (min > (root->val - pre->val)) 
        {
            min = root->val - pre->val;
        }
    }
    pre = root;
    dfs(root->right);
    return 0;
}

=====================================================================================================================
二叉树的最大宽度
就是把这个树画成满二叉树时，这每一行的最大宽度
/*给所有的节点进行编号（从1开始，空节点也编号），递归，若某个节点的编号为n,则左子节点编号为2n，
右子节点为2n+1，将该层起始第一个非空节点的编号保存下来记为j, 
则该层编号为k的节点，二者间的宽度为k-j+1，该层所有节点的宽度最大值即为该层宽度*/


#define MAX_INT 2147483648

void getTreeDepath(struct TreeNode* node, unsigned int iDepath, unsigned int *maxDepath)
{
    if(NULL == node) 
        return;
    (*maxDepath) = (*maxDepath) > iDepath ? (*maxDepath):iDepath;

    //我忽然发现一个极其聪明的事情，如果在左右递归之前写的就是前序遍历，意思也就是测试结点的顺序就是前序遍历的结果
    //中序遍历和后序遍历同理
    getTreeDepath(node->left, iDepath+1, maxDepath);
    getTreeDepath(node->right, iDepath+1, maxDepath);
}

void traversalTree(struct TreeNode* node, int *maxWidth, int depath, int index, int a[])
{
    if(NULL == node) 
        return;
    
    //因为是前序遍历，所以在depath还没有存值的时候让它保存的肯定是每一行的第一个
    if(a[depath] == 0)
    {
        //这个数组的目的就是记录每一行第一个结点的下标
        a[depath] = index;
    }
    
    /*
            1
          /  \
         2   3     3 - 2 = 1    1 + 1 = 2
    */
    int width = index - a[depath] + 1;
    
    //f更新最大宽度
    *maxWidth = (*maxWidth) > width ? (*maxWidth):width;


    //这个的目的是控制树的最大范围，如果它是有左孩子的，说明它底下还有一层，这一层最大是Max_INT,但它比这个还大m，就不符合题意返回
    if(NULL != node->left && index > (MAX_INT/2)) 
        return;
    if(NULL != node->right && index > ((MAX_INT)/2)) 
        return;

    traversalTree(node->left, maxWidth, depath+1, 2*index, a);
    traversalTree(node->right, maxWidth, depath+1, 2*index + 1, a);
}

int widthOfBinaryTree(struct TreeNode* root)
{
    int maxWidth = 0;
    int depath = 0;
    int index = 1;
    int *a = NULL;
    unsigned int maxDepath = 0; //深度是从0开始

    //下面这个函数完成之后就知道了maxDepath，知道maxdepth的目的主要是为了分配内存
    getTreeDepath(root, depath, &maxDepath);

    
    //最大深度是从0开始的
	a = (int *)malloc((maxDepath+1)*sizeof(int));

    if(NULL == a) 
        return 0;

    //将a数组中(maxDepath+1)*sizeof(int)大小的内存全部初始化为0，就是数组的初始值都是0
    memset(a, 0, (maxDepath+1)*sizeof(int));

    traversalTree(root, &maxWidth, depath, index, a);

    return maxWidth;
}

=====================================================================================================================
修剪搜索二叉树
把不在L R范围内的结点修剪掉
//记住：这是一棵搜索二叉树，可以利用搜索二叉树的性质
/*
    搜索二叉树分为三个部分，分别是父结点，左孩子，右孩子
    这个函数的目的就是去掉不在范围内的
    首先判断父结点在不在范围内f，如果父结点比范围小，只有它右边才可能在范围里，返回右边，左边同理

*/

又是典型的左右非裸露函数
struct TreeNode* trimBST(struct TreeNode* root, int L, int R)
{
    //要处理好两个过程，一个是结点向下遍历的过程，也就是两个递归，前序遍历的过程
	//一个是递归结果返回，也就是后序遍历的过程
	if(root == NULL)
        return NULL;
		
    if(root->val < L)
        return trimBST(root->right, L, R);
		
    else if(root->val > R)
        return trimBST(root->left, L, R);
		
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}

=====================================================================================================================
二叉树中第二小的结点
且父结点的值小于等于左右儿子的值

/*
	不说啦，老泪纵横，我终于懂了递归了、
	                   1
                     /   \
                    2     5
                  /  \  /  \
                3    6 4    9
                           / \
                          10 12

            中间竖杠的目的是把它分为左子树和右子树
            前序遍历：1 2 3 6 5  4  9  10 12      
            后序遍历：3 6 2 4 10 12 9  5  1			
			中序遍历：3 2 6 1 4  5  10 9 12
	
	咱们先把递归分成三部分：前序遍历的样子  中序遍历的样子  后序遍历的样子
	遍历的结果只是代表结点遍历的顺序，跟val的值无关，返回值的意思就是从这个结点返回到遍历的上一个结点中
	前序遍历只是测试顺序  后序遍历是定值返回顺序，也就体现一种从底层到上头的思想将底层的每一个都处理了
	返回到最高统治者的就是结果	
*/

int findSecondMinimumValue(struct TreeNode* root)
{
    return myfun(root, root->val);
}

int myfun(struct TreeNode* root, int val)
{
    //其实下面这个判断是否为空就包含两层含义，一层是这个根节点就为空，返回-1表示出错
	//如果是在遍历过程中，表示这一支没找到
	//这一支代表以一个结点开始，到它的左孩子为空或右孩子为空  或  左右孩子为空 时结束
	//这时候需要返回值，代表的意思就是这一支寻找的结果，如果一直都没有找到，就会一直返回=1
	//如果期间找到了，就会返回一个特定的值
	
	//当左边的左孩子为空时将要返回上一个结点，这个结点又要寻找它的右孩子
	//这时后序遍历就开始出现，所以先开始测试的两个值就是结点3和结点6，也就是l的值就是结点3测试的结果，r就是结点6测试的结果
	//这两个结点完成比较的结果之后返回给2，则下一个测试的l和r就是2和4，直到返回到1结束


    //所以俺的得出一个结论：前序遍历的目的就是给left一个值，相当于一个	
	if(root == NULL)
        return -1;  //表示错误
		
	//只要有一个比val大，那它肯定是第一个大于val的数
	
	///写在非裸露函数前面的是条件满足什么条件，返回什么值
    if(root->val > val)
        return root->val;
    
    /*
        卧槽，我滴娘嘞，我终于知道了，原来递归这么难
        在这两个递归前面的是先序遍历，先序遍历的目的就是为了找出这两个子树中
        比父结点大的

    */
    int l = myfun(root->left, val);
    int r = myfun(root->right, val);
    //这个是后序遍历，后序遍历的目的就是返回第二小的结点
    if(l > val && r > val)
    {
        return l > r ? r : l;
    }
    //如果没有找到是返回-1的，所以要取两个里面较大的
	//就是结点的左边全是1，右边有比结点大的
    return l > r ? l : r;
}






=====================================================================================================================

亢余连接
在本问题中, 树指的是一个连通且无环的无向图。

输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。

返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

示例 1：

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3


示例 2：

输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
解释: 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3


注意:


	输入的二维数组大小在 3 到 1000。
	二维数组中的整数在1到N之间，其中N是输入数组的大小。

#define MAXNUM 10001
int UF[MAXNUM];
int UFSize[MAXNUM];

void initialUF(int *UF, int num) 
{
    int i = 0;
    for (i = 0; i < MAXNUM; i++) 
    {
        UF[i] = i;
        UFSize[i] = 0;
    }
}

int root(int num) 
{
    while(UF[num] != num) 
    {
        num = UF[num];
    }
    return num;
}

int Find(int a, int b) 
{
    return root(a) == root (b);
}

void Union(int a, int b) 
{   
    /*
        我大概懂了：
        我当时困扰的点就是如何表示树的双向问题，其实大可不必关心双向，直接把它改成单向
             1
            / \
          2    3

        接下来的问题就是单向是2指向1还是1指向2，是3指向1还是1指向3  看图来说是1指向2，1指向3
        所以UFSize的意思就是这个结点的儿子个数，让儿子个数多的指向儿子个数少的，同时儿子把它的UF设置成根节点
        只要有环，根节点就会重合，输出这个点 
    
    */
    a = root(a);
    b = root(b);
    if (UFSize[a] < UFSize[b]) 
    {
        UF[a] = b;
        UFSize[b] += UFSize[a];
    } 
    else 
    {
        UF[b] = a;
        UFSize[a] += UFSize[b];
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int i = 0;

    //返回最后数组的大小是2
    * returnSize = 2;
    //因为最后返回数组的大小是2，所以分配的大小也是2
    int *ret = malloc(sizeof(int) * 2);

    //初始化UF[i] = i;   UFSize[i] = 0;
    initialUF(UF, MAXNUM);
    int a = 0;
    int b = 0;

    //edgesSize是数组的行数
    for (i = 0; i < edgesSize; i++) 
    {
        //a分别是每一行第一个和第二个数字
        a = edges[i][0];
        b = edges[i][1];

        if (!Find(a, b)) //如果这两个的根不是一个根
        {
            Union(a, b);
        } 
        else 
        {
            ret[0] = a;
            ret[1] = b;
            return ret;
        }
    }
    return ret;
}

=====================================================================================================================
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5


输出:

2


示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5


输出:

2

int ans;

int longestUnivaluePath(struct TreeNode* root) 
{
        ans = 0;
        arrowLength(root);
        return ans;
}
int arrowLength(struct TreeNode* node) 
{
        if (node == NULL) 
            return 0;
			
        int left = arrowLength(node->left);
        int right = arrowLength(node->right);
		
        int arrowLeft = 0, arrowRight = 0;
        /*
                 5
                / \
               4   5

            left的意思是左边的路径长 ， + 1的意思是加上5-4
			我懂啦，像这种写在左右非裸露递归下面的是从下头往上推，就是已知右边和左边
			如何推出root，而这个root又作为上一个的left或right
			
			arrowLeft 和 arrowRight 是临时变量，用来表示回到root时连续路径的长度
			如果不连续为0，连续为  left / right + 1
        */

        if (node->left != NULL && node->left->val == node->val) 
            arrowLeft += left + 1;
        
        if (node->right != NULL && node->right->val == node->val) 
        {
            arrowRight += right + 1;
        }
		
		//更新ans的值
        ans = ans > (arrowLeft + arrowRight) ? ans : (arrowLeft + arrowRight);
		
		//记住这个是求左边或者右边的最大值，因为路径肯定是一条线，只能取左边或者右边
        return arrowLeft > arrowRight ? arrowLeft : arrowRight;
}






————————————————————————————————————————————————————————————————————————————————————



=====================================================================================================================
另一个树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2


给定的树 t：

   4 
  / \
 1   2


返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

bool a_gain(struct TreeNode* s,struct TreeNode* t) //判同
{
    if(s == NULL && t == NULL) 
        return true;
		
    if(s == NULL || t == NULL) 
        return false;
		
    if(s->val != t->val) 
        return false;
		
    return a_gain(s->left,t->left) && a_gain(s->right,t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if((s == NULL && t != NULL) || (s != NULL && t == NULL)) 
        return false;
	
    //这个的意思就是有可能它符合题意  有可能它的儿子符合题意  如果只写a_gain表明只有他的根节点符合题意
    return a_gain(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);  //判同 判左 判右
}



————————————————————————————————————————————————————————————————————————————————————
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t == NULL)
        return true;
    if(s == NULL || t == NULL)
        return false;

	return ( (s->val == t->val) && isSubtree(s->left, t->left) && isSubtree(s->right, t->right) ) || (isSubtree(s->left, t) || isSubtree(s->right, t));
    
   
}

===========================================================================================================================
根据二叉树创建字符串
就是括号形式的二叉树
void travel(struct TreeNode* node, char *val)
{
    char buf[100];
    
    if(!node) 
        return;

    //咱先不用去深究sprinf和strcat是啥意思，咱只要知道他是把val输进去就行了
    sprintf(buf, "%d", node->val);
    strcat(val, buf);
	
    //process left child and right child
    if(node->left || node->right)
    {
        //如果左边存在或左边不存在都是下面这个样子的
        strcat(val, "(");
        travel(node->left, val);
        strcat(val, ")");

        //right() is optional
        if(node->right)
		{
            strcat(val, "(");
            travel(node->right, val);
            strcat(val, ")");
        }
    }
}
char * tree2str(struct TreeNode* t)
{
    char *result = (char*)malloc(32768);
    result[0] = 0;

    travel(t, result);
    
    return result;
}

===========================================================================================================================
合并二叉树
把两个二叉树重叠，重合部分相加
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
    
	if(t1 == NULL)
        return t2;
    if(t2 == NULL)
        return t1;

    t1->val += t2->val;
    
    if(t1->left != NULL && t2->left != NULL)
    {
        mergeTrees(t1->left, t2->left);
    }
    else if(t1->left == NULL && t2->left != NULL)
    {
        t1->left = t2->left;
    }

    if(t1->right != NULL && t2->right != NULL)
    {
        mergeTrees(t1->right, t2->right);
    }
    else if(t1->right == NULL && t2->right != NULL)
    {
        t1->right = t2->right;
    }

    return t1;

}

===========================================================================================================================
在二叉树中添加一行
示例 1:

输入: 
二叉树如下所示:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

输出: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   



示例 2:

输入: 
二叉树如下所示:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

输出: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1

void add(struct TreeNode* root, int v, int h,int d)
{
    if(root == NULL)
        return ;
    if(h + 1 == d)
    {
        struct TreeNode* l = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        struct TreeNode* r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        l->val = v;
        l->left = root->left;
        l->right = NULL;
        r->val = v;
        r->left = NULL;
        r->right = root->right;
        root->left = l;
        root->right = r;
    }
    add(root->left,v,h+1,d);
    add(root->right,v,h+1,d);
}
struct TreeNode* addOneRow(struct TreeNode* root, int v, int d) //v是添加的数字，d是添加的行数
{
    //t如果要添加的数字就在第一行，把它左边设置成根节点，右边设置为空，直接返回a
    if(d == 1)
    {
        struct TreeNode* a = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        a->val = v;
        a->left = root;
        a->right = NULL;
        return a;
    }
    add(root,v,1,d);
    return root;
}

===========================================================================================================================
二叉树的层平均值
#define MAXSIZE 1024 
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void dfs(struct TreeNode* root, double *res, int *cnt, int idx, int *returnSize) 
{
    if (root == NULL) 
        return;
    
    res[idx] += (double)root->val;
    cnt[idx]++;
	
	//这里的index = 0主要的目的就是为了和数组匹配，但是returnSize是个数得加1
    (*returnSize) = MAX(*returnSize, idx + 1);  //因为不但d要递归，还要回溯，回溯的时候returnsize就会变
    dfs(root->left, res, cnt, idx + 1, returnSize);
    dfs(root->right, res, cnt, idx + 1, returnSize);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    if (root == NULL) 
    {
        *returnSize = 0;
        return NULL;   //记着，假如这个二叉树是空的话，返回的类型是double*，所以是NULL
    }

    double *res = (double*)malloc(sizeof(double) * MAXSIZE);
    int *cnt = (int*)malloc(sizeof(int) * MAXSIZE);

    int i;
    for (i = 0; i < MAXSIZE; i++) 
    {
        res[i] = 0.0;
        cnt[i] = 0;
    }
    
    *returnSize = 0;
    dfs(root, res, cnt, 0, returnSize);
    for (i = 0; i < (*returnSize); i++) 
    {
        res[i] /= cnt[i];
    }
    free(cnt);
    return res;
}

===========================================================================================================================
最大二叉树


给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：


	二叉树的根是数组中的最大元素。
	左子树是通过数组中最大值左边部分构造出的最大二叉树。
	右子树是通过数组中最大值右边部分构造出的最大二叉树。


通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1



struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    //当这个数组里没有数字的时候，返回空
    if(numsSize <= 0) 
    {
        return NULL;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    //初始化指针数组就用这种方法
    memset(root, 0, sizeof(sizeof(struct TreeNode)));
    
    int max = 0;  //最大值的下标
    //寻找出最大值的下标
    for(int i=1; i<numsSize; i++) 
    {
        if(nums[max] < nums[i]) 
        {
            max = i;
        }
    }
    
    root->val = nums[max];
    root->left = constructMaximumBinaryTree(nums, max);
    root->right = constructMaximumBinaryTree(nums+max+1, numsSize-max-1);
    return root;    
}


===========================================================================================================================
输出二叉树
输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]


示例 2:

输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]


示例 3:

输入:
      1
     / \
    2   5
   / 
  3 
 / 
4 
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]

/*
    C语言版本，求树的高度m，矩阵的宽度n=2^（m - 1）-1； 创建初始化字符串，利用分制思想进行字符串处理
    这里的m是从1开始的
*/
int depthOfTree(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
	
    int left  = depthOfTree(root->left);
    int right = depthOfTree(root->right);
	
    return left > right ? left + 1 : right + 1;
}

void dfs(struct TreeNode* root, char ***res, int idx, int start, int end) 
{
    if (root == NULL || start > end) 
    {
        return;
    }
    int mid = start + (end - start) / 2;
    sprintf(res[idx][mid], "%d", root->val);
    dfs(root->left, res, idx + 1, start, mid - 1);
    dfs(root->right, res, idx + 1, mid + 1, end);
}

char *** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    //当结点h是空的情况
    if (root == NULL) 
    {
        *returnSize = 0;
        return NULL;
    }

    //m是树的深度，是从1开始数的
    int m = depthOfTree(root);

    //这个是树的宽度，其实本来的算法公式是2^m-1
    //注意这个移动2 << 1, 就是4，所以本来的m变成了m - 1
    int n = (2 << (m - 1)) - 1;  
    *returnSize = m;

    //我实在是不理解她内存是如何分配的
    char ***res = (char***)malloc(sizeof(char**) * m);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    int i, j;
    for (i = 0; i < m; i++) 
    {
        (*returnColumnSizes)[i] = n;  
        res[i] = (char**)malloc(sizeof(char*) * n);
        for (j = 0; j < n; j++) 
        {
            res[i][j]    = (char*)malloc(sizeof(char) * 10);
            res[i][j][0] = '\0';
        }
    }

    //这里n - 1是指最后一个元素
    dfs(root, res, 0, 0, n - 1);
    return res;
}


===========================================================================================================================
两数之和
/*
    给定一个二叉搜索树和一个目标结果，看这个树里有没有两个数的和等于这个目标结果
    因为是二叉搜索树，所以中序遍历的结果就是从小到大的排列，这时候就可以使用双指针
	按照数组的方法做
*/



#define MAXSIZE 10000
void inorder(struct TreeNode* root, int *res, int *size) 
{
    if (root == NULL) 
    {
        return;
    }
    inorder(root->left, res, size);
    res[(*size)++] = root->val;
    inorder(root->right, res, size);
}

bool findTarget(struct TreeNode* root, int k)
{
    if (root == NULL) 
    {
        return false;
    }
    int *res = (int*)malloc(sizeof(int) * MAXSIZE);
    int size = 0;
    int i, j;
    inorder(root, res, &size);
    i = 0;
    j = size - 1;
    while (i < j) 
    {
        if (res[i] + res[j] == k) 
        {
            return true;
        } 
        else if (res[i] + res[j] > k) 
        {
            j--;
        } 
        else 
        {
            i++;
        }
    }
    free(res);
    return false;
}

===========================================================================================================================
找树左下角的值
//给定一个二叉树，在树的最后一行找到最左边的值
/*
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

*/
int max = -999999;
int res;

void dfs(struct TreeNode* node, int depth)
{
    if(node != NULL)
    {
        if(node->left == NULL && node->right == NULL)
        {
            if(max < depth)
            {
                max = depth;
                res = node->val;
            }
        }

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
}




int findBottomLeftValue(struct TreeNode* root)
{
    dfs(root, 0);
    return res;
}

===========================================================================================================================
在每一行中找出最大的值，输入到一个数组中
#define max(a,b)  (a)>(b)?(a):(b)

//树的高度未知，可以先求解树的高度，按照高度开数组对应存储每层max
int TreeHeight(struct TreeNode* node)
{
    if(node == NULL) 
        return 0;
    int lh = TreeHeight(node->left);
    // printf("%d--",node->val);
    int rh = TreeHeight(node->right);
    return (lh > rh ? lh : rh) + 1;
}

void bfs(struct TreeNode* node, int *res, int resLevel)
{
    if(node==NULL) 
        return;

    res[resLevel] = max(res[resLevel], node->val);
    
    bfs(node->left, res, resLevel+1);
    bfs(node->right, res, resLevel+1);
}

int* largestValues(struct TreeNode* root, int* returnSize){

    int h = TreeHeight(root); // 求树的高度
    *returnSize = h;
    // printf("\n%d",INT_MIN);
    int resLevel = 0;
    int *res = (int*)malloc(sizeof(int) * h); // 开个数组，对应记录每一层的最大值
    // (void)memset(res, 0, sizeof(int)*h);  // 初始化0不行，val可能为负数
	
    for(int i=0;i<h;i++) 
	{
        res[i] = INT_MIN;
    }
   
    bfs(root, res, resLevel);

	return res;
}

===========================================================================================================================
//二叉搜索树的最小绝对差
#define MIN(a,b) ((a) < (b) ? (a) : (b)) 
void inorder(struct TreeNode* root, int *pre, int *min) 
{
    if (root == NULL) 
    {
        return;
    }
    inorder(root->left, pre, min);
	
    if ((*pre) != -1) 
    {
        *min = MIN(*min, root->val - (*pre));
    }
    (*pre) = root->val;
	
    inorder(root->right, pre, min);
    return;
}

int getMinimumDifference(struct TreeNode* root)
{
    int min = INT_MAX;
    int pre = -1;
    inorder(root, &pre, &min);
    return min;
}

===========================================================================================================================
把二叉搜索树转化为累加树
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

输入: 二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

		  13 5 2
/*
    中序遍历是从小到大排列，反向中序遍历是从大到小排列，把之前的累加，加到这个结点上就可以
*/

void accBST(struct TreeNode *root, int *sum)
{
    if (NULL == root) 
        return;

    accBST(root->right, sum);

    *sum += root->val;
    root->val = *sum;

    accBST(root->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    int sum = 0;
    accBST(root, &sum);
    return root;
}

===========================================================================================================================
二叉树的直径
/*
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    


返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

*/

int calMaxRoot(struct TreeNode* root, int *maxRoot)
{
    if (NULL == root) 
        return 0;
    int lLen = calMaxRoot(root->left, maxRoot);
    int rLen = calMaxRoot(root->right, maxRoot);
    if (lLen + rLen > *maxRoot) 
        *maxRoot = lLen + rLen;
    //我懂了，为啥返回的是下面的这个，因为lLen = calMaxRoot(root->left, maxRoot);所以这个计算出的就是左边或右边长度的最大值
    return (lLen > rLen ? lLen : rLen) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int maxRoot = 0;
    calMaxRoot(root, &maxRoot);
    return maxRoot;
}

===========================================================================================================================
二叉树的坡度
/*
给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

【整个树的坡度】就是其所有节点的坡度之和。

示例:

输入: 
         1
       /   \
      2     3
输出: 1
解释: 
结点的坡度 2 : 0
结点的坡度 3 : 0
结点的坡度 1 : |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1

*/

#define ABS(a,b) ((a) > (b) ? ((a) - (b)) : ((b) - (a)))

int calcTilt(struct TreeNode* root, int *sum) 
{
    if (root == NULL) 
    {
        return 0;
    }
    int left  = calcTilt(root->left, sum);
    int right = calcTilt(root->right, sum);
    *sum += ABS(left, right);
    return root->val + left + right;
}

int findTilt(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int sum = 0;
    calcTilt(root, &sum);
    return sum;
}

===========================================================================================================================
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
DFS
DFS(Depth-First-Search)深度优先搜索算法，是搜索算法的一种。
是一种在开发爬虫早期使用较多的方法。它的目的是要达到被搜索结构的叶结点 。

出现次数最多的子树元素和
/**
给出二叉树的根，找出出现次数最多的子树元素和。一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。

 

示例 1
输入:

  5
 /  \
2   -3


返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例 2
输入:

  5
 /  \
2   -5


返回 [2]，只有 2 出现两次，-5 只出现 1 次。
 */
#define LEN sizeof(struct myHash)
struct myHash {
    int val;
    int num;
};
int maxNum = INT_MIN;

//哈希表的建立与输入
//最后得到的结果就是和  和  这个和所出现的次数
void PutInHash(int val, struct myHash *hashSet)
{
    //如果是正数的建立规则，直接等于val % 10000
    int hash = val % 10000;

    //如果是负数的建立规则
    if (val < 0) 
    {
        hash = (-(val + 1)) % 10000;
    }

    //这个位置以前已经添加过东西而且这个位置所包含的和不是val
    while (hashSet[hash].num != 0 && hashSet[hash].val != val) 
    {
        hash++;
        if (hash >= 10000) 
        {
            hash = 0;
        }
    }

    //hash 是根据val（总和）所求的，hash表分成两部分 总和val 这个总和的个数
    hashSet[hash].val = val;
    hashSet[hash].num++;

    //更新最大次数的值
    maxNum = (maxNum < hashSet[hash].num ? hashSet[hash].num : maxNum);
}
int Dfs(struct TreeNode* root, struct myHash *hashSet)
{
    int left = 0;
    int right = 0;
    int sum = 0;

    if (root == NULL) 
    {
        return 0;
    }

    //这样遍历的末尾是根节点
    if (root->left != NULL) 
    {
        left = Dfs(root->left, hashSet);
    }
    if (root->right != NULL) 
    {
        right = Dfs(root->right, hashSet);
    }
    sum = root->val + left + right;
    PutInHash(sum, hashSet);
    return sum;
}
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize)
{
    struct myHash *hashSet = NULL;
    int rootVal = 0;
    int *result = NULL;
    int resultLen = 0;
    
    if (root == NULL) 
    {
        *returnSize = 0;
        return NULL;
    }
    maxNum = INT_MIN;

    hashSet = (struct myHash *)malloc(LEN * 10000);
    //把hashSet结构当中 val 和 num 的值全部初始化为0
    memset(hashSet, 0x0, LEN * 10000);

    Dfs(root, hashSet);

    result = (int *)malloc(sizeof(int) * 10000);
    memset(result, 0x0, sizeof(int) * 10000);

    for (int i = 0; i < 10000; i++) 
    {
        if (hashSet[i].num == maxNum) 
        {
            result[resultLen++] = hashSet[i].val;
        }
    }
    free(hashSet);
    *returnSize = resultLen;
    return result;
}

===========================================================================================================================
二叉搜索树中的众数
/*
    大于更换，等于添加
*/

//目的是给array赋值
void find(struct TreeNode* root, int *array, int *max, int *count, int *data, int *i)
{
    if (!root)
        return ;
    else
    {
        //中序遍历的结果是从小到大的顺序
        find(root->left, array, max, count, data, i);

        //count最开始初始化为1，代表的是现有元素的个数，如果下一个和data的值相同，count递增
        if (root->val == *data) 
        {
            *count = *count + 1;
        }

        //data != -99999主要是为了防止最开始的时候执行这一条
        else if (root->val != *data && *data != -99999)
        {
            //当出现第一个不等于data的值的时候
            //如果count的值大于max，则需要更改之前的数据
            if (*count > *max)
            {
                *max = *count;
                *i = 0;
                array[*i] = *data;
                *i = *i + 1;
            }
            //如果count的值等于，说明不需要更改只需要把这个数据添后面
            else if (*count == *max)
            {
                array[*i] = *data;
                *i = *i + 1;
            }
            *count = 1;
        }

        //最开始的时候执行的是这一条，给data赋值
        *data = root->val;
        find(root->right, array, max, count, data, i);
    }
}

int* findMode(struct TreeNode* root, int* returnSize)
{
    //根节点为空的情况
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int *array = malloc(sizeof(int) * 10000);
    int i, max = 0, count = 1, data = -99999;
    find(root, array, &max, &count, &data, &i);

    //最后一次的输进去
    if (count == max)
    {
        array[i] = data;
        i++;
    }
    else if (count > max)
    {
        i = 0;
        array[i++] = data;
    }

    *returnSize = i;
    return array;
}

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
===========================================================================================================================
左子叶之和
    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

int getLeftLeaves(struct TreeNode* root)
{
    if(root == 0)
        return 0;
    if(root->left != NULL)
    {
        if(root->left->left == NULL && root->left->right == NULL)
             return root->left->val + getLeftLeaves(root->left) + getLeftLeaves(root->right);
    }
    return getLeftLeaves(root->left) + getLeftLeaves(root->right);
}
__________________________________________________________________________________________________________________
我觉着这样写会好些

int sum;
void getLeftLeaves(struct TreeNode* root)
{
    if(root == 0)
        return 0;
    
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        sum += root->left->val;
    }
    
    getLeftLeaves(root->left);
    getLeftLeaves(root->right);
   
}





int sumOfLeftLeaves(struct TreeNode* root)
{
   sum = 0;
   getLeftLeaves(root);
   return sum;
}
===========================================================================================================================
路径总和
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11


int pathnumber;
int pathSum(struct TreeNode* root, int sum)
{
    if(root == NULL)
        return 0;
    Sum(root,sum);
    pathSum(root->left, sum);
    pathSum(root->right, sum);
    return pathnumber;
}

void Sum(struct TreeNode* root, int sum)
{
    //注意：这个是有负数的
    if(root == NULL) 
        return;

    sum -= root->val;
    if(sum == 0)
        pathnumber++;           
    
    Sum(root->left,sum);
    Sum(root->right,sum);




===========================================================================================================================
/*
        删除二叉搜索树中的结点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：


	首先找到需要删除的节点；
	如果找到了，删除它。


说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7


*/

struct TreeNode* min(struct TreeNode* node) 
{
        if (node->left == NULL) 
        {
            return node;
        }
        return min(node->left);
}

struct TreeNode* deleteMin(struct TreeNode* node) 
{
    if (node->left == NULL) 
    {
        return node->right;
    }
    node->left = deleteMin(node->left);
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    /*
        啥意思：这不同于root->left = deleteNode(root->left, key);   root->right = deleteNode(root->right, key);
        如果写成上面那样，是上面两条都执行  如果按照下面的形式写，是只执行一条 其实就是找出一条从根结点开始一直到待删除结点的一条线
        返回就是  当作上一个结点的左子树或右子树  又因为类似于后序遍历，所以返回的是root结点
    
    */
    //待删除节点为空的情况
	
	//return应该是返回删除后的结果
    if (root == NULL) 
    {
        return NULL;
    } 

    if (key < root->val) 
    {
        // 待删除节点在左子树中
        root->left = deleteNode(root->left, key);
        return root;
    } 
    else if (key > root->val) 
    {
        // 待删除节点在右子树中
        root->right = deleteNode(root->right, key);
        return root;
    } 

    //找到了要删除的结点
    else 
    {
        // key == root.val，root 为待删除节点
        if (root->left == NULL) 
        {
            // 返回右子树作为新的根
            return root->right;
        } 
        else if (root->right == NULL) 
        {
            // 返回左子树作为新的根
            return root->left;
        } 
        else 
        {
            // 左右子树都存在，返回后继节点（右子树最左叶子）作为新的根
            struct TreeNode* successor = min(root->right);
            successor->right = deleteMin(root->right);
            successor->left = root->left;
            return successor;
        }
    }
}


===========================================================================================================================
打家劫舍

/*
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 
除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

*/


#define MAX(a,b) (a>b?a:b)
int rob(struct TreeNode* root)
{
    //结点是空的情况
    if (root == NULL) 
    {
        return 0;
    }

    /*
        让聪明的姿姿解释一下这个是为什么？
        后序遍历按逻辑，假设这个递归是算钱数的
        算出爸爸的钱  和   爷爷和儿子的钱
        比较
        因为要偷最多的钱，所以要返回两者之间最大的那个
    */
    //爸爸的钱
    int notSteal = rob(root->left) + rob(root->right);
    int steal = 0;
    int stealLeft = 0;
    int stealRight = 0;

    
    if (root->left) 
    {
        stealLeft = rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) 
    {
        stealRight = rob(root->right->left) + rob(root->right->right);
    }

    //爷爷和孙子的钱
    steal = root->val + stealLeft + stealRight;
    return MAX(notSteal, steal);
}


===========================================================================================================================

二叉搜索树中第k小的元素

int gret[10000],gnum,gk;
void dfs(struct TreeNode* root)
{
    if (root == NULL || gnum >= gk)
        return;
    dfs(root->left);
    gret[gnum++] = root->val;
    dfs(root->right);
}
int kthSmallest(struct TreeNode* root, int k)
{
    gnum = 0;
    gk = k;
    dfs(root);
    return gret[k-1];
}

===========================================================================================================================
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

                 6
            /        \
          2           8
        /   \       /  \
      0     4      7   9
          /  \
        3    5

 

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。


示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。


*/

/*
利用二叉搜索树的特点，如果p、q的值都小于root，说明p q 肯定在root的左子树中；如果p q都大于root，说明肯定在root的右子树中，如果一个在左一个在右 则说明此时的root记为对应的最近公共祖先
*/


struct TreeNode* res = NULL;
void lca(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if(root->val < p->val && root->val < q->val)
    {
        lca(root->right, p , q);
    }

    else if(root->val > p->val && root->val > q->val)
    {
        lca(root->left, p , q);
    }
    else  
        res = root;
}



struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    lca(root, p, q);
    return res;
}

===========================================================================================================================
二叉树的最近公共祖先
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    /*
        太难了，我再来解释以下，首先进入这个函数，是对h这个结点的判断，如果这个结点满足题意，直接返回
        如果这个结点不满足题意，去看看它左边和右边满不满足题意，，如果左边和右边都不满足，返回空
        如果一个存在，另一个空，说明这两个点都在存在的那边   
    */
	
    if (root == NULL) 
    {
        return NULL;
    }

    //如果左边找到了或右边找到了，返回找到了的根节点
    if (root == p || root == q) 
    {
        return root;
    }

    //找到这个点右边的  和  左边的， 递归函数上面写着的是递归终止条件  ， 递归函数下面写的是返回上一个结点的。
    struct TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    //如果是NULL就代表没找到，意思就是left或right没找到，那么就在right或left
    if (left != NULL && right != NULL) 
    {
        return root;
    } 
    else if (left != NULL) 
    {
        return left;
    } 
    else if (right != NULL) 
    {
        return right;
    }
	
    //如果两边都没找到，返回空
    return NULL;
}


===========================================================================================================================
完全二叉树中结点的个数
int countNodes(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);

}

===========================================================================================================================
二叉树的右视图

/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


*/

void dfs(struct TreeNode* root, int* returnSize, int* res, int level)
{
    if(root == NULL)
    {
        return;
    }
    if(level >= *returnSize)
    {
        res[(*returnSize)++] = root->val;
    }
	
    dfs(root->right, returnSize, res, level + 1);
    dfs(root->left, returnSize, res, level + 1);
    return;
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    dfs(root, returnSize, res, 0);
    return res;
}

===========================================================================================================================
二叉搜索树
/*
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。

示例：
          7
       /     \
     3       15
           /   \
          9    20



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false


*/



typedef struct 
{
    int nums[10000];
    int top;
} BSTIterator;

void ReverseInOrder(struct TreeNode *root, BSTIterator *obj)
{
    if (root->right != NULL) 
    {
        ReverseInOrder(root->right, obj);
    }
	
    obj->nums[++obj->top] = root->val;
	
    if (root->left != NULL) 
    {
        ReverseInOrder(root->left, obj);
    }
}

//先看这个，这个和上面一步，目的就是创造了一个结构，保存了反向中序遍历的值和元素的个数
BSTIterator* bSTIteratorCreate(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return NULL;
    }
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    if (obj == NULL) 
    {
        return NULL;
    }
    obj->top = -1;
    ReverseInOrder(root, obj);
    return obj;
}

//实现栈顶元素的出栈
/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) 
{
    int num;
    num =  obj->nums[obj->top];
    --obj->top;
    return num;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) 
{
    if (obj == NULL || obj->top < 0) 
    {
        return false;
    }
    
    return true;
}

void bSTIteratorFree(BSTIterator* obj) 
{
    free(obj);
}

===========================================================================================================================
二叉树的前序遍历
迭代算法
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* res = (int*)malloc(sizeof(int) * 100),top = -1;
	
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    *returnSize = 0;
	
    if(!root) 
        return NULL;
    stack[++top] = root;
    while(top != -1)
    {
        root = stack[top--];
        res[(*returnSize)++] = root->val;
        if(root->right)
        {
            stack[++top] = root->right;
        }
        if(root->left)
        {
            stack[++top] = root->left;
        }
    }
    return res;
}

===========================================================================================================================

求根到叶子结点数字之和
/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.

示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.

*/


//n就是算出这个结点前面数字之和
int sum(struct TreeNode* root,int n)
{
    if(root == NULL)
        return 0;
    if(root->right == NULL && root->left == NULL)
        return (n * 10 + root->val);
    return sum(root->left,n * 10 + root->val) + sum(root->right,n * 10 + root->val);
}

int sumNumbers(struct TreeNode* root) 
{
    return sum(root,0);
}

===========================================================================================================================
从前序和中序遍历序列构造二叉树

/*
例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode* result = NULL;
    
    if(preorder == NULL || preorderSize == 0)   //preorder相当于每次递归的终止条件  preorderSize相当于如果本来这棵树就是空的情况
    {
        return NULL;
    }
   
    result = malloc(sizeof(struct TreeNode));
    if(result == NULL)
    {
        return NULL;
    }
    result->val = preorder[0];
    for(int i=0; i<inorderSize; i++)
    {
        if(inorder[i] == result->val)
        {
            result->left  = buildTree(preorder+1, i, inorder, i);
            result->right = buildTree(preorder+i+1, preorderSize - i - 1, inorder+i+1, inorderSize-i-1);
            break;
        }
    }
    return result;
}

===========================================================================================================================
从中序和后序遍历序列构造二叉树
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    struct TreeNode* result = NULL;
    
    if(postorder == NULL || postorderSize == 0)   //preorder相当于每次递归的终止条件  preorderSize相当于如果本来这棵树就是空的情况
    {
        return NULL;
    }
   
    result = malloc(sizeof(struct TreeNode));
    if(result == NULL)
    {
        return NULL;
    }
    result->val = postorder[postorderSize - 1];
    for(int i=0; i<inorderSize; i++)
    {
        if(inorder[i] == result->val)
        {
            result->left  = buildTree(inorder, i, postorder, i);
            result->right = buildTree(inorder+i+1, inorderSize-i-1, postorder + i, postorderSize - i - 1);
            break;
        }
    }
    return result;
}


===========================================================================================================================
路径总和
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
*/

typedef struct TreeNode* Node;
//递归，先将临时路径保存在新数组temp中，如果该路径满足就是输入在结果中
void search(Node root,int sum,int* returnSize, int** returnColumnSizes,int **result,int *temp,int now)
{
    if(root == NULL)  
        return;     //递归结束条件
    if(root->left == NULL && root->right == NULL && sum == root->val)     //到达叶节点并满足条件的情况
    {
        temp[now++] = root->val;
        int c = *returnSize;
        (*returnColumnSizes)[*returnSize] = now;    //该行的列数
        result[c] = (int*)malloc(sizeof(int)*now);

        for(int i = 0 ;i < now ;++i)
            result[c][i] = temp[i];
        ++(*returnSize);    //行数加一
    }
    temp[now++] = root->val;
    sum -= root->val;
    search(root->left,sum,returnSize,returnColumnSizes,result,temp,now);    //递归
    search(root->right,sum,returnSize,returnColumnSizes,result,temp,now);
}
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    int** result = (int**)malloc(sizeof(int*) * 1024);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 1024);
    *returnSize = 0;
    if(root == NULL)  
        return result;
    int *temp = (int*)malloc(sizeof(int)*1024);
    search(root,sum,returnSize,returnColumnSizes,result,temp,0);
    return result;
}

===========================================================================================================================
二叉树展开为链表
/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6

将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/




void flatten(struct TreeNode* root)
{
    if(root == NULL)
        return;
    flatten(root->left);
    flatten(root->right);
    struct TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    while(root->right != NULL) 
        root = root->right;
    root->right = tmp;
}

===========================================================================================================================
//二叉树的层次遍历
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int **res = malloc(sizeof(int*) * 1000); //结果数组
    for(int i = 0; i < 1000; i++) //全部初始化为1个特殊的元素。以便后面统计每排有几个
    {
        res[i] = malloc(sizeof(int) * 200);
        for(int j = 0; j < 200; j++)
            res[i][j] = -929;
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    order(root, 0, res); //递归


    for(int i = 0; i < 1000; i++) //确定返回元素每一层的宽度
    {
        if(res[i][0] == -929) //如果某一层第一个就是特殊元素，则这一层都没有存数据，即结束
        {
            *returnSize = i;
            break;
        }
        for(int j = 0; j < 200; j++) //统计每一层有多少元素存入
        {
            if(res[i][j] == -929)
            {
                (*returnColumnSizes)[i] = j;
                break;
            }
        }
    }
    return res;
}

//咱重点看这个步骤，这个步骤完成之后就可以把每一行的数字输入到数组中
void order(struct TreeNode* root,int k,int** res) 
{
    if(root == NULL)
        return;
		
    for(int i = 0; i < 1000; i++) //到第一个未填的位置填入当前值
    {
        if(res[k][i] == -929)
        {
            res[k][i] = (root->val);
            break;  //注意这个break
        }
    }
    order(root->left, k+1, res); //递归左子节点
    order(root->right, k+1, res);  //递归右子节点
}



===========================================================================================================================
验证搜索二叉树

//low和high是根节点root->val的范围
bool fun(struct TreeNode* root, long low, long high) 
{
    if (root == NULL) return true;
    long num = root->val;
    if (num <= low || num >= high) return false;
    return fun(root->left, low, num) && fun(root->right, num, high);
}
bool isValidBST(struct TreeNode* root)
{
    return fun(root, LONG_MIN, LONG_MAX);
}

===========================================================================================================================




























