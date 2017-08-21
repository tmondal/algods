#include <stdio.h>
#include <stdlib.h>


struct doublyll
{
	int data;
	struct doublyll *prev;
	struct doublyll *next;
};

void insertbegin(struct doublyll **head,int data){

	struct doublyll *newnode = (struct doublyll *)malloc(sizeof(struct doublyll));
	newnode->data = data;
	newnode->next = (*head);
	newnode->prev = NULL;
	if ((*head) != NULL)
	{
		(*head)->prev = newnode;
	}
	*head = newnode;
}

void insertend(struct doublyll **head, int data){

	struct doublyll *newnode = (struct doublyll *)malloc(sizeof(struct doublyll));
	newnode->data = data;
	newnode->next = NULL;
	struct doublyll *temp = *head;

	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
	}else{

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}


void showll(struct doublyll *head){

	while(head != NULL){
		printf("%d <-->",head->data);
		head = head->next;
	}
	printf("\n");
}

void insertafter(struct doublyll **head,int existval, int newdata){

	struct doublyll *temp = *head;
	while(temp != NULL){
		if (temp->data == existval)
		{
			struct doublyll *newnode = (struct doublyll *)malloc(sizeof(struct doublyll));
			newnode->data = newdata;
			newnode->next = temp->next;
			newnode->prev = temp;
			if (temp->next)
			{
				temp->next->prev = newnode;
			}
			temp->next = newnode;
			break;
		}else{
			temp = temp->next;
		}
	}
	if (temp->next == NULL)
	{
		printf("Node doesn't exist\n");
	}
}

void deleteNode(struct doublyll **head, struct doublyll *node){

	if ((*head) == NULL || node == NULL)
	{
		return;	
	}
	if ((*head) == node)
	{
		(*head) = (*head)->next; // for this double pointer needed
	}
	if (node->prev != NULL)
	{
		node->prev->next = node->next;
	}
	if (node->next != NULL)
	{
		node->next->prev = node->prev;
	}
	free(node);
}

int main(int argc, char const *argv[])
{
	
	struct doublyll *head = NULL;
	insertbegin(&head,8);
	insertbegin(&head,7);
	insertbegin(&head,5);

	showll(head);

	insertend(&head,6);
	insertend(&head,3);

	insertafter(&head,5,1);
	showll(head);

	deleteNode(&head,head->next);
	showll(head);
	return 0;
}