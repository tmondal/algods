#include <stdio.h>
#include <stdlib.h>


struct Queue {

	
};

struct ListNode
{
	int adjNodeval;
	struct ListNode *next;
};

struct AdjList
{
	struct ListNode *head; // head pointer to a list of list node
};

struct Graph
{
	int vertices;
	struct AdjList *array;
};

struct Graph *createGraph(int vertices){

	int i;
	struct Graph *newgraph = (struct Graph *)malloc(vertices*sizeof(struct Graph));
	newgraph->vertices = vertices;
	newgraph->array = (struct AdjList *)malloc(vertices*sizeof(struct AdjList));
	for (i = 0; i < vertices; ++i)
	{
		newgraph->array[i].head = NULL;
	}
	return newgraph;
}

void addEdge(struct Graph *graph, int vertices, int adjacency){

	if (vertices < graph->vertices && adjacency < graph->vertices)
	{
		
		struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
		newnode->next = graph->array[vertices].head;
		newnode->adjNodeval = adjacency;
		graph->array[vertices].head = newnode;

		struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->next = graph->array[adjacency].head;
		node->adjNodeval = vertices;
		graph->array[adjacency].head = node;
	}else{
		printf("Error!\n");
	}

}

void deleteEdge(struct Graph *graph, int u, int v){

	if (u < graph->vertices && v < graph->vertices)
	{
		struct ListNode *current = graph->array[u].head;
		struct ListNode *prev;
		if (current != NULL && current->adjNodeval == v)
		{
			graph->array[u].head = current->next;
			free(current);
		}else{

			while(current != NULL && current->adjNodeval != v){
				prev = current;
				current = current->next;
			}
			if (current == NULL)
			{
				printf("Not found\n");
			}else{
				prev->next = current->next;
				free(current);
			}
		}
	}

	if (u < graph->vertices && v < graph->vertices)
	{
		
		struct ListNode *current_2 = graph->array[v].head;
		struct ListNode *prev_2;
		if (current_2 != NULL && current_2->adjNodeval == u)
		{
			graph->array[v].head = current_2->next;
			free(current_2);
			return;
		}
		while(current_2 != NULL && current_2->adjNodeval != u){
			prev_2 = current_2;
			current_2 = current_2->next;
		}
		if (current_2 == NULL)
		{
			return;
		}
		prev_2->next = current_2->next;
		free(current_2);
	}
	
}

void bfs(struct Graph *graph){


}

void showGraph(struct Graph *graph){

	int i;
	for (i = 0; i < graph->vertices; ++i)
	{
		struct ListNode *temp = graph->array[i].head;
		printf("[%d]head -->",i);
		while(temp){
			printf("%d --> ", temp->adjNodeval);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	// Adjacency List representation
	struct Graph *graph = createGraph(5);
	addEdge(graph,3,4);
	addEdge(graph,3,2);
	addEdge(graph,1,4);
	showGraph(graph);
	deleteEdge(graph,1,4);
	showGraph(graph);
	bfs(graph);
	return 0;
}