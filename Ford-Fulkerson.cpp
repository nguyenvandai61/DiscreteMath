// Chuong trinh dua tren thuat toan Ford-Fulkerson
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 
#define MAX 20

void DOC_FILE(int Graph[MAX][MAX], int &s, int &t, int &n)
{
	ifstream file("Ford-FulkersonTest.txt");
	if (file.is_open())
	{
		file >> n;
		file >> s >> t;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				file >> Graph[i][j];
				cout << setw(4) << Graph[i][j];
			}
			cout << endl;
		}
		file.close();
		s--;
		t--;
	}
	else cout << "File ko tim thay.";
}

bool bfs(int rGraph[MAX][MAX], int s, int t, int n, int parent[]) 
{ 
	// Mang danh dau visited. Ban dau moi phan tu bang false.
	bool visited[n]; 
	memset(visited, 0, sizeof(visited)); 

	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 
 
	while (!q.empty()) 
	{ 
		int u = q.front(); 
		q.pop(); 

		for (int v=0; v<n; v++) 
		{ 
			if (visited[v]==false && rGraph[u][v] > 0) 
			{ 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true; 
			} 
		}
	} 
	return (visited[t] == true); 
} 

int fordFulkerson(int graph[MAX][MAX], int s, int t, int n) 
{ 
	int u, v; 
	int rGraph[MAX][MAX];
	  
	for (u = 0; u < n; u++) 
		for (v = 0; v < n; v++) 
			rGraph[u][v] = graph[u][v]; 

	int parent[n]; 
	int max_flow = 0; 
	
	while (bfs(rGraph, s, t, n, parent)) 
	{ 
		int path_flow = INT_MAX; 
		for (v=t; v!=s; v=parent[v]) 
		{ 
			u = parent[v]; 
			path_flow = min(path_flow, rGraph[u][v]); 
		} 
		for (v=t; v != s; v=parent[v]) 
		{ 
			u = parent[v]; 
			rGraph[u][v] -= path_flow; 
			rGraph[v][u] += path_flow; 
		} 
		max_flow += path_flow; 
		cout << path_flow;
	} 
	return max_flow; 
} 

int main() 
{ 
	int Graph[MAX][MAX];
	int s, t, n;
	DOC_FILE(Graph, s, t, n);

	cout << "The maximum possible flow is " << fordFulkerson(Graph, s, t, n); 

	return 0; 
} 

