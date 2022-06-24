
#include<bits/stdc++.h>
using namespace std;
#define V 4
bool isCyclicUtil(int graph[][V],int v, bool visited[], int *parent)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        for(int i = 0; i < V; ++i)
        {
            if ( graph[v][i]&&visited[i] &&parent[i]!=v)
                return true;
            else{
                parent[i]=v;
                return isCyclicUtil(graph,i,visited,parent);

            }
        }
 
    }
    return false;
}
bool isCyclic(int graph[][V])
{
    bool *visited = new bool[V];
    int * parent = new int[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    for(int i = 0; i < V; i++)
        if (!visited[i] && isCyclicUtil(graph,i, visited, parent))
            return true;
 
    return false;
}
int main()
{
	int graph[V][V];
	cout<<"Enter the Graph: ";
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
			cin>>graph[i][j];
	if(isCyclic(graph))
		cout<<"Yes Cyclic";
	else
		cout<<"Not Cyclic";



	return 0;
}
