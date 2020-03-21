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

struct node* deleteNode(struct node* root, int k) 
{ 
    // Base case 
    if (root == NULL) 
        return root; 
  
    // Recursive calls for ancestors of 
    // node to be deleted 
    if (root->data > k) { 
        root->left = deleteNode(root->left, k); 
        return root; 
    } 
    else if (root->data < k) { 
        root->right = deleteNode(root->right, k); 
        return root; 
    } 
  
    // We reach here when root is the node 
    // to be deleted. 
	//has no children
  	if (root->left == NULL && root->right == NULL) {  
        free(root); 
	return root;
        
    } 
    // If one of the children is empty 
    else if (root->left == NULL) { 
        struct node* temp = root->right; 
        free(root); 
        return temp; 
    } 
    else if (root->right == NULL) { 
        struct node* temp = root->left; 
        free(root); 
        return temp; 
    } 
  
    // If both children exist 
    else { 
  
        struct node* succParent = root->right; 
          
        // Find successor 
        struct node* succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
  
        // Delete successor.  Since successor 
        // is always left child of its parent 
        // we can safely make successor's right 
        // right child as left of its parent. 
        succParent->left = succ->right; 
  
        // Copy Successor Data to root 
        root->data = succ->data; 
  
        // Delete Successor and return root 
        free(succ);          
        return root; 
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
			 root =insert(root,x);
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
