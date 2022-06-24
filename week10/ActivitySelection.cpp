#include <bits/stdc++.h>
using namespace std;
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;
	i = 0;
    int c = 1 ;
    cout<<"List of selected activities : ";
	cout <<" "<< i+1;
	for (j = 1; j < n; j++)
	{
	    if (s[j] >= f[i])
        {
            cout <<" " << j+1;
            i = j;
            c++;
        }
	}
    cout<<"\nNo. of non-conflicting activities : "<<c;
}
int main()
{
    int n;
	int s[100];
	int f[100];
    cin>>n;
    for(int i = 0 ; i < n; i++ )
        cin>>s[i];
    for(int i = 0 ; i < n; i++ )
        cin>>f[i];   
	printMaxActivities(s, f, n);
	return 0;
}
