#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF INT_MAX
void floydWarshall(int graph[][V])
{
	int dist[V][V], i, j, k;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
    cout<<"Shortest distances between pairs : \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

int main()
{
    int graph[V][V];
    cout<<"If there is no edge then write 0 :"<<endl;
	cout<<"Enter the Graph: "<<endl;
	for(int i = 0 ; i < V ;i++ )
		for(int j = 0 ; j < V ; j++)
        {
            cin>>graph[i][j];
            if(graph[i][j]==0 and i!=j)
                graph[i][j] = INF; 
        }
	floydWarshall(graph);
	return 0;
}
