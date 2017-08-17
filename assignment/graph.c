// Adjacent matrix representation

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	int vertices,i,j;
	printf("Enter no of vertices: ");
	scanf("%d",&vertices);
	// define a matrix of size v*v
	int matrix[vertices][vertices];

	// populate matrix
	printf("Enter 1 if corresponding vertices are adjacent else 0 \n"); 
	for (i = 0; i < vertices; ++i){
		for (j = 0; j < vertices; ++j)
		{
			printf("Value for [%d,%d]: ", i,j);
			scanf("%d",&matrix[i][j]);
		}		
	}

	// show the matix
	for (i = 0; i < vertices; ++i)
	{
		for (j = 0; j < vertices; ++j)
		{
			printf("%d ", matrix[i][j]);		
		}
		printf("\n");
	}	
	return 0;
}