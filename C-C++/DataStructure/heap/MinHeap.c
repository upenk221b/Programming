#include<stdio.h>
#include<stdlib.h>
struct MinHeap{
    int *harr;
	int capacity;
	int heapSize;
};
//utility functions for MinHeap implementation.
void MinHeapify(int i);
//getters
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int parent(int i){return (i-1)/2;}

int getMin(){return harr[0];}

//decrease key
void decreaseKey(int i ,int key);
//extract min
int extractMin();
//Delete Key (decrease + extract min)
void deleteKey(int i);
//insert Key
void insertKey(int key);
//swap
void swap(int *a , int *b){
	*a=*a+*b-(*b=*a);
}
//print
void print(){
    cout<<"{";
    for(int i=0; i < heapSize; i++){
    cout<<harr[i]<<",";
    }
    cout<<"}"<<endl;
}
//MinHeap initialize
MinHeapInit(struct MinHeap* heap,int capacity){
	heap->harr = (int*)calloc();
	heap->capacity = capacity;
	heap->heapSize = 0;
}
