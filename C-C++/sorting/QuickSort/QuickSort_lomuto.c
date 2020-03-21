#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	*a = *a+*b-(*b=*a);
}
//Here partition method is lomuto partition
//IT returns the position where pivot element should be placed..
 
int partition(int a[],int startIndex , int lastIndex){
	int i = startIndex;
	int pivot = a[lastIndex];
	for(int j=startIndex; j<=lastIndex-1; j++){//notice j<=lastIndex-1 as pivot is taken as last element
		if(a[j]<=pivot){
			swap(&a[i],&a[j]);//this line makes sure all elements before ith index are smaller than pivot			
			i++;
		}	
	}	
	swap(&a[i],&a[lastIndex]);//i is the position where pivot(lastIndex element ) belongs in sorted array.
return i;
}
void Quicksort(int a[] ,int startIndex,int lastIndex){
	if(startIndex <lastIndex){
		
		int parted_here = partition(a,startIndex,lastIndex);
		Quicksort(a,startIndex,parted_here-1);
		Quicksort(a,parted_here +1,lastIndex);
	}
}
void printArray(int a[],int n){
	printf("{");
	for(int i=0; i < n; i++){
	printf(" %d,",a[i]);
	}
	printf("}");


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
