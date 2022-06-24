#include<iostream>
using namespace std;

int main()
{
    int t,n,ar[100],x;
    int count=0,pos;
    cin>>t;
    for(int i =0;i<t;i++)
    {
        count =0;
        cin>>n;
        for(int j=0; j<n; j++)
            cin>>ar[j];
        for(int a =0;a < n;a++)
        {
            for(int b = a+1;b<n;b++)
            {
                for(int c = b+1;c<n;c++)
                {
                    if(ar[a]+ar[b]==ar[c])
                        cout<<a<<","<<b<<","<<c<<endl;
                }
            }
        }

    }
}