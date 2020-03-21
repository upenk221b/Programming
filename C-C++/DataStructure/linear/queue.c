#include<stdio.h>
#include<stdlib.h>
#define MAX_LIMIT 20

struct Queue{
int f,r;
int data[MAX_LIMIT];
};

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


//MAIN FUNCTION
int main(int argc , char argv[]){
	int a=0,x=0;
	struct Queue queue,*q;
	q = &queue;

	while(a!=4){
	printf("\nEnter your choice :\n0.CREATE AND INITIALIZE QUEUE\n1.ADD an element to Queue.\n2.Delete an element from Queue\n3.PRINT the current Queue\n4.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 0 : init(q);
			printf("QUEUE CREATED!\n") ;
			break;
		case 1 : 
			printf("Enter the no you want to add : \n ---->");
			scanf("%d",&x);
			insertInQueue(q,x);
			break;

		case 2 :deleteFromQueue(q);
			break;
		
		case 3 : print(q);
			break;
		case 4 :printf("EXITING THE PROGRAM.......") ;
			break;
		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends

	}//while ends


return 0;}//MAIN ends
