#include<stdio.h>
typedef enum precedence {lparen,rparen,plus,minus,multipy,divide,mod,eos,operand}precedence;
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
char expr[100];
int stack[100];
int top=-1;
precedence getToken(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return multipy;
		case '/': return divide;
		case '%': return mod;
		case ' ': return eos;
		case '\0': return eos; 
		default: return operand;
	}
}
void printToken(precedence token)
{
	switch(token)
	{
		case lparen: printf("(");
					 break;
		case rparen: printf(")");
					 break;
		case plus: printf("+");
					break;
		case minus: printf("-");
					break;
		case multipy: printf("*");
					 break;
		case divide: printf("/");
					 break;
		case mod: printf("%%");
					break;
		case eos: printf(" ");
					break;
		case 8: break;
	}
}
void push(int token)
{
	stack[++top]=token;
}
int pop()
{
	return stack[top--];
}
void postfix(void)
{
	char symbol;
	precedence token;
	int n=0;
	top=0;
	stack[0]=eos;
	for(token=getToken(&symbol,&n);token!=eos;token=getToken(&symbol,&n))
	{
		if (token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				printToken(pop());
			pop();
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
				printToken(pop());
			push(token);
		}
	}
	while((token=pop())!=eos)
		printToken(token);
	printf("\n");
}
int main()
{
	printf("enter expr\n");
	scanf("%s",expr);
	postfix();
}
