1.����������
int maxSubArray(int* nums, int numsSize)
{
    int MaxSum, Sum, i, m, j = 0, h = 0, EndSum;
    m = nums[0];
    for(i = 0; (i < numsSize) && (nums[i] < 0); i++)  //i�ǵ�һ������0����
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
̰���㷨
���Ǵӵ�һ�����ֿ�ʼ������С��0�ľ�����

int maxSubArray(int* nums, int numsSize)
{
	//����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = nums[0];
        int sum = 0;
		int i;
        for (i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //���sum < 0�����¿�ʼ������
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
        //����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = INT_MIN;   //��һ������С����
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
        //ע������Ӧ��mid + 1������left + 1 = rightʱ��������ѭ��
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
		
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
		
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
    }
	
	//̰���㷨
    int findMaxCrossingSubarray(int *nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;   //��һ������С����
        int sum = 0;
		int i;
        for (i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //ע������i = mid + 1�������ظ��õ�nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};


=====================================================================================
�õݹ�ӷ��η��ҳ������е�һ��͵ڶ������
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
 
void max(int str[],int lo,int hi,int *x1,int *x2)//����lo��������hi 
{
	if(lo+2==hi)//����Ԫ�� lo��lo+1 ,������hi 
	{
		x1=str[lo];
		x2=str[lo+1];
		if(x1<x2) swap(&x1,&x2);
		return;
	}
	if(lo+3==hi)//����Ԫ��  lo��lo+1,lo+2 ��������hi 
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
	printf("�ϲ���%d %d\n",x1,x2);
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





������������������������������Ħ�����򣺾�������5���ˣ����������ˣ������ҵ������˸���򣬵������������2���ˣ�������Ӯ��

int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i] == key)		//���Ԫ�غͱ��Ԫ����ͬ��������һ
            count++;
        else		//�����һ
            count--;
        
        if(count <= 0)		//������С�ڵ�����ʱ���������
        {
            key = nums[i+1];
        }
        
    }
    return key;		//����������һ��Ϊ����
}
��������������������������������

==========================================================================
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
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
������ʵ�������������

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
        printf("��̬�ڴ����ʧ��");
        exit(-1);
    }

    PNODE pTail = pHead;
    pHead->next = NULL;
    printf("������������Ҫ�Ľڵ������");
    scanf("%d",&len);

    for(i = 0; i < len; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("��̬�ڴ����ʧ��");
            exit(-1);
        }

        printf("�������%d���ڵ��ֵ��",i + 1);
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
        printf("��̬�ڴ����ʧ��");
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
            printf("��̬�ڴ����ʧ��");
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
            printf("��̬�ڴ����ʧ��");
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
                printf("��̬�ڴ����ʧ��");
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
                printf("��̬�ڴ����ʧ��");
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
                printf("��̬�ڴ����ʧ��");
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
                printf("��̬�ڴ����ʧ��");
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
            printf("��̬�ڴ����ʧ��");
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
    printf("�뵹������һ������\n");
    PNODE pHead1 = creat_list();


    printf("�뵹������һ������\n");
    PNODE pHead2 = creat_list();

    printf("������������ӵĽ���ǣ�\n");
    PNODE answer = addTwoNumbers(pHead1,pHead2);

    while(answer != NULL)
    {
        answer = answer->next;
        printf("%d", answer->data);
    }
}



========================================================================================================================================================
�ж�һ�����ǲ��ǻ�����

ֱ��ǰһ����һ�����ж�
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
        printf("�����ǻ�����");
    else
        printf("�������ǻ�����");
		
--------------------------------------------------------------
#define true 1
#define false 0
//�����һ�������뵽k�У��жϺ�֮ǰ�������಻��ͬ
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
����һ����ά����������������
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
       printf("��ͬ���Ӵ�Ϊ��\n");
       for(i = i1 - count;i < i1 ; i++)
       {
           printf("%c",L1[i]);
       }
   }
   else
   {
       printf("������������û����ͬ��Ԫ��");
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

//������������
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
        printf("��̬�ڴ����ʧ�ܣ�");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->next = NULL;

    printf("����������Ҫ�Ľڵ������");
    scanf("%d", &point);

    for(i = 0; i < point; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("��̬�ڴ����ʧ�ܣ�");
            exit(-1);
        }

        printf("���������%d���ڵ�����֣�\n", i + 1);
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
        printf("��̬�ڴ����ʧ�ܣ�");
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
            printf("��̬�ڴ����ʧ�ܣ�");
            exit(-1);
        }

        pNew->data = P1->data;
        pNew->next = NULL;
        P3_tail->next = pNew;
        P3_tail = pNew;

        PNODE pNew1 = (PNODE)malloc(sizeof(NODE));
        if(pNew1 == NULL)
        {
            printf("��̬�ڴ����ʧ�ܣ�");
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
            printf("��̬�ڴ����ʧ�ܣ�");
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
            printf("��̬�ڴ����ʧ�ܣ�");
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
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
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
�������
��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������ǰ�������£�

1.     1
2.     11
3.     21
4.     1211
5.     111221


1 ������  "one 1"  ("һ��һ") , �� 11��
11 ������ "two 1s" ("����һ"��, �� 21��
21 ������ "one 2",  "one 1" ��"һ����" ,  "һ��һ") , �� 1211��


int number = 1; //��¼���������ж�������

void beautiful(int *s, int n)
{
    int num[20];
    int m = 0; //������������
    int i = 1; //��¼��ǰ�ж��ٸ��ظ�����
    int j = 0; //���뵽num�����е�
    int p;

    if(n == 0)   //n�������ĵݹ�ִ�м���
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
//���һ�����ʵĳ���
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
һ������ƽ��
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

ɾ���ظ�Ԫ�أ��ղأ�����Ǵ�ģ�
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
        printf("��̬�ڴ����ʧ�ܣ�");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->next = NULL;

    printf("����������Ҫ�Ľڵ������");
    scanf("%d", &point);

    for(i = 0; i < point; i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("��̬�ڴ����ʧ�ܣ�");
            exit(-1);
        }

        printf("���������%d���ڵ�����֣�\n", i + 1);
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
        printf("��̬�ڴ����ʧ��");
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

����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�


ʾ�� 2:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��


/**
 * jָ��ǰ������ֵ��iָ��ǰ��������ֵ�е���Сֵ��max��ʾ��ǰ���������
 * ��prices[j] < prices[i]������i�������ж�prices[j] - prices[i]�Ƿ����max��Ȼ�����max
 */

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    for(int i = 0, j = 0; j < pricesSize; j++){		
        if(prices[j] < prices[i]){
            i = j;
	}else if(prices[j] - prices[i] > max){
            max = prices[j] - prices[i];
        }
    ��
    return max;
}

=================================================================================================
��Ʊ����

1.
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 7
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 3 �죨��Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
     ����ڵ� 4 �죨��Ʊ�۸� = 3����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ������, ��ʽ������ܻ������ = 6-3 = 3 ��


ʾ�� 2:

����: [1,2,3,4,5]
���: 4
����: �ڵ� 1 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �� ����Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
     ע���㲻���ڵ� 1 ��͵� 2 ����������Ʊ��֮���ٽ�����������
     ��Ϊ��������ͬʱ�����˶�ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��


ʾ�� 3:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��

*̰���㷨
����ǵ�һ����������Եڶ��������Ļ����ڶ������ͬʱ�����
����ͨ���ֲ�������󣬾��������������
����ǵ��� 1   4    6   7  ��һ��������ڶ����������ڶ������������������������
�͵�һ����������������Ľ����ͬ

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

*��̬�滮
��Ϊ���У���һ�����������Եõ�����Ǯ���ڶ�����������Եõ�����Ǯ
���ݣ� 7  1  5  3  6  4  

        0      -7
		0      -1
		4      -1
        4       1
        7       4	

ԭ��û��Ǯ                                         ����õ���Ǯ�Ǹ���
������������Եõ�-6 ��Ǯ�������粻����	           ������룬���һ��Ǯ����ԭ���٣�������	
������������Եõ��Ŀ�Ǯ����ԭ���࣬���Ծ�Ҫ����   ������룬�������Ǯ������
���������������Ǯ��û��ԭ���࣬���Բ���           �����������������һ��Ǯ��������
������������Եõ��߿�Ǯ����                       ������룬�������Ǯ������

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

����������������������������������������������������������������������������������������������������������������������������������������������������������������
λ����
����

������Ƕ� 0 �Ͷ�����λ�� XOR ���㣬�õ�����Ȼ�����������λ

a��0=aa \oplus 0 = aa��0=a


������Ƕ���ͬ�Ķ�����λ�� XOR ���㣬���صĽ���� 0

a��a=0a \oplus a = 0a��a=0


XOR ���㽻���ɺͽ����

a��b��a=(a��a)��b=0��b=ba \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = ba��b��a=(a��a)��b=0��b=b



��������ֻ��Ҫ�����е������� XOR �������õ��Ǹ�Ψһ�����֡�


����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:

����: [2,2,1]
���: 1


ʾ�� 2:

����: [4,1,2,1,2]
���: 4

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


����������������������������������������������������������������������������������������������������������������������������������������������������������������
����һ�������ж��������Ƿ��л���

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

*˫ָ�������
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

����һ���������������������� ������

ʾ��:

����: [1,null,2,3]
   1
    \
     2
    /
   3

���: [1,3,2]



struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


/**
	��Ϊ�ҵ�Ŀ���Ǵ������ϱ�����ڵ㣬�Ը�����ڵ�Ϊ��㣬��ʼ������������ұ�
**/

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode* st[1000] = {0};  //struct TreeNode*  ����st������ÿ��Ԫ�ص�����
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
����һ������ n������������ 1 ... n Ϊ�ڵ�����ɵĶ���������������

ʾ��:

����: 3
���:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
����:
���ϵ������Ӧ���� 5 �ֲ�ͬ�ṹ�Ķ�����������

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
	���������ڴ����
	��Ϊ�������
	struct TreeNode*       �����������˼���� ����һ������������Ľṹ ����ÿһ�����ڵ㶼��һ��ָ������
	struct TreeNode**      �����������˼���� һ�������ﴢ���Ŵ����źܶ������  ÿһ�����ڵ㶼��һ��ָ��
	
	���Է����ڴ�Ҫ�������Σ�һ���Ǹ����������λ�÷����ڴ棬����һ���Ǹ�����������ڴ�

*/


struct TreeNode** create(int start,int end,int*m)   //m������������м���λ��
// �������д�start��ʼ��end������Щ�����ܹ��ɵĶ�������������ͨ����Ӹ�ֵ�����Щ����������Ŀ

{
    struct TreeNode **p,**lefts,**rights;
    int a,i,b,j,k,count = 0;   
		
	
    if(start > end) 
    {              
        //�����Ҳ��������ռһ��λ��
		p = (struct TreeNode**)malloc(sizeof(struct TreeNode*)); //����ָ��ָֻ��һ��һ��ָ��
        *p = NULL; 
        *m = 1; 
        return p;
    } 
    
    if(start == end)             //����������Ϊһʱ���������
    {
         p = (struct TreeNode**)malloc(sizeof(struct TreeNode*));   //����ָ��ָֻ��һ��һ��ָ��
        *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*p)->left = (*p)->right = NULL;   //������Ϊ1ʱ�ĸ�ֵ
        (*p)->val = start;
        *m = 1;
        return p;
    }                         //Ϊ�˼���ѭ��������дҲ����
	
	//�����p������ڴ���������������10000��λ��
    p=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);//����һ���㹻��ķ����ڴ�ռ����洢���������ĸ������
	
    
	for(i = start;i<=end;i++)
    {
        //������������Ŀ�ľ���ȷ�����ڵ�i �������������� ab�����������ж��ٸ�λ��
		//�������������֮��lefts �� rights����������ά���飬ÿһ�зֱ���һ�����
		lefts = create(start,i-1,&a);
        rights = create(i+1,end,&b);     //�ݹ�������������s
        
        for(k = 0;k<a;k++)
        {
            for(j=0;j<b;j++)          //����forѭ��������������s        
            {
                //��Ϊ�ղ��Ѿ�������λ�ã���������ֻҪ���������
				p[count] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                p[count]->val = i;
                p[count]->left = lefts[k];
                p[count]->right = rights[j];      
                count++; //��¼����
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
    }       //��nΪ0���������
    p = create(1,n,returnSize);  //���ú�������
    return p;
}//����

=====================================================================================================================

��תһ�ö�������

ʾ����

���룺

     4
   /   \
  2     7
 / \   / \
1   3 6   9

�����

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


����������������������������������������������������������������������������������������������������������������������������������������������������������������
struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return root;
		
    //��ס����ͨ��ָ��������ֻҪ���һ��ˣ�����������еĺ��ұ����еĶ�����
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
    ����һ������������ arr�����������������������Ķ�������


	ÿ���ڵ㶼�� 0 ������ 2 ���ӽڵ㡣
	���� arr �е�ֵ���������������ÿ��Ҷ�ڵ��ֵһһ��Ӧ����֪ʶ�عˣ����һ���ڵ��� 0 ���ӽڵ㣬��ô�ýڵ�ΪҶ�ڵ㡣��
	ÿ����Ҷ�ڵ��ֵ����������������������Ҷ�ڵ�����ֵ�ĳ˻���


    �����������Ķ������У�����ÿ����Ҷ�ڵ��ֵ����С�����ܺ͡�����͵�ֵ��һ�� 32 λ������

     

    ʾ����

    ���룺arr = [6,2,4]
    �����32
    ���ͣ�
    �����ֿ��ܵ�������һ�ֵķ�Ҷ�ڵ���ܺ�Ϊ 36���ڶ��ַ�Ҷ�ڵ���ܺ�Ϊ 32��

        24            24
       /  \          /  \
      12   4        6    8
     /  \               / \
    6    2             2   4
    
    ��������ظ�һ����������˼��
    ���ڵ��ֵ����������Ҷ�ڵ����� �� ������Ҷ�ڵ����ģ���ΪҶ�ڵ㣬�����������ֵ����Ϊ���ڵ㣬�����������ֵ
    ��������Ҫȡ��������������
    ������������������
    �����������м� 
     
    ��Ϊ�ڵ�ֵ������ߵ�Ҷ�ӽڵ�����ֵ * �ұ�Ҷ�ӽ������ֵ  ����ҪʹҶ�ӽ�㾡�����ڸߴ�������ֻ�б����ߵĽ���Ӱ�죬���������Ĳ��ᱻӰ��	 

**/

/*
Ϊ�˱�֤�������Ľ����С��������֪��������ֵ��ķֲ��ڽϸߵĽڵ㴦��
���������Ҷ�ڵ�ֵ��ʱ����õ�����ϴ���ֵ�Ĵ�������ԱȽ����ˡ�
�Դ˷������������ֵΪ�ֽ�㣬
������Ϊ�����������������ֱ�����Ҷ�ڵ�ĺͼ��ɡ�
*/

//�����ľ�������������Ӧ���±�
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

//�ݹ���ʵ���ǿ����ڵ���������ӵ����
int CalcMin(int *arr, int arrSize)
{
    /* 1���õ�����������Ա��� */
    
    //������������ֻ������Ԫ�أ��������ǵĳ˻�
    if (arrSize == 2) 
    {
        return arr[0] * arr[1];
    }
    
    //�����1��Ԫ�أ���û���������
    if (arrSize == 1) 
    {
        return 0;
    }
    
    int finalOut = 0x7fff;
	
    //ȡ�������������ֵ���±�
    int Idx = GetMaxIdx(arr, arrSize);
    
    for (int i = 0; i < arrSize; i++)  //���ѭ����Ŀ�ľ����ҳ���û����������Ҿ���û��
    {
        if (arr[i] == arr[Idx]) 
        {
            int out = 0;
            int maxIdx = i;
            
            /* �����ֵ�����˵����� */
            if (maxIdx == 0) 
            {
                //�ҳ�ʣ�µ����ֵ
                int secMax = GetMaxIdx(arr + 1, arrSize - 1);
                
                //out����˼���Ǹ��ڵ��ֵ
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
            
            //�����ֵ���м�����
            else 
            {
                int leftMax = GetMaxIdx(arr, maxIdx); // ������ֵ��������
                int rightMax = GetMaxIdx(arr + maxIdx + 1, arrSize - maxIdx - 1); // �Ҳ����ֵ����
                int left = arr[leftMax];
                int right = (arr + maxIdx + 1)[rightMax];
                
                /* ���ݴδ����ֵѡ�������ֵλ������������������ */
                if (left > right) 
                { 
                    out = left * arr[maxIdx]; //�δ���ֵ����࣬�������ֵ������������
                    //����������
                    out += CalcMin(arr + maxIdx, arrSize - maxIdx);
                    //����������
                    out += CalcMin(arr, maxIdx);
                } 
                else if (left < right) 
                {
                    out = right * arr[maxIdx]; //�δ���ֵ���Ҳ࣬�����Ԫ�ط���������
                    out += CalcMin(arr + maxIdx + 1, arrSize - maxIdx - 1);
                    out += CalcMin(arr, maxIdx + 1);
                } 
                else 
                {   // ����δ���ֵ�������ֵ�����඼�У��ǾͶ�����һ��Ƚ����ֱȽ�С
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
            //����ѡ���������Сֵ
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
����һ�ö����������㷵�������������������нڵ��ֵ֮�ͣ�


	�ýڵ���游�ڵ��ֵΪż������һ���ڵ���游�ڵ���ָ�ýڵ�ĸ��ڵ�ĸ��ڵ㡣��


����������游�ڵ�ֵΪż���Ľڵ㣬��ô���� 0 ��

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
������ȱ��������Ǽ��ÿһ���ڵ㣩
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

����������������������������������������������������������������������������������������������������������������������������������������������������������������
������ȱ���
���ȼ��һ���ڵ��Ƿ���ż��������ǣ������������
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) 
	{
        //����һ������
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
����һ���� root Ϊ���Ķ�������һ������ target ������ɾ������ֵΪ target �� Ҷ�ӽڵ� ��

ע�⣬һ��ɾ��ֵΪ target ��Ҷ�ӽڵ㣬���ĸ��ڵ�Ϳ��ܱ��Ҷ�ӽڵ㣻�����Ҷ�ӽڵ��ֵǡ��Ҳ�� target ����ô����ڵ�ҲӦ�ñ�ɾ����

Ҳ����˵������Ҫ�ظ��˹���ֱ�����ܼ���ɾ����

//һ��Ҫ��ס���������κͻ���������
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
����һ�ö����������㷵�ز�������ġ�Ҷ�ӽڵ㡿�ĺ͡�
                       1
                     /   \
                    2     5
                  /  \  /  \
                3    6 4    9
                           / \
                          10 12

            �м����ܵ�Ŀ���ǰ�����Ϊ��������������
            ǰ�������1 2 3 6 5  4  9  10 12      
            ���������3 6 2 4 10 12 9  5  1			
			���������3 2 6 1 4  5  10 9 12
��ľ���
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
    
    

    //�������ʲôʱ��ִ�У����ǵ�ǰ�������������ʱ���أ�����ֻҪһ���������Һ��Ӷ�Ϊ��ʱ������������������Ϳ�ʼִ����
    //����˵�п����м�������Ǿʹ�������Ҫ����ǰ�����ȫ����ʱ���
    /*
        50
           \
           54
          /  \
         98   6
               \
               34
        
        ����˵�������ǰ��ִ����ʱ  root->val = 98, ��ʱmaxDeepth = 2 ������Ҫ�������ʹ���
        ����ϸ����һ�£������������ȣ��ſ�����������

        ��Ҫ���ģ��и��뷨����ȷ������ǰ�������������ֵ�����ں������һֱ����
    */
    printf("%d ", maxDeepth);
    if(deep == maxDeepth)
        *sumNode += root->val; 
    printf(" ��%d����%d��[%d] \n", *sumNode, root->val, deep);
      
}


int deepestLeavesSum(struct TreeNode* root)
{
    int sumNode = 0;
    maxDeepth = 0;
    calcSum(root, 0, &sumNode);
    return sumNode;
}


��������������������������������������������������������������������������������������������������������������������������������������������������������������������

void calcSum(struct TreeNode* root, int deep, int* maxDeepth, int* sumNode) 
{
   //��Ⱦ��Ǵ�1��ʼ  
   
   /*
		�������ַ���������
		���deep > *maxDeepth  ����Ϊ��ǰ������sumNode������
		sumNode�ô�root->val��ʼ������
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
����λ������Ҳ�����һ������������ɫ������Ϸ����Ϸ�У������������ĸ��ڵ� root�������ܹ��� n ���ڵ㣬�� n Ϊ����������ÿ���ڵ��ϵ�ֵ�� 1 �� n ������ͬ��

 

��Ϸ�ӡ�һ�š���ҿ�ʼ����һ�š����Ϊ��ɫ�������š����Ϊ��ɫ�����ʼʱ��

��һ�š���Ҵ� [1, n] ��ȡһ��ֵ x��1 <= x <= n����

�����š����Ҳ�� [1, n] ��ȡһ��ֵ y��1 <= y <= n���� y != x��

��һ�š���Ҹ�ֵΪ x �Ľڵ�Ⱦ�Ϻ�ɫ���������š���Ҹ�ֵΪ y �Ľڵ�Ⱦ����ɫ��

 

֮����λ����������в�����ÿһ�غϣ����ѡ��һ����֮ǰͿ����ɫ�Ľڵ㣬����ѡ�ڵ�һ�� δ��ɫ ���ڽڵ㣨�������ӽڵ㡢�򸸽ڵ㣩����Ⱦɫ��

�����ǰ����޷��ҵ������Ľڵ���Ⱦɫʱ�����ĻغϾͻᱻ������

��������Ҷ�û�п���Ⱦɫ�Ľڵ�ʱ����Ϸ��������ɫ�ڵ�������λ��һ��ʤ�� ??��

 

���ڣ��������ǡ����š���ң����������������룬�������һ�� y ֵ����ȷ����Ӯ���ⳡ��Ϸ���򷵻� true�����޷���ʤ�����뷵�� false��

����������������������������������������������������������������������������������������������������������������������������������������������������������������
����һ������һ��ɫ����һ����ɫ��������Ѿ���ɫ�ĵط�������
���Ը����Ѿ���ɫ�ĵط���������ɢ

/**
    ���ݵ�һ��Ϳ��ĵ���Է�Ϊ�����֣����ӵ�һ��  �Һ��ӵ�һ��  ʣ�µ�����
    ���ѡ�������ӣ��ͽ��������������Ϳ����ɫ  ʣ��������Ϳ�ɺ�ɫ
    ʣ��ͬ�� 
**/

�൱������
     O
	 |
	 O
	/ \
   O   O


struct TreeNode *g_firstPlayer;

//�ҵ�������������еĸ���,��������ڵ�
int CalcNodeNum(struct TreeNode *root)
{
    if (root != NULL) 
        return 1 + CalcNodeNum(root->left) + CalcNodeNum(root->right);
}

//�ҵ����������������еĸ���
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
    
	//�������ҵݹ���¶����
	//����ȫ�ֱ���num ���������г�ʼ��numΪ0
	
	/**
	
	num++;
    CalcAndFind(root->left, toFind);
    CalcAndFind(root->right, toFind);
    return num;
	
	**/
    
	//�������ҵݹ����¶����
	return (1 + CalcAndFind(root->left, toFind) + CalcAndFind(root->right, toFind));
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x)
{   
    g_firstPlayer = NULL;
	
	//��סһ��������������ǵ�root�Ǹ��ڵ��ʱ��
    if (x == root->val) 
    {
        /* 1�������һ�����ѡ����ǵ�һ�����ڵ� */
        /* 1.1�����ӽڵ��½ڵ����� */
        int left = CalcNodeNum(root->left);
        
        /* 1.2�����ӽڵ��½ڵ����� */
        int right = n - left - 1;  //ȥ����ߵĸ����͸��ڵ�
        if (left == right) 
            return false;

        else 
            return true;
    } 
	
	//���root���Ǹ��ڵ�
    else 
    {
        /* 2����һ�����ѡ��ǵ�һ�����ڵ� */
        /* 2.1����һ�����ѡ��ڵ�ĸ��ڵ� */
        int Root = CalcAndFind(root, x);   
        /* 2.2����һ�����ѡ��ڵ�����ӽڵ� */
        int Left = CalcNodeNum(g_firstPlayer->left);
        /* 2.3����һ�����ѡ��ڵ�����ӽڵ� */
        int Right = CalcNodeNum(g_firstPlayer->right);
         printf("Root = %d, Right = %d, Left = %d", Root, Right, Left);
         
        //��1��Ŀ�ľ���Ϊ�˼����Ǹ����ڵ�
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
������Ѱ·
������һ����ȫ�������У�������˳�򲻱䣬ż���з��������ҵ�һ�����·��

��Ϊ��1Ϊ���ڵ��α�ŵ������������Զ�Ӧ��λ�ı�ʾ��������λ�����˼·���ɡ�
��Ϊÿ���˳���ڱ䣬����ÿ����Ҫ����λ�������λȡ����
����14=1110b��
�Ƚ�14���ƣ���Ϊ111b(7)��Ȼ��Գ���һλ������λȡ����Ϊ100b�������ĸ��ڵ�4��
ͬ��100b(4)�����Ʊ�Ϊ10b(2)���Գ���һλ������λȡ����Ϊ11b�������ĸ��ڵ�3
һֱ��1������


�ȿ�ʼ�������������λ��Ϊ0
0000 0000 0000 0000 
��һ��   0000 0000 0000 0001
�ڶ���   λ������ƶ�һλ������ǰ��ģ��������01  
		 0000 0000 0000 0010
         0000 0000 0000 0011
��n��ͬ��  ����˵ÿһ���������־��� 1 1111.....��һ��1����һ������ƶ�һ���ģ����ܱ�
                       ��С�����־��� 1 0000
���Բ�������Ľ���  << >>�൱�ڳ�2  ��2

������ͼ


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
    //ȷ��returnSize
    while (tmp != 0){
        tmp >>= 1;
        count++;
    }
    *returnSize = count;
    int *ret = (int *)malloc(sizeof(int)*count);
    //��ĩ��λ��ʼд��
    for( int i = count - 1; i > -1;i--){
        ret[i]=label;
        //��label��ֵ����һλ����������
        label >>= 1;
        //��������ʵ����Ŀ�еķ�ת˳�����û�н���˳��Ļ�����Ҫ��һ�������Ϳ��Եõ��丸�ڵ㡣
		/*
			����label = 1000   (int)pow(2, i - 1) - 1 = 111; ���±��֪����bΪ1ʱ��aȡ�� 
			��ֵ�� 
			 a   b   a ^ b
			 1   0     1
	     	(1   1     0)
			 0   0     0
			(0   1     1)

		*/
        label ^= (int)pow(2,i-1)-1; //(int)pow(2,i-1)����˼������һ���ܹ������֣�Ҳ�����ܹ��Ķ�������λ����1���ǳ��˵�һλ��
    }
    return ret;

}

=====================================================================================================================
����һ�ö�����������ÿ������ֵ���� 0 �� 1 ��ÿһ���Ӹ���Ҷ��·��������һ���������Чλ��ʼ�Ķ������������磬���·��Ϊ 0 -> 1 -> 1 -> 0 -> 1����ô����ʾ�������� 01101��Ҳ���� 13 ��

�����ϵ�ÿһƬҶ�ӣ����Ƕ�Ҫ�ҳ��Ӹ�����Ҷ�ӵ�·������ʾ�����֡�

�� 10^9 + 7 Ϊģ��������Щ����֮�͡�

 

ʾ����
		1
	  /   \
     0     1 
	/ \   / \
   0   1 0   1

���룺[1,0,1,0,1,0,1]
�����22
���ͣ�(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

���ҵݹ����¶����

int _sumRootToLeaf(struct TreeNode *root, int num) 
{
    int sum = 0; 
    /**
        ��һ����ɶ��˼�ˣ����ǰ�num������һλ���ճ�����λ����root->val
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
    //�������˼�����жϸ��ڵ��Ƿ���ڣ������������Ľ�������������0
    return root ? _sumRootToLeaf(root, 0) : 0;
}

__________________________________________________________________________________________________________________int num;
���ҵݹ���¶����

int num;
void _sumRootToLeaf(struct TreeNode *root, int sum)
{
    if(root == NULL)
        return;

    sum = (sum << 1) + root->val;
	
    //���ȶ�sum�����ϲ����������������������sum
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


����Ҷ�ڵ�������������
����һ���и��ڵ�Ķ��������ҵ��������Ҷ�ڵ������������ȡ�

����һ�£�


	Ҷ�ڵ� �Ƕ�������û���ӽڵ�Ľڵ�
	���ĸ��ڵ�� ��� Ϊ 0�����ĳһ�ڵ�����Ϊ d���������ӽڵ����Ⱦ��� d+1
	������Ǽٶ� A ��һ��ڵ� S �� ����������ȣ�S �е�ÿ���ڵ㶼���� A Ϊ���ڵ�������У��� A ����ȴﵽ�������¿��ܵ����ֵ��


 

ʾ�� 1��

Ҫע�Ⱑ������ֵ����[1,2,3]������飬����һ������

���룺root = [1,2,3]
�����[1,2,3]


ʾ�� 2��

���룺root = [1,2,3,4]
�����[4]


ʾ�� 3��

���룺root = [1,2,3,4,5]
�����[2,4,5]


//�����dep���Ǵ˽������
//�����fa���Ǽ�¼������֮�� ��ߵ����ұߵĽ��
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
			��Ӧ�����˵�أ�������Щ�൱�ں���������еĻ���
			
		*/
        if (l.dep==r.dep)
        {
            res.dep = l.dep + 1; //��ΪҪ���ݣ����ݵĺ�����������������
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

�ڵ���������֮�������ֵ
�����������ĸ��ڵ� root���ҳ������ڲ�ͬ�ڵ� A �� B ֮������ֵ V������ V = |A.val - B.val|���� A �� B �����ȡ�

����� A ���κ��ӽڵ�֮һΪ B������ A ���κ��ӽڵ��� B �����ȣ���ô������Ϊ A �� B �����ȣ�

 


���룺[8,3,10,1,6,null,14,null,null,4,7,13]
�����7
���ͣ� 
�����д����Ľڵ��������ȵĲ�ֵ������һЩ���£�
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
�����п��ܵĲ�ֵ�У����ֵ 7 �� |8 - 1| = 7 �ó���

class Solution 
{
    int res = Integer.MIN_VALUE;  //�����ʽ�Ĵ����Ǻ���������ˣ���ȫ���д��ڣ��ҿ����޸�
	
	
    public int maxAncestorDiff(TreeNode root) 
	{
        if (root == null) return 0;
        //�����ǰ�ڵ�û���ӽڵ㣬��ֱ�ӷ���
        helper(root, root.val, root.val);
        return res;
    }

    /**
     * ÿ���Ӹ��ڵ㵽Ҷ�ӽڵ��·���е����ֵ����Сֵ���������ֵ����ȫ�ֱ���
     */
    private void helper(TreeNode node, int max, int min) 
	{
        if (node == null) 
			return;
        max = Math.max(node.val, max);
        min = Math.min(node.val, min);
        //����Ҷ�ӽڵ㣬������ֵ
		//��ΪҪ����������Ⱥ�����֮��Ĺ�ϵ�����Ա����ڵ���һ���ߵ�ĩβ�����жϣ�̫������
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
��ת�ȼ۶�����
���ǿ���Ϊ������ T ����һ����ת������������ʾ��ѡ������ڵ㣬Ȼ�󽻻���������������������

ֻҪ����һ�������ķ�ת��������ʹ X ���� Y�����Ǿͳƶ����� X ��ת�ȼ��ڶ����� Y��

��дһ���ж������������Ƿ��Ƿ�ת�ȼ۵ĺ�������Щ���ɸ��ڵ� root1 �� root2 ������

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1 && !root2)
        return true;

    if(root1 == NULL || root2 == NULL || root1->val != root2->val)
        return false;

    return ((flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right)) || (flipEquiv(root1->right,root2->left)&&flipEquiv(root1->left,root2->right))) ;

}

=====================================================================================================================
��ȫ������
����һ����������ȷ�����Ƿ���һ����ȫ��������

�ٶȰٿ��ж���ȫ�������Ķ������£�

��������������Ϊ h������ h ���⣬�������� (1��h-1) �Ľ�������ﵽ���������� h �����еĽ�㶼��������������ߣ��������ȫ����������ע���� h ����ܰ��� 1~ 2h ���ڵ㡣��


ÿ��������ӵĲ�α�����ֻҪ��������������ʱ����һ��һ����ģ����ò��������ֻҪ
�õ������������Ҫ����ӳ��ӵķ���

bool isCompleteTree(struct TreeNode* root) 
{
    struct TreeNode *Queue[2000];
    int front=0,back=0;
    if(root) 
		Queue[back++]=root;
		
    //��α���
    while(front<back)
    {
        int cnt=back-front;//һ��Ľ����Ŀ����һ��Ľ����Ŀ
        for(int i=0;i<cnt;i++)
        {
            //������һ��Ľ�������
			root=Queue[front++];
            if(root)
            {
                Queue[back++]=root->left;
                Queue[back++]=root->right;
            }
            else//���Ϊnullʱ
            {
                while(front<back)//����һ��Ľڵ���ȫ�������ж�
                {
					if(Queue[front++]!=NULL)//���ֲ�Ϊnull�������Ϊfalse
                        return false; 
                }
            }

        }
    }
    return true;
}

��������������������������������������������������������������������������������������������������������������������������������������������������������������������
�����в�α����Ĵ���
���ģ����̫�����ˣ��Լ�����ͼһĿ��Ȼ
֮�����Ҫ����һ��һ��ı����������������������ͷβָ�룬�ȼ�����ڵ㵽�����У�Ȼ���������ڵ�ĺ��ӵ������У�βָ�벻���ƶ�......
���������ȫ��������һ�����ֿգ�����֮���ǿգ�������ֲ��ǿյ�������Ƿ���ȫ������

bool isCompleteTree(struct TreeNode* root) 
{
    struct TreeNode *Queue[200];
    int front=-1,rear=-1;
    Queue[++rear]=root;
    while(front<rear)
    {
        root=Queue[++front];//DeQueue�����й���
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

��ֵ������
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��

bool helper(struct TreeNode* root,int val)
{
	/*
		�ҵ�Ŀ�ľ��ǲ��ϼ��ÿ������ֵ�Ƿ���val��������̿����õݹ���ʵ��
		������ǣ�����false
		��return helper(root->left, val) && helper(root->right, val);
		����Ϳ��ԴﵽĿ��
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
��ת��������ƥ���������
**
    voyage�Ǹ������������������
    root�Ǹ�����һ����
    ���Ƿ���ͨ�������������һ���������Ҷ���ʹ����������������voyage��ƥ��
    �������������뵽returnSize������
    
    ������ԣ��򷵻ط�ת�����нڵ��ֵ���б�����԰��κ�˳�򷵻ش𰸡�
    ������ܣ��򷵻��б� [-1]��

**/


int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int)*voyageSize);
    
    //����������ջ����Ϊ����ͨ��������ģ�ͨ��ָ�����ҵ���һ����㣬����ÿһ������������struct TreeNode *
    //ջ�Ĵ�����ʽ������Ҳ���������鱾�ʾ���ָ�룬����ղ�˵Ҳ��ͨ��ָ��Ѱ�ң�����ջ�����;���struct TreeNode **
    //���������Ļ����Ϳ��԰�ջ�����һ�Ź��ӣ�����������±�����ҵ�������ӣ����ݹ������洢��ĵ�ַ�ֿ����ҵ�������
    //������ڴ����Ϳ��Կ�����stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*voyageSize)
    //�ڴ�ķ�����Ƿ�����ӵĴ�С�������ܹ��Ĵ�С����װ��Ʒ������struct TreeNode *����װ��Ʒ�Ķ���voyageSize����
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*voyageSize);
    int i;
    int top = 0;
    stack[0] = root;
    int flipcunt = 0;
    
    for(i = 0;  i < voyageSize; i++)
    {
        if(top < 0 || stack[top]->val != voyage[i])   //���top < 0��˼����˵���������Һ��Ӷ���voyage����Ĳ����
                                                      //����һ���������������Ͳ����  ������������ǲ����������
													  //���top < 0���Ͳ�������stack[top]->val������ʽ��д��
        {
            ret[0] = -1;
            *returnSize = 1;
            return ret;
        }
        root = stack[top--];
     
        /*
            ��Ϊ��ջ���Ƚ������Ӧ�����ȿ�һ���ڵ�����ӣ��ٿ�һ�������Һ��ӵģ���Ϊջ�պ����෴�����������Һ���
            ����������˼����������������Һ��ӵ�˳���ֵ�պú�voyage��ͬ�����
            ͬ��ע��ѽ��ÿ��if֮����һ��continue����˼����������ֻ��ִ��һ��
        */
        if(NULL != root->left && root->left->val == voyage[i+1])  //�������������Ӳ�Ϊ�գ���������Ӻ�yoyage�е���ͬ
        {
            if(NULL != root->right)  //����������Һ��Ӳ�Ϊ��
            {
                stack[++top] = root->right;  //��ԭ���Ÿ��ڵ�ĵط������Һ���
            }
            stack[++top] = root->left;  //ջ����һλ��������
            continue; //ע�����
        }
        
        /*
            ����������˼����������������Һ��ӵ�˳���ֵ�պú�voyage�෴�����
            ����෴���������Ҫ��ret����
        
        */
        
        if(NULL != root->right && root->right->val == voyage[i+1])  //�����������Һ��Ӳ�Ϊ�գ�������Һ��Ӻ�yoyage�е���ͬ
        {
            if(NULL != root->left)   //������������Ӳ�Ϊ��      
            {
                ret[flipcunt++] = root->val;  
                stack[++top] = root->left;
            }
            stack[++top] = root->right;
            continue; //ע�����
        }        
    }
	
    *returnSize = flipcunt;  //*returnSize�Ƿ����������Ĵ�С
    return ret;

}


=====================================================================================================================
����ƶ����ʹ��ÿ����㶼������һ�����
/*
       ʾ��1�����2
                3         ans = 2      ���� 0
              /   \
             0     0      0 ���� -1    0 ���� -1
          
       ʾ��2�����3
                0         ans = 3      ���� 0
              /   \
             3     0      3 ���� 2���������������ң����Ƶ����ڵ㴦����Ҫ������   0 ���� -1������Ҫһ����ң��Ӹ��ڵ��Ƶ�������Ҫһ����  ������һ�� = 3
       
       ʾ��3�����2
                1         ans = 2      ���� 0
              /   \
             0     2      0 ���� -1    0 ���� 1                 
       
       ʾ��4�����4
                1         ans = 2      ���� 0     ans = 4
              /   \
             0     0      0 ���� 1    0 ���� -1   ans = 2
              \
               3          ���û�з���0   3����2   
*/

int ans;

//�Խ��Ϊ��λ��ȷ���ݹ麯���ĺ���
//�����Ҫ�Ľ����
//L�����Ҫ�Ľ����   R�ұ���Ҫ�Ľ����
int dfs(struct TreeNode* node)
{
    if(node == NULL)
        return 0;

    int L = dfs(node->left);  //�����Ҫ�Ľ����
    int R = dfs(node->right); //�ұ���Ҫ�Ľ����
    int absL = L > 0 ? L : -L;
    int absR = R > 0 ? R : -R;

    ans += (absL + absR);          //��Ҫ�ƶ��Ĳ���
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
    ����������
    ��������壺һ����������ÿ���ڵ��ֵ�������������е��κ�����ֵ��
    ����������ĸ��ڵ� root��
    
	��valֵ���뵽�������
	�����¼��һ����������ѽ
	ֻҪ�漰����������ɾ�͵ü�¼��һ�����

*/


struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
    struct TreeNode *dummy = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    dummy->val = -1;
    dummy->right = root;
    dummy->left = NULL;

    struct TreeNode *prev = dummy;
    struct TreeNode *curr = root;
    
    while(curr != NULL && curr->val > val)  //�ҵ������Ӧ����ӵ�λ��
    {
        prev = curr;  //�����curr����һ�����
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
�����������ֵܽ��
�ڶ������У����ڵ�λ����� 0 ����ÿ�����Ϊ k �Ľڵ���ӽڵ�λ����� k+1 ����

����������������ڵ������ͬ�������ڵ㲻ͬ����������һ�����ֵܽڵ㡣

���Ǹ����˾���Ψһֵ�Ķ������ĸ��ڵ� root���Լ�����������ͬ�ڵ��ֵ x �� y��

ֻ����ֵ x �� y ��Ӧ�Ľڵ������ֵܽڵ�ʱ���ŷ��� true�����򣬷��� false��


//����������e���ڵ�
struct TreeNode* x_f = NULL;
struct TreeNode* y_f = NULL;
bool isCousins(struct TreeNode* root, int x, int y)
{
    int x_depth = find_depth_x(NULL, root, x);
    int y_depth = find_depth_y(NULL, root, y);
    return (x_f != y_f && x_depth == y_depth);
}


/**
	һ�������Է�Ϊ�����֣������  ����   �Һ���
	��������Ĳ����ǶԸ��ڵ�Ĳ���  �ݹ�Ĳ����ǲ�������������Ӻ��к����Ƿ���������
	����ݹ�root->left �����Ϊ��ʱ��˵�����Ӳ��������� 
	����ݹ�root->right �����Ϊ��ʱ��˵���Һ��Ӳ���������
	��󷵻�-1ʱ���������Һ��Ӷ�����������
**/
int find_depth_x(struct TreeNode* f_node, struct TreeNode* root, int node_val)
{
    /*
		��ס��Ѱ�Һͻ��ݵĹ��̿��Կ��������Եģ���Ϊ���Ե�
		����һ��·�ߵ��ڣ����԰������������Ϊ���������һ��·����ô�����˵����·û���ҵ�
		�ͷ���-1��ʾ�����ret = -1�ͱ������������⣬ֻҪһ���ִ���0���������˵����Ҫ��ʼ������	
	*/
	if (root == NULL)  
		return -1;   //Ϊʲô����0��0��ʾ�����0����-1��ʾ�����ȸ���������
    if (root->val == node_val) 
	{
        x_f = f_node;
        return 0;
    }
    int ret;
	//�ҵ�����㣬ֻ��һ��·
    if ((ret = find_depth_x(root, root->left,  node_val)) >= 0) return ret+1;   //�������ֵ�����Һ��ӷ��ظ����ڵ�Ķ���
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
    �������Ĵ������
    ɶ��˼�������Ҷ��ӵ�λ��ȡ�����䣬�������������Χ�ڵĽ���ж��٣��������Χ�ڵĽ����ϵ��������
    ��1��
             3
            / \
           9  20
              / \
             15  7

         ���룺[3,9,20,null,null,15,7]
         �����[[9],[3,15],[20],[7]]
         
    ��2��
                1
              /   \
             /     \
            /       \
           2         3
          / \       / \
         4   5     6   7
         
         ���룺[1,2,3,4,5,6,7]
         �����[[4],[2],[1,5,6],[3],[7]]
    
    ��1��ʹ�ýṹ�壬��ʾ�ڵ��λ�ú�����
    ��2�����ö�ؼ����������Ȱ���x�����������Ȼ����y����������������ֵ��С��������
    ��3�����б���
*/

typedef struct Node
{
    int val;
    int xPos;
    int yPos;
} Node;

int num = 0;

//������
int cmp(const void *temp1, const void *temp2)
{
    Node *node1 = (Node *)temp1;
    Node *node2 = (Node *)temp2;
    if (node1->xPos == node2->xPos)      //������������������ͬ
    {
        if (node1->yPos == node2->yPos)  //��������ͬ
        {
            return node1->val - node2->val; //��������ͬ��������Ҳ��ͬ��������һ���㣬����0
        }
        return node2->yPos - node1->yPos;//�����겻��ͬ�����������С��������
    }
    return node1->xPos - node2->xPos;    //�����겻��ͬ����������Ӵ�С����
}

//��ʼ�� node �� num ��ֵ
void dfs(struct TreeNode *root, int x, int y, Node *node)
{
    if (root == NULL)
    {
        return;
    }
    
    //num��ȫ�ֱ�������ֵΪ0
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
    
    Node *node = (Node *)malloc(sizeof(Node) * 1000);  //������������
    num = 0;
    dfs(root, 0, 0, node);
    
    //����һ��������
    /*
        int (*cmp)(const void *,const void *);
        qsort(*s, n, sizeof(s[0]), cmp);

        ���е�һ������s��һ����ַ��������������׵�ַ��
        n����Ҫ�����������
        sizeof(s[0])����ÿһ��Ԫ��ռ�õĿռ��С��
        ָ������ָ�룬����ȷ�������˳��
    
    */
    //�ź���֮�� num�������ֵ�������Ҵ��ϵ��µ�˳���ź�
    qsort(node, num, sizeof(Node), cmp);
    
    tempXPos = node[0].xPos;
    result = (int **)malloc(sizeof(int *) * num);
    columnSizes = (int *)malloc(sizeof(int)*num);
    
    for (i = 0; i < num; i++)
    {
        if (tempXPos != node[i].xPos)  //i����ǰ������ֵĺ����겻��ͬ
        {
            columnSizes[*returnSize] = i - cur;   //����ÿһ���ж��ٸ�����
            result[*returnSize] = (int *)malloc(sizeof(int) * (i - cur));  //Ӧ�ø���һ�з�������ڴ�  i - cur����һ��Ԫ�صĸ���
            
            m = 0;  //m���ڵڼ���
            for (int j = cur; j < i; j++)  //���ÿ�����ֵ�����
            {
                result[*returnSize][m] = node[j].val;
                m++;
            }
            *returnSize = *returnSize + 1;  //������ڵڼ���
            cur = i;  //cur��ÿ��С��ĵ�һ�������±�  Ҳ���ǵ�һ�������ұ߲���ͬ�ĺ���������ֵ��±�
            tempXPos = node[i].xPos;  //���¸����±�ֵ
        }
    }
    //����������ֵ��12333333  �����һ��ֻ������������б仯���ſ�������������������3��û�������
    columnSizes[*returnSize] = num - cur;   //iֵ��num��ֵ����ͬ�� 
    result[*returnSize] = (int *)malloc(sizeof(int) * (num - cur));
    m = 0;
    for (int j = cur; j < i; j++)   
    {
        result[*returnSize][m] = node[j].val;
        m++;
    }
    *returnSize = *returnSize + 1;  //�����Ǵ�0��ʼ�ģ����յ������Ǵ�1��ʼ�ģ��������������ü�1
    *returnColumnSizes=columnSizes; //����ÿһ���ж��ٸ�����
    free(node);  //�ղŰ������Ҵ��ϵ����ź��������
    return result;
}

=====================================================================================================================
��������֦
https://leetcode-cn.com/problems/binary-tree-pruning/
��������������� root ����������ÿ������ֵҪô�� 0��Ҫô�� 1��

�����Ƴ������в����� 1 ��������ԭ��������

( �ڵ� X ������Ϊ X �����Լ����� X �ĺ����)


void ss(struct TreeNode* root)
{
    /**
        ��Ȼ���������С���ӵ�����
        ���ȣ���һ�� ͨ�����������������ҵ����еĽ��
             �ڶ���  �����������������������д��˼���Ǵ�������   ������д���Ǵ�������
        ss(root->right);  ��һ�����ҵ����н����ҽڵ�
        ss(root->left);   ��һ�����ҵ����нڵ����ڵ�

        �۲������Ŀ  Ӧ��ѡ���������  ���Եݹ�д����  ����ҵ�һ�����������Ϊ0����û�����Һ��ӣ���ɾ�������Ҫɾ�������㣬�͵�ȡ��ַ�������
        ȡ��ַ���͵ø������ĸ��ڵ㣬�������ڵ�ĺ�����ΪNULL����ʽ��������ɾ�������Բ����������ʽ
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
        �Ҷ��ˣ�����Ϊʲô������ַ����Ϊ�������ַ��Ŀ�ľ���Ϊ�˸ı���������������ݣ�Ҳ����Ϊ�˸ı�root��ָ��
        �����ﲢ����Ҫ�ı�root��ָ����Ҫ�ı����root���������ӻ��Һ��ӵ�ָ�򣬿���ֱ�Ӹ�
    */
    ss(root);
    return root;
}


=====================================================================================================================
�����������о���Ϊk�Ľ��

����һ�������������и���� root���� һ��Ŀ���� target ����һ������ֵ K ��
���ص�Ŀ���� target ����Ϊ K �����н���ֵ���б� �𰸿������κ�˳�򷵻ء�
 //�ҵ�������ĸ��׽��
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



//�ҵ������������Ŀ����
//curNode��Ŀ����  distCnt���ߵ���������Ҫ�Ĳ���  returnSize������Ԫ�صĸ���  valK�ǿ����ߵĲ���  distRst�Ǳ������ս��������
void preOrderCnt(struct TreeNode* curNode, int* distCnt, int* returnSize, int valK, int* distRst) 
{
    int tempDist = 0;
    if (curNode == NULL) 
    {
        return;
    }

    (*distCnt)++;      //�ȵ�������Ϊ��������ĺ����о���distCnt
    tempDist = *distCnt;  

    if (*distCnt == (valK + 1))  //��Ϊ�ղŵ�������������valK + 1
    {
        if (*returnSize < 500) 
        {
            distRst[*returnSize] = curNode->val;  //���������ֵ���뵽���������
            *returnSize = *returnSize + 1;        //����ĳ��ȵ���1
        }
    }
    //��Ϊ������ָ�룬��ı�distCnt��ֵ������Ҫ��¼����distCnt֮ǰ��ֵ
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

    getParNode(root, target, &pareNode);  //�ҵ�Ŀ��ڵ�ĸ��ڵ�pareNode����ΪҪ�ı�pareNode��ָ������Ҫȡ��ַ
    tempTarget = target;

    //�ҵ������������Ŀ��ڵ�
	preOrderCnt(target, &distCnt, returnSize, K, distRst);
    distCnt = 0;

    while (pareNode != NULL)  //Ŀ��ڵ�ĸ��ڵ�pareNode��������ڵ��ǿգ��ʹ����Ǹ����
    {
        pareNum++;     //��¼�ߵĲ�������ΪpareNode������e���ڵ㣬��target�ߵ�pareNode��Ҫһ����������֮ǰ��Ҫ����

        //��������Ҹ��ڵ㣬���ڵ�ĸ��ڵ㡣����������ֱ���ҵ���󣬰��������뵽disRst�У�break����
        if (pareNum == K) 
        {
            //returnSizeָ����ǵ�һ������������ݵ�λ��
            distRst[*returnSize] = pareNode->val;
            (*returnSize)++;
            break;
        } 


        //˵�ļ�һ�㣬���Ǵ�����Ҫ��һ��������һ���ſ��Ե���ģ��ȴ������㵽�����ĸ��ڵ㣬�ٴ��������㵽����һ������
		//Ϊɶ��������д�ĺϲ�����Ϊ������(K - pareNum - 1) > 0   �����������right��
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

        //��סpareNode�����ĸ����
        //��һ��������ֵܽ��
        if (pareNode->left == tempTarget && (K - pareNum - 1) > 0)  //�����һ��Ŀ�ľ���k��ȥpareNode->right��һ������˼�������right���µ�
        {
            //�ǵ�֮ǰdisCnt�ֱ���Ϊ0
            preOrderCnt(pareNode->right, &distCnt, returnSize, (K - pareNum - 1), distRst);//���ĸ��������Ǵ������㿪ʼ����Ҫ�ߵĲ���
            distCnt = 0;
        } 
        else if (pareNode->right == tempTarget && (K - pareNum - 1) > 0) 
        {
            preOrderCnt(pareNode->left, &distCnt, returnSize, (K - pareNum - 1), distRst);
            distCnt = 0;
        }
        
        //tempTarget����ԭ�����׵Ľ��
        tempTarget = pareNode;
        pareNode = NULL;   //��Ϊ֮��Ҫ�޸���������������ָ���
        
        //pareNode����tempTarget���׵Ľ��
        getParNode(root, tempTarget, &pareNode);
    }

    return distRst;
}

=====================================================================================================================
�������������С������������һ��������
�����ҵ�����Ľ�㣬������ĸ���
/*
    ��������д�����������������������������������
    �ҵ��뷨��¼��ÿһ��·�ߵĳ��ȣ�����д��ڣ���������·��
    ͬʱ��¼ÿһ�����ĸ��ڵ㣬����·�ߵ�ͬʱ����������ڵ�
*/


�ٲٲ�  ֻҪ�漰���Ҷ��Ӻ͸����ľ������ҷ���¶����ѽ
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
			
         else if(diff > 0)   //˵����ߵ���ȴ����ұߵ����
         {
             return subtreeWithAllDeepest(root->left);
         }
         else               //˵����ߵ����С���ұߵ�e���
         {
            return subtreeWithAllDeepest(root->right);
         }
}

����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
��д�ģ�Ҳ��֪�����

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
Ҷ�����Ƶ���
�ж��������Ĵ����ҵ�Ҷ���Ƿ���ͬ
/*˼·���Ȱ�����root��Ҷ�ӽ��ֱ���������������棬Ȼ���ٱȽ������������Ԫ���Ƿ�һ��*/
void ordertraversal(struct TreeNode* root, int* leaf, int* count)
{
    if(root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            leaf[*count] = root->val;
            (*count)++;
        }
        ordertraversal(root->left, leaf, count); //�����count�Ͳ���&count����Ϊ�����count�൱��ָ����
        ordertraversal(root->right, leaf, count);
    } 
}
    
  
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) 
{
    int leaf1[100] = {0}, leaf2[100] = {0}, i = 0, j = 0, count1 = 0, count2 = 0;
    ordertraversal(root1, leaf1, &count1);  //����һ�㶼Ҫ����ַ��count�ĵ�ַ����ֵ�ͻ����
    ordertraversal(root2, leaf2, &count2); 
    while(i < count1 && j < count2 && count1 == count2 && leaf1[i++] == leaf2[j++]);

    //��Ϊ������������಻��ȣ�i��j��Ҫ����  ����Ҫ�ж�(leaf1[--i] != leaf2[--j])
	//�������һ������1  ��һ������2�Ͳ���
    if((i < count1 || j < count2) || (leaf1[--i] != leaf2[--j])) 
        return false;
    else 
        return true;
}

=====================================================================================================================
����ǰ��ͺ���������������
��׼���ҷ���¶����
struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize)
{
    if (pre == NULL || post == NULL || preSize <= 0)  //preSize��postSize����ȵ�
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
            //�ҵ����������������λ��
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

            �м����ܵ�Ŀ���ǰ�����Ϊ��������������
            ǰ������� 1 2 3 6 | 5 4 9 10 12      1�ұߵ�2��1������
            ���������3 6 2 | 4 10 12 9 5 1       1��ߵ�5��1���Һ���
            i����˼��2�ں�������е�λ�ã�����2
            pre + 1����˼�����������ڵ��λ��  i + 1����˼����������3�����
            pre + i + 2����˼�����������ڵ��λ��  preSize - i - 2����˼����������5�����

        */
        root->left  = constructFromPrePost(pre + 1, i + 1, post, i + 1);
        root->right = constructFromPrePost(pre + i + 2, preSize - i - 2, post + i + 1, preSize - i - 2);
    }
    return root;
}


=====================================================================================================================
���п��ܵ���������
�������ĸ�����������п��ܵ���������
�������
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
    if (N%2 != 0) //���ĸ���������
    {
        for (int i = 1; i < N-1; i += 2) //��Ϊ������������������i += 2;
        {
            //�����ⲽ��ʵ�������������ķ���
            //lForest�����������п�������Ķ�ά����    rForest�����������п�������Ķ�ά����  
            //cntL����������������ĸ���     cntL����������������ĸ��� 
            lForest = allPossibleFBT(i, &cntL);   //������߽��ĸ�����i
            rForest = allPossibleFBT(N - 1 - i, &cntR);  //�ұ߽��ĸ�����N - 1 - i
            sum += cntL * cntR;   //�������  Ŀ����֪����������ڴ�

            newForest = realloc(forest, sum*sizeof(struct TreeNode*));

            if (newForest == NULL)    //�����̬�ڴ����ʧ��
            {
                free(forest);
                return NULL;
            }
            
            //forest�������������Ķ�ά����
            forest = newForest;
            for (int j = 0; j < cntL; j++) 
            {
                for (int k = 0; k < cntR; k++) 
                {
                    //��Ϊ����ֻ��һ��struct TreeNode���ڴ�
                    forest[cnt] = calloc(1, sizeof(struct TreeNode));
                    forest[cnt]->left = lForest[j];
                    forest[cnt]->right = rForest[k];
                    cnt++;
                }
            }
        }
    }
    //���ض�ά���������
    *returnSize = cnt;
    return forest;
}

=====================================================================================================================
//����˳�������
/*
����һ���������������������������ʹ��������ߵĽ�����������ĸ�������ÿ�����û�����ӽ�㣬ֻ��һ�����ӽ�㡣

 

ʾ�� ��

���룺[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

�����[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

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

//����������  ��˵���������ʱ������
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

��������������������������������������������������������������������������������������������������������������������������������������������������������������������
/*
    
	�������
	�����������ý���������
    ������������������˼
    ������������ĵڶ����������������root������һ�����
    �����������˼�����Ȱ�root�������Ū�����ߵģ�Ū�����ߵ�ͬʱ������µ��ұ�Ū��root���ǵ���ָ�룬����root�ͱ������������ߵ���׶�
    ����Ҫ��root��������ó�NULL
    ����Ҫ����root���ұ��ˣ���סpre���������������һ���㣬Ҳ����root�ĸ��ڵ㣬����ұ��ǿյģ������pre������ұ߲��ǿյģ������ұ߱�����ߵ�
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


��������������������������������������������������������������������������������������������������������������������������������������������������������������������
=====================================================================================================================
����¶���� + �ݹ鷨 + ����ж�

//��ס����������������������L �� R��Χ�ڵĺ�
int rangeSumBST(struct TreeNode* root, int L, int R)
{
        //���ģ��Ҿ���һ����������զ�ؾ�û����ˣ�root = NULL��Ҫ����ô�࣬�ͼ�����һ����㣬��������NULL��Ӧ�÷���ɶ����ɶ
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
����������������BST���ĸ��ڵ��һ��ֵ�� ����Ҫ��BST���ҵ��ڵ�ֵ���ڸ���ֵ�Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� NULL��

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    
	//���������߼����һ�£�����һ����㣬����Ҫ�ж��������ǲ��ǿգ��������ж�������������ݺ͸��������಻��ͬ���������ͬ�����������������ÿһ����
	if(root == NULL)
        return NULL;
    if(root->val == val)
        return root;
    else if(root->val > val)
        return searchBST(root->left, val);  //���������������ҵĽ��
    else
        return searchBST(root->right, val); //���������������ҵĽ��
}

=====================================================================================================================
����������������С����
//��������������������Ľ�����Ǵ�С�����˳��
int min;
struct TreeNode* pre;

//�����main����
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
�������������
���ǰ������������������ʱ����ÿһ�е������
/*�����еĽڵ���б�ţ���1��ʼ���սڵ�Ҳ��ţ����ݹ飬��ĳ���ڵ�ı��Ϊn,�����ӽڵ���Ϊ2n��
���ӽڵ�Ϊ2n+1�����ò���ʼ��һ���ǿսڵ�ı�ű���������Ϊj, 
��ò���Ϊk�Ľڵ㣬���߼�Ŀ��Ϊk-j+1���ò����нڵ�Ŀ�����ֵ��Ϊ�ò���*/


#define MAX_INT 2147483648

void getTreeDepath(struct TreeNode* node, unsigned int iDepath, unsigned int *maxDepath)
{
    if(NULL == node) 
        return;
    (*maxDepath) = (*maxDepath) > iDepath ? (*maxDepath):iDepath;

    //�Һ�Ȼ����һ��������������飬��������ҵݹ�֮ǰд�ľ���ǰ���������˼Ҳ���ǲ��Խ���˳�����ǰ������Ľ��
    //��������ͺ������ͬ��
    getTreeDepath(node->left, iDepath+1, maxDepath);
    getTreeDepath(node->right, iDepath+1, maxDepath);
}

void traversalTree(struct TreeNode* node, int *maxWidth, int depath, int index, int a[])
{
    if(NULL == node) 
        return;
    
    //��Ϊ��ǰ�������������depath��û�д�ֵ��ʱ����������Ŀ϶���ÿһ�еĵ�һ��
    if(a[depath] == 0)
    {
        //��������Ŀ�ľ��Ǽ�¼ÿһ�е�һ�������±�
        a[depath] = index;
    }
    
    /*
            1
          /  \
         2   3     3 - 2 = 1    1 + 1 = 2
    */
    int width = index - a[depath] + 1;
    
    //f���������
    *maxWidth = (*maxWidth) > width ? (*maxWidth):width;


    //�����Ŀ���ǿ����������Χ��������������ӵģ�˵�������»���һ�㣬��һ�������Max_INT,�������������m���Ͳ��������ⷵ��
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
    unsigned int maxDepath = 0; //����Ǵ�0��ʼ

    //��������������֮���֪����maxDepath��֪��maxdepth��Ŀ����Ҫ��Ϊ�˷����ڴ�
    getTreeDepath(root, depath, &maxDepath);

    
    //�������Ǵ�0��ʼ��
	a = (int *)malloc((maxDepath+1)*sizeof(int));

    if(NULL == a) 
        return 0;

    //��a������(maxDepath+1)*sizeof(int)��С���ڴ�ȫ����ʼ��Ϊ0����������ĳ�ʼֵ����0
    memset(a, 0, (maxDepath+1)*sizeof(int));

    traversalTree(root, &maxWidth, depath, index, a);

    return maxWidth;
}

=====================================================================================================================
�޼�����������
�Ѳ���L R��Χ�ڵĽ���޼���
//��ס������һ��������������������������������������
/*
    ������������Ϊ�������֣��ֱ��Ǹ���㣬���ӣ��Һ���
    ���������Ŀ�ľ���ȥ�����ڷ�Χ�ڵ�
    �����жϸ�����ڲ��ڷ�Χ��f����������ȷ�ΧС��ֻ�����ұ߲ſ����ڷ�Χ������ұߣ����ͬ��

*/

���ǵ��͵����ҷ���¶����
struct TreeNode* trimBST(struct TreeNode* root, int L, int R)
{
    //Ҫ������������̣�һ���ǽ�����±����Ĺ��̣�Ҳ���������ݹ飬ǰ������Ĺ���
	//һ���ǵݹ������أ�Ҳ���Ǻ�������Ĺ���
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
�������еڶ�С�Ľ��
�Ҹ�����ֵС�ڵ������Ҷ��ӵ�ֵ

/*
	��˵���������ݺᣬ�����ڶ��˵ݹ��ˡ�
	                   1
                     /   \
                    2     5
                  /  \  /  \
                3    6 4    9
                           / \
                          10 12

            �м����ܵ�Ŀ���ǰ�����Ϊ��������������
            ǰ�������1 2 3 6 5  4  9  10 12      
            ���������3 6 2 4 10 12 9  5  1			
			���������3 2 6 1 4  5  10 9 12
	
	�����Ȱѵݹ�ֳ������֣�ǰ�����������  �������������  �������������
	�����Ľ��ֻ�Ǵ����������˳�򣬸�val��ֵ�޹أ�����ֵ����˼���Ǵ������㷵�ص���������һ�������
	ǰ�����ֻ�ǲ���˳��  ��������Ƕ�ֵ����˳��Ҳ������һ�ִӵײ㵽��ͷ��˼�뽫�ײ��ÿһ����������
	���ص����ͳ���ߵľ��ǽ��	
*/

int findSecondMinimumValue(struct TreeNode* root)
{
    return myfun(root, root->val);
}

int myfun(struct TreeNode* root, int val)
{
    //��ʵ��������ж��Ƿ�Ϊ�վͰ������㺬�壬һ����������ڵ��Ϊ�գ�����-1��ʾ����
	//������ڱ��������У���ʾ��һ֧û�ҵ�
	//��һ֧������һ����㿪ʼ������������Ϊ�ջ��Һ���Ϊ��  ��  ���Һ���Ϊ�� ʱ����
	//��ʱ����Ҫ����ֵ���������˼������һ֧Ѱ�ҵĽ�������һֱ��û���ҵ����ͻ�һֱ����=1
	//����ڼ��ҵ��ˣ��ͻ᷵��һ���ض���ֵ
	
	//����ߵ�����Ϊ��ʱ��Ҫ������һ����㣬��������ҪѰ�������Һ���
	//��ʱ��������Ϳ�ʼ���֣������ȿ�ʼ���Ե�����ֵ���ǽ��3�ͽ��6��Ҳ����l��ֵ���ǽ��3���ԵĽ����r���ǽ��6���ԵĽ��
	//�����������ɱȽϵĽ��֮�󷵻ظ�2������һ�����Ե�l��r����2��4��ֱ�����ص�1����


    //���԰��ĵó�һ�����ۣ�ǰ�������Ŀ�ľ��Ǹ�leftһ��ֵ���൱��һ��	
	if(root == NULL)
        return -1;  //��ʾ����
		
	//ֻҪ��һ����val�������϶��ǵ�һ������val����
	
	///д�ڷ���¶����ǰ�������������ʲô����������ʲôֵ
    if(root->val > val)
        return root->val;
    
    /*
        �Բۣ��ҵ����ϣ�������֪���ˣ�ԭ���ݹ���ô��
        ���������ݹ�ǰ�����������������������Ŀ�ľ���Ϊ���ҳ�������������
        �ȸ������

    */
    int l = myfun(root->left, val);
    int r = myfun(root->right, val);
    //����Ǻ�����������������Ŀ�ľ��Ƿ��صڶ�С�Ľ��
    if(l > val && r > val)
    {
        return l > r ? r : l;
    }
    //���û���ҵ��Ƿ���-1�ģ�����Ҫȡ��������ϴ��
	//���ǽ������ȫ��1���ұ��бȽ����
    return l > r ? l : r;
}






=====================================================================================================================

��������
�ڱ�������, ��ָ����һ����ͨ���޻�������ͼ��

����һ��ͼ����ͼ��һ������N���ڵ� (�ڵ�ֵ���ظ�1, 2, ..., N) ������һ�����ӵı߹��ɡ����ӵıߵ��������������1��N�м䣬�������ӵı߲����������Ѵ��ڵıߡ�

���ͼ��һ���Ա���ɵĶ�ά���顣ÿһ���ߵ�Ԫ����һ��[u, v] ������ u < v����ʾ���Ӷ���u ��v������ͼ�ıߡ�

����һ������ɾȥ�ıߣ�ʹ�ý��ͼ��һ������N���ڵ����������ж���𰸣��򷵻ض�ά�����������ֵıߡ��𰸱� [u, v] Ӧ������ͬ�ĸ�ʽ u < v��

ʾ�� 1��

����: [[1,2], [1,3], [2,3]]
���: [2,3]
����: ����������ͼΪ:
  1
 / \
2 - 3


ʾ�� 2��

����: [[1,2], [2,3], [3,4], [1,4], [1,5]]
���: [1,4]
����: ����������ͼΪ:
5 - 1 - 2
    |   |
    4 - 3


ע��:


	����Ķ�ά�����С�� 3 �� 1000��
	��ά�����е�������1��N֮�䣬����N����������Ĵ�С��

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
        �Ҵ�Ŷ��ˣ�
        �ҵ�ʱ���ŵĵ������α�ʾ����˫�����⣬��ʵ��ɲ��ع���˫��ֱ�Ӱ����ĳɵ���
             1
            / \
          2    3

        ��������������ǵ�����2ָ��1����1ָ��2����3ָ��1����1ָ��3  ��ͼ��˵��1ָ��2��1ָ��3
        ����UFSize����˼����������Ķ��Ӹ������ö��Ӹ������ָ����Ӹ����ٵģ�ͬʱ���Ӱ�����UF���óɸ��ڵ�
        ֻҪ�л������ڵ�ͻ��غϣ��������� 
    
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

    //�����������Ĵ�С��2
    * returnSize = 2;
    //��Ϊ��󷵻�����Ĵ�С��2�����Է���Ĵ�СҲ��2
    int *ret = malloc(sizeof(int) * 2);

    //��ʼ��UF[i] = i;   UFSize[i] = 0;
    initialUF(UF, MAXNUM);
    int a = 0;
    int b = 0;

    //edgesSize�����������
    for (i = 0; i < edgesSize; i++) 
    {
        //a�ֱ���ÿһ�е�һ���͵ڶ�������
        a = edges[i][0];
        b = edges[i][1];

        if (!Find(a, b)) //����������ĸ�����һ����
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
����һ�����������ҵ����·�������·���е�ÿ���ڵ������ֵͬ�� ����·�����Ծ���Ҳ���Բ��������ڵ㡣

ע�⣺�����ڵ�֮���·������������֮��ı�����ʾ��

ʾ�� 1:

����:

              5
             / \
            4   5
           / \   \
          1   1   5


���:

2


ʾ�� 2:

����:

              1
             / \
            4   5
           / \   \
          4   4   5


���:

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

            left����˼����ߵ�·���� �� + 1����˼�Ǽ���5-4
			�Ҷ�����������д�����ҷ���¶�ݹ�������Ǵ���ͷ�����ƣ�������֪�ұߺ����
			����Ƴ�root�������root����Ϊ��һ����left��right
			
			arrowLeft �� arrowRight ����ʱ������������ʾ�ص�rootʱ����·���ĳ���
			���������Ϊ0������Ϊ  left / right + 1
        */

        if (node->left != NULL && node->left->val == node->val) 
            arrowLeft += left + 1;
        
        if (node->right != NULL && node->right->val == node->val) 
        {
            arrowRight += right + 1;
        }
		
		//����ans��ֵ
        ans = ans > (arrowLeft + arrowRight) ? ans : (arrowLeft + arrowRight);
		
		//��ס���������߻����ұߵ����ֵ����Ϊ·���϶���һ���ߣ�ֻ��ȡ��߻����ұ�
        return arrowLeft > arrowRight ? arrowLeft : arrowRight;
}






������������������������������������������������������������������������������������������������������������������������������������������������������������������������



=====================================================================================================================
��һ����������
���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������

ʾ�� 1:
�������� s:

     3
    / \
   4   5
  / \
 1   2


�������� t��

   4 
  / \
 1   2


���� true����Ϊ t �� s ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

bool a_gain(struct TreeNode* s,struct TreeNode* t) //��ͬ
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
	
    //�������˼�����п�������������  �п������Ķ��ӷ�������  ���ֻдa_gain����ֻ�����ĸ��ڵ��������
    return a_gain(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);  //��ͬ ���� ����
}



������������������������������������������������������������������������������������������������������������������������������������������������������������������������
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t == NULL)
        return true;
    if(s == NULL || t == NULL)
        return false;

	return ( (s->val == t->val) && isSubtree(s->left, t->left) && isSubtree(s->right, t->right) ) || (isSubtree(s->left, t) || isSubtree(s->right, t));
    
   
}

===========================================================================================================================
���ݶ����������ַ���
����������ʽ�Ķ�����
void travel(struct TreeNode* node, char *val)
{
    char buf[100];
    
    if(!node) 
        return;

    //���Ȳ���ȥ�sprinf��strcat��ɶ��˼����ֻҪ֪�����ǰ�val���ȥ������
    sprintf(buf, "%d", node->val);
    strcat(val, buf);
	
    //process left child and right child
    if(node->left || node->right)
    {
        //�����ߴ��ڻ���߲����ڶ�������������ӵ�
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
�ϲ�������
�������������ص����غϲ������
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
�ڶ����������һ��
ʾ�� 1:

����: 
������������ʾ:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

���: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   



ʾ�� 2:

����: 
������������ʾ:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

���: 
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
struct TreeNode* addOneRow(struct TreeNode* root, int v, int d) //v����ӵ����֣�d����ӵ�����
{
    //t���Ҫ��ӵ����־��ڵ�һ�У�����������óɸ��ڵ㣬�ұ�����Ϊ�գ�ֱ�ӷ���a
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
�������Ĳ�ƽ��ֵ
#define MAXSIZE 1024 
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void dfs(struct TreeNode* root, double *res, int *cnt, int idx, int *returnSize) 
{
    if (root == NULL) 
        return;
    
    res[idx] += (double)root->val;
    cnt[idx]++;
	
	//�����index = 0��Ҫ��Ŀ�ľ���Ϊ�˺�����ƥ�䣬����returnSize�Ǹ����ü�1
    (*returnSize) = MAX(*returnSize, idx + 1);  //��Ϊ����dҪ�ݹ飬��Ҫ���ݣ����ݵ�ʱ��returnsize�ͻ��
    dfs(root->left, res, cnt, idx + 1, returnSize);
    dfs(root->right, res, cnt, idx + 1, returnSize);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    if (root == NULL) 
    {
        *returnSize = 0;
        return NULL;   //���ţ���������������ǿյĻ������ص�������double*��������NULL
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
��������


����һ�������ظ�Ԫ�ص��������顣һ���Դ����鹹�������������������£�


	�������ĸ��������е����Ԫ�ء�
	��������ͨ�����������ֵ��߲��ֹ����������������
	��������ͨ�����������ֵ�ұ߲��ֹ����������������


ͨ�����������鹹�������������������������ĸ��ڵ㡣

 

ʾ�� ��

���룺[3,2,1,6,0,5]
�������������������ĸ��ڵ㣺

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1



struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    //�����������û�����ֵ�ʱ�򣬷��ؿ�
    if(numsSize <= 0) 
    {
        return NULL;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    //��ʼ��ָ������������ַ���
    memset(root, 0, sizeof(sizeof(struct TreeNode)));
    
    int max = 0;  //���ֵ���±�
    //Ѱ�ҳ����ֵ���±�
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
���������
����:
     1
    /
   2
���:
[["", "1", ""],
 ["2", "", ""]]


ʾ�� 2:

����:
     1
    / \
   2   3
    \
     4
���:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]


ʾ�� 3:

����:
      1
     / \
    2   5
   / 
  3 
 / 
4 
���:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]

/*
    C���԰汾�������ĸ߶�m������Ŀ��n=2^��m - 1��-1�� ������ʼ���ַ��������÷���˼������ַ�������
    �����m�Ǵ�1��ʼ��
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
    //�����h�ǿյ����
    if (root == NULL) 
    {
        *returnSize = 0;
        return NULL;
    }

    //m��������ȣ��Ǵ�1��ʼ����
    int m = depthOfTree(root);

    //��������Ŀ�ȣ���ʵ�������㷨��ʽ��2^m-1
    //ע������ƶ�2 << 1, ����4�����Ա�����m�����m - 1
    int n = (2 << (m - 1)) - 1;  
    *returnSize = m;

    //��ʵ���ǲ�������ڴ�����η����
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

    //����n - 1��ָ���һ��Ԫ��
    dfs(root, res, 0, 0, n - 1);
    return res;
}


===========================================================================================================================
����֮��
/*
    ����һ��������������һ��Ŀ�����������������û���������ĺ͵������Ŀ����
    ��Ϊ�Ƕ�����������������������Ľ�����Ǵ�С��������У���ʱ��Ϳ���ʹ��˫ָ��
	��������ķ�����
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
�������½ǵ�ֵ
//����һ�������������������һ���ҵ�����ߵ�ֵ
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
��ÿһ�����ҳ�����ֵ�����뵽һ��������
#define max(a,b)  (a)>(b)?(a):(b)

//���ĸ߶�δ֪��������������ĸ߶ȣ����ո߶ȿ������Ӧ�洢ÿ��max
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

    int h = TreeHeight(root); // �����ĸ߶�
    *returnSize = h;
    // printf("\n%d",INT_MIN);
    int resLevel = 0;
    int *res = (int*)malloc(sizeof(int) * h); // �������飬��Ӧ��¼ÿһ������ֵ
    // (void)memset(res, 0, sizeof(int)*h);  // ��ʼ��0���У�val����Ϊ����
	
    for(int i=0;i<h;i++) 
	{
        res[i] = INT_MIN;
    }
   
    bfs(root, res, resLevel);

	return res;
}

===========================================================================================================================
//��������������С���Բ�
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
�Ѷ���������ת��Ϊ�ۼ���
����һ��������������Binary Search Tree��������ת����Ϊ�ۼ�����Greater Tree)��ʹ��ÿ���ڵ��ֵ��ԭ���Ľڵ�ֵ�������д������Ľڵ�ֵ֮�͡�

���磺

����: ����������:
              5
            /   \
           2     13

���: ת��Ϊ�ۼ���:
             18
            /   \
          20     13

		  13 5 2
/*
    ��������Ǵ�С�������У�������������ǴӴ�С���У���֮ǰ���ۼӣ��ӵ��������ϾͿ���
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
��������ֱ��
/*
����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ�������㡣

ʾ�� :
����������

          1
         / \
        2   3
       / \     
      4   5    


���� 3, ���ĳ�����·�� [4,2,1,3] ���� [5,2,1,3]��

ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��

*/

int calMaxRoot(struct TreeNode* root, int *maxRoot)
{
    if (NULL == root) 
        return 0;
    int lLen = calMaxRoot(root->left, maxRoot);
    int rLen = calMaxRoot(root->right, maxRoot);
    if (lLen + rLen > *maxRoot) 
        *maxRoot = lLen + rLen;
    //�Ҷ��ˣ�Ϊɶ���ص���������������ΪlLen = calMaxRoot(root->left, maxRoot);�������������ľ�����߻��ұ߳��ȵ����ֵ
    return (lLen > rLen ? lLen : rLen) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int maxRoot = 0;
    calMaxRoot(root, &maxRoot);
    return maxRoot;
}

===========================================================================================================================
���������¶�
/*
����һ�����������������������¶ȡ�

һ�����Ľڵ���¶ȶ��弴Ϊ���ýڵ��������Ľ��֮�ͺ����������֮�͵Ĳ�ľ���ֵ���ս��ĵ��¶���0��

�����������¶ȡ����������нڵ���¶�֮�͡�

ʾ��:

����: 
         1
       /   \
      2     3
���: 1
����: 
�����¶� 2 : 0
�����¶� 3 : 0
�����¶� 1 : |2-3| = 1
�����¶� : 0 + 0 + 1 = 1

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
DFS(Depth-First-Search)������������㷨���������㷨��һ�֡�
��һ���ڿ�����������ʹ�ý϶�ķ���������Ŀ����Ҫ�ﵽ�������ṹ��Ҷ��� ��

���ִ�����������Ԫ�غ�
/**
�����������ĸ����ҳ����ִ�����������Ԫ�غ͡�һ����������Ԫ�غͶ���Ϊ�Ըý��Ϊ���Ķ����������н���Ԫ��֮�ͣ�������㱾����Ȼ��������ִ�����������Ԫ�غ͡�����ж��Ԫ�س��ֵĴ�����ͬ���������г��ִ�������Ԫ�أ�����˳�򣩡�

 

ʾ�� 1
����:

  5
 /  \
2   -3


���� [2, -3, 4]�����е�ֵ��ֻ����һ�Σ�������˳�򷵻�����ֵ��

ʾ�� 2
����:

  5
 /  \
2   -5


���� [2]��ֻ�� 2 �������Σ�-5 ֻ���� 1 �Ρ�
 */
#define LEN sizeof(struct myHash)
struct myHash {
    int val;
    int num;
};
int maxNum = INT_MIN;

//��ϣ��Ľ���������
//���õ��Ľ�����Ǻ�  ��  ����������ֵĴ���
void PutInHash(int val, struct myHash *hashSet)
{
    //����������Ľ�������ֱ�ӵ���val % 10000
    int hash = val % 10000;

    //����Ǹ����Ľ�������
    if (val < 0) 
    {
        hash = (-(val + 1)) % 10000;
    }

    //���λ����ǰ�Ѿ���ӹ������������λ���������ĺͲ���val
    while (hashSet[hash].num != 0 && hashSet[hash].val != val) 
    {
        hash++;
        if (hash >= 10000) 
        {
            hash = 0;
        }
    }

    //hash �Ǹ���val���ܺͣ�����ģ�hash��ֳ������� �ܺ�val ����ܺ͵ĸ���
    hashSet[hash].val = val;
    hashSet[hash].num++;

    //������������ֵ
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

    //����������ĩβ�Ǹ��ڵ�
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
    //��hashSet�ṹ���� val �� num ��ֵȫ����ʼ��Ϊ0
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
�����������е�����
/*
    ���ڸ������������
*/

//Ŀ���Ǹ�array��ֵ
void find(struct TreeNode* root, int *array, int *max, int *count, int *data, int *i)
{
    if (!root)
        return ;
    else
    {
        //��������Ľ���Ǵ�С�����˳��
        find(root->left, array, max, count, data, i);

        //count�ʼ��ʼ��Ϊ1�������������Ԫ�صĸ����������һ����data��ֵ��ͬ��count����
        if (root->val == *data) 
        {
            *count = *count + 1;
        }

        //data != -99999��Ҫ��Ϊ�˷�ֹ�ʼ��ʱ��ִ����һ��
        else if (root->val != *data && *data != -99999)
        {
            //�����ֵ�һ��������data��ֵ��ʱ��
            //���count��ֵ����max������Ҫ����֮ǰ������
            if (*count > *max)
            {
                *max = *count;
                *i = 0;
                array[*i] = *data;
                *i = *i + 1;
            }
            //���count��ֵ���ڣ�˵������Ҫ����ֻ��Ҫ��������������
            else if (*count == *max)
            {
                array[*i] = *data;
                *i = *i + 1;
            }
            *count = 1;
        }

        //�ʼ��ʱ��ִ�е�����һ������data��ֵ
        *data = root->val;
        find(root->right, array, max, count, data, i);
    }
}

int* findMode(struct TreeNode* root, int* returnSize)
{
    //���ڵ�Ϊ�յ����
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int *array = malloc(sizeof(int) * 10000);
    int i, max = 0, count = 1, data = -99999;
    find(root, array, &max, &count, &data, &i);

    //���һ�ε����ȥ
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
����Ҷ֮��
    3
   / \
  9  20
    /  \
   15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24

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
�Ҿ�������д���Щ

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
·���ܺ�
����һ��������������ÿ����㶼�����һ������ֵ��

�ҳ�·���͵��ڸ�����ֵ��·��������

·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��

������������1000���ڵ㣬�ҽڵ���ֵ��Χ�� [-1000000,1000000] ��������

ʾ����

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

���� 3���͵��� 8 ��·����:

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
    //ע�⣺������и�����
    if(root == NULL) 
        return;

    sum -= root->val;
    if(sum == 0)
        pathnumber++;           
    
    Sum(root->left,sum);
    Sum(root->right,sum);




===========================================================================================================================
/*
        ɾ�������������еĽ��
����һ�������������ĸ��ڵ� root ��һ��ֵ key��ɾ�������������е� key ��Ӧ�Ľڵ㣬����֤���������������ʲ��䡣���ض������������п��ܱ����£��ĸ��ڵ�����á�

һ����˵��ɾ���ڵ�ɷ�Ϊ�������裺


	�����ҵ���Ҫɾ���Ľڵ㣻
	����ҵ��ˣ�ɾ������


˵���� Ҫ���㷨ʱ�临�Ӷ�Ϊ O(h)��h Ϊ���ĸ߶ȡ�

ʾ��:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

������Ҫɾ���Ľڵ�ֵ�� 3���������������ҵ� 3 ����ڵ㣬Ȼ��ɾ������

һ����ȷ�Ĵ��� [5,4,6,2,null,null,7], ����ͼ��ʾ��

    5
   / \
  4   6
 /     \
2       7

��һ����ȷ���� [5,2,6,null,4,null,7]��

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
        ɶ��˼���ⲻͬ��root->left = deleteNode(root->left, key);   root->right = deleteNode(root->right, key);
        ���д������������������������ִ��  ��������������ʽд����ִֻ��һ�� ��ʵ�����ҳ�һ���Ӹ���㿪ʼһֱ����ɾ������һ����
        ���ؾ���  ������һ��������������������  ����Ϊ�����ں�����������Է��ص���root���
    
    */
    //��ɾ���ڵ�Ϊ�յ����
	
	//returnӦ���Ƿ���ɾ����Ľ��
    if (root == NULL) 
    {
        return NULL;
    } 

    if (key < root->val) 
    {
        // ��ɾ���ڵ�����������
        root->left = deleteNode(root->left, key);
        return root;
    } 
    else if (key > root->val) 
    {
        // ��ɾ���ڵ�����������
        root->right = deleteNode(root->right, key);
        return root;
    } 

    //�ҵ���Ҫɾ���Ľ��
    else 
    {
        // key == root.val��root Ϊ��ɾ���ڵ�
        if (root->left == NULL) 
        {
            // ������������Ϊ�µĸ�
            return root->right;
        } 
        else if (root->right == NULL) 
        {
            // ������������Ϊ�µĸ�
            return root->left;
        } 
        else 
        {
            // �������������ڣ����غ�̽ڵ㣨����������Ҷ�ӣ���Ϊ�µĸ�
            struct TreeNode* successor = min(root->right);
            successor->right = deleteMin(root->right);
            successor->left = root->left;
            return successor;
        }
    }
}


===========================================================================================================================
��ҽ���

/*
���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ�����
�������ֻ��һ����ڣ����ǳ�֮Ϊ�������� 
���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮������
һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö��������� 
�������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������

�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�

ʾ�� 1:

����: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

���: 7 
����: С͵һ���ܹ���ȡ����߽�� = 3 + 3 + 1 = 7.

ʾ�� 2:

����: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

���: 9
����: С͵һ���ܹ���ȡ����߽�� = 4 + 5 = 9.

*/


#define MAX(a,b) (a>b?a:b)
int rob(struct TreeNode* root)
{
    //����ǿյ����
    if (root == NULL) 
    {
        return 0;
    }

    /*
        �ô��������˽���һ�������Ϊʲô��
        ����������߼�����������ݹ�����Ǯ����
        ����ְֵ�Ǯ  ��   үү�Ͷ��ӵ�Ǯ
        �Ƚ�
        ��ΪҪ͵����Ǯ������Ҫ��������֮�������Ǹ�
    */
    //�ְֵ�Ǯ
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

    //үү�����ӵ�Ǯ
    steal = root->val + stealLeft + stealRight;
    return MAX(notSteal, steal);
}


===========================================================================================================================

�����������е�kС��Ԫ��

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
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶���������:  root = [6,2,8,0,4,7,9,null,null,3,5]

                 6
            /        \
          2           8
        /   \       /  \
      0     4      7   9
          /  \
        3    5

 

ʾ�� 1:

����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
���: 6 
����: �ڵ� 2 �ͽڵ� 8 ��������������� 6��


ʾ�� 2:

����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
���: 2
����: �ڵ� 2 �ͽڵ� 4 ��������������� 2, ��Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��


*/

/*
���ö������������ص㣬���p��q��ֵ��С��root��˵��p q �϶���root���������У����p q������root��˵���϶���root���������У����һ������һ������ ��˵����ʱ��root��Ϊ��Ӧ�������������
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
�������������������
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    /*
        ̫���ˣ��������������£����Ƚ�������������Ƕ�h��������жϣ�����������������⣬ֱ�ӷ���
        ��������㲻�������⣬ȥ��������ߺ��ұ������������⣬�������ߺ��ұ߶������㣬���ؿ�
        ���һ�����ڣ���һ���գ�˵���������㶼�ڴ��ڵ��Ǳ�   
    */
	
    if (root == NULL) 
    {
        return NULL;
    }

    //�������ҵ��˻��ұ��ҵ��ˣ������ҵ��˵ĸ��ڵ�
    if (root == p || root == q) 
    {
        return root;
    }

    //�ҵ�������ұߵ�  ��  ��ߵģ� �ݹ麯������д�ŵ��ǵݹ���ֹ����  �� �ݹ麯������д���Ƿ�����һ�����ġ�
    struct TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    //�����NULL�ʹ���û�ҵ�����˼����left��rightû�ҵ�����ô����right��left
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
	
    //������߶�û�ҵ������ؿ�
    return NULL;
}


===========================================================================================================================
��ȫ�������н��ĸ���
int countNodes(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);

}

===========================================================================================================================
������������ͼ

/*
����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

ʾ��:

����: [1,2,3,null,5,null,4]
���: [1, 3, 4]
����:

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
����������
/*
ʵ��һ���������������������㽫ʹ�ö����������ĸ��ڵ��ʼ����������

���� next() �����ض����������е���һ����С������

ʾ����
          7
       /     \
     3       15
           /   \
          9    20



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // ���� 3
iterator.next();    // ���� 7
iterator.hasNext(); // ���� true
iterator.next();    // ���� 9
iterator.hasNext(); // ���� true
iterator.next();    // ���� 15
iterator.hasNext(); // ���� true
iterator.next();    // ���� 20
iterator.hasNext(); // ���� false


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

//�ȿ���������������һ����Ŀ�ľ��Ǵ�����һ���ṹ�������˷������������ֵ��Ԫ�صĸ���
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

//ʵ��ջ��Ԫ�صĳ�ջ
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
��������ǰ�����
�����㷨
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

�����Ҷ�ӽ������֮��
/*
����һ��������������ÿ����㶼���һ�� 0-9 �����֣�ÿ���Ӹ���Ҷ�ӽڵ��·��������һ�����֡�

���磬�Ӹ���Ҷ�ӽڵ�·�� 1->2->3 �������� 123��

����Ӹ���Ҷ�ӽڵ����ɵ���������֮�͡�

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ�� 1:

����: [1,2,3]
    1
   / \
  2   3
���: 25
����:
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12.
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13.
��ˣ������ܺ� = 12 + 13 = 25.

ʾ�� 2:

����: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
���: 1026
����:
�Ӹ���Ҷ�ӽڵ�·�� 4->9->5 �������� 495.
�Ӹ���Ҷ�ӽڵ�·�� 4->0 �������� 40.
��ˣ������ܺ� = 495 + 491 + 40 = 1026.

*/


//n�������������ǰ������֮��
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
��ǰ�������������й��������

/*
���磬����

ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]

�������µĶ�������

    3
   / \
  9  20
    /  \
   15   7

*/

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode* result = NULL;
    
    if(preorder == NULL || preorderSize == 0)   //preorder�൱��ÿ�εݹ����ֹ����  preorderSize�൱�����������������ǿյ����
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
������ͺ���������й��������
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    struct TreeNode* result = NULL;
    
    if(postorder == NULL || postorderSize == 0)   //preorder�൱��ÿ�εݹ����ֹ����  preorderSize�൱�����������������ǿյ����
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
·���ܺ�
/*
����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����
*/

typedef struct TreeNode* Node;
//�ݹ飬�Ƚ���ʱ·��������������temp�У������·��������������ڽ����
void search(Node root,int sum,int* returnSize, int** returnColumnSizes,int **result,int *temp,int now)
{
    if(root == NULL)  
        return;     //�ݹ��������
    if(root->left == NULL && root->right == NULL && sum == root->val)     //����Ҷ�ڵ㲢�������������
    {
        temp[now++] = root->val;
        int c = *returnSize;
        (*returnColumnSizes)[*returnSize] = now;    //���е�����
        result[c] = (int*)malloc(sizeof(int)*now);

        for(int i = 0 ;i < now ;++i)
            result[c][i] = temp[i];
        ++(*returnSize);    //������һ
    }
    temp[now++] = root->val;
    sum -= root->val;
    search(root->left,sum,returnSize,returnColumnSizes,result,temp,now);    //�ݹ�
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
������չ��Ϊ����
/*
����һ����������ԭ�ؽ���չ��Ϊ����

���磬����������

    1
   / \
  2   5
 / \   \
3   4   6

����չ��Ϊ��

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
//�������Ĳ�α���
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int **res = malloc(sizeof(int*) * 1000); //�������
    for(int i = 0; i < 1000; i++) //ȫ����ʼ��Ϊ1�������Ԫ�ء��Ա����ͳ��ÿ���м���
    {
        res[i] = malloc(sizeof(int) * 200);
        for(int j = 0; j < 200; j++)
            res[i][j] = -929;
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    order(root, 0, res); //�ݹ�


    for(int i = 0; i < 1000; i++) //ȷ������Ԫ��ÿһ��Ŀ��
    {
        if(res[i][0] == -929) //���ĳһ���һ����������Ԫ�أ�����һ�㶼û�д����ݣ�������
        {
            *returnSize = i;
            break;
        }
        for(int j = 0; j < 200; j++) //ͳ��ÿһ���ж���Ԫ�ش���
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

//���ص㿴������裬����������֮��Ϳ��԰�ÿһ�е��������뵽������
void order(struct TreeNode* root,int k,int** res) 
{
    if(root == NULL)
        return;
		
    for(int i = 0; i < 1000; i++) //����һ��δ���λ�����뵱ǰֵ
    {
        if(res[k][i] == -929)
        {
            res[k][i] = (root->val);
            break;  //ע�����break
        }
    }
    order(root->left, k+1, res); //�ݹ����ӽڵ�
    order(root->right, k+1, res);  //�ݹ����ӽڵ�
}



===========================================================================================================================
��֤����������

//low��high�Ǹ��ڵ�root->val�ķ�Χ
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




























