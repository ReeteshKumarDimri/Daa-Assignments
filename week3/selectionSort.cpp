#include <iostream>

using namespace std;


void selection_sort(int a[],int n,int &c,int &s)
{
    for(int i = 1; i < n; i++)
    {

        int min = a[i-1];
        int loc = i-1;
        for(int j = i; j<n; j++)
        {
            if(a[j]<min)
            {
                min = a[j];
                loc = j;
              
            
            }
              c++;
 
        }
            s++;
            a[loc]=a[i-1];
            a[i-1]=min;
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
    selection_sort(arr,n,comp,shift);
    for(int i = 0; i< n; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<endl;
    cout<<"comparisons= "<<comp<<endl;
    cout<<"swaps= "<<shift;
    

    return 0;
}
