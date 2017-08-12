#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Term
{
	int coefficient,power;
	struct Term *next;
};

void createterm(struct Term **term, int coeffi, int pow){

	// insert at begining
	struct Term *newterm = (struct Term *)malloc(sizeof(struct Term));
	if (newterm)
	{		
		newterm->coefficient = coeffi;
		newterm->power	= pow;
		newterm->next = (*term);
		(*term) = newterm;
	}else{
		printf("Error!\n");
	}
	// print immediately after insersion
	struct Term *temp = (*term);
	while(temp != NULL){

		printf("%d*x^%d ", temp->coefficient,temp->power);
		if (temp->next != NULL)
		{
			printf("+ ");
		}
		temp = temp->next;
	}
	printf("\n");
}


struct Term *addpolly(struct Term **p1, struct Term **p2){


	struct Term *temp = *p1;
	struct Term *fake = *p2;

	struct Term *p3 = NULL;

	int count = 0;

	while(temp->next || fake->next){

		printf("count: %d\n", ++count);
		struct Term *newnode = (struct Term *)malloc(sizeof(struct Term));

		// if pow(p1) > pow(p2)
		if (temp->power > fake->power)
		{
			printf("temp\n");
			newnode->power = temp->power;
			newnode->coefficient = temp->coefficient;
			temp = temp->next;
		}
		else if (temp->power < fake->power)
		{
			printf("fake\n");
			newnode->power = fake->power;
			newnode->coefficient = fake->coefficient;
			fake = fake->next;
		}
		else{
			printf("equal\n");
			newnode->power = temp->power;
			newnode->coefficient = temp->coefficient + fake->coefficient;
			temp = temp->next;
			fake = fake->next;
		}
		newnode->next = p3;
		p3 = newnode;

	}
	while(temp->next){
		struct Term *newterm = (struct Term *)malloc(sizeof(struct Term));
		newterm->coefficient = newterm->coefficient;
		newterm->power = newterm->power;
		newterm->next = p3;
		p3 = newterm;
		temp = temp->next;
	}
	while(fake->next){
		struct Term *newterm = (struct Term *)malloc(sizeof(struct Term));
		newterm->coefficient = newterm->coefficient;
		newterm->power = newterm->power;
		newterm->next = p3;
		p3 = newterm;
		temp = temp->next;
	}

	return p3;
}

// void show(struct Term *term){
// 	while(term != NULL){

// 		printf("%d*x^%d + ", term->coefficient,term->power);
// 		term = term->next;
// 	}
// }

int main(int argc, char const *argv[])
{
	struct Term *p1 = NULL;
	struct Term *p2 = NULL;
	printf("Enter first polynomial :\n");
	char yes,y;
	int coeffi,pow;
	while(1){
		printf("Enter coefficient : ");
		scanf("%d",&coeffi);
		//getchar();
		printf("Enter power: ");
		scanf("%d",&pow);
		getchar(); // important don't forget
		printf("\n");

		createterm(&p1,coeffi,pow);

		printf("More term ? [y/n]\n");
		scanf("%c",&yes);

		if (yes == 'n' || yes == 'N' )
		{

			printf("Enter second polynomial: \n\n");
			while(1){
				printf("Enter coefficient : ");
				scanf("%d",&coeffi);
				printf("Enter power: ");
				scanf("%d",&pow);
				getchar();
				printf("\n");

				createterm(&p2,coeffi,pow);

				printf("More term ? [y/n]\n");
				scanf("%c",&y);
				if (y == 'n' || y == 'N')
				{
					break;
				}
			}
			break;
		}

	}

	struct Term *poly = addpolly(&p1,&p2);
	
	while(poly){
		printf("%d*x^%d ", poly->coefficient,poly->power);
		if (poly->next != NULL)
		{
			printf("+ ");
		}
		poly = poly->next;
	}

	return 0;
}