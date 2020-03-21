#include<stdio.h>
#include<stdlib.h>
//find a smallest fibonacci no greater than or equal to n
//offset is index below which element can't be found
//i is the index where we check if element is present or not ...we chosoe i=fibM2
//this divides array in two unequal parts where first part till fibM2 is approx 1/3rd of array and rest is obviously 2/3rd
//if element is smaller than a[i] go for lower half and if greater go for upper half

 int min(int a , int b){
	return (a<=b)? a:b;

}
int FibonacciSearch(int a[] , int n ,int key){
	int fibM =1,fibM1=1,fibM2=0;
	
	while(fibM<n){
	fibM2 = fibM1; 
        fibM1 = fibM; 
        fibM  = fibM2 + fibM1; 
	}
	int offset = -1;
	while(fibM >1){
		int i =	min(offset + fibM2,n-1);//for getting valid index in i...should not exceed n-1.
		//shift down by 2 fibonacci no and shift offfset to fibM2... i.e.search in 2/3 rd part from end		
		if(a[i] < key){
		fibM  = fibM1; 
            	fibM1 = fibM2; 
            	fibM2 = fibM - fibM1; 
           	offset = i; 
		}else
		if(a[i] > key){
			//shift down by 2 fibonacci no and shift offfset to fibM2... i.e.search in 2/3 rd part from end
		fibM  = fibM2; 
            	fibM1 = fibM1 - fibM2; 
            	fibM2 = fibM - fibM1; 
			
		}
		else return i;
	}

	if(fibM1 == 1 && a[offset+1] == key) return offset +1;
return -1;
}

int main(int argc , char argv[]){
	printf("****************FIBONACCI SEARCH******************\n");
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
	
	int flag = FibonacciSearch(arr,n,key);
	if(flag == -1){
		printf("NOT FOUND!\n");
	}
	else{
		printf("found at index %d\n",flag);
	}
return 0;
}
