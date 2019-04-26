#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define MAX 100
#define INF 32767

void Doc_File(int W[MAX][MAX], int &n)
{
	ifstream _File("BaiToanDuLichTest.txt");
	if (_File.is_open())
	{
	_File >> n;
	cout << "Do thi nhap vao: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_File >> W[i][j];
			if(W[i][j] != INF) cout << setw(4) << W[i][j];
			else cout << "NULL";
		}
		cout << endl;	
	}
	_File.close();
	}	
}
int minValueOfRow(int W[MAX][MAX], int n, int row)
{
	int min = INF;
	for (int i = 0; i < n; i++)
		if (min > W[row][i]) 
			min = W[row][i];
	return min;
}
int minValueOfRow(int W[MAX][MAX], int n, int row, int pos)
{
	int min = INF;
	for (int i = 0; i < n; i++)
		if (min > W[row][i] && i != pos) 
			min = W[row][i];
	return min;
}
int minValueOfCol(int W[MAX][MAX], int n, int col)
{
	int min = INF;
	for (int i = 0; i < n; i++)
		if (min > W[i][col]) 
			min = W[i][col];
	return min;
}
int minValueOfCol(int W[MAX][MAX], int n, int col, int pos)
{
	int min = INF;
	for (int i = 0; i < n; i++)
		if (min > W[i][col] && i!= pos) 
			min = W[i][col];
	return min;
}
void subtractRow(int W[MAX][MAX], int n, int row, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (W[row][i]!= INF)
			W[row][i] -= value; 
	}
}
void subtractCol(int W[MAX][MAX], int n, int col, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (W[i][col]!= INF)
			W[i][col] -= value; 
	}
}
void RutGonMatran(int W[MAX][MAX], int n, int &sum)
{
	for (int i = 0; i < n; i++)
		{
			int min = minValueOfRow(W, n, i);
			if (min == 0) continue;
				else 
				{
					sum+= min;
					subtractRow(W, n, i, min);
				}
		}
		
	for (int i = 0; i < n; i++)
	{
		int min = minValueOfCol(W, n, i);
		if (min == 0) continue;
		else 
		{
			sum+= min;
			subtractCol(W, n, i, min);
		}
	}		
}
void printMatrix(int W[MAX][MAX], int n)
{	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(W[i][j] != INF) cout << setw(4) << W[i][j];
			else cout << "NULL";
		}
		cout << endl;	
	}
}
void reduceDegreeMatrix(int W[MAX][MAX], int& n, int row, int col, int *R, int *C)
{
	for (int i = row ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			W[i][j] = W[i+1][j];
			R[i] = R[i + 1];
		}
	}
	for (int j = col ; j < n; j++)
		for (int i = 0; i < n; i++)
		{
			W[i][j] = W[i][j + 1];
			C[j] = C[j + 1];
		}
	n--;
}
void process(int W[MAX][MAX], int n, int& sum)
{
	int P[n]; int n1 = n;
	int R[n], C[n];  
	int r, s;
	
	for (int i = 0; i < n; i++)
	{
		R[i] = i;
		C[i] = i;
	}
	
	while (n != 2)
	{
		// Buoc 1. Matran rut gon
		RutGonMatran(W, n, sum);
		//	cout << "Ma tran rut gon: " << endl;
		//	printMatrix(W, n);
		
		// Buoc 2. Chon canh phan nhanh
		
	
		int alph = - INF;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (W[i][j] == 0)
				{
					int temp = minValueOfRow(W, n, i, j) + minValueOfCol(W, n, j, i);
					if (alph < temp)
						alph = temp, r = i, s = j;
				}
		P[R[r]] = C[s];
		// Buoc 3. Phan nhanh
		
		//cout << R[r]+1 << " <- " << P[R[r]] + 1 << endl;
		W[s][r] = INF;
		reduceDegreeMatrix(W, n, r, s, R, C);
	//	cout << "Giam cap ma tran: " << endl;
	//	printMatrix(W, n);
	}
	// Xu ly ma tran 2*2
	RutGonMatran(W, n, sum);
	if(W[0][0] = 0) 
	{
		P[R[0]] = C[0];
		P[R[1]] = C[1];	
	}
	else
	{
		P[R[0]] = C[1];
		P[R[1]] = C[0];	
	}
	cout << "Chu trinh ngan nhat tao tu cac diem: " << sum << endl;
	/*
	cout << "Cac cap: " << endl;
	for (int i = 0; i < n1; i++) 
		cout << i + 1<< " <- " << P[i] + 1 << endl;*/
	cout << "Chu trinh: " << 1;
	int v = P[0];
	while (v != 0)
	{
		cout << "<-" << v + 1;
		v = P[v];
	}
	cout << "<-" << v + 1; 	
}

int main()
{
	int W[MAX][MAX], n, sum = 0;
	Doc_File(W, n);
	process(W, n, sum);	
}
