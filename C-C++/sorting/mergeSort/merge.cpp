//©All Rights Reserved @upendra_kadre
//ALGORITHM  TIME COMPLEXITY : O(N LOGN)
//DIVIDE AND CONQUER ALGORITHM
//we first keep on dividing the array/list into equal halfs until we reach atomic level.
//then we merge smallest lists in sorted order and ultimately get sorted array/list.
//mergesort function is called recursively and merge function merges the two lists in sorted order
#include<iostream>
using namespace std;
int i,n,j,k;
void merge_(int a[],int l,int m,int r)
{
    i=l;
    j=m+1;
    k=0;
    int b[n];
    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    while(i<=m)
        b[k++]=a[i++];

    while(j<=r)
        b[k++]=a[j++];

    for(i=l,j=0;i<=r;i++,j++)
        a[i]=b[j];

}
void merge_sort(int a[],int l,int r)//this function divides the array to atomic level by recursive calling and merge function unites the sorted array.
{
    if(l<r)
    {
        int m=(l+r)/2;

        merge_sort(a,l,m);
        merge_sort(a,m+1,r);

        merge_(a,l,m,r);
    }

}
int main()
{
    std::cout<<"ENTER THE NO OF ELEMENTS"<<endl;
    std::cin>>n;
    int a[n];
    std::cout<<"ENTER "<<n<< "ELEMENTS"<<endl;
    for(i=0;i<n;i++)
    {
        std::cin>>a[i];
    }

    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        std::cout<<a[i]<<endl;
    }
    std::cout<<"PRESS ANY KEY AND ENTER TO EXIT"<<endl;
    std::cin>>n;
    return 0;
}
