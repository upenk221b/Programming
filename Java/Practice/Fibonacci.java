package com.practice;
import java.lang.*;
import java.util.Scanner;

public class Fibonacci{
	long a,b,c;	/** Variables to store the recent 3 values of fibonacci*/ 

	void nthFibonacci(int n){
	a=0;b=1;c=1;
	if(n==1){System.out.println(n+"th fibonacci NO: 0"); return;}
	if(n==2){System.out.println(n+"th fibonacci No: 1"); return;}	
	/**Loop (n-2) times to get c as a nth fibonacci no*/	
	for(int i=0; i<n-2; i++){
	c=a+b;/**f(n)=f(n-1)+f(n-2)*/
	a=b;/**f(n-2)=f(n-1)*/
	b=c;/**f(n-1)=f(n)*/
	
	}
	System.out.println(n+"th fibonacci No: "+c);
	}
	
	void nthFibonacciList(int n){
	a=0;b=1;c=1;
	if(n==1){System.out.println("list of "+n+" fibonacci nos: 0"); return;}
	if(n==2){System.out.println("list of "+n+" fibonacci nos: 0,1"); return;}
	else{
	System.out.print("list of "+n+" fibonacci nos: 0,1");
	/**Loop (n-2) times to get c as a nth fibonacci no*/	
	for(int i=0; i<n-2; i++){
	c=a+b;/**f(n)=f(n-1)+f(n-2)*/
	a=b;/**f(n-2)=f(n-1)*/
	b=c;/**f(n-1)=f(n)*/
	System.out.print(","+c);
	}
	System.out.println(" ");
		
	}	
	
	
	}
	
	public static void main(String []args){
	Scanner scanner = new Scanner(System.in);
	int n=scanner.nextInt();
	/**Calling functions using anonymous object*/
	if(new String("list").equals(args[0])){new Fibonacci().nthFibonacciList(n);}

	 if(new String("n").equals(args[0])){
	Fibonacci f = new Fibonacci();
	f.nthFibonacci(n);
	}
	scanner.close();

	}
}
