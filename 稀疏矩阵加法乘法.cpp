#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
using namespace std;

typedef int ElemType;

struct tuple
{
	int row;
	int col;
	ElemType value;
};

typedef struct 
{
	int row;
	int col;
	int num;
	struct tuple data[Maxsize];
} Matrix;

void CreateMat(Matrix *A, int a[Maxsize][Maxsize]);
void JudgeAddMat(Matrix *A, Matrix *B, Matrix *C); 
void JudgeMulMat(Matrix *A, Matrix *B, Matrix *D);
void DisplayMat(Matrix *A);

int main(void)
{
	Matrix *A, *B, *C, *D;
	A = (Matrix*)malloc(sizeof(Matrix));
	B = (Matrix*)malloc(sizeof(Matrix));
	C = (Matrix*)malloc(sizeof(Matrix));
	D = (Matrix*)malloc(sizeof(Matrix));
	int x1, x2, y1, y2, i, j, k = 0;
	int a[Maxsize][Maxsize];
	int b[Maxsize][Maxsize];
	printf ("请输入A矩阵的行数和列数:");  //输入矩阵A 
	scanf("%d %d",&x1 ,&y1);
	printf("请输入A矩阵元素:\n");
	for (i = 0; i < x1; i++)
	{
		for (j = 0; j < y1 ; j++)
		{
			scanf("%d", &a[i][j]);
			A->row = x1; 
	        A->col = y1;
		}
	}
	
	printf ("请输入B矩阵的行数和列数:");  //输入矩阵A 
	scanf("%d %d",&x2 ,&y2);
	printf("请输入A矩阵元素:\n");
	for (i = 0; i < x2; i++)
	{
		for (j = 0; j < y2 ; j++)
		{
			scanf("%d", &b[i][j]);
			B->row = x2;
	        B->col = y2;
		}
	}
    
    CreateMat(A, a);  //将矩阵A三元组存储 
	CreateMat(B, b);  //将矩阵B三元组存储 
    JudgeAddMat(A, B, C);
    JudgeMulMat(A, B, D);
	return 0;
}

void CreateMat(Matrix *A, int a[Maxsize][Maxsize])
{
	int i, j;
	A->num = 0;  //初始化非零元素总数 此值又可当做第k个非零元素的序号 
	
	for (i = 0; i < A->row; i++)
	{
		for (j = 0; j < A->col; j++)
		{
			if (a[i][j] != 0)
			{
				A->data[A->num].row = i;
				A->data[A->num].col = j;
				A->data[A->num].value = a[i][j];
				A->num++;
			}
		}
	}
}

void DisplayMat(Matrix *A)
{
	int i;
	printf("运算结果为:\n");
	printf("矩阵行数为%d 列数为%d 非零元素数量为%d。\n", A->row, A->col, A->num); 
	printf("非零元素分别为\n");
	printf("行\t列\t数值\t\n");
	
	for (i = 0; i < A->num; i++) 
	{
		printf("%d\t%d\t%d\t\n", A->data[i].row, A->data[i].col, A->data[i].value);
	}
		
}

void JudgeAddMat(Matrix *A, Matrix *B, Matrix *C)
{
	int i, j, flag;
	C->num = 0;
    
	if (A->row == B->row && A->col == B->col) //判断矩阵A与矩阵B能否相加 
	{
		printf("矩阵A和矩阵B可以相加\n");
		C->row = A->row;
		C->col = A->col;

		for (i = 0; i < A->num; i++)
		{
			flag = 0;
			for (j = 0; j < B->num; j++) //这个循环将同行同列的非零元素相加 
			{
				if (A->data[i].row == B->data[j].row && A->data[i].col == B->data[j].col) 
			    {
			    	flag = 1;
			    	
				    if (A->data[i].value + B->data[i].value)//判断如果两元素之和不为0则为非零元素  
			        {
				        C->data[C->num].value = A->data[i].value + B->data[j].value;
				        C->data[C->num].row = A->data[i].row;
				        C->data[C->num].col = A->data[i].col;
				        C->num++; 
			        }
			    }
			}
			if (!flag)    //如果B矩阵中没有元素匹配A矩阵中的非零元素a 则a+0
			{
				C->data[C->num].value = A->data[i].value;
				C->data[C->num].row = A->data[i].row;
				C->data[C->num].col = A->data[i].col;
				C->num++;
			}	  
		}
		
		for (j = 0; j < B->num; j++)
		{
			flag = 0;
			for (i = 0; i < A->num; i++)
			{
				if (A->data[i].row == B->data[j].row && A->data[i].col == B->data[j].col) 
			    	flag = 1;
			}
			
			if (!flag)   //如果A矩阵中没有元素匹配B矩阵中的非零元素b 则b+0
			{
				C->data[C->num].value = B->data[j].value;
				C->data[C->num].row = B->data[j].row;
				C->data[C->num].col = B->data[j].col;
				C->num++;
			}	  
		}
		
		DisplayMat(C); //打印加法结果
	} 
	else
	    printf("矩阵A和矩阵B不可以相加\n");
}

void JudgeMulMat(Matrix *A, Matrix *B, Matrix *D)
{
	int i, j, n = 0;
	
	if (A->col == B->row)  //判断矩阵A与矩阵B能否相乘 
	{
		printf("矩阵A和矩阵B可以相乘\n");
		D->row = A->row;
		D->col = B->col;
		
		for (i = 0; i < A->num; i++)  //从A三元组元素开始遍历 
		{
			for (j = 0; j < B->num; j++)  //与B三元组元素一一匹配 
			{
				if (A->data[i].col == B->data[j].row) //判断是否有可以做乘法的元素
				{
					D->data[n].value =  A->data[i].value * B->data[j].value; 
					D->data[n].col =  B->data[j].col;
					D->data[n].row =  A->data[i].row;
					n++;
				}	
				
			}
		}
		
        D->num = 0;
        
        for (i = 0; i < n; i++)
        {
        	for (j = i + 1; j < n; j++)
        	{
        		if (D->data[i].row == D->data[j].row && D->data[i].col == D->data[j].col)
				{
					D->data[D->num].value += D->data[j].value;
					D->data[D->num].col =  D->data[j].col;
					D->data[D->num].row =  D->data[i].row;
				} 
        	}
        	D->num++;
        }
        
		DisplayMat(D); //打印加法结果
	}
}


