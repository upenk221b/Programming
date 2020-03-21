#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
void print(unordered_set<string> *s){
	unordered_set <string> :: iterator itr;
		for(itr = s->begin(); itr != s->end(); itr++){
			cout<<*itr<<endl;
		}
}
int main(int argc , char* argv[]){
	int n=0;
	string s;
	unordered_set <string> uset;
	while(n!=4){
	cout<<"*****UNORDERED SET*****\n1.Insert\n2.Erase\n3.Print\n4.Exit"<<endl;
	cin>>n;
	switch(n){
	case 1 :cout<<"ENTER THE string:"<<endl; 
		cin>>s;	
		uset.insert(s);
		break;
	case 2 :cout<<"ENTER THE string:"<<endl; 
		cin>>s;	
		uset.erase(s);
		break;
	case 3 :print(&uset);
		break;
	case 4 :cout<<"EXITING\n"<<endl;
		break;
	}
	}
	



return 0;
}
