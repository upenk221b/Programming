#include<stdio.h>
#include<stdlib.h>
//Graph structure
struct Graph{
	int V;
	int** arr;
};
struct Graph createGraph(struct Graph* g,int V){
	g->V = V;
	g->arr = (int**)calloc(V,sizeof(int));
	for(int i=0; i< V; i++){
		g->arr[i] = (int*)calloc(V,sizeof(int));	
	}
	
return *g;
}
int main(int argc , char argv[]){
	struct Graph graph;
	graph = createGraph(&graph,5);	
	for(int i=0; i<graph.V; i++){
		for(int j=0; j< graph.V; j++){
			printf("%d ",graph.arr[i][j]);	
		}
		printf("\n");
	}
		
return 0;
}
