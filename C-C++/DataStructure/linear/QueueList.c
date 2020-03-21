#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next; 
}*front,*rear;

void insertInQueue(int x){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	if(newNode == NULL){
		printf("MEMORY OVERFLOW!!!");
	}else
	{
	newNode->data = x;
	if(front == NULL){
		front = newNode;
		rear = newNode;
		front -> next = NULL;  
            	rear -> next = NULL;  

	}
	else{
		rear->next = newNode;
		rear = newNode;
		rear->next = NULL;
	}
	}
}
void deleteFromQueue(){
	struct Node* temp;
	if(front == NULL){
		printf("UNDERFLOW");
	}
	else{
		temp = front;
		front = front->next;
		free(temp);
	}

}
void display(){
struct Node* temp;
temp = front;
	while(temp){
	printf("(%d)--",temp->data);
	temp = temp->next;
	}


}
int main(int argc ,char argv[]){
	int a=0,x=0;
	while(a!=4){
	printf("\nEnter your choice :\n1.ADD an element to Queue.\n2.Delete an element from Queue\n3.PRINT the current Queue\n4.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 1 : 
			printf("Enter the no you want to add : \n ---->");
			scanf("%d",&x);
			insertInQueue(x);
			break;

		case 2 :deleteFromQueue();
			break;
		
		case 3 : display();
			break;
		case 4 :printf("EXITING THE PROGRAM.......") ;
			break;
		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends

	}//while ends

return 0;
}
