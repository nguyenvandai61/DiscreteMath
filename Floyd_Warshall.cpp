#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 100
#define INF 32767
#define VALUE 4

void Doc_File(int W[VALUE][VALUE], int &n)
{
	ifstream _File("Floyd_WarshallTest.txt");
	if (_File.is_open())
	{
		_File >> n;
		cout << "Ma tran do thi: " << endl;
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
	}
	else cout << "File khong ton tai!";
}

void Floyd_Warshall(int W[VALUE][VALUE], int &n)
{
	int D[n][n];
	int P[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			D[i][j] = W[i][j];
			if (W[i][j] != INF) P[i][j] = j;
			else P[i][j] = INF;
		}
	}
	for (int k = 0; k < n; k++) // |V| = n
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			if (D[i][j] > D[i][k] + D[k][j]) { 	
				D[i][j] = D[i][k] + D[k][j];
				P[i][j] = P[i][k];
			}
	}
	
	
	
	cout << "Bang the hien do dai ngan nhat: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (D[i][j] == INF) cout << "NULL";
			else cout << setw(4) << D[i][j];
		}
		cout << endl;
	}
	
	cout << "Bang P[i]: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (P[i][j] == INF) cout << "NULL";
			else cout << setw(4) << P[i][j] + 1;
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			cout << "Doan duong tu " << i + 1
			<< " den " << j + 1 << ": " ;
			if (D[i][j] == INF) 
			{ 
				cout << "Khong ton tai duong di!" << endl;
				continue;
			}
			else cout << D[i][j];
			cout << "    Di theo: " << i + 1;
			
			int v = P[i][j];
			while (v!= j)
			{
				cout << "->" << v + 1;
				v = P[v][j];
			}
			cout << "->" << v + 1 << endl;
		}
		cout << endl;
	}
	
	
}
int main()
{
	//int W[MAX][MAX], n;
	//Doc_File(W, n);
	
	int n = VALUE;
	int W[VALUE][VALUE] = { {0,   5,  INF, 10}, 
            				{INF, 0,   3, INF}, 
           					{INF, INF, 0,   1}, 
           					{INF, INF, INF, 0}  };
	Floyd_Warshall(W, n);
}
