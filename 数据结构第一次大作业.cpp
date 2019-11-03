#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int num;
	struct Node* next;
}node, *p;

void createlist(p *headptr, int n, int x);//创建链表，并使编号为x的人为第一个节点 
int ysf(int y, int n, int x);//实现约瑟夫环 

int main(void)
{
	int x,y,n,i,j;
	printf("请输入敢死队人数n：");
	scanf("%d", &n);
	printf("n为敢死队队员人数，x为开始计数的人的编号，y为每次循环数\n");
	printf("1号队员能留在最后的条件是：\n");
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
	
	/*为每一个结点编号*/
	for(i = 1; i <= n; i++)
	{
		current = (p)malloc(sizeof(node));
		current->num = i;
		head->next = current;
		head = current; 
	}
	current->next = (*headptr)->next;
	
	/*编号为x的人为第一个节点 */
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
		/*删除结点n*/
		//将第n+1个结点复制到第n个结点上，第n个结点就变成了第n+1个结点 
		prev = current->next ;
		current->num = current->next->num;
		current->next = current->next->next;
		free(prev);//释放第n+1个结点 
	}
	return current->num;
}


