// List all x1, x2,.... xn have a sum which is equal = k
// all elements are isn't negative integer
#include <iostream>
using namespace std;


int sum;
void init(int &n, int &k)
{
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
}

int sumf(int l, int *a) {
	if(l == 1) return 0;
	int sum = 0;
	for (int i = 1; i < l; i++)
	{
		sum+= a[i];
	}
	return sum;
}
void out(int n, int *a) 
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] <<" ";
	}
	cout << endl;
}
void Try(int i, int n, int k, int *a) 
{
	for(int j = 0; j <= k; j++)
	{
		if(j == 0 && i == n-1) sum = sumf(i, a);
		if(sumf(i, a) <= k)
		{
		a[i] = j;
		if (i == n-1)
			{
				a[i+1] = k - sum++;
				if(a[i+1] >= 0) 
					out(n, a);
			}
		else
			Try(i+1, n, k, a);
		}
	}
}

int main() 
{
	int n, k;
	init(n, k);
	int a[n+1];
	Try(1, n, k, a);
}
