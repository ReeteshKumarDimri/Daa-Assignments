
#include<bits/stdc++.h>
using namespace std;
#define V 5
bool Path(int graph[][V],int s,int d)
{
	vector<bool> visited(V, false);
	stack<int> stack;
	stack.push(s);

	while (!stack.empty())
	{

		int s = stack.top();

		stack.pop();
		if (!visited[s])
		{
			cout<<s<<" ";
			visited[s] = true;
		}
		if(s==d)
			return true;

		for (auto i = 0; i < V; ++i)
			if (graph[s][i]!=0 && !visited[i])
				stack.push(i);
	}
	return false;
}

void addEdge(int graph[][V],int u,int v)
{
	graph[u][v]=1;
}

// Driver program to test methods of graph class
int main()
{
	int graph[V][V];
	cout<<"Enter the Graph: ";
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
			cin>>graph[i][j];
	int s,d;
	cout<<"Enter the source and destination: ";
	cin>>s>>d;
	if(Path(graph,s,d))
		cout<<"Yes Path Exists.";
	else
		cout<<"No Path does not Exist";



	return 0;
}
