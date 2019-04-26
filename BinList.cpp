// Output 000 001 010

#include <iostream>
using namespace std;


void init(int &n)
{
	cout << "n = ";
	cin >> n;
}
void result(int n, int s[])
{
	for (int i = 1; i <= n; i++)
		cout << s[i] << " ";
	cout << endl;
}
void Try(int i, int s[], int n)
{
	for (int j = 0; j <= 1; j++)
	{
		s[i] = j;
		if (i == n)
			result(n, s);
		else
			Try(i + 1, s, n);
	}
}
int main()
{
	int n;
	init(n);
	int *s = new int[n + 1];

	Try(1, s, n);
}
