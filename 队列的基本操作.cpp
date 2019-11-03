/*���еĻ�������*/
#include<stdio.h>
#include<stdlib.h>
#define size 100

typedef struct Queue
{
	int front;     //��¼��ǰ�����������±� 
	int rear;      //��¼���һ����Ч���ֵ���һ������ 
	int arr[size]; 
}Queue, *LinkQueue;

//���г�ʼ������ 
void queue_init(LinkQueue p)
{
	p->front = 0;
	p->rear = 0;
}

//���е������� 
void queue_deinit(LinkQueue p)
{
	p->front = 0;
	p->rear = 0;
} 

//��������н�����
int queue_size(LinkQueue p) 
{
	retur (p->rear - p->front);
}

//�ж϶����Ƿ�Ϊ��
int queue_empty(LinkQueue p)
{
	return !(p->rear - p->front);
} 

//�ж϶����Ƿ�����
int queue_full(LinkQueue p) 
{
	return p->rear >= p->front; 
}

//��������������
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

//�Ӷ�����ȡ������
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

//��ȡ��ͷ������
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
 




