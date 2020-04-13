#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n;
    string s[10];
    cout<<"Enter Total Number of Address codes";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int flag=0,pos=4;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-flag;j++)
        {
            if(s[i][pos]==s[j][pos])
            {
                if(s[i][pos]=='+'||s[i][pos]=='*')
                {
                    if((!(s[i][pos-1]==s[j][pos-1])!=!(s[i][pos-1]==s[j][pos+1]))&&(!(s[i][pos+1]==s[j][pos+1])!=!(s[i][pos+1]==s[j][pos-1])))
                       {
                           flag++;
                           for(k=j;k<n-flag;k++)
                            {
                                string temp=s[k];
                                s[k]=s[k+1];
                            }
                       }
                }
                else if(s[i][pos]=='-'||s[i][pos]=='/')
                {
                    if(s[i][pos-1]==s[j][pos-1]&&s[i][pos+1]==s[i][pos+1])
                    {
                           flag++;
                           for(k=j;k<n-flag;k++)
                            {
                                string temp=s[k];
                                s[k]=s[k+1];
                            }
                    }
                }
            }
        }
    }
    cout<<"Genearated Optimised code is:-"<<endl;
    for(i=0;i<n-flag;i++)
        cout<<s[i]<<endl;
    cin>>i;
}

