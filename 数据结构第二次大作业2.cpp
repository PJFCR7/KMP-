/*�б�����ַ���*/
#include<stdio.h>
#include<stdlib.h>
#define size 100

typedef struct Queue
{
	int front;     //��¼��ǰ�����������±� 
	int rear;      //��¼���һ����Ч���ֵ���һ������ 
	int arr[size]; 
}Queue, *LinkQueue;

typedef struct Stack
{
	int head;
	int tail;
	int arr[size];
}Stack, *LinkStack;

//���г�ʼ������ 
void queue_init(LinkQueue p)
{
	p->front = 0;
	p->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
int queue_empty(LinkQueue p)
{
	return !(p->rear - p->front);
} 

//�ж϶����Ƿ�����
int queue_full(LinkQueue p) 
{
	return p->rear >= size; 
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
		p->rear++;
		return 1;
	}
} 

//�Ӷ�����ȡ������
int queue_pop(LinkQueue p)
{
	int num;
	if (queue_empty(p))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	else
	{
		num = p->arr[p->front];
		p->front++;
		return num;
	}
} 

//��ȡ��ͷ������
int queue_front(LinkQueue p)
{
	if (queue_empty(p))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	else
	{
		return p->arr[p->front];
	}
} 

//��ʼ��ջ 
void stack_init(LinkStack s)
{
	s->head = 0;
	s->tail = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int stack_empty(LinkStack s)
{
	if (s->head == s->tail)
	    return 1;
	else
	    return 0;
} 

//�ж�ջ�Ƿ�����
int stack_full(LinkStack s) 
{
	return s->tail - s->head >= size; 
}

//��ջ
int stack_push(LinkStack s, int x)
{
	if (stack_full(s))
	{
		return 0;
	}
	else
	{
		s->arr[s->tail] = x;
	    s->tail++;
	    return 1;
	}
} 

//��ջ
int stack_pop(LinkStack s)
{
	if (stack_empty(s))
	{
		return 0;
	}
	else
	{
		s->tail--;
		return 1;
	}
	
} 

//ȡջ��Ԫ��
int stack_gettop(LinkStack s)
{	
	if (stack_empty(s))
	{
		return -1;
	}
	else
	{
		return s->arr[s->tail];
	}
} 

int main()
{
	char ch;
	int isok = 1;
	LinkStack s;
	LinkQueue t;
	//printf("dfsdd\n");
	queue_init(t);
	stack_init(s);
	while ((ch = getchar()) != '\n')
	{
		stack_push(s,ch - '0');
		queue_push(t,ch - '0');
	}
	stack_pop(s);
	while (!stack_empty(s))
	{
		if (stack_gettop(s) != queue_front(t))
		{
			isok = 0;
			break;
		}
		else
		{
			stack_pop(s);
			queue_pop(t);
		}    
	}
	
	if (isok)
	    printf("��һ�������ַ���\n");
	else
	    printf("����һ�������ַ���\n");
	return 0;
}  
 




