#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int jumpsearch(int a[],int n,int x,int &c)
{
    int jump = sqrt(n);
    int prev = 0,step = jump;
    while(a[min(step,n)-1]<x)
    {
        c++;
        prev = step;
        step+=jump;
        if(prev >= n)
            return -1;
    }
    while(a[prev]<x)
    {
        c++;
        prev++;
        if(prev==min(step,n))
            return -1;
    }
    if(a[prev]==x)
        c++;return prev;
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
        pos = jumpsearch(a,n,x,count);
        if(pos == -1)
            cout<<"Not present"<<count;
        else
            cout<<"Present "<<count;
    }
}