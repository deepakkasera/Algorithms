#include <bits/stdc++.h>
using namespace std;
int fun(int a[],int n){
	int x = 0;
	int y = 0;
	for(int i = 1; i < n; i++){
		x^=i;
	}
	for(int i = 0; i < n; i++){
		y ^= a[i];
	}
	return x^y;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << fun(a,n)<<endl;
	return 0;
}