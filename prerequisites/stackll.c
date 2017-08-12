// implement a singly list which should work as a stack

#include <stdio.h>
#include <stdlib.h>


struct List
{
	int data;
	struct List *next;
};


void push(struct List **root, int data){

	// Actually inserting at begining
	struct List *newnode = (struct List *)malloc(sizeof(struct List));
	newnode->data = data;
	newnode->next = (*root);
	(*root) = newnode;	
}

int pop(struct List **root){

	// delete from begining
	int ret = (*root)->data;
	struct List *temp = *root;
	*root = (*root)->next;
	free(temp);
	return ret;
}

void show(struct List *root){
	if (root == NULL)
	{
		printf("No element\n");
		return;
	}
	printf("Stack is : \n");
	while(root){
		printf("%d\n", root->data);
		root = root->next;
	}
}

int main(int argc, char const *argv[])
{
	
	struct List *root = NULL;

	push(&root,8);
	push(&root,7);

	show(root);

	printf("poped: %d\n", pop(&root));

	show(root);
	push(&root,4);
	push(&root,2);
	show(root);

	return 0;
}