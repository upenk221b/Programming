#include<stdio.h>
#include"path/to/module.h" //e.g.#include "DataStructure/graphs/GraphList.h"
int main(int argc , char** argv){
	int a=0,v=0;
	int src,dest;
	while(a!=4){
	printf("*********[----] Module Test********\nEnter your choice :\n1.CREATE GRAPH .\n2.ADD EDGE\n3.PRINT\n4.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 1 :
			printf("Enter the no of vertices : \n ---->");
			scanf("%d",&v);
            /*function call here
			e.g.struct Graph* g = createGraph(v);*/
			break;

		case 2 :printf("Enter the source vertex : \n ---->");
			scanf("%d",&src);
			printf("Enter the destination vertex : \n ---->");
			scanf("%d",&dest);

            /*function call here
			e.g.struct Graph* g = createGraph(v);*/
			break;

		case 3 :/*function call here
        e.g.struct Graph* g = createGraph(v);*/
			break;
		case 4 :/*function call here
        e.g.struct Graph* g = createGraph(v);*/
			break;
		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends

	}//while ends1
return 0;
}
