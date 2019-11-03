/*栈的基本操作*/
#include<stdio.h> 
#include<stdlib.h>
typedef struct Stack
{
	int data;
	struct Stack * next;
}Stack, *LinkStack;

//初始化栈 
LinkStack stack_init()
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(Stack));
	p = NULL;
	return p;
}

//入栈
LinkStack stack_push(LinkStack head, int x)
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(Stack));
	
	if (p == NULL)
	{
		printf("分配内存失败\n");
		return head;
	}
	else
	{
		p->data = x;
	    p->next = head; 
	    return p;
	}
} 

//出栈
LinkStack stack_pop(LinkStack head)
{
	LinkStack p;
	p = head;
	
	if (p == NULL)
	{
		printf("栈为空！\n");
	}
	else
	{
		p = p->next;
		free(head);
	}
	return p;
} 

//取栈顶元素
int stack_gettop(LinkStack head)
{	
	if (head == NULL)
	{
		printf("栈为空！\n");
		return -1;
	}
	else
	{
		return head->data;
	}
} 

//判断栈是否为空
int stack_empty(LinkStack head)
{
	if (head == NULL)
	    return 1;
	else
	    return 0;
} 

//显示栈元素
void stack_display(LinkStack head)
{
	LinkStack p;
	p = head;
	if (p == NULL)
	{
		printf("栈为空！\n");
	}
	else
	{
		while(p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}

//释放栈
LinkStack stack_setnull(LinkStack head)
{
	LinkStack p;
	p = head;
	while(p != NULL)
	{
		p = p->next;
		free(head);
		head = p;
	}
	return head;
} 





