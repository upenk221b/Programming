#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
void insert(struct Node** head , int x){
	struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));	
	struct Node *temp = *head;
	if(NewNode == NULL){
		printf("MEMORY INSUFFICIENT!!");
	}
	else{
		NewNode->data = x;
		NewNode->next = NULL;
		if(*head == NULL){
			*head = NewNode;
			return;
		}
		
			temp = *head;
		while(temp->next != NULL){
			temp = temp->next;	
		}
		temp->next = NewNode;
		return;
		
	}

}
void delete(struct Node** head){
	struct Node *temp = *head,*p;
	if(*head == NULL){
			printf("CAN NOT DELETE,LIST EMPTY!");
			return;
	}
	else{
	temp = *head;
		while(temp->next->next != NULL){
			temp = temp->next;	
		}
	temp->next = NULL;
	p= temp->next;
	free(p);

	}

}
void display(struct Node** head){
	if(*head== NULL){
		printf("LIST IS EMPTY!!!\n");
	}
	else{
		struct Node *temp = *head;
		while(temp){
			printf("(%d)->",temp->data);
			temp = temp->next;	
		}
		printf("\n");
	}


}
void reverseList(struct Node** head){
	struct Node *curr,*prev,*nex;
	prev=nex=NULL;
	curr = *head;
	while(curr!=NULL){
		nex=curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;	
	}
	*head=prev;
}
int detectRemoveLoop(struct Node** head){
	struct Node* slow= *head;
	struct Node* fast= *head;
	while(fast && fast->next!=NULL){
	slow = slow->next;
	fast = fast->next->next;
	}
	if(slow == fast){
		printf("LOOP DETECTED!!\n");
		//LOOP REMOVAL CODE HERE
		//SET SLOW = HEAD AND MOVE BOTH POINTER AT SAME PACE TILL THEY COLLIDE ...
		//NODE WHERE THEY MEET IS FIRST NODE OF LOOP
		slow = *head;
		while(slow->next != fast->next){
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;//or fast->next=NULL
		printf("LOOP REMOVED!!\n");
		return 1;
	}
	
printf("NO LOOP DETECTED!!\n");
return 0;

}

int main(int argc , char argv[]){ 
	struct Node* head = NULL;
	int a=0,x=0;
	while(a!=6){
	printf("********LINKED LIST********\nEnter your choice :\n0.REVERSE\n1.INSERT .\n2.DELETE\n3.PRINT\n4.MAKE LOOP\n5.DETECT AND REMOVE LOOP\n6.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 0 :reverseList(&head);
			break;

		case 1 : 
			printf("Enter the no you want to add : \n ---->");
			scanf("%d",&x);
			insert(&head , x);
			break;

		case 2 :delete(&head);
			break;
		
		case 3 :display(&head);
			break;

		case 4 :head->next->next->next->next->next = head->next->next;//makeLoop(&head);
			break;

		case 5:detectRemoveLoop(&head);
			break;

		case 6 :printf("EXITING THE PROGRAM.......\n") ;
			break;

		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends

	}//while ends
return 0;
}
