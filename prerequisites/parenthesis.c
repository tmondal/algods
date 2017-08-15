#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Stack
{
	int top;
	char array[20];
};

int match(char c1, char c2){

	if (c1 == ')' && c2 == '(')
	{
		return 1;
	}
	else if (c1 == '}' && c2 == '{')
	{
		return 1;
	}
	else if (c1 == ']' && c2 == '[')
	{
		return 1;
	}
	else{
		return 0;
	}
}

void push(struct Stack **stack,char data){
	(*stack)->array[++(*stack)->top] = data;
}

char pop(struct Stack **stack){
	return (*stack)->array[(*stack)->top--];
}

char pick(struct Stack **stack){
	return (*stack)->array[(*stack)->top];
}

void matchparenthesis(char *exp){


	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->top = -1;

	int i = 0,flag = 0;
	while(exp[i] != '\0'){
		if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
		{
			push(&stack,exp[i]);
			i++;
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (match(exp[i],pick(&stack)))
			{
				pop(&stack);
				i++;
			}else{
				printf("Does not match\n");
				flag = 1;
				break;
			}
		}
		else{
			i++;
		}
	}
	if (!flag)
	{
		if (stack->top != -1)
		{
			printf("Does not match\n");
			printf("Top: %d\n",stack->top );
		}else{
			printf("Match\n");
		}
	}
}


int main(int argc, char const *argv[])
{
	// get expression
	char expression[10];
	printf("Enter an expression: ");
	gets(expression);
	printf("%s\n", expression);

	matchparenthesis(expression);
	return 0;
}