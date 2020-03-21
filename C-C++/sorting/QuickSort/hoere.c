#include<stdio.h>
#include<stdlib.h>
void swap(int *a , int *b){
	*a=*a+*b-(*b=*a);

}
//HOERE PARTITION
int partition(int a[],int startIndex,int lastIndex){
	int i=startIndex-1;
	int j=lastIndex+1;
	int pivot = a[startIndex];
	while(i<j){
		do{
		i++;
		}while(a[i]<=pivot);
		
		do{
		j--;
		}while(a[j]>pivot);
		
		if(i<j) swap(&a[i],&a[j]);
	}	
swap(&a[startIndex],&a[j]);
return j;
}
void printArray(int a[],int n){
	printf("{");
	for(int i=0; i < n; i++){
	printf(" %d,",a[i]);
	}
	printf(" }\n");


}
int main(int argc , char argv[]){
	printf("************HOERE PARTITION**************\n");
	int n;
	printf("ENTER THE SIZE OF ARRAY : ");
	scanf("%d",&n);

	int a[n];
	printf("Enter the Elements of array");
	for(int i=0; i<n ;i++){
	scanf("%d",&a[i]);
	}
	printf("ARRAY BEFORE placing element %d into correct position : ",a[0]);
	printArray(a,n);
	int j= partition(a,0,n-1);
	printf("ARRAY AFTER placing  element %d into correct position : ",a[j]);
	printArray(a,n);
	printf("Element at index %d is at correct position.\n",j);
return 0;
}
