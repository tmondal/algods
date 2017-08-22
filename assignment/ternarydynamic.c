#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LL
{
	char *data;
	struct LL *next;
}LL;

typedef struct Queue
{
	LL *front , *rear;
}Queue;

typedef struct Tree
{
	Queue *queue;
	struct Tree *left, *mid, *right;
}Tree;

Tree *initialize(){
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->left = tree->mid = tree->right = NULL;
	tree->queue = (Queue *)malloc(sizeof(Queue));
	tree->queue->front = NULL;
	tree->queue->rear = NULL;

	return tree;
}

Tree *createNode(){
	
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->left = tree->mid = tree->right = NULL;
	tree->queue = (Queue *)malloc(sizeof(Queue));
	tree->queue->front = NULL;
	tree->queue->rear = NULL;

	return tree;	
}

void insert(Tree **tree){

	Tree *temp = *tree;
	if (temp == NULL)
	{
		(*tree) = createNode();
		return;
	}
	if (temp->left == NULL)
	{
		// printf("here\n");
		(*tree)->left = createNode();
		return;
	}
	if (temp->mid == NULL)
	{
		(*tree)->mid = createNode();
		return;
	}
	if (temp->right == NULL)
	{
		(*tree)->right = createNode();
		return;
	}
}

void enqueue(Tree *tree,char *path, char *data){
	if (tree == NULL)
	{
		return;
	}
	
	int i = 0;
	Tree *temp = tree;
	while(path[i] != '\0'){
		if (path[i] == 'L')
		{
			if (temp->left != NULL){
				temp = temp->left;
				//printf("here\n");
			}else{
				printf("No tree node found\n");
				return;
			}
		}
		else if (path[i] == 'M')
		{
			if (temp->mid != NULL){
				temp = temp->mid;
			}else{
				printf("No tree node found\n");
				return;
			}
		}else{
			if (temp->right != NULL){
				temp = temp->right;
			}else{
				printf("No tree node found\n");
				return;
			}
		}
		i++;
	}
	// enqueue
	LL **front = &(temp->queue->front);
	LL **rear = &(temp->queue->rear);
	if (temp->queue->rear == NULL)
	{
		LL *list = (LL *)malloc(sizeof(LL));
		list->data = data;
		list->next = NULL;
		// temp->queue->rear = temp->queue->front = list;
		*front = list;
		*rear = list;
		// printf("%s\n",temp->queue->front->data );
	}
	else{
		LL *list = (LL *)malloc(sizeof(LL));
		list->data = data;
		list->next = NULL;
		temp->queue->rear->next = list;
		temp->queue->rear = list;
	}

}

void traverse(Tree *tree){
	if (tree == NULL){
		return;
	}
	if (tree->left != NULL){
		traverse(tree->left);
	}
	// print current node
	LL *f = tree->queue->front;
	while(f != NULL){
		//printf("here\n");
		printf("%s-->",f->data);
		f = f->next;
	}
	printf("\n");
	if (tree->mid != NULL){
		traverse(tree->mid);
	}
	if (tree->right != NULL){
		traverse(tree->right);
	}
}

void dequeue(Tree *tree, char *path){

	if (tree == NULL)
	{
		return;
	}
	
	int i = 0;
	Tree *temp = tree;
	while(path[i] != '\0'){
		if (path[i] == 'L')
		{
			if (temp->left != NULL){
				temp = temp->left;
				//printf("here\n");
			}else{
				printf("No tree node found\n");
				return;
			}
		}
		else if (path[i] == 'M')
		{
			if (temp->mid != NULL){
				temp = temp->mid;
			}else{
				printf("No tree node found\n");
				return;
			}
		}else{
			if (temp->right != NULL){
				temp = temp->right;
			}else{
				printf("No tree node found\n");
				return;
			}
		}
		i++;
	}
	// enqueue
	LL **front = &(temp->queue->front);
	LL **rear = &(temp->queue->rear);
	if (temp->queue->front == NULL)
	{
		printf("No item in the queue\n");
	}
	else{
		printf("Dequeued: %s\n", temp->queue->front->data);
		LL *del = (*front);
		(*front) = (*front)->next;
		if ((*front) == NULL)
		{
			(*rear) = NULL;
		}
		free(del);
	}
}

void access(Tree *tree, char *path){
	if (tree == NULL)
	{
		return;
	}
	int i = 0;
	while(path[i] != '\0'){
		if (path[i] == 'L'){
			if (tree->left){
				tree = tree->left;
			}else{
				printf("No node exist\n");
				return;
			}
		}
		else if (path[i] == 'M'){
			if (tree->mid){
				tree = tree->mid;
			}else{
				printf("No node exist\n");
				return;
			}
		}else{
			if (tree->right){
				tree = tree->right;
			}else{
				printf("No node exist\n");
				return;
			}
		}
		i++;
	}
	LL *front = tree->queue->front;
	while(front != NULL){
		printf("%s-->", front->data);
		front = front->next;
	}
	printf("\n");
}

void destroy(Tree *tree){

	if (tree == NULL){
		return;
	}
	if (tree->left != NULL){
		destroy(tree->left);
	}
	if (tree->mid != NULL){
		destroy(tree->mid);
	}
	if (tree->right != NULL){
		destroy(tree->right);
	}
	free(tree);
}

int main(int argc, char const *argv[])
{
	Tree *tree = initialize();
	insert(&tree);
	insert(&tree);
	insert(&tree);
	insert(&(tree->left));

	enqueue(tree,"","root");
	enqueue(tree,"LL","Hello");
	enqueue(tree,"LL","world");
	traverse(tree);
	//dequeue(tree,"L");
	//dequeue(tree,"RL");
	//traverse(tree);
	access(tree,"L");
	destroy(tree);
	//traverse(tree);
	return 0;
}