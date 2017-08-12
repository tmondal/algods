#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int top;
	int size;
	int *array;
};

struct Stack *createstack(int size){

	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(sizeof(int)*size);
	if (stack->array)
	{
		return stack;
	}else{
		printf("Memory allocation error!\n");
	}
}

int isFull(struct Stack *stack){
	return (stack->top == stack->size - 1) ? 1 : 0;
}

void push(struct Stack *stack, int data){

	if (isFull(stack))
	{
		printf("Stack overflow!\n");
	}else{
		stack->array[++(stack->top)] = data;
	}
}

int isEmpty(struct Stack *stack){

	return (stack->top == -1);
}

int pop(struct Stack *stack){
	if (!isEmpty(stack))
	{
		return stack->array[(stack->top)--];
	}else{
		printf("Stack underflow!\n");
	}
}
void showstack(struct Stack *stack){
	int i;
	printf("Stack is: \n");
	for (i = 0; i <= stack->top; ++i)
	{
		printf("%d\n", stack->array[i]);
	}
}

int main(int argc, char const *argv[])
{
	// create stack
	struct Stack *stack = createstack(8);

	push(stack,8);
	push(stack,5);
	push(stack,7);

	showstack(stack);

	printf("Poped value: %d\n",pop(stack));
	showstack(stack);
	return 0;
}