#include <stdio.h>
#include <stdlib.h>


struct Stack
{
	int top,currentsize,capacity;
	int *array;
};


struct Stack *createstack(int capacity){

	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->currentsize = 0;
	stack->capacity = capacity;
	stack->array = (int *)malloc(sizeof(int)*capacity);

	return stack;
}

int isFull(struct Stack *stack){
	return (stack->currentsize == stack->capacity) ? 1 : 0;
}

int isEmpty(struct Stack *stack){

	return (stack->top == -1) ? 1 : 0;
}

void push(struct Stack *stack,int data){

	if (isFull(stack))
	{
		// allocate memory for array of 2*capacity
		stack->capacity = 2*stack->capacity;
		stack->array = (int *)realloc(stack->array,stack->capacity);
		printf("Array extended!\n");
	}
	stack->array[++(stack->top)] = data;
	stack->currentsize += 1;
}

int pop(struct Stack *stack){
	if (isEmpty(stack))
	{
		printf("Stack underflow!\n");
		return -1;
	}else{
		return stack->array[(stack->top)--];
	}
}

void show(struct Stack *stack){
	int i;
	printf("Stack is: \n");
	for (i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->array[i]);
	}
}

int main(int argc, char const *argv[])
{
	struct Stack *stack = createstack(2);

	push(stack,5);
	push(stack,9);
	show(stack);
	printf("value poped: %d\n", pop(stack));
	printf("value poped: %d\n", pop(stack));
	printf("value poped: %d\n", pop(stack));
	show(stack);
	push(stack,7);
	push(stack,3);
	show(stack);
	return 0;
}