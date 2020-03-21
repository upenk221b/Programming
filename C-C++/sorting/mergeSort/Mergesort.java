import java.util.*;

public class Mergesort{
	static int n;
	public static Scanner scanner = new Scanner(System.in); 
//STATIC BLOCK
	static{
	System.out.println("Enter the size of array :");
	n=scanner.nextInt();
	}
//MERGE METHOD
void merge(int arr[], int l, int m, int r) 
    { 
        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
  
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
  
        int i = 0, j = 0; 
  
        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
  
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
//sort method
    void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            // Find the middle point 
            int m = (l+r)/2; 
  
            // Sort first and second halves 
            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            // Merge the sorted halves 
            merge(arr, l, m, r); 
        } 
    } 
//PRINT ARRAY METHOD
	static void print(int a[]){
	System.out.print("{");
	for(int i=0; i<n ; i++){
	System.out.print(" "+a[i]+",");
	}
	System.out.println("}");
	}
//MAIN METHOD
	public static void main(String []args){
	int a[] = new int[n];
	Mergesort obj = new Mergesort();
	System.out.println("ENTER THE ELEMENTS OF ARRAY  :");
	for(int i=0; i<n ; i++){
	a[i] = scanner.nextInt();
	}

	System.out.println("Array before sorting :");
	print(a);
	obj.sort(a,0,n-1);
	System.out.println("Array after sorting :");
	print(a);
	}
}
