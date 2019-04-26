// Ma di tuan su dung thuat toan Warnsdoff
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 8
#define NULL 0 

  
// Cap (x, y)[i] - Ma di chuyen
static int cx[N] = {1,1,2,2,-1,-1,-2,-2}; 
static int cy[N] = {2,-2,1,-1,2,-2,1,-1}; 
  
// Gioi han trong board
bool limits(int x, int y) 
{ 
    return ((x >= 0 && y >= 0) && (x < N && y < N)); 
} 

// Ma chua di qua o nay  
bool isempty(int a[], int x, int y) 
{ 
    return (limits(x, y)) && (a[y*N+x] < 0); 
} 
  
/* Dem so o lien ke co the di chuyen duoc*/
int getDegree(int a[], int x, int y) 
{ 
    int count = 0; 
    for (int i = 0; i < N; ++i) 
        if (isempty(a, (x + cx[i]), (y + cy[i]))) 
            count++; 
  
    return count; 
} 
  
// False neu het duong de di

bool nextMove(int a[], int *x, int *y) 
{ 
    int min_deg_idx = -1, c, min_deg = (N+1), nx, ny; 
  
    // Try all N adjacent of (*x, *y) starting 
    // from a random adjacent. Find the adjacent 
    // with minimum degree. 
    int start = rand()%N; 

    for (int count = 0; count < N; ++count) 
    { 
        int i = (start + count)%N; 
        nx = *x + cx[i]; 
        ny = *y + cy[i]; 
        if ((isempty(a, nx, ny)) && 
           (c = getDegree(a, nx, ny)) < min_deg) 
        { 
            min_deg_idx = i; 
            min_deg = c; 
        } 
    } 
  
    // Neu khong tim thay duong de di 
    if (min_deg_idx == -1) 
        return false; 
  
    // Luu vi tri tiep theo (nx, ny)
    nx = *x + cx[min_deg_idx]; 
    ny = *y + cy[min_deg_idx]; 
  
    // Danh dau tren board
    a[ny*N + nx] = a[(*y)*N + (*x)]+1; 
  
    // Update 
    *x = nx; 
    *y = ny; 
  
    return true; 
} 
  

// In cac buoc di cua ma
void print(int a[]) 
{ 
    for (int i = 0; i < N; ++i) 
    { 
        for (int j = 0; j < N; ++j) 
            printf("%d\t",a[j*N+i]); 
        printf("\n"); 
    } 
} 
  
// True: Buoc tiep theo de Hoan thanh hanh trinh

bool neighbour(int x, int y, int xx, int yy) 
{ 
    for (int i = 0; i < N; ++i) 
        if (((x+cx[i]) == xx)&&((y + cy[i]) == yy)) 
            return true; 
  
    return false; 
} 
  


bool findClosedTour() 
{ 
  	// Tat ca cac o gan -1
    int a[N*N]; 
    for (int i = 0; i< N*N; ++i) 
        a[i] = -1; 
  
    // Chon ngau nhien mot vi tri cho ma 
    int sx = rand()%N; 
    int sy = rand()%N;
    
    int x = sx, y = sy; 
    // Danh dau buoc dau tien
	a[y*N+x] = 1;  
  
    // Tim cac diem tiep theo - het duong thi ket thuc
	for (int i = 0; i < N*N-1; ++i) 
        if (nextMove(a, &x, &y) == 0) 
            return false; 
  
  	// !Hoan thanh hanh trinh
    if (!neighbour(x, y, sx, sy)) 
        return false; 
  
    print(a);
    cout << sx << " " << sy;
    return true; 
}



bool findClosedTour(int sx, int sy) 
{ 
  	// Tat ca cac o gan -1
    int a[N*N]; 
    for (int i = 0; i< N*N; ++i) 
        a[i] = -1; 
  
    int x = sx, y = sy; 
    // Danh dau buoc dau tien
	a[y*N+x] = 1;  
  
    // Tim cac diem tiep theo - het duong thi ket thuc
	for (int i = 0; i < N*N-1; ++i) 
        if (nextMove(a, &x, &y) == 0) 
            return false; 
  
  	// !Hoan thanh hanh trinh
    if (!neighbour(x, y, sx, sy)) 
        return false; 
  
    print(a);
    return true; 
} 
  
int main() 
{ 
	// Sinh ra cac rand - khac nhau
    srand(time(NULL)); 
  	int sel;
	cout << "1. Tim mot nghiem bat ky" << endl;
	cout << "2. Vi tri quan ma" << endl;
	cin >> sel;
	switch(sel)
	{
    // Lien tuc den khi co nghiem	
	case 1: while (!findClosedTour()) { ; } ; break;
  	case 2: {
  		int sx, sy;
  		cin >> sx >> sy;
	  	if(!findClosedTour(sx - 1, sy - 1)) cout << "Khong co ket qua!";
	  }
	}
  	
    return 0; 
} 
