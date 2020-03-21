#include<iostream>
#include<climits> 
using namespace std;
void swap(int *a , int *b){
	*a=*a+*b-(*b=*a);

}
class MinHeap{

	int *harr;
	int capacity;
	int heapSize;
public:
	//constructor
	MinHeap(int capacity);
	//heapify
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
	//Print
	void print(){
		cout<<"{";
		for(int i=0; i < heapSize; i++){
		cout<<harr[i]<<",";
		}
		cout<<"}"<<endl;
	}
};
MinHeap::MinHeap(int capacity){
	this->harr = new int[capacity];
	this->capacity = capacity;
	this->heapSize = 0;
}
//Heapify the heap at index i
void MinHeap::MinHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;//consider root is smallest at first
	if(l<heapSize && harr[l] < harr[smallest] )
		smallest = l;
	if(r<heapSize && harr[r] < harr[smallest] )
		smallest = r;	
	//if root is not smallest
	if(i!=smallest){
		swap(&harr[smallest],&harr[i]);
		MinHeapify(smallest);
		}
	
}
void MinHeap::insertKey(int key) 
{ 
    if (heapSize == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
  
    // First insert the new key at the end 
    heapSize++; 
    int i = heapSize - 1; 
    harr[i] = key; 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 
void MinHeap::decreaseKey(int i, int key) 
{ 
    harr[i] = key; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 
int MinHeap::extractMin() 
{ 
    if (heapSize <= 0) 
        return INT_MAX; 
    if (heapSize == 1) 
    { 
        heapSize--; 
        return harr[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    int root = harr[0]; 
    harr[0] = harr[heapSize-1]; 
    heapSize--; 
    MinHeapify(0); 
  
    return root; 
} 
void MinHeap::deleteKey(int key) 
{ 
    decreaseKey(key, INT_MIN); 
    extractMin(); 
} 
int main(int argc , char *argv[]){
	int a;
	MinHeap heap = MinHeap(20);
	heap.print();
	for(int i=0; i<8; i++){
		cin>>a;	
		heap.insertKey(a);
	}
		
	cout<<"Min:"<<heap.getMin();
	heap.print();
return 0;
}
