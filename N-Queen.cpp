#include <iostream>
using namespace std;
static int count = 0;

void out(int s[], int n)
{
	cout << "["; count++;
	for (int i = 1; i <= n; i++)
	{
		cout << s[i];
		cout << " "; 
	}
	cout << "] " << endl;
}


void Try(int i, int s[], int a[], int b[], int c[], int n)
{
	for (int j = 1; j <= n ; j++ ) 
	{
		if (b[j] == 1 && a[i + j] == 1 && c[n+i-j] == 1)
		{
			s[i] = j;
			b[j] = 0;
			a[i + j] = 0;
			c[n + i - j] = 0;
			if (i == n)
				out(s, n);
			else
				Try(i + 1, s, a, b, c, n);
			b[j] = 1;
			a[i + j] = 1;
			c[n + i - j] = 1;
		}
	}
}



int main()
{
	int n;
	cin >> n;
	int k = 0;
		int s[n + 1], a[2 * n], b[n + 1], c[2 * n];
	
		for (int i = 1 ; i <= n; i++ ) 
		{
			b[i] = 1;
		}
	
		for (int i = 1; i <= 2*n + 1; i++)
		{
			a[i] = 1;
			c[i] = 1;
		}
	
		Try(1, s, a, b, c, n);
		if ( count == 0) cout << -1;
		cout << endl;
		count = 0;	
	return 0;
}
