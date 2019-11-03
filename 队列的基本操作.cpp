/*队列的基本操作*/
#include<stdio.h>
#include<stdlib.h>
#define size 100

typedef struct Queue
{
	int front;     //记录最前面数字所在下标 
	int rear;      //记录最后一个有效数字的下一个坐标 
	int arr[size]; 
}Queue, *LinkQueue;

//队列初始化函数 
void queue_init(LinkQueue p)
{
	p->front = 0;
	p->rear = 0;
}

//队列的清理函数 
void queue_deinit(LinkQueue p)
{
	p->front = 0;
	p->rear = 0;
} 

//计算队列中结点个数
int queue_size(LinkQueue p) 
{
	retur (p->rear - p->front);
}

//判断队列是否为空
int queue_empty(LinkQueue p)
{
	return !(p->rear - p->front);
} 

//判断队列是否已满
int queue_full(LinkQueue p) 
{
	return p->rear >= p->front; 
}

//向队列里加入数字
int queue_push(LinkQueue p, int val)
{
	if (queue_full(p))
	{
		return 0;
	}
	else
	{
		p->arr[p->rear] = val;
		p->rear ++;
		return 1;
	}
} 

//从队列里取出数字
int queue_pop(LinkQueue p, int *num)
{
	if (queue_empty(p))
	{
		return 0;
	}
	else
	{
		*num = p->arr[p->front];
		p->front++;
		return 1;
	}
} 

//获取队头的数字
int queue_front(LinkQueue p, int *num)
{
	if (queue_empty(p))
	{
		return 0;
	}
	else
	{
		*num = p->arr[p->front];
		return 1;
	}
} 
 




