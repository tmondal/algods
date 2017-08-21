#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
}Tree;

Tree *insertNode(Tree *tree, int data){
	if (tree == NULL){

		Tree *newnode = (Tree *)malloc(sizeof(Tree));
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		return newnode; // new root
	}
	if (tree->data > data)
	{
		tree->left = insertNode(tree->left,data);
	}else if (tree->data < data)
	{
		tree->right = insertNode(tree->right,data);
	}else{
		printf("No duplicate allowed.\n");
	}

	// return unchanged root
	return tree;
}

void inordertraversal(Tree *root){

	if(root != NULL){
		if (root->left)
		{
			inordertraversal(root->left);
		}
		printf("%d\n", root->data);
		if (root->right)
		{
			inordertraversal(root->right);
		}
	}
}

void search(Tree *root,int data){
	if (root == NULL)
	{
		printf("Not found\n");
		return;
	}

	if (root->data == data)
	{
		printf("Data found.\n");
	}else if (root->data > data)
	{
		search(root->left,data);
	}else{
		search(root->right,data);
	}
}

void inorderpredecessor(Tree *root,Tree *pre,int key){

	if (root == NULL) {return;}

	if (root->data == key)
	{
		if (root->left != NULL)
		{
			Tree *temp = root->left;
			while(temp->right){
				temp = temp->right;
			}
			printf("Predecessor: %d\n", temp->data);
		}else{

			printf("P : %d\n", pre->data);
		}
	}
	else if (root->data > key)
	{
		inorderpredecessor(root->left,pre,key);
	}
	else{
		pre = root;
		inorderpredecessor(root->right,pre,key);
	}
}

void inordersuccesor(Tree *root,Tree *succ, int key){

	if (root == NULL) {return;}

	if (root->data == key)
	{
		if (root->right != NULL)
		{
			Tree *temp = root->right;
			while(temp->left){
				temp = temp->left;
			}
			printf("Successor: %d\n", temp->data);
		}else{

			printf("S : %d\n", succ->data);
		}
	}
	else if (root->data > key)
	{
		succ = root;
		inordersuccesor(root->left,succ,key);
	}
	else{
		inordersuccesor(root->right,succ,key);
	}
}

Tree *deleteNode(Tree *root, int data){

	// node found to be deleted
	if (root->data == data)
	{
		// covers only left child and no child
		if (root->right == NULL)
		{
			Tree *new = root->left;
			free(root);
			return new;
		}
		// only right child
		else if (root->left == NULL)
		{
			Tree *temp = root->right;
			free(root);
			return temp;
		}
		else{
			// find inorder successor then swap with the node then delete the successor
			Tree *temp = root->right;
			while(temp->left){
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	else if (data < root->data){
		root->left = deleteNode(root->left,data);
	}else{
		root->right = deleteNode(root->right,data);
	}

	return root;
}

int isBst(Tree *tree, int min, int max){
	if (tree == NULL){
		return 1;
	}
	if (tree->data < min || tree->data > max){
		return 0;
	}
	else{
		isBst(tree->left,min,tree->data -1);
		isBst(tree->right,tree->data + 1, max);
	}
}

void Lca(Tree *root, int key1, int key2){
	if (key1 < key2)
	{
		while(root != NULL){
			if (root->data > key1 && root->data < key2)
			{
				printf("lca: %d\n", root->data);
				break;
			}
			if (root->data > key2)
			{
				root = root->left;
			}
			if (root->data < key1)
			{
				root = root->right;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Tree *tree = NULL, *succ = NULL,*pre = NULL;
	tree = insertNode(tree,50);
	insertNode(tree,40);
	insertNode(tree,60);
	insertNode(tree,30);
	insertNode(tree,45);
	insertNode(tree,25);
	insertNode(tree,55);
	insertNode(tree,70);

	inordertraversal(tree);
	// search(tree,20);

	// inorderpredecessor(tree,pre,55);
	inordersuccesor(tree,succ,45);

	deleteNode(tree,50);
	deleteNode(tree,30);
	inordertraversal(tree);
	if(isBst(tree,-1,100)){
		printf("Bst\n");
	}
	Lca(tree,25,45);
	return 0;
}