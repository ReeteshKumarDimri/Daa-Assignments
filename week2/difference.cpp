#include<iostream>
using namespace std;

int linearsearch(int a[],int n,int x,int &c)
{
    for(int i =0;i<n;i++)
    {
        if(a[i]==x)
        {
            c++;
            return i;
        }
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
        count=0;
        cin>>n;
        for(int j=0; j<n; j++)
            cin>>a[j];
        cin>>x;
        for(int j=0;j<n;j++)
            linearsearch(a,n,a[j]+x,count);
        cout<<count<<endl;

    }
}