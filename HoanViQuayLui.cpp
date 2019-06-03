#include <iostream>
using namespace std;

void init(int &n, int *&check) {
	cout << "Nhap n: ";
	cin >> n;
	
	
	check = new int[n+1];
	
	for (int i = 1; i <= n; i++)
		check[i] = 1;
	
}


void out(int n, int *a) 
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Try(int i, int *a, int n, int *check)
{
	for (int j = 1; j <= n; j++)
	{
		if (check[j] == 1)
		{
			check[j] = 0;
			a[i] = j;
			if (i == n)
				out(n, a);
			else 
				Try(i+1, a, n, check);
			check[j] = 1;
		}
	}
}

int main()
{
	int n;
	int *check; 
	init(n, check);
	int *a = new int[n+1];
	Try(1, a, n, check);
	delete[] a;
	delete[] check;
}
