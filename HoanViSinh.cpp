#include <iostream>
using namespace std;

void init(int *a, int &n) {
	cout << "Nhap n: ";
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		a[i] = i;
}


void out(int *a, int &n) 
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isLast(int *a, int n)
{
	for(int i = n; i>=1; i--)
		if (a[i] != n-i+1) return false;
	return true;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Gen(int *a, int n)
{
	int i = n - 1;
	while (!(a[i] < a[i+1])) i--;
	
	int j = n;
	while (!(a[j] > a[i])) j--;
	
	swap(a[i], a[j]);
	
	int l = i + 1;
	int r = n;
	
	while (l < r)
	{
		swap(a[l], a[r]);
		l++; r--;
	}
	out(a, n);
}

void Method(int *a, int &n)
{
	init(a, n);
	out(a, n);
	while(!isLast(a, n))
	{
		Gen(a, n);
	}
}

int main()
{
	int n, k;
	int a[100];
	
	Method(a, n);
}
