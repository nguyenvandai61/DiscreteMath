#include <iostream>
using namespace std;

void init(int *a, int &n, int &k) {
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	
	for (int i = 1; i <= k; i++)
		a[i] = 1;
}


void out(int *a, int k) 
{
	for (int i = 1; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isLast(int *a, int n, int k)
{
	for(int i = k; i>=1; i--)
		if (a[i] != n) return false;
	return true;
}
void Gen(int *a, int n, int k)
{
	int p = k;
	while (a[p] == n) p--;
	a[p]++;
	for (int i = p+1; i <= k; i++)
		a[i] = 1;
	out(a, k);
}

void Method(int *a, int &n, int &k)
{
	init(a, n, k);
	out(a, k);
	while(!isLast(a, n, k))
	{
		Gen(a, n, k);
	}
}

int main()
{
	int n, k;
	int a[100];
	
	Method(a, n, k);
}
