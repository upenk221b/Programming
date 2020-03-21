package com.practice;
import java.lang.*;

public class Args{
	public static void main(String []args){
	System.out.println("args[0]= "+args[0]+" args[1]= "+args[1]);
	main();
	}
	public static void main(){
	System.out.println("Right shifting result by 2 bits-->"+Integer.toBinaryString(new BinaryOps().Rshift(0b01100,2)));

	}

}
