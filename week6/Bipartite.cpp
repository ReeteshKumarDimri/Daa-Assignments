
#include<bits/stdc++.h>
using namespace std;
#define V 5
bool isBipartite(int G[][V], int src)
{
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    colorArr[src] = 1;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (G[u][u] == 1)
            return false;
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}
int main()
{
	int graph[V][V];
	cout<<"Enter the Graph: ";
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
			cin>>graph[i][j];
	if(isBipartite(graph,0))
		cout<<"Yes Bipartite";
	else
		cout<<"Not Bipartite";



	return 0;
}
