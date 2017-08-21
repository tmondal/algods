#include <stdio.h>
#include <stdlib.h>


typedef struct Queue{
	int front,rear,capacity,size;
	char **array;
}Queue;

typedef struct Tree{
	Queue *queue;
	struct Tree *left,*mid,*right;
}Tree;


void initialize(Tree **root, int capacity){
	(*root) = (Tree *)malloc(sizeof(Tree));
	(*root)->queue = (Queue *)malloc(sizeof(Queue));
	(*root)->queue->front = -1;
	(*root)->queue->rear = 0;
	(*root)->queue->capacity = capacity;
	(*root)->queue->size = 0;
	(*root)->queue->array = (char **)malloc(sizeof(char *)*capacity);
}

Tree *createTreeNode(int capacity){

	Tree *node = (Tree *)malloc(sizeof(Tree));
	node->left = node->right = node->mid = NULL;
	node->queue = (Queue *)malloc(sizeof(Queue));
	node->queue->front = 0;
	node->queue->rear = -1;
	node->queue->size = 0;
	node->queue->capacity = capacity;
	node->queue->array = (char **)malloc(sizeof(char *)*capacity);
}

void insert(Tree **root){

	if ((*root) == NULL)
	{
		(*root) = createTreeNode(10);
		return;
	}

	if ((*root)->left == NULL)
	{
		(*root)->left = createTreeNode(10);
		return;
	}
	else if ((*root)->mid == NULL)
	{
		(*root)->mid = createTreeNode(10);
		return;	
	}
	else if ((*root)->right == NULL)
	{
		(*root)->right = createTreeNode(10);
		return;	
	}
	else if ((*root)->left != NULL)
	{
		insert(&(*root)->left);	
	}
	else if ((*root)->mid != NULL)
	{
		insert(&(*root)->mid);	
	}
	else
	{
		insert(&(*root)->right);	
	}

}

int isFull(Queue *queue){
	return (queue->size == queue->capacity - 1) ? 1 : 0;
}

void enqueue(Tree *tree, char *str){
	if (!isFull(tree->queue))
	{
		tree->queue->array[tree->queue->rear] = str;
		tree->queue->rear = (tree->queue->rear + 1) % tree->queue->capacity;
		tree->queue->size += 1;
	}else{
		printf("Full\n");
	}
}

void traversal(Tree *tree){

	if (tree == NULL)
	{
		return;
	}
	if (tree->left != NULL)
	{
		traversal(tree->left);
	}
	if (tree->mid != NULL)
	{
		traversal(tree->mid);
	}
	int front = tree->queue->front;
	int rear = tree->queue->rear;
	printf("f r: %d %d\n",front,rear );
	while(front != rear){
		printf("here\n");
		printf("%s -->", tree->queue->array[front]);
		front += 1;
	}
	printf("\n");
	if (tree->right != NULL)
	{
		traversal(tree->right);
	}
}

int main(int argc, char const *argv[])
{

	Tree *root = NULL;
	initialize(&root,10);
	insert(&root);
	insert(&root);
	insert(&root);

	enqueue(root,"hello world");
	enqueue(root,"world hello");

	traversal(root);

	return 0;
}