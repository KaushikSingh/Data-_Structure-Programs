#include <stdio.h>
#define MAX_TERMS 101
#define MAX_COL 101
typedef struct 
{
	int row;
	int col;
	int val;
}term;
void input(term a[])
{
	int A[100][100],m,n,i,j,current;
	printf("enter the number of rows\n");
	scanf("%d",&m);
	printf("enter the number of columns\n");
	scanf("%d",&n);
	printf("enter the matrix elements\n");
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	current=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if (A[i][j]!=0)
			{
				a[current].row=i;
				a[current].col=j;
				a[current].val=A[i][j];
				current++;
			}
		}
	}
	a[0].row=m;
	a[0].col=n;
	a[0].val=current-1;
}
void fast_transpose(term a[],term b[])
{
	int row_terms[100],starting_pos[100];
	int i,j,num_cols=a[0].col,num_terms=a[0].val;
	b[0].col=num_cols;
	b[0].row=a[0].row;
	b[0].val=num_terms;
	if(num_terms>0)
	{
		for(i=0;i<num_cols;i++)
			row_terms[i]=0;
		for(i=1;i<=num_terms;i++)
			row_terms[a[i].col]++;
		starting_pos[0]=1;
		for(i=1;i<num_cols;i++)
			starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
		for(i=1;i<=num_terms;i++)
		{
			j=starting_pos[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].val=a[i].val;
		}
	}
}
void output(term k[])
{
	int i,num_terms;
	num_terms=k[0].val;
	printf("row\tcol\tvalue\n");
	for(i=0;i<=num_terms;i++)
		printf("%d\t%d\t%d\n",k[i].row,k[i].col,k[i].val);
}
int main()
{
	term a[MAX_TERMS],b[MAX_TERMS];
	printf("Enter the matrix\n");
	input(a);
	output(a);
	fast_transpose(a,b);
	output(b);
}
