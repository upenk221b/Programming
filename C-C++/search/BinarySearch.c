#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int arr[] , int startIndex , int lastIndex, int key){
	
	if(startIndex <= lastIndex){
	int m = (startIndex + lastIndex)/2;
	if(key == arr[m]){
		printf("Binary Search :Found %d at index %d\n",arr[m],m);
		return m ;
	}
	if(key > arr[m]){
	return BinarySearch(arr, m+1,lastIndex ,key);
	}
	else{
	return BinarySearch(arr, startIndex,m-1 ,key);	
	}
	}
return -1;
}

int main(int argc ,char argv[]){
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter the %d elements of Array in sorted order :",n);
	for(int i=0; i < n; i++){
		scanf("%d",&arr[i]);
	} 
	printf("Enter the element you want to search :");
	int key;
	scanf("%d",&key);
	
	int flag = BinarySearch(arr, 0,n-1,key);
	if(flag == -1){
		printf("NOT FOUND!\n");
	}
return 0;
}
