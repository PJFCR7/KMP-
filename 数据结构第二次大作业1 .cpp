/* 2/8����ת��*/
//˼·�������Ƚ�����������ջ��
//Ȼ���ڳ�ջ��ͬʱ��ջ��Ԫ�س���Ȩ����� 
#include<stdio.h> 
#include<stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack * next;
}Stack, *link;

link init()
{
	link p;
	p = (link)malloc(sizeof(Stack));
	p = NULL;
	return p;
} 

link push(link head, int x)
{
	link p;
	p = (link)malloc(sizeof(Stack));
	if (p == NULL)
	{
		printf("����ռ�ʧ��\n");
		return head;
	}
	else
	{
		p->data = x;
	    p->next = head;
	    return p;
	}
}

link pop(link head)
{
	link p;
	p = head;
	if (p == NULL)
	{
		printf("ջΪ�գ�\n");
	}
	else
	{
		p = p->next;
		free(head);
		head = p;
	}
}

int empty(link head)
{
	if (head == NULL)
	    return 1;
	else
	    return 0;
}

int gettop(link head)
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

//��ʾջԪ��
void display(link head)
{
	link p;
	p = head;
	if (p == NULL)
	{
		printf("ջΪ�գ�\n");
	}
	else
	{
		while(p != NULL)
		{
			printf("%d", p->data);
			p = p->next;
		}
	}
	printf("\n");
}

int pow(int x, int y)
{
	int i; 
	int result = 1;
	if (y == 0)
	    return 1;
	else
	{
		while(y)
		{
			result *= x;
			y--;
		}
		return result;
	}
}
/**************************************
                 2-->8 
***************************************/
/*int main(void)
{
	link s;
	s = init();
	int i = 0;
	int result = 0;
	char ch;
	
	while ((ch = getchar()) != '#')
	{
		s = push(s,ch - '0');
	}
	
	while (!empty(s))
	{
		result += gettop(s) * pow(2,i); //2^i���� 
		i++;
		s = pop(s);
	}
	
	printf("%d\n", result);
	return 0;
}*/

/**************************************
                 10-->8
***************************************/
int main(void)
{
	int n;//ʮ������
	scanf("%d", &n);
	link s;
	s = init();
	while ((n))
	{
		s = push(s,n%8);
		n /= 8;
	} 
    display(s);
	return 0;
} 
