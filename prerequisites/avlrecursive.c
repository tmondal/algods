#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node *left, *right;
	int height;
}Node;

Node *createNode(int data){
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->left = newnode->right = NULL;
	newnode->height = 1;
	newnode->data = data;
	return newnode;
}
int max(int a,int b){
	return (a > b)?a:b;
}

int Height(Node *root){
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}

Node *rotateright(Node *root){

	Node *child = root->left;
	Node *grandchild = root->left->left;

	Node *temp = NULL;
	temp = child->right;
	child->right = root;
	root->left = temp;

	// update height of root and child (order important)
	root->height = 1 + max(Height(root->left),Height(root->right));
	child->height = 1 + max(Height(child->left),Height(child->right));

	return child;
}

Node *rotateleft(Node *root){

	Node *child = root->right;
	Node *grandchild = root->right->right;

	Node *temp = NULL;
	temp = child->left;
	child->left = root;
	root->right = temp;

	// update height of root and child (order matters)
	root->height = 1 + max(Height(root->left),Height(root->right));
	child->height = 1 + max(Height(child->left), Height(child->right));

	return child;
}

Node *insert(Node *root, int data){
	// standard recursive insert
	Node *newnode = createNode(data);
	if (root == NULL)
	{
		return newnode;
	}
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right,data);
	}else{
		return root;
	}
	// update height of the current ancestor of the newly inserted node
	root->height = 1 + max(Height(root->left),Height(root->right));

	int bf = Height(root->left) - Height(root->right);
	// if bf is greater than 1
	// the case must be ll or lr
	if (bf > 1)
	{
		// check if ll
		if (data < root->left->data)
		{
			// apply ll rotation on the current node and return new root to its(subtree) parent
			return rotateright(root);
		}else{
			// apply lr rotation on the current node
			root->left = rotateleft(root->left);
			return rotateright(root);
		}
	}
	if (bf < -1)
	{
		// check rr
		if (data > root->right->data)
		{
			// apply rr rotation on the current node
			return rotateleft(root);
		}else{
			// apply rl rotation on the current node
			root->right = rotateright(root->right);
			return rotateleft(root);
		}
	}

	return root;
}

void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	Node *root = NULL;
	root = insert(root,20);
	root = insert(root,21);
	root = insert(root,22);
	printf("Root: %d\n", root->data);
	inorder(root);
	return 0;
}