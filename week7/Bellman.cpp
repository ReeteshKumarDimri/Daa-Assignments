
#include <bits/stdc++.h>
using namespace std;
#define V 5

void printPath(int parent[],int i)
{
    if(i==-1)
        return;
    cout<<i<<" ";
    printPath(parent,parent[i]);
}

void printSolution(int dist[],int parent[])
{
	for (int i = 0; i < V; i++)
	{
        if(dist[i]!=INT_MAX)
        {
            printPath(parent,i);
            cout<<" : "<<dist[i]<<endl;
        }
    }
}
void BellmanFord(int graph[][V],int src)
{
   int dist[V];
   int parent[V];
   parent[src] = -1;
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for(int v = 0 ; v<V;v++)
            {
                if(graph[u][v]!=0)
                {
                    int weight = graph[u][v];
                    if (dist[u] != INT_MAX&& dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        parent[v] = u; 
                    }        
                }
            }

        }
    }
    for (int u = 0; u < V; u++) 
    {
        for(int v = 0 ; v<V;v++)
        {
            if(graph[u][v]!=0)
             {
                int weight = graph[u][v];
                if (dist[u] != INT_MAX&& dist[u] + weight < dist[v])
                {
                    cout<<"Graph contains negative weight cycle";
                    return;
                }
            }
        }
    }
    printSolution(dist,parent);
    
}
int main()
{
	int graph[V][V];
	cout<<"Enter the Graph: "<<endl;
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
                cin>>graph[i][j];
            
            
    int S;
    cin>>S;
	BellmanFord(graph,S);
	return 0;
}
