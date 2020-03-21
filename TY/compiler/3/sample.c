#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//this is comment
struct book{
	int book_no;
	char* book_name;
	float price;
};
int main(int argc , char* argv[]){
	struct book b;
	b.book_no=10;
	b.book_name="Goblet of fire";
	b.price=49.8;
return 0;	
}
