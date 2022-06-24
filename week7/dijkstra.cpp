
#include <bits/stdc++.h>
using namespace std;
#define V 5
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
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



void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];
    int parent[V];
    parent[src] = -1; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v]=u;

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
	dijkstra(graph, S);

	return 0;
}
