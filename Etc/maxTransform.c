#include <iostream>
#include <vector>
using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int max(vector<int> v,int i ,int j){
    int ma =v[0];
    for(int m=i; m<j;m++){
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
            b.push_back(max(A,i,j));
        }
    }
    for(int i=0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }
    for(int k=0; k<b.size();k++){
        for(int i=0; i<=b.size()-k-1; i++){
            int j= i+k;
            c.push_back(max(b,i,j));
        }
    }
    long abc = sum(c);
    return (abc)%(10^9 +7);
}

int main()
{
   	vector<int> A(3);
	A[0] = 3;
	A[1] =2; A[2] = 1;
	solve(A);
    return 0;
}


