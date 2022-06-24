#include <bits/stdc++.h>
using namespace std;
#define V 4
int shortestPath(int graph[][V], int u, int v, int k)
{
   if (k == 0 && u == v)             return 0;
   if (k == 1 && graph[u][v] != INT_MAX) return graph[u][v];
   if (k <= 0)                       return INT_MAX;
   int res = INT_MAX;
   for (int i = 0; i < V; i++)
   {
       if (graph[u][i] != INT_MAX && u != i && v != i)
       {
           int dist = shortestPath(graph, i, v, k-1);
           if (dist != INT_MAX)
              res = min(res, graph[u][i] + dist);
       }
   }
   return res;
}
int main()
{
	int graph[V][V];
	cout<<"Enter the Graph: "<<endl;
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
                cin>>graph[i][j]; 
    int S;
    int D;
    int K;
    cin>>S>>D>>K;
	int distance = shortestPath(graph,S,D,K);
    if(distance == INT_MAX )
        cout<<"no path of length "<<K<<" is available.";
    else
        cout<<"Weight of shortest path from "<<S<<" to "<<D<<" with "<<K<<" edges : "<<distance;
	return 0;
}
