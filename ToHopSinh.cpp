// List k elements in a n-element set with unordered selections
// Combinations

#include <iostream>
using namespace std;

int a[100];

void init(int &n, int &k, int *&a) {
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	
	for(int i = 1; i <= k; i++)
		a[i] = i;
}

void out(int *a, int k, int &count) 
{
	for (int i = 1; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	count++;
	cout << endl;
}

bool isLast(int *a, int n, int k)
{
	for (int i = k; i >= 1; i--)
	{
		if (a[i] != n - (k - i)) return false;
	}
	return true;
}

void Generate(int *a, int n, int k, int &count)
{
	int p = k;
	while(a[p] == n - (k - p)) p--;
		
	a[p]++;
	
	for(int i = p+1; i <=k; i++)
	{
		a[i] = a[i-1] + 1;
	}
	out(a, k, count);
}

void Method(int *a, int n, int k, int &count)
{
	init(n, k, a);
	out(a, k, count);
	while(!isLast(a, n, k))
	{
		Generate(a, n, k, count);
	}
	cout << "So tap hop con co k phan tu: " << count;
}

int main()
{
	int n, k;
	static int count = 0;
	Method(a, n, k, count);
}
