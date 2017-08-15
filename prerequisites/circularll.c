#include <stdio.h>
#include <stdlib.h>


struct SinglyNode
{
	int data;
	struct SinglyNode *next;
};

struct DoublyNode
{
	int data;
	struct DoublyNode *next;
	struct DoublyNode *prev;
};


void insertbegin(struct SinglyNode **head, int data){

	struct SinglyNode *newnode = (struct SinglyNode *)malloc(sizeof(struct SinglyNode));
	newnode->data = data;
	if (*head == NULL)
	{
		newnode->next = newnode;
		*head = newnode;
	}else{
		struct SinglyNode *temp = *head;
		while(temp->next != (*head)){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = *head;
		*head = newnode;
	}
}

void insert(struct DoublyNode **root, int data){

	struct DoublyNode *newnode = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
	newnode->data = data;
	if (*root == NULL)
	{
		newnode->prev = newnode->next;
		newnode->next = newnode;
		*root = newnode;
	}else{

		struct DoublyNode *temp = *root;
		newnode->prev = temp->prev;
	printf("here\n");
		newnode->prev->next = newnode; // problem
		newnode->next = temp;
		temp->prev = newnode;
		*root = newnode;
	}
}

void showll(struct SinglyNode *head){

	struct SinglyNode *temp = head;
	while(head){
		printf("%d -->",head->data);
		if (head->next == temp)
		{
			break;
		}
		head = head->next;
	}
	printf("\n");
}

void show(struct DoublyNode *head){

	struct DoublyNode *temp = head;
	while(head){
		printf("%d -->",head->data);
		if (head->next == temp)
		{
			break;
		}
		head = head->next;
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	// struct SinglyNode *head = NULL;
	// insertbegin(&head,8);
	// insertbegin(&head,6);
	// insertbegin(&head,3);

	// showll(head);

	struct DoublyNode *root = NULL;
	insert(&root,8);
	show(root);
	insert(&root,6);
	show(root);
	insert(&root,3);
	show(root);

	return 0;
}