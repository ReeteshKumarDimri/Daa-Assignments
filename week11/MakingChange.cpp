#include<bits/stdc++.h>

using namespace std;
int dp[100][100];
int count( int S[], int N, int m )
{
	if(N==0)return 1;
	if(m<0)return 0;
	if(dp[N][m]!=-1)
		return dp[N][m];
	if(S[m]>N)
		return dp[N][m] = count(S,N,m-1);
	return dp[N][m] = count(S,N-S[m],m)+count(S,N,m-1);

}

int main()
{
	int arr[100];
    int m,N;
    cin>>m;
    for(int i = 0 ; i < m ; i++)
        cin>>arr[i];
    cin>>N;
	for(int i = 0 ; i < N+1;i++)
		for(int j = 0 ; j < m+1 ; j++)
			dp[i][j]=-1;
	cout << count(arr, N, m-1);
	return 0;
}