#include<stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

bool judge(char A[]);

int main(void) 
{
	char A[10000];
	scanf("%s",A);
	judge(A);
	return 0;
} 

bool judge(char A[])
{
	int countI = 0;
	int countO = 0;
	int i;
	
	for(i = 0; A[i] != '\0'; i++)
	{
		if(A[i] == 'I')
		{
			countI++;
		}
		
		else
		{
			countO++;
			if(countO > countI)
			{
				printf("�Ƿ�����\n");
				return false;
			}
		}
	}
	
	printf("�Ϸ�����\n");
	return true;
}
