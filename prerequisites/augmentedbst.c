#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	int rank;
	struct Node *left, *right;
}Node;

void insert(Node **root, int data){
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	if (*root == NULL){
		newnode->left = newnode->right = NULL;
		newnode->rank = 0;
		(*root) = newnode;
		return;
	}
	if (data < (*root)->data){
		(*root)->rank ++;
		insert(&(*root)->left,data);
	}
	else if(data > (*root)->data){
		insert(&(*root)->right,data);
	}
	else{
		printf("Duplicate value not allowed.\n");
	}
}

void k_thSmallest(Node *root,int *k){

	if (root == NULL){
		return;
	}
	if (root->left != NULL){
		k_thSmallest(root->left,k);
		(*k) --; // important 
	}
	if ((*k) == 1){
		printf("Node: %d\n", root->data);
		return;
	}
	if (root->right != NULL){
		(*k) --;
		k_thSmallest(root->right,k);
	}	
}

void augmentk_thSmallest(Node *root, int k){

	if (root == NULL){
		return;
	}
	if (root->rank + 1 == k){
		printf("Node_kth : %d\n", root->data);
		return;
	}
	else if (root->rank + 1 > k){
		augmentk_thSmallest(root->left,k);
	}else{
		k = k - (root->rank + 1);
		augmentk_thSmallest(root->right,k);
	}
}

void inorderShow(Node *root){

	if (root == NULL){
		return;
	}
	if (root->left != NULL){
		inorderShow(root->left);
	}
	printf("Val: %d Rank: %d\n", root->data, root->rank);
	if (root->right != NULL){
		inorderShow(root->right);
	}
}

int main(int argc, char const *argv[])
{
	Node *root = NULL;
	int k = 6;
	insert(&root,5);
	insert(&root,2);
	insert(&root,9);
	insert(&root,1);
	insert(&root,4);
	insert(&root,8);
	inorderShow(root);
	k_thSmallest(root,&k);
	// augmentk_thSmallest(root,k);
	return 0;
}