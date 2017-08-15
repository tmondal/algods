#include <stdio.h>
#include <stdlib.h>

struct operatorStack
{
	int top;
	char array[20];
};

struct  operandStack
{
	int top;
	int array[20];
};

void pushopnd(struct operandStack *stack, int data){
	stack->array[++stack->top] = data;
}

void pushopr(struct operatorStack *stack, char data){
	stack->array[++stack->top] = data;
}

char oprstackTop(struct operatorStack *stack){
	return stack->array[stack->top];
}

int isEmpty(struct operatorStack *stack){
	if (stack->top > -1){
		return 0;
	}else{
		return 1;
	}
}

int isempty(struct operandStack *stack){
	if (stack->top > -1){
		return 0;
	}else{
		return 1;
	}
}

int popopndStack(struct operandStack *stack){
	if (!isempty(stack))
	{
		return stack->array[stack->top--];
	}else{
		printf("opnd underflow\n");
	}
}

char popoprStack(struct operatorStack *stack){
	if (!isEmpty(stack))
	{
		return stack->array[stack->top--];
	}else{
		printf("underflow\n");
	}
}

int applyOperator(int d1, int d2, char op){

	switch(op){

		case '+':
			return d1 + d2;
		case '-':
			return d1 - d2;
		case '*': 
			return d1*d2;
		case '/': 
			if (d2 != 0)
			{
				return d1/d2;
			}else{
				printf("Division by 0 exception!\n");
				break;
			}
		default:
			printf("Invalid operator!\n");
			return -1000;
	}
}

int precedence(char opr1, char opr2){
	if (opr1 == '(' || opr1 == ')')
	{
		return 0;
	}
	else if ((opr1 == '*' || opr1 == '/') && (opr2 == '+' || opr2 == '-'))
	{
		return 1;
	}else{
		return 0;
	}
}

void infixevaluate(char *infix){

	int i = 0,flag = 0;
	struct operatorStack *oprstack = (struct operatorStack *)malloc(sizeof(struct operatorStack));
	struct operandStack *opnstack = (struct operandStack *)malloc(sizeof(struct operandStack));
	oprstack->top = -1;
	opnstack->top = -1;

	while(infix[i] != '\0'){

		if (infix[i] == ' '){
			i++;
		}
		else if (infix[i] == '('){
			pushopr(oprstack,infix[i++]);
		}
		else if (infix[i] >= '0' && infix[i] <= '9'){
			pushopnd(opnstack, infix[i++]);
		}
		else if (infix[i] == ')'){
			while(oprstackTop(oprstack) != '('){
				int op2 = popopndStack(opnstack);
				int op1 = popopndStack(opnstack);
				char op = popoprStack(oprstack);

				int val = applyOperator(op1,op2,op);
				pushopnd(opnstack,val);
			}
			popoprStack(oprstack);
			i++;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
			while(!isEmpty(oprstack) && precedence(oprstackTop(oprstack),infix[i])){

				int op2 = popopndStack(opnstack);
				int op1 = popopndStack(opnstack);

				char op = popoprStack(oprstack);
				int val = applyOperator(op1,op2,op);
				pushopnd(opnstack,val);	
			}
			pushopr(oprstack,infix[i]);
			i++;
		}
		else{
			printf("Invalid character encounterd!!\n");
			flag = 1;
			break;
		}
	}

	if (!flag){
		
		while(!isEmpty(oprstack)){
			int op2 = popopndStack(opnstack);
			int op1 = popopndStack(opnstack);
			char op = popoprStack(oprstack);
			int val = applyOperator(op1,op2,op);
			pushopnd(opnstack,val);
		}

		printf("Final value : %d\n", popopndStack(opnstack));
	}
}

int main(int argc, char const *argv[]){
	char infix[30] = "9*(5+4)";
	// printf("Enter an vlaid infix expression: ");
	// gets(infix);

	infixevaluate(infix);
	return 0;
}