#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int main(int argc , char* argv[]){
	int n;
	cin>>n;
	int a[n];
	int sum;
	cin>>sum;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	unordered_set <int> set;
	for(int j=0; j<n-1; j++){
		for(int k=j+1; k<n; k++){
			if(a[j]+a[k] == sum){
				if(set.find(a[j])==set.end()){//not found in existing
				set.insert(a[j]);
				cout<<"("<<a[j]<<" "<<a[k]<<")"<<endl;
				}
				
			}
		}	
	}
return 0;
}
