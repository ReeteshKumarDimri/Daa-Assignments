// C++ Program for finding out
// majority element in an array
#include <bits/stdc++.h>
using namespace std;
void FindMajority(int a[], int size)
{
	int maj_index = 0, count = 1;
	for (int i = 1; i < size; i++) {
		if (a[maj_index] == a[i])
			count++;
		else
			count--;
		if (count == 0) {
			maj_index = i;
			count = 1;
		}
	}
	count = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == a[maj_index])
			count++;

	if (count > size / 2)
		cout << "Yes\n" << a[maj_index] << " ";

	else
		cout << "No";
}

int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i= 0 ; i < n ; i++)
        cin>>arr[i];
	FindMajority(arr, n);
	return 0;
}
