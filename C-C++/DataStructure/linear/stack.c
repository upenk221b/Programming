#include<stdio.h>
#include<stdlib.h>
#define MAX_VALUE 100
struct Stack{
	int data[MAX_VALUE];
	int top;
};

void init(struct Stack *s){
	s->top =-1;
	
}
int isFull(struct Stack *s){
	if(s->top == MAX_VALUE -1)
		return 1;
return 0;
}

int isEmpty(struct Stack *s){
	if(s->top == -1)
		return 1;
return 0;
}

void push(struct Stack *s , int x){
	if(isFull(s)){
	printf("STACK OVERRFLOW OCCURED!");	
	}
	else{
	s->top++;
	s->data[s->top] = x;
	}

}
int pop(struct Stack *s){
	int x;
	if(isEmpty(s)){
	printf("STACK IS EMPTY");	
	}
	else{
	
	x= s->data[s->top];
	s->top--;
	}
return x;
}
void print(struct Stack *s){
	
	if(s->top == -1){
	printf("stack is empty\n");
	}
	else{
	printf("Stack contents Top to down: \n");
	for(int i = s->top; i >= 0 ; i--){
	printf("%d \n",s->data[i]);
	}
	}	
}
int main(int argc ,char* argv ){
	int a=0,x=0;
	struct Stack k;

	while(a!=4){
	printf("\nEnter your choice :\n0.CREATE AND INITIALIZE STACK\n1.ADD an element to Queue.\n2.Delete an element from Queue\n3.PRINT the current Queue\n4.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 0 : init(&k);
			printf("QUEUE CREATED!\n") ;
			break;
		case 1 : 
			printf("Enter the no you want to add : \n ---->");
			scanf("%d",&x);
			push(&k,x);
			break;

		case 2 :pop(&k);
			break;
		
		case 3 : print(&k);
			break;
		case 4 :printf("EXITING THE PROGRAM.......") ;
			break;
		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends
}//while ends
return 0;
}
