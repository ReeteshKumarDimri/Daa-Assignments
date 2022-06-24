#include <bits/stdc++.h>
using namespace std;
#define V 5
int parent[V];
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void Union(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}
void kruskalMST(int graph[][V])
{
	int weight = 0;
	for (int i = 0; i < V; i++)
		parent[i] = i;
	int count = 0;
	while (count < V - 1) {
		int max = INT_MIN, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (graph[i][j] != 0 && find(i) != find(j) && graph[i][j] > max ) {
					max = graph[i][j];
					a = i;
					b = j;
				}
			}
		}
		Union(a, b);
        count++;
		weight += max;
	}
    cout<<"Maximum Spanning Weight : "<<weight;
}
int main()
{
    int graph[V][V];
	cout<<"Enter the Graph: "<<endl;
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
                cin>>graph[i][j];
	kruskalMST(graph);

	return 0;
}
