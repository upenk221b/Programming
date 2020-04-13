/*1.TAKE STRING AS INPUT (C = A+B) 
2.PRINT SYMBOL TABLE 
3.IT HAS ID ,NO AND OPERATORS IN STRING PRINT THEM SEPARATLY
4.IN CASE OF MULTIPLE OCCURENCE PRINT ONLY ONCE WITH ITS ADDRESS WHEN IT APPEARED 1ST*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
void print(unordered_map<char,char*> *s){
	unordered_map <char ,char*> :: iterator itr;
		for(itr = s->begin(); itr != s->end(); itr++){
			cout<<itr->first<<" "<<(void*)itr->second<<endl;
		}
}
int main(int argc , char** argv){
	unordered_map <char,char*> id;
	unordered_map <char,char*> no;
	unordered_map <char,char*> ops;
	string str;
	cin>>str;
	for(int i=0; i <str.length(); i++ ){
		if(('A'<=str[i] && str[i] <='Z')||('a'<=str[i] && str[i] <='z')){
			id[str[i]] = &str[i];
		}
		if(('0'<=str[i] && str[i] <='9')){
			no[str[i]] = &str[i];
		}
	if((42 <=str[i] && str[i] <= 47) || (60 <=str[i] && str[i] <= 62) || (91<=str[i] && str[i] <=94)){
			ops[str[i]] = &str[i];
		}
	}
	cout<<"ids:"<<endl;
	print(&id);
	
	cout<<"Nos:"<<endl;
	print(&no);
	
	cout<<"operators:"<<endl;
	print(&ops);
return 0;
}
