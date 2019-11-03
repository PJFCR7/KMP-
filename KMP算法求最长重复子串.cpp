/* 字符串ababababab中最长重复子串为ababab*/ 

#include<stdio.h>
#include<string.h>
#define  n 10000	

int next[n];
int getnext(char str[]); 

int main(void)
{
	char str[n];
	
	scanf("%s", str);
	printf("%d\n", getnext(str));
	
	return 0;
}

int getnext(char str[])
{
	int i = 0;
	int j = -1;
	int max = 0;
	next[0] = -1;
	
	while(i < strlen(str))
	{
		if( j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			next[i] = j;
			if(max < j)
			{
				max = j;
			}
		}
		else
		{
			j = next[j];
		}
	}

	return max;
}





