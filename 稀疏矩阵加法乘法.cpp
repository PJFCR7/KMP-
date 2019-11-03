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
	printf ("������A���������������:");  //�������A 
	scanf("%d %d",&x1 ,&y1);
	printf("������A����Ԫ��:\n");
	for (i = 0; i < x1; i++)
	{
		for (j = 0; j < y1 ; j++)
		{
			scanf("%d", &a[i][j]);
			A->row = x1; 
	        A->col = y1;
		}
	}
	
	printf ("������B���������������:");  //�������A 
	scanf("%d %d",&x2 ,&y2);
	printf("������A����Ԫ��:\n");
	for (i = 0; i < x2; i++)
	{
		for (j = 0; j < y2 ; j++)
		{
			scanf("%d", &b[i][j]);
			B->row = x2;
	        B->col = y2;
		}
	}
    
    CreateMat(A, a);  //������A��Ԫ��洢 
	CreateMat(B, b);  //������B��Ԫ��洢 
    JudgeAddMat(A, B, C);
    JudgeMulMat(A, B, D);
	return 0;
}

void CreateMat(Matrix *A, int a[Maxsize][Maxsize])
{
	int i, j;
	A->num = 0;  //��ʼ������Ԫ������ ��ֵ�ֿɵ�����k������Ԫ�ص���� 
	
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
	printf("������Ϊ:\n");
	printf("��������Ϊ%d ����Ϊ%d ����Ԫ������Ϊ%d��\n", A->row, A->col, A->num); 
	printf("����Ԫ�طֱ�Ϊ\n");
	printf("��\t��\t��ֵ\t\n");
	
	for (i = 0; i < A->num; i++) 
	{
		printf("%d\t%d\t%d\t\n", A->data[i].row, A->data[i].col, A->data[i].value);
	}
		
}

void JudgeAddMat(Matrix *A, Matrix *B, Matrix *C)
{
	int i, j, flag;
	C->num = 0;
    
	if (A->row == B->row && A->col == B->col) //�жϾ���A�����B�ܷ���� 
	{
		printf("����A�;���B�������\n");
		C->row = A->row;
		C->col = A->col;

		for (i = 0; i < A->num; i++)
		{
			flag = 0;
			for (j = 0; j < B->num; j++) //���ѭ����ͬ��ͬ�еķ���Ԫ����� 
			{
				if (A->data[i].row == B->data[j].row && A->data[i].col == B->data[j].col) 
			    {
			    	flag = 1;
			    	
				    if (A->data[i].value + B->data[i].value)//�ж������Ԫ��֮�Ͳ�Ϊ0��Ϊ����Ԫ��  
			        {
				        C->data[C->num].value = A->data[i].value + B->data[j].value;
				        C->data[C->num].row = A->data[i].row;
				        C->data[C->num].col = A->data[i].col;
				        C->num++; 
			        }
			    }
			}
			if (!flag)    //���B������û��Ԫ��ƥ��A�����еķ���Ԫ��a ��a+0
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
			
			if (!flag)   //���A������û��Ԫ��ƥ��B�����еķ���Ԫ��b ��b+0
			{
				C->data[C->num].value = B->data[j].value;
				C->data[C->num].row = B->data[j].row;
				C->data[C->num].col = B->data[j].col;
				C->num++;
			}	  
		}
		
		DisplayMat(C); //��ӡ�ӷ����
	} 
	else
	    printf("����A�;���B���������\n");
}

void JudgeMulMat(Matrix *A, Matrix *B, Matrix *D)
{
	int i, j, n = 0;
	
	if (A->col == B->row)  //�жϾ���A�����B�ܷ���� 
	{
		printf("����A�;���B�������\n");
		D->row = A->row;
		D->col = B->col;
		
		for (i = 0; i < A->num; i++)  //��A��Ԫ��Ԫ�ؿ�ʼ���� 
		{
			for (j = 0; j < B->num; j++)  //��B��Ԫ��Ԫ��һһƥ�� 
			{
				if (A->data[i].col == B->data[j].row) //�ж��Ƿ��п������˷���Ԫ��
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
        
		DisplayMat(D); //��ӡ�ӷ����
	}
}


