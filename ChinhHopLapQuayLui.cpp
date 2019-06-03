#include <iostream>
using namespace std;

void init(int &n, int &k) {
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
}


void out(int n, int *a) 
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Try(int i, int *a, int n, int k)
{
	for (int j = 1; j <= n; j++)
	{
		a[i] = j;
		if (i == k)
			out(k, a);
		else 
			Try(i+1, a, n, k);
	}
}

int main()
{
	int n, k; 
	init(n, k);
	int *a = new int[n+1];
	Try(1, a, n, k);
	delete[] a;
}
