#include <iostream>
#include <vector>
#include<math>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int max(vector<int> v,int i ,int j){
    int ma =v[i];
    for(int m=i; m<=j;m++){
        if(ma < v[m]) ma = v[m];
    }
    return ma;
}
long sum(vector<int> v){
    long sum =0;
    for(int m=0; m<v.size();m++){
        sum+=v[m];
    }
    return sum;
}
int solve(vector<int> A) {
    // Return the sum of S(S(A)) modulo 10^9+7.
    vector<int> b;
    vector<int> c;
    for(int k=0; k<A.size();k++){
        for(int i=0; i<=A.size()-k-1; i++){
            int j= i+k;
	    int temp = max(A,i,j);
            b.push_back(temp);
        }
    }
	cout<<endl;
    for(int i=0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }
	cout<<endl;
    for(int k=0; k<b.size();k++){
        for(int i=0; i<=b.size()-k-1; i++){
            int j= i+k;
            c.push_back(max(b,i,j));
        }
    }
    for(int i=0; i<c.size(); i++){
        cout<<c[i]<<" ";
    }
    long abc = sum(c);
	cout<<endl;
	cout<<abc;
    return (abc)%(pow(10,9) +7);
}

int main(){	
	qq	int n;
	cin>>n;
   	vector<int> A(n);
	
	solve(A);
    return 0;
}


