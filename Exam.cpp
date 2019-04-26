#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int d;
    long l;
    char ch;
    float f;
    double lf;
    
    cin >> d >> l >> ch >> f >> lf;
    cout << d << endl;
	cout << l << endl; 
	cout << ch << endl; 
	cout <<setflagio(std::fixed)<< f << endl; 
	cout << lf;
    return 0;
}
