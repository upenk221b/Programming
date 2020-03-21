#include<stdio.h>
#include<stdlib.h>
void swap(int *a , int *b){
	*a=*a+*b-(*b=*a);

}
//HOERE IS MORE EFFICIENT THAN LOMUTO AS IT MAKES 3 TIMES LESS COMPARISONS
//Here partition method is hoere partition method..
//we use two pointers i and j ..starting from extreme ends one tracks element smaller than pivot and another tracks greater.
//when these two pointers cross each other we return the pointer pointing to greater value(j)
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
void Quicksort(int a[] ,int startIndex,int lastIndex){
	if(startIndex <lastIndex){
		
		int parted_here = partition(a,startIndex,lastIndex);
		Quicksort(a,startIndex,parted_here);//NOTICE THIS...WE INCLUDE THEINDEX WHERE IT WAS PARTED
		Quicksort(a,parted_here +1,lastIndex);
	}
}
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
	Quicksort(a,0,n-1);
	printf("ARRAY AFTER SORTING : ");
	printArray(a,n);

return 0;
}
