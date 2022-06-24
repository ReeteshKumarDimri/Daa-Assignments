#include <iostream>
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
	int n = mid - left + 1;
	int m = right - mid;

	auto *leftArray = new int[n],
		*rightArray = new int[m];
	for (auto i = 0; i < n; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < m; j++)
		rightArray[j] = array[mid + 1 + j];

	int i = 0, 
		j = 0; 
	int k = left; 

	while (i < n && j < m) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < n) {
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < m) {
		array[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; 

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}


int main()
{
	int a[100];
	int arr_size ;
	cin>>arr_size;
	for(int i = 0; i< arr_size ; i++)
    {
        cin>>a[i];
    }
    int target;
    cin>>target;
	mergeSort(a, 0, arr_size - 1);
	int i = 0;
    int j = arr_size -1;
    while(i<j)
    {
        int currSum = a[i]+a[j];
        if(currSum>target)
        {
            j--;
        }
        else if(currSum<target)
        {
            i++;
        }
        else
        {
            cout<<a[i]<<","<<a[j]<<" ";
            i++;j--;
        }
    }

	return 0;
}
