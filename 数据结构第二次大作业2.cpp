/*判别回文字符串*/
#include<stdio.h>
#include<stdlib.h>
#define size 100

typedef struct Queue
{
	int front;     //记录最前面数字所在下标 
	int rear;      //记录最后一个有效数字的下一个坐标 
	int arr[size]; 
}Queue, *LinkQueue;

typedef struct Stack
{
	int head;
	int tail;
	int arr[size];
}Stack, *LinkStack;

//队列初始化函数 
void queue_init(LinkQueue p)
{
	p->front = 0;
	p->rear = 0;
}

//判断队列是否为空
int queue_empty(LinkQueue p)
{
	return !(p->rear - p->front);
} 

//判断队列是否已满
int queue_full(LinkQueue p) 
{
	return p->rear >= size; 
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
		p->rear++;
		return 1;
	}
} 

//从队列里取出数字
int queue_pop(LinkQueue p)
{
	int num;
	if (queue_empty(p))
	{
		printf("队列为空\n");
		return 0;
	}
	else
	{
		num = p->arr[p->front];
		p->front++;
		return num;
	}
} 

//获取队头的数字
int queue_front(LinkQueue p)
{
	if (queue_empty(p))
	{
		printf("队列为空\n");
		return 0;
	}
	else
	{
		return p->arr[p->front];
	}
} 

//初始化栈 
void stack_init(LinkStack s)
{
	s->head = 0;
	s->tail = 0;
}

//判断栈是否为空
int stack_empty(LinkStack s)
{
	if (s->head == s->tail)
	    return 1;
	else
	    return 0;
} 

//判断栈是否已满
int stack_full(LinkStack s) 
{
	return s->tail - s->head >= size; 
}

//入栈
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

//出栈
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

//取栈顶元素
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
	    printf("是一个回文字符串\n");
	else
	    printf("不是一个回文字符串\n");
	return 0;
}  
 




