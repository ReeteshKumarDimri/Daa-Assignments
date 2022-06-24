#include <iostream>

using namespace std;


void insertion_sort(int a[],int n,int &c,int &s)
{
    for(int i = 1; i < n; i++)
    {

        int key = a[i];
        int j=i-1;
        
        while(j>=0&&key<a[j])
        {
            s++;
            c++;
            a[j+1]=a[j];
            j--;
        }
        s ++;
        
        a[j+1]=key;
    }
}



int main()
{
    int arr[100];
    int n ;
    cin>>n;
    int comp = 0;
    int shift = 0;
    for(int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr,n,comp,shift);
    for(int i = 0; i< n; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;
    cout<<"comparisons= "<<comp<<endl;
    cout<<"shifts= "<<shift;
    

    return 0;
}
