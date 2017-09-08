#include <stdio.h>
#include <stdlib.h>

typedef struct Bst Bst;
typedef struct Bst
{
	int data;
	Bst *left;
	Bst *right;
	Bst *parent;
}Bst;

Bst	*createNode(int data){
	Bst *newnode = (Bst *)malloc(sizeof(Bst));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	newnode->parent = NULL;
	return newnode;
}

void insert(Bst **root, int data){
	

	Bst *temp = createNode(data);
	Bst *parent = NULL;

	while(*root != NULL){

		if(data	< (*root)->data){
			parent = (*root);
			(*root) = (*root)->left;
		}
		else if (data > (*root)->data)
		{
			parent = (*root);
			(*root)= (*root)->right;
		}else{
			printf("Duplicate not allowed.\n");
			break;
		}
	}
	if (*root == NULL)
	{
		temp->parent = parent;
		(*root) = temp;
	}
}

void inorder(Bst *root){
	if (root == NULL)
	{
		return;
	}
	while(root != NULL){
		while(root->left != NULL){
			root = root->left;
		}
		if (root->parent)
		{
			printf("%d ",root->parent->data);
		}else{
			printf("%d ", root->data);
		}
		
	}

}

int main(int argc, char const *argv[])
{
	Bst *root = NULL;
	insert(&root,5);	
	return 0;
}