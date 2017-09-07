#include<stdio.h>
#include<stdlib.h>
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

void traversal(Tree *tree){

	// base case
	if(tree == NULL){
		return;
	}
	// call left link recursively
	if(tree->left != NULL){
		traversal(tree->left);
	}
	if(tree->mid != NULL){
		traversal(tree->mid);
	}
	// print current node
	int f = tree->queue->front ;
	int r = tree->queue->rear;
	while(f != r - 1){ // r-1 as r increases after enqueue
		printf("%c-->",tree->queue->arr[++f]);
	}
	printf("\n");
	
	if(tree->right != NULL){
		traversal(tree->right);
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

char dequeue(Tree *root, char *str){
	// base case when "LMR" null
	if(strlen(str) == 0){

		if(root != NULL){
			char data = root->queue->arr[++root->queue->front];
			return data;
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

void destroy(Tree *tree,char *str){
	
	// when "LMR" null 
	if(strlen(str) == 0){
		if(tree != NULL){
			free(tree->queue);
			free(tree);
		}
	}
}


int main(){


	Tree *tree = initialize(10);
	insert(&tree);
	insert(&tree);
	insert(&tree);
	
	
	// inserting character in the queue instead of datetime
	enqueue(tree,'r',"");
	enqueue(tree,'o',"");
	enqueue(tree,'o',"");
	enqueue(tree,'t',"");
	
	enqueue(tree->left,'l',"");
	enqueue(tree->left,'e',"");
	enqueue(tree->left,'f',"");
	enqueue(tree->left,'t',"");

	enqueue(tree->mid,'m',"");
	enqueue(tree->mid,'i',"");
	enqueue(tree->mid,'d',"");
	enqueue(tree->right,'r',"");
	enqueue(tree->right,'i',"");
	enqueue(tree->right,'g',"");
	enqueue(tree->right,'h',"");
	enqueue(tree->right,'t',"");
	
	// traverse the tree
	traversal(tree);
	
	// Dequeue from particular tree node
	printf("Dequed: %c\n",dequeue(tree,""));
	printf("dequed: %c\n",dequeue(tree->left,""));
	
	traversal(tree);

	printf("Accessed: %c\n",access(tree,""));
	
	// destroy a subtree
	destroy(tree,"");
	return 0;
}
