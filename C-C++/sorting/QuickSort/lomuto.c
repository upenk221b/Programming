#include<stdio.h>
#include<stdlib.h>
void swap(int *a , int *b){
	*a=*a+*b-(*b=*a);

}
//LOMUTO PARTITION
int partition(int a[],int startIndex,int lastIndex){
	int i=startIndex;
	int pivot = a[lastIndex];
	for(int j=0; j<=lastIndex-1;j++){
		if(a[j]<=pivot){
			swap(&a[j],&a[i]);			
			i++;		
		}
	}
swap(&a[lastIndex],&a[i]);
return i;
}
void printArray(int a[],int n){
	printf("{");
	for(int i=0; i < n; i++){
	printf(" %d,",a[i]);
	}
	printf(" }\n");


}
int main(int argc , char argv[]){
	int n;
	printf("************LOMUTO PARTITION**************\n");
	printf("ENTER THE SIZE OF ARRAY YOU WANT TO SORT ");
	scanf("%d",&n);

	int a[n];
	printf("Enter the Elements of array");
	for(int i=0; i<n ;i++){
	scanf("%d",&a[i]);
	}
	printf("ARRAY BEFORE placing element %d into correct position : ",a[n-1]);
	printArray(a,n);
	int j= partition(a,0,n-1);
	printf("ARRAY AFTER placing  element %d into correct position : ",a[j]);
	printArray(a,n);
	printf("Element at index %d is at correct position.\n",j);
return 0;
}

