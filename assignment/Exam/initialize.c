#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Queue {
	int front, rear;
	int capacity;
	char *arr;
}Queue;

typedef struct Tree {
	Queue *queue;
	struct Tree *left,*mid,*right;
}Tree;



Tree *initialize(int capacity){
	
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->left = tree->mid = tree->right = NULL;
	tree->queue = (Queue *)malloc(sizeof(Queue));
	tree->queue->front = -1;
	tree->queue->rear = 0;
	tree->queue->arr = (char *)malloc(sizeof(char)*capacity);
	tree->queue->capacity = capacity; 
	return tree;
}


int main(){


	Tree *tree = initialize(10);
	printf("Front :%d,Rear: %d, Capacity :%d\n", tree->queue->front, tree->queue->rear,tree->queue->capacity);
	return 0;
}