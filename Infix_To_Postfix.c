#include<stdio.h>
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
precedence stack[20];
char expr[20];
int n;
int top;
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
precedence pop()
{
	return stack[top--];
}
void push (precedence token)
{
	stack[++top]=token;
}
precedence getToken(char* symbol, int* n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '-': return minus;
	case '+': return plus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}
void printToken(precedence token)
{
	switch(token)
	{
	case plus:
		printf("+");
		break;
	case minus:
		printf("-");
		break;
	case divide:
		printf("/");
		break;
	case times:
		printf("*");
		break;
	case mod:
		printf("%%");
		break;
	}
}
void postfix()
{
	char symbol;
	precedence token;
	n=0;
	top=0;
	stack[0]=eos;
	for(token = getToken(&symbol, &n); token!=eos; token = getToken(&symbol, &n))
	{
		if(token == operand)
			printf("%c",symbol);
		else if(token == rparen)
		{
			while(stack[top]!=lparen)
				printToken(pop());
			pop();

		}
		else
		{
			while(isp[stack[top]]>=icp[token])
			{
				printToken(pop());

			}
			push(token);
		}
	}
	while((token = pop())!=eos)
		printToken(token);
	printf("\n");
}
int eval()
{
	precedence token;
	char symbol;
	int op1,op2;
	 n=0;
	top=-1;
	token=getToken(&symbol, &n);
	while(token != eos)
	{
		if ( token == operand )
		{
			push(symbol-'0');

		}
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
			case plus:
				push(op1+op2);
				break;
			case minus:
				push(op1-op2);
				break;
			case times:
				push(op1*op2);
				break;
			case divide:
				push(op1/op2);
				break;
			case mod:
				push(op1%op2);
				break;

			}
		}
		token=getToken(&symbol, &n);
	}
	return pop();
}
int main()
{
    int choice;
    while(1)
    {
        printf("\nMENU : \n1.Infix to Postfix Conversion \n2.Evaluation of Postfix expression");
        printf("\nEnter your choice : ");
        scanf("%d",choice);
        switch(choice)
        {
            case 1: printf("Enter expression :");
                    scanf("%s",expr);
                    postfix();
                    break;
            case 2: printf("Enter expression :");
                    scanf("%s",expr);
                    eval();
                    break;
            default: printf("Invalid choice");
                    break;
        }
    }
}



