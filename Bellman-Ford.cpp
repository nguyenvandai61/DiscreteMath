
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define INF 32767
#define MAX 100

void Doc_File(int W[MAX][MAX], int &n, int &a)
{
	ifstream _File("Bellman-FordTest.txt");
	if (_File.is_open())
	{
	_File >> n >> a;
	cout << "Do thi nhap vao: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_File >> W[i][j];
			if(W[i][j] != INF) cout << setw(4) << W[i][j];
			else cout << "NULL";
		}
		cout << endl;	
	}
	_File.close();
	a--;
	}	
}

void Bellman_Ford(int W[MAX][MAX], int &n, int &a)
{
	int L[MAX];
	int P[MAX], v;
	
	for (int i = 0; i < n; i++)
	{
		L[i] = INF;
		P[i] = a;
	}
	
	L[a] = 0;
	
	for (int v = 0; v < n; v++)
		for (int u = 0; u < n; u++)
			if (L[u] > W[v][u] + L[v]) {
				L[u] = W[v][u] + L[v];
				P[u] = v;
			}
	
	for (int i = 0; i < n; i++)
	{
		if (i == a) continue;
		cout << "Khoang cach tu " << a + 1 << " den " << i + 1 << ": " <<  L[i];
		cout << "     Theo duong: " << i + 1; 
	
		int v = P[i];
		while (v != a)
		{
			cout << "<-" << v + 1;
			v = P[v];
		}
		cout << "<-" << a + 1 <<endl;
	}
}

int main()
{
	int W[MAX][MAX], n, a;
	Doc_File(W,n,a);
	Bellman_Ford(W, n, a);
}
