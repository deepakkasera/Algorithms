#include <bits/stdc++.h>
using namespace std;
int main(){
	// int a = 10;
	// int *ptr = &a;
	// int *q = ptr;
	// cout << (*q)++ << "\n";
	// cout << a << endl;
	int a = 100;
	int *p = &a;
	int **q = &p;
	int b = (**q)++ + 4;
	cout << a << " " << b << endl;
	return 0;
}