// deque using Doubly Lnked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Deque
{
	struct Node *front , *rear;
};

void enqueueFront(struct Deque **deque,int data){

	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = data;
	if ((*deque)->front == NULL)
	{
		newnode->next = newnode->prev = NULL;
		(*deque)->front = (*deque)->rear = newnode;
		return;
	}
	newnode->next = (*deque)->front;
	newnode->prev = NULL;
	(*deque)->front->prev = newnode;
	(*deque)->front = newnode;
}

int dequeFront(struct Deque **deque){
	if ((*deque)->front != NULL)
	{
		int data = (*deque)->front->data;
		struct Node *temp = (*deque)->front;
		(*deque)->front = temp->next;
		if ((*deque)->front == NULL)
		{
			(*deque)->rear = NULL;
		}
		free(temp);
		return data;
	}else{
		printf("Deque empty!\n");
		exit(0); 
	}

}

void enqueueRear(struct Deque **deque, int data){
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = data;
	if ((*deque)->rear == NULL)
	{
		newnode->prev = newnode->next = NULL;
		(*deque)->front = (*deque)->rear = newnode;
		return;
	}
	newnode->prev = (*deque)->rear;
	newnode->next = NULL;
	(*deque)->rear->next = newnode;
	(*deque)->rear = newnode;
}

int dequeRear(struct Deque **deque){
	if ((*deque)->rear != NULL)
	{
		int data = (*deque)->rear->data;
		struct Node *temp = (*deque)->rear;
		(*deque)->rear = temp->prev;
		temp->prev->next = NULL;
		if ((*deque)->rear == NULL)
		{
			(*deque)->front = NULL;
		}
		free(temp);
		return data;
	}else{
		printf("Deque empty!\n"); 
	}
}

void show(struct Deque **deque){

	struct Node *temp = (*deque)->front;
	while(temp != NULL){
		
		printf("%d <--> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
	deque->front = deque->rear = NULL;

	enqueueFront(&deque,5);
	enqueueFront(&deque,8);
	// enqueueFront(&deque,6);
	// enqueueFront(&deque,3);
	show(&deque);
	// printf("Deque from front: %d\n",dequeFront(&deque));
	// show(&deque);
	enqueueRear(&deque,2);
	//enqueueRear(&deque,7);
	show(&deque);
	// printf("Deque from rear: %d\n", dequeRear(&deque));
	// show(&deque);
	return 0;
}