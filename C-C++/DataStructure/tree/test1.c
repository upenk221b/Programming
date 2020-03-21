#include<stdio.h>
#include<stdlib.h>
//Node
struct node{
	int data;
	struct node *left , *right;
};
struct node* createNode(int x){
	struct node *NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->data = x;
	NewNode->left = NULL;
	NewNode->right =NULL;
return NewNode;
}
struct node* insert(struct node *root, int x){
	if(root == NULL){
		return createNode(x);
	}
	else{
		if (x < root->data) 
        	root->left  = insert(root->left, x); 
   		 else if (x > root->data) 
       		 root->right = insert(root->right,x);
		else {
			printf("\t\t\t\t!!!!!!!DUPLICATES NOT ALLOWED IN BST!!!!!!!!");
				return root;
		}   
	}

}

struct node* deleteNode(struct node* root , int x){
	if(root = NULL){
		return root;	
	}
	//recursive calls untill root  becomes node to be deleted
	if(x < root->data){
		root->left = deleteNode(root->left,x);
	}
	else if(x > root->data){
		root->right = deleteNode(root->right,x);
	}
	else{
	//now the root is the node to be deleted
	//case 1: one of the node of node to be deleted id null
	if(root->left == NULL){
		struct node *temp;
		temp = root->right;
		free(root);
		return temp;
	}
	else if(root->left == NULL){
		struct node *temp;
		temp = root->right;
		free(root);
		return temp;
	}
	else{
		struct node *succesor,*succesorParent;
		succesor = root->right;
		
		while(succesor->left){
			succesorParent = succesor;
			succesor = succesor->left;
		}
		
		//copy the contents of succesor to succesor
		succesorParent->left = succesor->right;
		root->data = succesor->data;
		free(succesor);
		return root;		
	}
	}




}
void inorder(struct node *root){
	if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
}
int main(int argc , char argv[]){

	int a=0,x=0;
	struct node *root = NULL;
	while(a!=4){
	printf("\nEnter your choice :\n1.ADD an element to TREE.\n2.Delete an element from TREE\n3.Inorder traversal of TREE (DFS)\n4.EXIT\n---->");
	scanf("%d",&a);
		switch(a){
		case 1 : 
			printf("Enter the no you want to add : \n ---->");
			scanf("%d",&x);
			if(root == NULL){
				root =insert(root,x);
			}
			else insert(root,x);
			break;
		case 2 :printf("Enter the no you want to delete : \n ---->");
			scanf("%d",&x);
			deleteNode(root,x);
			break;
		case 3 :inorder(root);
			break;
		case 4 :printf("EXITING THE PROGRAM.......") ;
			break;
		default : printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ENTER A VALID OPTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			break;

		}//switch ends
}//while ends
return 0;
}
