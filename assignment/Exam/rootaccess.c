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

// utility function of insert function
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

void enqueue(Tree *root, char data, char *str){

	int i = 0;
	// when "LMR" null
	if(root != NULL){
		root->queue->arr[root->queue->rear++] = data;
	}
	if(str == "LR"){
		if(root->left->right != NULL){
			root->left->right->queue->arr[root->left->right->queue->rear++] = data;
		}else{
			printf("Node does not exist!\n");
		}
	}	
}

char access(Tree *root,char *str){

	// base case
	if(strlen(str) == 0){

		if(root != NULL){
			char data = root->queue->arr[root->queue->front];
			return data;
		}		
	}
}


int main(){


	Tree *tree = initialize(10);
	insert(&tree);
	insert(&tree);
	insert(&tree);

	enqueue(tree,'r',"");
	enqueue(tree->left,'l',"");
	enqueue(tree->mid,'m',"");
	enqueue(tree->right,'r',"");

	printf("Accessed: %c\n",access(tree,""));	
	return 0;
}