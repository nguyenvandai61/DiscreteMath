// List k elements in a n-element set with unordered selections
// Combinations

#include <iostream>
using namespace std;

bool a[100];

void init(int &n, bool *&a) {
	cout << "Nhap n: ";
	cin >> n;
}

void out(bool *a, int n, int &count) 
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i]) 
			cout << i << " ";
	}
	count++;
	cout << endl;
}

bool isLast(bool *a, int n)
{
	for (int i = n; i > 0; i--)
	{
		if (a[i] == 0) return false;
	}
	return true;
}

void Generate(bool *a, int n, int &count)
{
	int p = n;
	while(a[p] != 0) p--;
	
	a[p] = 1;
	
	for (int i = p+1; i <= n; i++)
		a[i] = 0;
		
	out(a, n, count);
}

void Method(bool *a, int n, int &count)
{
	init(n, a);
	out(a, n, count);
	while(!isLast(a, n))
	{
		Generate(a, n, count);
	}
	cout << "So tap hop con: " << count;
}

int main()
{
	int n;
	static int count = 0;
	Method(a, n, count);
}
