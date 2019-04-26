#include <iostream>
#include <fstream>
using namespace std;
#define max 100
void Doc_File(int A[max][max], int &n, int &a, int &z) {
	//FILE *f = fopen("TestDijkstra.txt", "rb");
	ifstream f("TestDijkstra.txt");
	if(f.is_open())
	{
		f >> n >> a >> z;
		cout << "Ma Tran Graph: ";
		cout << a << " " << z << endl;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				f >> A[i][j];
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		f.close();
		a--; z--;
	}
}

// thuat toan Dijkstra

void DistanceVertice(int n, int* L, int *T, int &v)
{
	int min = 32757;
	for (int j = 0; j < n; j++)
		if (min > L[j] && T[j] == 0) {
			v = j;
			min = L[j];
		}
	if (min == 32757 && v!= 0)
	{
		cout << "Khong ton tai duong di tu a den z"; return;
	}
	else
	{
		T[v] = 1;
	}
}

void Dijkstra(int W[max][max], int n, int a, int z) {
	int T[max];
	int L[max], min, v;
	int P[max];
	// Step 1:
	for (int i = 0; i < n; i++) {
		L[i] = 32757;
		T[i] = 0;
		P[i] = a;
	}
	L[a] = 0;
	T[a] = 1;
	
	// Step 2:
	
	v = a;
	DistanceVertice(n, L, T, v);
	
	// Step 3:
	while (v != z) {
		// Step 4:
		for (int u = 0; u < n; u++)
			if (W[v][u] > 0 && L[u] > W[v][u] + L[v] && T[u] == 0) {
				L[u] = W[v][u] + L[v];
				P[u] = v;
			}
		// Go to step 2:	
		DistanceVertice(n, L, T, v);
	}
	
	
	cout << "Duong di ngan nhat la:" << L[z] << endl;
	cout << z + 1 << " <- " << P[z] + 1;
	int i = P[z];
	
	while (i != a) {
		i = P[i];
		cout << " <- " << i + 1;
	}
}

int main() {
	int W[max][max], n, Dau, Cuoi;
	Doc_File(W, n, Dau, Cuoi);
	Dijkstra(W, n, Dau, Cuoi);
}
