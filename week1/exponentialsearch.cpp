#include<iostream>
using namespace std;

int binarySearch(int arr[], int, int, int, int&);
 
int exponentialSearch(int arr[], int n, int x,int &c)
{
    if (arr[0] == x)
    {
        c++;
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] <= x)
    {
        c++;
        i = i*2;
    }  
    return binarySearch(arr, i/2,min(i, n-1), x,c);
}

int binarySearch(int arr[], int l, int r, int x,int &y)
{
    y++;
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x,y);
        return binarySearch(arr, mid+1, r, x,y);
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
        pos = exponentialSearch(a,n,x,count);
        if(pos == -1)
            cout<<"Not present"<<count;
        else
            cout<<"Present "<<count;
    }
}