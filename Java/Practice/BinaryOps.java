package com.practice;
import java.lang.*;
/** java docomentation check*/
public class BinaryOps{
	int result=0b0000;
	 public int add(int a, int b){
	return result=a+b;	
	}
	 public int Rshift(int a,int b){
	return (a=a>>b);
	}
	 public int Lshift(int a,int b){
	return a=(a<<b);
	}
public static void main(String []args){
	BinaryOps binary = new BinaryOps();
	int c=binary.add(0b0100,0b0010);
	System.out.println(Integer.toBinaryString(c));
	System.out.println("Left shifting result by 2 bits-->"+Integer.toBinaryString(binary.Lshift(c,2)));
	
	System.out.println("Right shifting result by 2 bits-->"+Integer.toBinaryString(binary.Rshift(c,2)));
	
}
}
