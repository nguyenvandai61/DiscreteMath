#include <iostream>
using namespace std;

void init(int &n, int &m)
{
	cout << "Input n (row), m (column): ";
	cin >> n >> m;
}
void checkF(int &n, int &m, int *check, int loc)
{
	int x = loc%m;
	int y = loc/m;
	for (int i = 0; i < n*m; i++)
	{
		check[i] = 1;
	}
	check[loc] = 0;
	if (x!=0 && y>1) check[loc-2*m-1] = 0;
	if (x!=m-1 && y>1) check[loc-2*m+1] = 0;
	if (x>1 && y!=0) check[loc-m-2] = 0;
	if (x<m-2 && y!=0) check[loc-m+2] = 0;
	if (x>1 && y<n-1) check[loc+m-2] = 0;
	if (x<m-2 && y<n-1) check[loc+m+2] = 0;
	if (x!=0 && y<n-2) check[loc+2*m-1] = 0;
	if (x<m-1 && y<n-2) check[loc+2*m+1] = 0;
}
int main() 
{	
	int n, m;
	init(n, m);
	int *check = new int[n*m+1];
	int a[4];
	int count, count2 = 0;
	for(int i = 0; i < n*m; i++)
	{
		count = 0;
		checkF(n, m, check, i);
		for (int j = 0; j < m*n; j++)	
			if (check[j] == 1)
			{
				count++;
				cout<< i%m << i/m << " " << j%m << j/m << endl;
			}
		count2+= count;
		cout << count << endl;
	}
	cout << count2;
}
