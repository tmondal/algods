// queue using dynamic array

#include <stdio.h>
#include <stdlib.h>

struct  Queue
{
	int front,rear;
	int *array;
};


struct Queue *createqueue(int size){

	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->front = 0;
	queue->rear = -1;
	queue->array = (int *)malloc(sizeof(int)*size);

	return queue;
}


void enqueue(struct Queue **queue, int data){

	(*queue)->array[++(*queue)->rear] = data;
}

int dequeue(struct Queue **queue){

	return (*queue)->array[(*queue)->front ++];
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
	struct Queue *queue = createqueue(5);

	enqueue(&queue,7);
	enqueue(&queue,5);

	show(queue);

	printf("deleted: %d\n",dequeue(&queue));

	show(queue);
	return 0;
}