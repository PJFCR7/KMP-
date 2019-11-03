/*ջ�Ļ�������*/
#include<stdio.h> 
#include<stdlib.h>
typedef struct Stack
{
	int data;
	struct Stack * next;
}Stack, *LinkStack;

//��ʼ��ջ 
LinkStack stack_init()
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(Stack));
	p = NULL;
	return p;
}

//��ջ
LinkStack stack_push(LinkStack head, int x)
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(Stack));
	
	if (p == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return head;
	}
	else
	{
		p->data = x;
	    p->next = head; 
	    return p;
	}
} 

//��ջ
LinkStack stack_pop(LinkStack head)
{
	LinkStack p;
	p = head;
	
	if (p == NULL)
	{
		printf("ջΪ�գ�\n");
	}
	else
	{
		p = p->next;
		free(head);
	}
	return p;
} 

//ȡջ��Ԫ��
int stack_gettop(LinkStack head)
{	
	if (head == NULL)
	{
		printf("ջΪ�գ�\n");
		return -1;
	}
	else
	{
		return head->data;
	}
} 

//�ж�ջ�Ƿ�Ϊ��
int stack_empty(LinkStack head)
{
	if (head == NULL)
	    return 1;
	else
	    return 0;
} 

//��ʾջԪ��
void stack_display(LinkStack head)
{
	LinkStack p;
	p = head;
	if (p == NULL)
	{
		printf("ջΪ�գ�\n");
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

//�ͷ�ջ
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





