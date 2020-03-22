#ifndef GRAPHLIST
    struct AdjListNode{
        int destination;
        struct AdjListNode *next;
    };

    struct AdjList{
    	struct AdjListNode *head;
    };

    struct Graph{
    int V;
    struct AdjList *array;
    };
    //function to create new node in AdjList
    struct AdjListNode* addNode(int destination);
    //function to create graph(uninitialized)
    struct Graph* createGraph(int V);
    //Add edge in a graph
    void addEdge(struct Graph* graph,int src , int dest);
    //print graph in adjescency list
    void printGraph(struct Graph* graph);
    int main(int argc , char** argv);
    #define GRAPHLIST
#endif
