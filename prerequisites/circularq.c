// queue with dynamic array

#include <stdio.h>
#include <stdlib.h>

struct  Queue
{
	int front,rear,size;
	int *array;
};


struct Queue *createqueue(int size){

	size += 1;
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->front = 0;
	queue->rear = 0;
	queue->array = (int *)malloc(sizeof(int)*size);
	queue->size = size;

	return queue;
}

int isFull(struct Queue *queue){
	int val = (queue->rear + 1) % queue->size;
	if (val == queue->front)
	{
		printf("here\n");
		return 1;
	}
	return 0;
}

int isEmpty(struct Queue *queue){

	int val = (queue->front + 1) % queue->size;
	if (val == queue->rear)
	{
		return 1;
	}
	return 0;
}

void enqueue(struct Queue **queue, int data){

	if (isFull(*queue))
	{
		// reallocate memory
		(*queue)->size = 2*(*queue)->size + 1;
		(*queue)->array = (int *)malloc((*queue)->size);	// problem is here
	}
	(*queue)->rear = ((*queue)->rear + 1) % (*queue)->size;
	(*queue)->array[(*queue)->rear] = data;
	printf("enqueued\n");
}

int dequeue(struct Queue **queue){
	
	if (!isEmpty(*queue))
	{
		int temp = (*queue)->array[(*queue)->front + 1];
		(*queue)->front = ((*queue)->front + 1) % (*queue)->size;
		return temp;
	}
}

void show(struct Queue *queue){

	int i;
	printf("queue is: \n");
	for (i = queue->front + 1; i <= queue->rear; ++i)
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