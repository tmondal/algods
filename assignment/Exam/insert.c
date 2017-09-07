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

Tree *createTreeNode(int capacity){
	
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->left = tree->mid = tree->right = NULL;
	tree->queue = (Queue *)malloc(sizeof(Queue));
	tree->queue->front = -1;
	tree->queue->rear = 0;
	tree->queue->arr = (char *)malloc(sizeof(char)*capacity);
	
	return tree;
}

// insert a tree node
void *insert(Tree **tree){
	
	Tree *newnode = createTreeNode(10);
	
	if((*tree) == NULL){
		(*tree) = newnode; // root changed
	}
	// if tree having only one node just the root
	if((*tree)->left == NULL){
		(*tree)->left = newnode;
		return tree; // unchanged root
	}
	else if((*tree)->mid == NULL){
		(*tree)->mid = newnode;
		return tree; // unchanged root
	}else{
		(*tree)->right = newnode;
		return tree; // unchanged root
	}
	
	// Wrong logic

	// if tree has many nodes then call recursively
	if((*tree)->left != NULL){
		(*tree)->left = insert(&(*tree)->left);
	}
	if((*tree)->mid != NULL){
		(*tree)->mid = insert(&(*tree)->mid);
	}
	if((*tree)->right){
		(*tree)->right = insert(&(*tree)->right);
	}
}

int main(){


	Tree *tree = initialize(10);
	insert(&tree);
	if (tree->left != NULL){
		printf("Left node inserted\n");
	}
	insert(&tree);
	if (tree->mid != NULL){
		printf("Mid node inserted\n");
	}
	insert(&tree);
	if (tree->right != NULL){
		printf("Right node inserted\n");
	}

	return 0;
}