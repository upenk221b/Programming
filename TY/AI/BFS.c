//this is the adjascency list representation of graph
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIMIT 200

//AdjListNOde
//This represents that particular vertex is adj to destination vertex
struct AdjListNode{
	int destination;
	struct AdjListNode *next;
};
//AdjList structure
//initially for each vertex this head is NULL
struct AdjList{
	struct AdjListNode *head;
};
//struct for graph
struct Graph{
int V;
struct AdjList *array;
};

struct Queue{
int f,r;
int data[MAX_LIMIT];
};

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

//functions to work with Queue
//0.initialize the queue data structure

void init(struct Queue *q){
	q->f=-1;
	q->r=-1;
}

//other boolean functions for checking status of queue.
int isFull(struct Queue *q){
	if(q->r == (MAX_LIMIT-1))
		return 1;
return 0;	

}

int isEmpty(struct Queue *q){
	if(q->f == q->r)
		return 1;
return 0;
}

//1.adding a element to queue(at rear)
void insertInQueue(struct Queue *q, int x){
	if(isFull(q)){
	printf("QUEUE IS FULL");
	}
	else{
	q->r++;
	q->data[q->r] = x;

	}
}

//2.Delete
void deleteFromQueue(struct Queue *q){
	if(isEmpty(q)){
	printf("QUEUE IS EMPTY");
	}
	else{
	q->f++;
	}
}
//3.PRINT
void print(struct Queue *q){
	for(int i= q->f+1 ; i <= q->r ; i++){
	printf("(%d)->",q->data[i]);
	}
}

void BFS(struct Graph *g , struct Queue *q,int start){
	int visited[g->V];
	for(int i = 0; i < g->V; i++) {
		 visited[i] = 0; 
	}
	printf("visited initaialized\n");
	visited[start] =1;
	insertInQueue(q,start);
	printf("%d inserted in queue\n",start);
	printf("isEmpty :%d\n",isEmpty(q));
	while(!isEmpty(q)){
		printf("inside while !empty\n");
		start = q->data[q->f];
		printf("start : %d",start);
		deleteFromQueue(q);

		struct AdjListNode *temp = g->array[start].head;
		while(temp){
			if(visited[temp->destination]==0){
			visited[(temp->destination)] = 1;
			insertInQueue(q,temp->destination);
			printf("\n%d inserted in queue\n",temp->destination);
			temp = temp->next;
			}
			print(q);
		}

	}
return;
}
int main(int argc , char argv[]){
	//initialize both Data structures Graph and Queue
	struct Queue queue,*q;
	q = &queue;
	
	//Queue of MAX_SIZE created and initialized 
	//graph with n nodes created and initialized ;
	int a=0,v=0;
	int src,dest;
	while(a!=5){
	printf("*********GRAPH ADJACENCY LIST********\nEnter your choice :\n1.CREATE GRAPH and queue.\n2.ADD EDGE\n3.BFS\n4.PRINT\n5.EXIT---->");
	scanf("%d",&a);
		switch(a){
		case 1 : 
			printf("Enter the no of vertices : \n ---->");
			scanf("%d",&v);
			struct Graph* g = createGraph(v);
			init(q);
			break;

		case 2 :printf("Enter the source vertex : \n ---->");
			scanf("%d",&src);
			printf("Enter the destination vertex : \n ---->");
			scanf("%d",&dest);
			
			addEdge(g,src,dest);
			break;
		
		case 3 :BFS(g,q,0);
			break;
		case 4 :printGraph(g);
			break;
		case 5 :printf("EXITING THE PROGRAM.......\n") ;
			break;
		default : printf("!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends

	}//while ends
	
	
return 0;
}
