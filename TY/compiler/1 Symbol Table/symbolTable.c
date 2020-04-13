/*1.TAKE STRING AS INPUT (C = A+B) 
2.PRINT SYMBOL TABLE 
3.IT HAS ID ,NO AND OPERATORS IN STRING PRINT THEM SEPARATLY
4.IN CASE OF MULTIPLE OCCURENCE PRINT ONLY ONCE WITH ITS ADDRESS WHEN IT APPEARED 1ST*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int isPresent(char* arr,char a,int size){
	int i = 0;
	while(i<size && arr[i]!=a){
		i++;
	}
	if(i == size){
		return 0;
	}else{
		return 1;
	}

}
int main(int argc , char** argv){
	char str[SIZE];
	printf("ENTER THE INPUT STRING :  ");
	scanf("%s",str);
	char id[SIZE/2];
	char operator[SIZE/2];
	int j=0,k=0;
	for(int i=0; i <strlen(str); i++ ){
		if((('A'<=str[i] && str[i] <='Z')||('a'<=str[i] && str[i] <='z')) && (!isPresent(id,str[i],j)||(j==0))){
			id [j++] = str[i];
			printf("id       : %c\taddress :%u\n",str[i],(str+i));
		}
		if(('0'<=str[i] && str[i] <='9')){
			id [j++] = str[i];
			printf("NO       : %c\taddress :%u\n",str[i],(str+i));
		}
	if(((42 <=str[i] && str[i] <= 47) || (60 <=str[i] && str[i] <= 62) || (91<=str[i] && str[i] <=94))&&(!isPresent(operator,str[i],k)||(k==0))){

			operator[k++] = str[i];
			printf("operator : %c\taddress :%u\n",str[i],(str+i));
		}

	}
return 0;	
}
