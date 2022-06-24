// See the Cormen book for details of the
// following algorithm
#include <bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int p[], int n)
{
	int m[100][100];

	int i, j, k, L, q;
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}
int main()
{
	int P[100];
    int arr[100][2];
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < 2 ; j++)
            cin>>arr[i][j];
    P[0] = arr[0][0];
    P[n] = arr[n-1][1];
    for(int i = 1 ; i < n; i++)
        P[i] = arr[i][0];
    cout<<endl;
	cout<< MatrixChainOrder(P,n+1);
	return 0;
}