package com.practice;
import java.lang.*;
public class This{
	int id;
	String name,college;
	char grade;
	
	This(int id,String name,String college){
	this.id=id;
	this.name=name;
	this.college=college;
	}

	This(int id,String name,String college,char grade){
	this(id,name,college);
	this.grade=grade;
	}

	void display(){
	System.out.println(this.id+" "+this.name+" "+this.college+" "+this.grade+"");
	}
	
	public static void main(String []args){
	This t = new This(10,"Upendra","vit");
	This t1 = new This(10,"Upendra","vit",'A');
	t.display();
	t1.display();
	}



}
