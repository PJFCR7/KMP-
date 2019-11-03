#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int KMP(char str[],char substr[],int next[]);
void getnext(char substr[],int *next);

//KMP
int KMP(char str[],char substr[],int next[])
{
	int i = 0,j = 0;
	int n = strlen(str);
	int m = strlen(substr);
	while(i < n && j < m)
	{
		if(j == -1 || str[i] == substr[j])
		{
			++i;
			++j;
		}
		else{
			j = next[j];//匹配失败,i从下一个位置开始
		}
	}

	if(j == m)
	{	
		return i-m+1;
	}
	else
		return 0;
}
 
//求next数组
void getnext(char substr[],int next[])
{
	
	int i = 0,j = -1;
	next[0] = -1;
	while(i < strlen(substr))
	{
		if(j == -1 || substr[i] == substr[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
 
int main()
{
	char str[100],substr[100];
	int next[100] ;
	int result;
	scanf("%s",str);
	scanf("%s",substr);
	getnext(substr,next);//根据模式串求next数组
	//字符串简单匹配
	result = KMP(str,substr,next);
	printf("%d\n",result);
 
	return 0;
}
