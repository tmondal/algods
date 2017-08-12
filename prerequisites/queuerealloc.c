// queue with realloc

#include <stdio.h>
#include <stdlib.h>

struct  Queue
{
	int front,rear,size;
	int *array;
};


struct Queue *createqueue(int size){

	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->front = 0;
	queue->rear = -1;
	queue->array = (int *)malloc(sizeof(int)*size);
	queue->size = size;

	return queue;
}

int isFull(struct Queue *queue){
	return (queue->rear == queue->size - 1) ? 1 : 0;
}

int isEmpty(struct Queue *queue){

	return (queue->front == queue->rear) ? 1 : 0;
}

void enqueue(struct Queue **queue, int data){

	if (isFull(*queue))
	{
		(*queue)->array = (int *)realloc((*queue)->array,2*(*queue)->size);	
		printf("Array resized!\n");
	}
	(*queue)->array[++(*queue)->rear] = data;
}

int dequeue(struct Queue **queue){
	if (!isEmpty(*queue))
	{		
		return (*queue)->array[(*queue)->front ++];
	}
	printf("Queue empty!\n");
}

void show(struct Queue *queue){

	int i;
	printf("queue is: \n");
	for (i = queue->front; i <= queue->rear; ++i)
	{
		printf("%d\n", queue->array[i]);
	}
}

int main(int argc, char const *argv[])
{
	struct Queue *queue = createqueue(2);

	enqueue(&queue,7);
	enqueue(&queue,5);

	show(queue);

	printf("deleted: %d\n",dequeue(&queue));

	show(queue);
	enqueue(&queue,8);
	enqueue(&queue,4);
	show(queue);
	return 0;
}