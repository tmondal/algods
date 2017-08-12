#include <stdio.h>
#include <stdlib.h>

struct singlyll
{
	int data;
	struct singlyll *next;
};

void insertfirst(struct singlyll **head, int data){

	struct singlyll *newnode = (struct singlyll *)malloc(sizeof(struct singlyll));
	newnode->data = data;
	newnode->next = (*head);
	(*head) = newnode;
}

void insertend(struct singlyll **head, int data){

	struct singlyll *newnode = (struct singlyll *)malloc(sizeof(struct singlyll));
	struct singlyll *temp = *head;
	
	newnode->data = data;
	if ((*head) == NULL)
	{
		newnode->next = NULL;
		(*head) = newnode;
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
}

void insertAfter(struct singlyll **head, int data, int newdata){

	struct singlyll *temp = (*head);
	while(temp != NULL){
		if (temp->data == data)
		{
			struct singlyll *newnode = (struct singlyll *)malloc(sizeof(struct singlyll));
			newnode->data = newdata;
			newnode->next = temp->next;
			temp->next = newnode;
			break;
		}else{

			temp = temp->next;
		}
	}

	if (temp == NULL)
	{
		printf("Target node not present\n");
	}

}

void showll(struct singlyll **head){

	struct singlyll *temp = *head;

	while(temp != NULL){
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	struct singlyll *head = NULL;

	insertfirst(&head,5);
	insertfirst(&head,6);
	insertfirst(&head,7);

	showll(&head);
	// insertend(&head,9);
	// showll(&head);
	// insertAfter(&head,9,1);
	// showll(&head);
	return 0;
}