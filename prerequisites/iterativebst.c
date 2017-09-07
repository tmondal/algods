#include <stdio.h>
#include <stdlib.h>

typedef struct Bst Bst;
typedef struct Bst
{
	int data;
	Bst *left;
	Bst *right;
}Bst;

Bst	*createNode(int data){
	Bst *newnode = (Bst *)malloc(sizeof(Bst));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void insert(Bst **root, int data){
	

	Bst *temp = createNode(data);
	
}

int main(int argc, char const *argv[])
{
	Bst *root = NULL;
	insert(&root,5);	
	return 0;
}