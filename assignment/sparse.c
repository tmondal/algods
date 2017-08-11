#include <stdio.h>


int main(int argc, char const *argv[])
{
	int i,j,count = 0,count_two = 0,k = 0;

	// get sparse matrix
	int sparse[4][5] = {

		{0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
	};

	int sparse_two[4][5] = {

		{1 , 0 , 2 , 0 , 0 },
        {0 , 6 , 0 , 0 , 5 },
        {0 , 0 , 7 , 0 , 0 },
        {3 , 0 , 8 , 0 , 0 }
	};

	// count no of non-zero entries
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (sparse[i][j] != 0)
			{
				count ++;
			}
		}
	}

	// now define compact matrix where row always 3(rows,coloum and value)
	int compact[3][count];

	// populate compact matrix
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (sparse[i][j] != 0)
			{
				compact[0][k] = i;
				compact[1][k] = j;
				compact[2][k] = sparse[i][j];
				k++;
			}
		}
	}

	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (sparse[i][j] != 0)
			{
				count_two ++;
			}
		}
	}

	int compact_two[3][count_two];
	k = 0;
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (sparse_two[i][j] != 0)
			{
				compact_two[0][k] = i;
				compact_two[1][k] = j;
				compact_two[2][k] = sparse_two[i][j];
				k++;
			}
		}
	}


	for (i=0; i<3; i++)
    {
        for (j = 0; j < count; j++){
            printf("%d ", compact[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for (i=0; i<3; i++)
    {
        for (j = 0; j < count_two; j++){
            printf("%d ", compact_two[i][j]);
        }
        printf("\n");
    }

	return 0;
}