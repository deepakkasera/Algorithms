#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x = a[0];
	for(int i = 1; i < n; i++){
		// x = min(x,a[i]);
		if(a[i] < x){
			x = a[i];
		}
	}
	int y = INT_MAX;
	for(int i = 0; i < n; i++){
		if(a[i] <= y && a[i] > x){
			y = a[i];
		} 
	}
	cout << x << " "  << y << endl;
	return 0;
}