#include<iostream>
using namespace std;

class dfa
{ public:
  int n,start_state,end_state,delta[10][2];
  void load();
  int simulate();
};
void dfa::load()
{ int i=0;
  cout<<"no of state,start state , end state repectively ";
  cin>>n>>start_state>>end_state;
  cout<<"enter the delta";
    for(i=0;i<n;i++)
    {
       cout<<"enter the state no\t"  <<i<<"\t";
       cin>>delta[i][0];
    }
    for(i=0;i<n;i++)
    {
       cout<<"enter the state no\t"  <<i<<"\t";
       cin>>delta[i][1];
    }
 //  for(i=0;i<n;i++)
 //   {
  //    cout<<"enter the state no\t"  <<i<<"\t";
  //    cin>>delta[i][2];
  //  }

}
int dfa::simulate()
{
  int len,i;
  cout<<"enter the length of string";
  cin>>len;
  int input[len];
  for(i=0;i<len;i++)
  {
    cout<<"enter the input string";
    cin>>input[i];
  }

int state ;
state=start_state;
for(i=0;i<len;i++)
{  input[i]+=1;
 state=delta[state][input[i]];
}
if(state==end_state)
  return 1;
  return 0;
}
 int main()
 {
 dfa d1;
 d1.load();

 int result=d1.simulate();
  if(result==1)
  cout<<"accepted" ;
 else
  cout<<"rejected";
  return 0;
 }
