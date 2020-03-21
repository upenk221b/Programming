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
struct Node* reverse (struct Node *head, int k)  
{  
   struct  Node* current = head;  
    struct Node* next = NULL;  
    struct Node* prev = NULL;  
    int count = 0;  
      
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)  
    head->next = reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev;  
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
int main(){
	struct Node* head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	insert(&head,6);
	display(&head);
	head = reverse(head,4);
	display(&head);

}
