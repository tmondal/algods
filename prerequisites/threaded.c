#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Threaded
{
	int data;
	struct Threaded *left, *right;
	bool rightthread, leftthread;
}Threaded;

Threaded *insert(Threaded *root, int data){

	Threaded *newnode = (Threaded *)malloc(sizeof(Threaded));
	newnode->data = data;
	
}

void inorder(Threaded *root){
	while(root){

		
	}
}

void recursiveinorder(Threaded *root){
	if (root == NULL){
		return;
	}
	if (root->left != NULL){
		recursiveinorder(root->left);
	}
	printf("%d\n", root->data);
	if (root->right != NULL){
		recursiveinorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	Threaded *root = NULL;
	root = insert(root,5);
	root = insert(root,4);
	root = insert(root,7);
	// inorder(root);
	recursiveinorder(root);	
	return 0;
}