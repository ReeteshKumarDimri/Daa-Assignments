#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(int arr[], int n, int sum,int dp[][100])
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (dp[n][sum] != -1) {
		return dp[n][sum];
	}
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum, dp);
	return dp[n][sum]= isSubsetSum(arr, n - 1, sum, dp)|| isSubsetSum(arr, n - 1, sum - arr[n - 1],dp);
}
bool findPartiion(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;

    int dp [100][100];
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <=sum ; j++)
            dp[i][j]=-1;
	return isSubsetSum(arr, n, sum / 2, dp);
}
int main()
{
	int arr[100];
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
	if (findPartiion(arr, n) == true)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
