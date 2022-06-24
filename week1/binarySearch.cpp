#include<iostream>
using namespace std;

int binarysearch(int a[],int l,int r,int x,int &c)
{
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        c++;
        if(a[mid]==x)
            return mid;
        else if(a[mid]<x)
            l = mid +1;
        else
            r = mid -1;
    }
    return -1;
}

int main()
{
    int t,n,a[100],x;
    int count=0,pos;
    cin>>t;
    for(int i =0;i<t;i++)
    {
        count = 0;
        cin>>n;
        for(int j=0; j<n; j++)
            cin>>a[j];
        cin>>x;
        pos = binarysearch(a,0,n-1,x,count);
        if(pos == -1)
            cout<<"Not present"<<count;
        else
            cout<<"Present "<<count;
    }
}