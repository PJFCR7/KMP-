#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int num;
	struct Node* next;
}node, *p;

void createlist(p *headptr, int n, int x);//����������ʹ���Ϊx����Ϊ��һ���ڵ� 
int ysf(int y, int n, int x);//ʵ��Լɪ�� 

int main(void)
{
	int x,y,n,i,j;
	printf("���������������n��");
	scanf("%d", &n);
	printf("nΪ�����Ӷ�Ա������xΪ��ʼ�������˵ı�ţ�yΪÿ��ѭ����\n");
	printf("1�Ŷ�Ա���������������ǣ�\n");
	for(i = 1; i <= n; i++)
	{
		y = i;
		for(j = 1; j <= n; j++)
		{
			x = j;
			if(ysf(y,n,x) == 1)
			printf("n = %d x = %d y = %d\n",n,x,y);
		}
	}
	
}

void createlist(p *headptr, int n, int x)
{
	int i;
	p current, head;
	*headptr = (p)malloc(sizeof(node));
	head = *headptr;
	
	/*Ϊÿһ�������*/
	for(i = 1; i <= n; i++)
	{
		current = (p)malloc(sizeof(node));
		current->num = i;
		head->next = current;
		head = current; 
	}
	current->next = (*headptr)->next;
	
	/*���Ϊx����Ϊ��һ���ڵ� */
	for(i = 0; i < n; i++)
	{
		if(current->num == x)
		{
			(*headptr)->next = current;
			break;
		}
		else
		current = current->next;
	}
}

int ysf(int y, int n, int x)
{
	int i,j;
	p head, current, prev;
	createlist(&head, n, x);
	current = head->next;
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < y - 1; j++)
		{
			current = current->next;
		}
		/*ɾ�����n*/
		//����n+1����㸴�Ƶ���n������ϣ���n�����ͱ���˵�n+1����� 
		prev = current->next ;
		current->num = current->next->num;
		current->next = current->next->next;
		free(prev);//�ͷŵ�n+1����� 
	}
	return current->num;
}


