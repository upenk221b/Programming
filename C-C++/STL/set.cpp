#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void print(set<int > *s){
	set <int> :: iterator itr;
		for(itr = s->begin(); itr != s->end(); itr++){
			cout<<*itr<<" ";
		}
	cout<<endl;
}
int main(int argc , char* argv[]){

	int n=0,a=0;
	 set <int> s;
	while(n!=4){
	cout<<"*****SET*****\n1.Insert\n2.Erase\n3.Print\n4.Exit"<<endl;
	cin>>n;
	switch(n){
	case 1 :cout<<"ENTER THE NO:"<<endl; 
		cin>>a;	
		s.insert(a);
		break;
	case 2 :cout<<"ENTER THE NO:"<<endl; 
		cin>>a;	
		s.erase(a);
		break;
	case 3 :print(&s);
		break;
	case 4 :cout<<"EXITING\n"<<endl;
		break;
	}
	}
	


return 0;
}
