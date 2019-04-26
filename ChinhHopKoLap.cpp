// List k elements in a n-element set with unordered selections
// Combinations

#include <iostream>
using namespace std;

int a[100];


int fact(int n)
{
	return n*fact(n-1);
}

int Permutation(int n, int k)
{
	return fact(n)/ fact(n-k);
}

void init(int &n, int &k, int *&a, int &count, int &per) {
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	
	for(int i = 1; i <= k; i++)
		a[i] = i;
	
	count = 0;
	per = Permutation(n, k);
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
void Gen(int *a, int k, int &count)
{
	int i = k - 1;
	while (!(a[i] < a[i+1])) i--;
	
	int j = k;
	while (!(a[j] > a[i])) j--;
	
	swap(a[i], a[j]);
	
	int l = i + 1;
	int r = k;
	
	while (l < r)
	{
		swap(a[l], a[r]);
		l++; r--;
	}
	
	out(a, k, count);
}

void Generate(int *a, int n, int k, int &count, int per)
{
	int p = k;
	while(a[p] == n - (k - p)) p--;
		
	a[p]++;
	
	for(int i = p+1; i <=k; i++)
	{
		a[i] = a[i-1] + 1;
	}
}



void Method(int *a, int n, int k, int &count, int per)
{
	init(n, k, a, count, per);
	Generate(a, n, k, count, per);
	Gen(a, k, count);
		
	
	while(count != per)
	{
		
		Generate(a, n, k, count, per);
		Gen(a, k, count);
	}
	cout << "So tap hop con co k phan tu: " << count;
}

int main()
{
	int n, k, per;
	static int count = 0;
	Method(a, n, k, count, per);
}
