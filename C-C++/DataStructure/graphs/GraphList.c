//this is the adjascency list representation of graph
#include<stdio.h>
#include<stdlib.h>
#include"GraphList.h"

//function to create new node in AdjList
struct AdjListNode* addNode(int destination){
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->destination = destination;
	newNode->next = NULL;
	return newNode;
}
//function to create graph(uninitialized)
struct Graph* createGraph(int V){
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));
	for(int i=0; i < V; i++){
		graph->array[i].head = NULL;
	}
return graph;
}
//Add edge in a graph
void addEdge(struct Graph* graph,int src , int dest){
	struct AdjListNode* newNode = addNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	//node added each time at the begining of list
	//do same for dest vertex

	newNode = addNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}
//print graph in adjescency list
void printGraph(struct Graph* graph){
	for(int i= 0; i < graph->V; i++){
		struct AdjListNode* current = graph->array[i].head;
		printf("AdjList for Vertex %d is head",i);
		while(current){
		printf("->%d",current->destination);
		current = current->next;
		}//while ends
		printf("\n");
	}//for ends


}
/** main function to check the module*/
// int main(int argc , char** argv){
// 	int a=0,v=0;
// 	int src,dest;
// 	while(a!=4){
// 	printf("*********GRAPH ADJACENCY LIST********\nEnter your choice :\n1.CREATE GRAPH .\n2.ADD EDGE\n3.PRINT\n4.EXIT\n---->");
// 	scanf("%d",&a);
// 		switch(a){
// 		case 1 :
// 			printf("Enter the no of vertices : \n ---->");
// 			scanf("%d",&v);
// 			struct Graph* g = createGraph(v);
// 			break;
//
// 		case 2 :printf("Enter the source vertex : \n ---->");
// 			scanf("%d",&src);
// 			printf("Enter the destination vertex : \n ---->");
// 			scanf("%d",&dest);
//
// 			addEdge(g,src,dest);
// 			break;
//
// 		case 3 :printGraph(g);
// 			break;
// 		case 4 :printf("EXITING THE PROGRAM.......\n") ;
// 			break;
// 		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
// 			break;
//
// 		}//switch ends
//
// 	}//while ends1
// return 0;
// }
