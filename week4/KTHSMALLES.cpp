#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r);
int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1) {
		int pos = partition(arr, l, r);
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1) 
			return kthSmallest(arr, l, pos - 1, k);
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}
	return INT_MAX;
}

int partition(int arr[],int l, int h)
{
    int pivot = arr[h];
    int index = l -1;
    for(int i = l ; i < h ; i++)
    {
        if(arr[i]<pivot)swap(arr[i],arr[++index]);
    }
    swap(arr[index+1],arr[h]);
    return index +1 ;
}
int main()
{
    int n,k;
    int arr[100];
    cin>>n;
    for(int i = 0; i< n;i++)
        cin>>arr[i];
    cin>>k;
    cout<<k<<"th smallest element is :"<<kthSmallest(arr,0,n-1,k);
	return 0;
}
