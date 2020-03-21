package com.practice;
import java.lang.*;


public class Practice1{
	int data=10;
	static String college = "VIT";
	String name;
	
	public void display(){
	System.out.println("my name is "+ this.name+" and i  study in "+this.college+" DATA= "+this.data);
		
	}
	public static void main(String []args){
	Practice1 obj = new Practice1();
	Practice1 obj1 = new Practice1();
	obj.name="upendra";
	obj1.name="sushil";
	obj.display();
	obj1.display();

	}


}
