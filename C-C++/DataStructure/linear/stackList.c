#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
}*top;

void push(int x){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	if(newNode == NULL){
		printf("Memory Overflow!!");
	}
	else{
	newNode->data = x;
		if(top == NULL){
			top = newNode;				
		
		}
		else{
		newNode->next = top;
		top = newNode;
		}
	}
}

int pop(){
	int x;
	if(top == NULL){
	printf("Stack is Empty");
	}
	else{
	x =top->data;
	top = top->next;
	}
return x;
}
void display(){
struct Node* temp;
temp = top;
	printf("Stack content Top to Down: \n");
	while(temp){
	printf("(%d)\n",temp->data);
	temp = temp->next;
	}


}
int main(int argc , char argv[]){
	int a=0,x=0;
	while(a!=4){
	printf("\nEnter your choice :\n1.PUSH.\n2.POP\n3.PRINT\n4.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 1 : 
			printf("Enter the no you want to add : \n ---->");
			scanf("%d",&x);
			push(x);
			break;

		case 2 :pop();
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
