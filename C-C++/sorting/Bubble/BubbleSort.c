//Bubble sort
#include<stdio.h>
#include<stdlib.h>
//Sortig fuction
void bubbleSort(int a[],int n){
	int count =0;
	while(count != n){
	for(int i=0; i< n-1 ; i++){
		if(a[i]>a[i+1]){
		a[i] = a[i+1]+ a[i]-(a[i+1] =a[i]);
		}
	}
	count++;
	}	
}
//Print function
void printArray(int a[],int n){
	printf("{");
	for(int i=0; i < n; i++){
	printf(" %d,",a[i]);
	}
	printf(" }");


}
int main(int argc , char argv[]){
	int n;
	printf("ENTER THE SIZE OF ARRAY YOU WANT TO SORT ");
	scanf("%d",&n);

	int a[n];
	printf("Enter the Elements of array");
	for(int i=0; i<n ;i++){
	scanf("%d",&a[i]);
	}
	printf("ARRAY BEFORE SORTING : ");
	printArray(a,n);
	bubbleSort(a,n);
	printf("ARRAY AFTER SORTING : ");
	printArray(a,n);

return 0;

}
