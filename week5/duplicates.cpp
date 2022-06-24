#include<bits/stdc++.h>
#include<string>
using namespace std;
void countingsort(string s)
{
    int n=s.length();
    char arr[n];
    int x=0;
    memset(arr,0,sizeof(arr));
    for(auto i:s)
    {
        arr[x++]=i;
    }
    int count[26];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++)
    {
        count[arr[i]-'a']++;
    }
    char l='a';
    int num=0;
    for(int i=0;i<26;i++)
    {
        if(num<count[i])
        {
            num=count[i];
            l=l+i;
        }
    }
    if(num<=1)
    {
        cout<<"NO DUPLICATE ELEMENTS"<<endl;
    }
    else
    {
        cout<<l<<" - "<<num<<endl;
    }
}
int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    countingsort(s);
    return 0;
}