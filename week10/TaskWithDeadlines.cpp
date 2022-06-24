#include<bits/stdc++.h>
using namespace std;

 static bool sortbyfirst(pair<int,int> &p1,pair<int,int> &p2)
 {
     return p1.first<p2.first;
 }
 vector<int> JobScheduling(int start[],int dead[], int n) 
    { 
        vector<pair<int, int> > vec(n);
        vector<pair<int,int>>vec2(n);
        for(int i=0; i<n; i++) 
        {
            vec[i]=make_pair(start[i],dead[i]);
            vec2[i]=make_pair(start[i],i);
        }
        
        sort(vec.begin(), vec.end());
        sort(vec2.begin(), vec2.end());

        int maxi=vec[0].second;
        for (int i=0;i<n;i++)
            maxi=max(maxi,vec[i].second);
        
        
        int * temp = new int[maxi+1];
        for (int i=1;i<=maxi;i++)
           temp[i]=-1;
           
        int jobs=0;
        vector<int>job;
        for (int i=0;i<n;i++)
        {
            for (int j=vec[i].second;j>0;j--)
            {
                if (temp[j]==-1)
                {
                    int x=j,count=0;
                    while (x>0 && temp[x]==-1)
                    {
                        x--;
                        count++;
                    }
                    if (count>=vec[i].first)
                    {
                        int count2=vec[i].first,x2=j;
                        while (count2--)
                        {
                            temp[x2]=vec[i].first;
                            x2--;
                        }
                        jobs++;
                        job.push_back(vec2[i].second);
                        break;
                    }
                }
            }
        }
     return job;
    } 

int main()
{
    int n;
    cin>>n;
    int * start = new int[n];
    for (int i=0;i<n;i++)
        cin>>start[i];
    int * dead = new int[n];
    for (int i=0;i<n;i++)
        cin>>dead[i];

    vector<int>job = JobScheduling(start,dead,n); 
    cout<<"Max number of tasks = "<<job.size()<<endl;
    cout<<"Selected task numbers :";
    for(auto i : job)
        cout<<i<<" ";

    
}