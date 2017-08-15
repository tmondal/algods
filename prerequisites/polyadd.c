#include <stdio.h>
#include <stdlib.h>

struct Term
{
	int coeffi,pow;
	struct Term *next;
};

void createnode(struct Term **root,int coeffi,int pow){

	struct Term *x,*y = *root;

	x = (struct Term *)malloc(sizeof(struct Term));
	if ((*root) == NULL)
	{
		x->coeffi = coeffi;
		x->pow = pow;
		x->next = NULL;
		(*root) = x;	
	}else{

		while(y->next){
			y = y->next;
		}
		y->next = x;
		x->next = NULL;
		x->coeffi = coeffi;
		x->pow = pow;
	}
}

void show(struct Term *root){
	while(root){
		printf("%d*x^%d ", root->coeffi, root->pow);
		if (root->next)
		{
			printf("+ ");
		}
		root = root->next;
	}
	printf("\n");
}

void addpoly(struct Term **p1, struct Term **p2, struct Term **p){

	struct Term *temp = *p1;
	struct Term *temp2 = *p2;
	while(temp && temp2){

		if (temp->pow > temp2->pow)
		{
			createnode(p,temp->coeffi,temp->pow);
			temp = temp->next;
		}
		else if (temp->pow < temp2->pow)
		{
			createnode(p,temp2->coeffi,temp2->pow);
			temp2 = temp2->next;
		}
		else if (temp->pow == temp2->pow)
		{
			createnode(p,temp->coeffi + temp2->coeffi, temp->pow);
			temp = temp->next;
			temp2 = temp2->next;
		}
	}

	while(temp){
		createnode(p,temp->coeffi,temp->pow);
		temp = temp->next;
	}
	while(temp2){
		createnode(p,temp2->coeffi,temp2->pow);
		temp2 = temp2->next;
	}
}

// void multiply(struct Term **p1, struct Term **p2, struct Term *p){
// 	struct Term *temp = *p1;
// 	struct Term *temp2 = *p2;

	
// }

int main(int argc, char const *argv[])
{
	
	struct Term *p1 = NULL,*p2 = NULL,*p = NULL;

	createnode(&p1,8,3);
	createnode(&p1,6,2);
	createnode(&p1,4,0);
	show(p1);
	createnode(&p2,7,4);
	createnode(&p2,5,3);
	createnode(&p2,3,1);
	show(p2);
	addpoly(&p1,&p2,&p);
	show(p);
	return 0;
}