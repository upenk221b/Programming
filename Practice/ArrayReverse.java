import java.util.*;
public class ArrayReverse{
	static Scanner scan = new Scanner(System.in);
	public static void ArrayRotate(int a[] , int d,int n){
		d=d%n;
		reverse(a,0,d-1);
		reverse(a,d,n-1);
		reverse(a,0,n-1);
	}
	public static void reverse(int a[] ,int start , int end){
		int i=start,j=end;
		int temp;	
		while(i<j){
			temp = a[i];
			a[i] = a[j];
			a[j]= temp;
			i++;
			j--;	
		}
	}
	public static void main(String []args){
		System.out.println("ENTER THE ARRAY SIZE");		
		int n = scan.nextInt();
		System.out.println("ENTER THE DEGREE OF ROTATION");		
		int d = scan.nextInt();
		int a[] = new int[n];
		System.out.println("ENTER THE ARRAY ELEMENTS");
		for(int i=0; i< n; i++){
			a[i]=scan.nextInt();
		}
		ArrayRotate(a,d,n);
		System.out.println("AFTER ROTATION");
		for(int i=0; i< n; i++){
			System.out.print(a[i]+" ");
		}
		System.out.println("");
	}
}
