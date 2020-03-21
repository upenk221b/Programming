#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[] ,int startIndex ,int lastIndex , int key){
	for(int i=startIndex; i <= lastIndex; i++){
		if(arr[i] == key){
		printf("Linear Search :Found %d at index %d\n",arr[i],i);
		return 0;	
		}
	}
return -1;
}
int main(int argc , char argv[]){
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter the %d elements of Array :",n);
	for(int i=0; i < n; i++){
		scanf("%d",&arr[i]);
	} 
	printf("Enter the element you want to search :");
	int key;
	scanf("%d",&key);
	
	int flag = linearSearch(arr, 0,n-1,key);
	if(flag == -1){
		printf("NOT FOUND!\n");
	}

return 0;
}
