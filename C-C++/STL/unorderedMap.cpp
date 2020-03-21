#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;
void print(unordered_map<string,int> *s){
	unordered_map <string ,int> :: iterator itr;
		for(itr = s->begin(); itr != s->end(); itr++){
			cout<<itr->first<<" "<<itr->second<<endl;
		}
}
void printWordFreq(const string &s){
	unordered_map <string,int> wordFreq;
	stringstream ss(s);//ss stores all the words in string in it as a "stream of words"
	string word;	//each time new word is placed in string "word"
	while(ss >> word){
		wordFreq[word]++;//add word to map or increase freq if already present
	}
	print(&wordFreq);
}


int main(int argc , char* argv[]){
	
	
	cout<<"*****UNORDERED MAP PRINTING FREQUNCY OF EACH WORD IN STRING *****\nENTER A STRING: "<<endl;
		string s ="what the fuck is this";
	//cin>>s;
	printWordFreq(s);
	
	
	
return 0;
}
