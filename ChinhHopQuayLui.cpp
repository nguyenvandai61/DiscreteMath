// List k elements in a n-element set with order selections
// Number of Permutations

#include <iostream>
using namespace std;

void init(int &n, int &k, int *&check) {
	
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	
	check = new int[n+1];
	
	for (int i = 1; i <= n; i++)
		check[i] = 1;
}
void process(int j, int *&check)
{
	for (int k = 1; k <= j; k++)
		check[k] = 0;
}

void out(int k, int *a, int &count) 
{
	for (int i = 1; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	count++;
	cout << endl;
}

void Try(int i, int *a, int k, int n, int *check, int &count)
{
	for (int j = 1;j <= n; j++)
	{
		if (check[j] == 1 )
		{
			check[j] = 0;
			a[i] = j;
			if (i == k)
				out(k, a, count);
			else 
				Try(i+1, a, k, n, check, count);
			check[j] = 1;
		}
	}
}

int main()
{
	int n, k;
	static int count = 0;
	int *check; 
	init(n, k, check);
	int *a = new int[n+1];
	a[0] = 0;
	Try(1, a, k, n, check, count);
	cout << count;
	delete[] a;
	delete[] check;
}
